%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/* AST Node Definition */
typedef struct ASTNode {
    char *type;                /* Type of node (e.g., "BINOP", "PRINT") */
    char *value;               /* Specific value (e.g., "+", "exhibit") */
    struct ASTNode **children; /* Array of child nodes */
    int num_children;          /* Number of child nodes */
} ASTNode;

/* Function Prototypes */
void yyerror(const char *s);
int yylex();
ASTNode *create_ast_node(char *type, char *value, int num_children, ASTNode **children);
void print_ast(ASTNode *node, int indent, FILE *file);
void save_ast_to_yaml(ASTNode *root, const char *filename);

ASTNode *ast_root; // Root of the AST
%}

/* Union for Parser Values */
%union {
    char *str;           /* For strings and identifiers */
    int num;             /* For numbers */
    struct ASTNode *node; /* For AST nodes */
}

/* Tokens */
%token EXHIBIT BRANCH ELSE WHILE FOR INT_TYPE LOG_TYPE VERUM FALSUM
%token LPAREN RPAREN LBRACE RBRACE COLON SEMICOLON COMMA EQ LT GT ASSIGN PLUS MINUS TIMES DIVIDE
%token BICONDITIONAL IMPLICATION OR AND NOT
%token <str> IDENTIFIER STRING
%token <num> NUMBER

%type <node> assignment_expression program statement_list statement print_statement print_arguments print_expr_list_opt print_expr_list declaration_statement assignment_statement if_statement while_statement for_statement block expression biconditional implication disjunction conjunction sum term factor atom identifier_decl identifier_list assign_opt else_opt type

/* Grammar Start */
%start program

%%

/* Grammar Rules */
program:
    statement_list {
        ast_root = create_ast_node("PROGRAM", NULL, $1->num_children, $1->children);
        free($1);
    }
    ;

statement_list:
    /* empty */ {
        $$ = create_ast_node("STATEMENT_LIST", NULL, 0, NULL);
    }
    | statement_list statement {
        ASTNode *list = $1;
        if ($2) {
            list->num_children += 1;
            list->children = realloc(list->children, sizeof(ASTNode *) * list->num_children);
            list->children[list->num_children - 1] = $2;
        }
        $$ = list;
    }
    ;

statement:
    print_statement
    | declaration_statement
    | assignment_statement
    | if_statement
    | while_statement
    | for_statement
    | SEMICOLON { $$ = NULL; } /* To handle optional semicolons in blocks */
    ;

print_statement:
    EXHIBIT LPAREN print_arguments RPAREN SEMICOLON {
        $$ = create_ast_node("EXHIBIT", NULL, $3->num_children, $3->children);
        free($3);
    }
    ;

print_arguments:
    STRING print_expr_list_opt {
        int num_children = 1 + $2->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = create_ast_node("STRING", $1, 0, NULL);
        for (int i = 0; i < $2->num_children; i++) {
            children[i + 1] = $2->children[i];
        }
        free($2->children);
        free($2);
        $$ = create_ast_node("PRINT_ARGUMENTS", NULL, num_children, children);
        free(children);
    }
    ;

print_expr_list_opt:
    /* empty */ {
        $$ = create_ast_node("EXPR_LIST", NULL, 0, NULL);
    }
    | COMMA biconditional print_expr_list {
        int num_children = 1 + $3->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = $2;
        for (int i = 0; i < $3->num_children; i++) {
            children[i + 1] = $3->children[i];
        }
        free($3->children);
        free($3);
        $$ = create_ast_node("EXPR_LIST", NULL, num_children, children);
        free(children);
    }
    ;

print_expr_list:
    /* empty */ {
        $$ = create_ast_node("EXPR_LIST", NULL, 0, NULL);
    }
    | COMMA biconditional print_expr_list {
        int num_children = 1 + $3->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = $2;
        for (int i = 0; i < $3->num_children; i++) {
            children[i + 1] = $3->children[i];
        }
        free($3->children);
        free($3);
        $$ = create_ast_node("EXPR_LIST", NULL, num_children, children);
        free(children);
    }
    ;

