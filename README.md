# Propositional_Language

## Objective

  In the subject of Computer Logic, one of the most challenging topics to visualize and understand was the mathematics behind propositional logic. Therefore, when assigned the final project of creating a new language, I decided to develop **Prop**, a propositional language designed to help future students gain a deeper understanding of propositional logic.

## EBNF

  The syntax of **Prop** is defined below using Extended Backus–Naur Form (EBNF):



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

## Language Characteristics

### Types

In **Prop**, there are two types: **logical/boolean** and **integer**, represented respectively as `log` and `int`.

#### Logical Type

The logical type accepts either the Latin concepts of truth and falsehood, **`verum`** (true) and **`falsum`** (false), or their corresponding integer representations, **`0`** (false) and **`1`** (true).

#### Integer Type

The integer type supports both positive and negative integer values.


### Operators

  In **Prop** there is two different types of operators the logical and arithmetical.

#### Logical Operators

**Biconditional**:

  - The biconditional operator evaluates to true only when both logical operands are equal. This is illustrated in the image below:
  
  *[]*

  - Additionally, it can be represented in code using the following formats:
    1. `A <-> B`
    2. `A biconditional B`




