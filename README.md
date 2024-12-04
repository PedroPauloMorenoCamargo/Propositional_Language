# Propositional_Language

## Objective

In the subject of Computer Logic one of the main topics that was difficult to actually visualize and understand was the mathematics of propositional math. Hence, when tasked with the final project of creating a brand new language I had the idea of making a propositional language to help future students to gain better insight on propositional math.

## EBNF

The syntax of the language is represented below in the extended Backus–Naur form notation:

```ebnf
program            ::= statement_list ";" ;

statement_list     ::= { statement } ;

statement          ::= print_statement
                      | declaration_statement
                      | assignment_statement
                      | if_statement
                      | while_statement
                      | for_statement
                      | SEMICOLON ;

print_statement    ::= "exhibit" "(" print_arguments ")" SEMICOLON ;

print_arguments    ::= STRING [ print_expr_list ] ;

print_expr_list    ::= "," biconditional { "," biconditional } ;

declaration_statement ::= identifier_decl ":" type SEMICOLON ;

identifier_decl    ::= IDENTIFIER [ assign_opt ] { "," IDENTIFIER [ assign_opt ] } ;

assign_opt         ::= "=" biconditional ;

type               ::= "int" | "log" ;

assignment_statement ::= assignment_expression SEMICOLON ;

assignment_expression ::= IDENTIFIER "=" biconditional ;

if_statement       ::= "branch" "(" biconditional ")" block [ "ELSE" block ] ;

while_statement    ::= "while" "(" biconditional ")" block ;

for_statement      ::= "for" "(" assignment_expression ";" biconditional ";" assignment_expression ")" block ;

block              ::= "{" statement_list "}" ;

biconditional      ::= implication { ("↔"|"<->"|"biconditional" ) implication } ;

implication        ::= disjunction { ("->| →"|"implies") disjunction } ;

disjunction        ::= conjunction { ("∨"|"||"|"or") conjunction } ;

conjunction        ::= expression { ("∧"|"&&"|"and") expression } ;

expression         ::= sum { ("==" | "<" | ">" ) sum } ;

sum                ::= term { ("+" | "-") term } ;

term               ::= factor { ("*" | "/" | "%") factor } ;

factor             ::= ("+" | "-" | "¬"| "!"| "~"| "not") factor
                      | atom ;

atom               ::= "(" expression ")"
                      | NUMBER
                      | "verum"
                      | "falsum"
                      | IDENTIFIER ;

STRING             ::= '"' character* '"' ;

IDENTIFIER         ::= letter (letter | digit | "_")* ;

NUMBER             ::= digit (digit)* ;

letter             ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z" ;

digit              ::= "0" | "1" | ... | "9" ;

character          ::= letter | digit | " " | any_other_printable_character ;

comment ::= "//" { character2 } (newline | EOF) ;

character2 ::= ? any character except newline ? ;

newline ::= "\n" | "\r\n" ;


```