declaration_statement:
    identifier_decl COLON type SEMICOLON {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("DECLARATION_STATEMENT", NULL, 2, children);
        free(children);
    }
    ;

identifier_decl:
    IDENTIFIER assign_opt identifier_list {
        int total_children = 1 + ($2 ? 1 : 0) + $3->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * total_children);
        int idx = 0;
        children[idx++] = create_ast_node("IDENTIFIER", $1, 0, NULL);
        if ($2) {
            children[idx++] = $2;
        }
        for (int i = 0; i < $3->num_children; i++) {
            children[idx++] = $3->children[i];
        }
        free($3->children);
        free($3);
        $$ = create_ast_node("IDENTIFIER_DECL", NULL, total_children, children);
        free(children);
    }
    ;

assign_opt:
    /* empty */ { $$ = NULL; }
    | ASSIGN biconditional { $$ = $2; }
    ;

identifier_list:
    /* empty */ {
        $$ = create_ast_node("IDENTIFIER_LIST", NULL, 0, NULL);
    }
    | COMMA IDENTIFIER assign_opt identifier_list {
        int total_children = 1 + ($3 ? 1 : 0) + $4->num_children;
        ASTNode **children = malloc(sizeof(ASTNode *) * total_children);
        int idx = 0;
        children[idx++] = create_ast_node("IDENTIFIER", $2, 0, NULL);
        if ($3) {
            children[idx++] = $3;
        }
        for (int i = 0; i < $4->num_children; i++) {
            children[idx++] = $4->children[i];
        }
        free($4->children);
        free($4);
        $$ = create_ast_node("IDENTIFIER_LIST", NULL, total_children, children);
        free(children);
    }
    ;

type:
    INT_TYPE { $$ = create_ast_node("TYPE", "int", 0, NULL); }
    | LOG_TYPE { $$ = create_ast_node("TYPE", "log", 0, NULL); }
    ;

assignment_statement:
    assignment_expression SEMICOLON {
    }
    ;


if_statement:
    BRANCH LPAREN biconditional RPAREN block else_opt {
        int num_children = 2 + ($6 ? 1 : 0);
        ASTNode **children = malloc(sizeof(ASTNode *) * num_children);
        children[0] = $3; // Condition
        children[1] = $5; // If Block
        if ($6) {
            children[2] = $6; // Else Block
        }
        $$ = create_ast_node("IF_STATEMENT", NULL, num_children, children);
        free(children);
    }
    ;

else_opt:
    /* empty */ { $$ = NULL; }
    | ELSE block { $$ = $2; }
    ;

while_statement:
    WHILE LPAREN biconditional RPAREN block {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $3; // Condition
        children[1] = $5; // Body
        $$ = create_ast_node("WHILE_STATEMENT", NULL, 2, children);
        free(children);
    }
    ;

assignment_expression:
    IDENTIFIER ASSIGN biconditional {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = create_ast_node("IDENTIFIER", $1, 0, NULL);
        children[1] = $3;
        $$ = create_ast_node("ASSIGNMENT_STATEMENT", NULL, 2, children);
        free(children);
    }
    ;


for_statement:
    FOR LPAREN assignment_expression SEMICOLON biconditional SEMICOLON assignment_expression RPAREN block {
        ASTNode **children = malloc(sizeof(ASTNode *) * 4);
        children[0] = $3; // Initialization
        children[1] = $5; // Condition
        children[2] = $7; // Update
        children[3] = $9; // Body
        $$ = create_ast_node("FOR_STATEMENT", NULL, 4, children);
        free(children);
    }
    ;


block:
    LBRACE statement_list RBRACE {
        $$ = create_ast_node("BLOCK", NULL, $2->num_children, $2->children);
        free($2);
    }
    ;

biconditional:
    biconditional BICONDITIONAL implication {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "biconditional", 2, children);
        free(children);
    }
    | implication {
        $$ = $1;
    }
    ;

implication:
    implication IMPLICATION disjunction {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "implication", 2, children);
        free(children);
    }
    | disjunction {
        $$ = $1;
    }
    ;

disjunction:
    disjunction OR conjunction {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "or", 2, children);
        free(children);
    }
    | conjunction {
        $$ = $1;
    }
    ;

conjunction:
    conjunction AND expression {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "and", 2, children);
        free(children);
    }
    | expression {
        $$ = $1;
    }
    ;

expression:
    expression EQ sum {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "equal", 2, children);
        free(children);
    }
    | expression LT sum {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "lesser", 2, children);
        free(children);
    }
    | expression GT sum {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "greater", 2, children);
        free(children);
    }
    | sum {
        $$ = $1;
    }
    ;

sum:
    sum PLUS term {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "plus", 2, children);
        free(children);
    }
    | sum MINUS term {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "minus", 2, children);
        free(children);
    }
    | term {
        $$ = $1;
    }
    ;

term:
    term TIMES factor {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "mult", 2, children);
        free(children);
    }
    | term DIVIDE factor {
        ASTNode **children = malloc(sizeof(ASTNode *) * 2);
        children[0] = $1;
        children[1] = $3;
        $$ = create_ast_node("BINARY_OP", "div", 2, children);
        free(children);
    }
    | factor {
        $$ = $1;
    }
    ;

factor:
    PLUS factor {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = $2;
        $$ = create_ast_node("UNARY_OP", "plus", 1, children);
        free(children);
    }
    | MINUS factor {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = $2;
        $$ = create_ast_node("UNARY_OP", "minus", 1, children);
        free(children);
    }
    | NOT factor {
        ASTNode **children = malloc(sizeof(ASTNode *) * 1);
        children[0] = $2;
        $$ = create_ast_node("UNARY_OP", "not", 1, children);
        free(children);
    }
    | atom {
        $$ = $1;
    }
    ;

atom:
    LPAREN biconditional RPAREN {
        $$ = $2;
    }
    | NUMBER {
        char buffer[20];
        sprintf(buffer, "%d", $1);
        $$ = create_ast_node("NUMBER", buffer, 0, NULL);
    }
    | VERUM {
        $$ = create_ast_node("BOOLEAN", "verum", 0, NULL);
    }
    | FALSUM {
        $$ = create_ast_node("BOOLEAN", "falsum", 0, NULL);
    }
    | IDENTIFIER {
        $$ = create_ast_node("IDENTIFIER", $1, 0, NULL);
    }
    ;

%%

/* AST Node Functions */
ASTNode *create_ast_node(char *type, char *value, int num_children, ASTNode **children) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->num_children = num_children;
    if (num_children > 0 && children != NULL) {
        node->children = (ASTNode **)malloc(sizeof(ASTNode *) * num_children);
        for (int i = 0; i < num_children; i++) {
            node->children[i] = children[i];
        }
    } else {
        node->children = NULL;
    }
    return node;
}

void print_ast(ASTNode *node, int indent, FILE *file) {
    for (int i = 0; i < indent; ++i) fprintf(file, "  ");
    fprintf(file, "- type: %s\n", node->type);

    if (node->value) {
        for (int i = 0; i < indent + 1; ++i) fprintf(file, "  ");
        fprintf(file, "value: %s\n", node->value);
    }

    if (node->num_children > 0) {
        for (int i = 0; i < indent + 1; ++i) fprintf(file, "  ");
        fprintf(file, "children:\n");
        for (int i = 0; i < node->num_children; ++i) {
            print_ast(node->children[i], indent + 2, file);
        }
    }
}

void save_ast_to_yaml(ASTNode *root, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "AST:\n");
    print_ast(root, 1, file);
    fclose(file);
}

/* Error Handling */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/* Main Function */
int main(void) {
    if (yyparse() == 0) {
        save_ast_to_yaml(ast_root, "../ast/output.yaml");
        printf("AST written to output.yaml\n");
    }
    return 0;
}
