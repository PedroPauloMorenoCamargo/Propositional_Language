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

- The `biconditional/XNOR` operator evaluates to **verum** only when both logical operands are equal. This is illustrated in the image below:

  ![Biconditional/XNOR Truth Table](/imgs/xnor.jpg)

- Additionally, it can be represented in code using the following formats:
  1. `A <-> B`
  2. `A biconditional B`
  3. `A ↔ B`

**Implication**:

- The `implication` operator evaluates to **falsum** only when the first operand is true, and the second operand is false. In all other cases, it evaluates to **verum**. This is illustrated in the image below:

  ![Implication Truth Table](/imgs/implication.png)

- Additionally, it can be represented in code using the following formats:
  1. `A -> B`
  2. `A implies B`
  3. `A → B`

**Disjunction**:

- The `disjunction` operator evaluates to **verum** if at least one of the operands is **verum**. This is commonly referred to as the "logical OR" operator. The behavior of this operator is illustrated in the image below:

  ![Disjunction Truth Table](/imgs/disjunction.png)

- Additionally, it can be represented in code using the following formats:
  1. `A || B`
  2. `A or B`
  3. `A ∨ B`

**Conjunction**:

- The `conjunction` operator evaluates to **verum** only if both operands are **verum**. This is commonly referred to as the "logical AND" operator. The behavior of this operator is illustrated in the image below:

  ![Conjunction Truth Table](/imgs/conjunction.png)

- Additionally, it can be represented in code using the following formats:
  1. `A && B`
  2. `A and B`
  3. `A ∧ B`

**Negation**:

- The `negation` operator inverts the logical value of its operand. If the operand is **verum**, the result is **falsum**, and vice versa. This is commonly referred to as the "logical NOT" operator. The behavior of this operator is illustrated in the image below:

  ![Negation Truth Table](/imgs/Negation.png)

- Additionally, it can be represented in code using the following formats:
  1. `!A`
  2. `not A`
  3. `¬A`
  4. `~A`

**Equal**:

- The `equal` operator checks if two integer operands are equal. It evaluates to **verum** if the operands are equal, and **falsum** otherwise. This is commonly referred to as the equality operator. The behavior of this operator is illustrated in the image below:

- Additionally, it can be represented in code using the following formats:
  1. `A == B`
  
---

**Greater Than**:

- The `greater than` operator checks if the first integer operand is greater than the second integer operand. It evaluates to **verum** if the first operand is greater, and **falsum** otherwise. The behavior of this operator is illustrated in the image below:


- Additionally, it can be represented in code using the following formats:
  1. `A > B`

---

**Less Than**:

- The `less than` operator checks if the first integer operand is smaller than the second integer operand. It evaluates to **verum** if the first operand is less, and **falsum** otherwise. The behavior of this operator is illustrated in the image below:

- Additionally, it can be represented in code using the following formats:
  1. `A < B`


##### Characteristics:

Logical operators in **Prop** can be used in binary operations involving `integer-integer`, `boolean-boolean`, and `integer-boolean` combinations. For unary operations, a single `integer` or `boolean` value can be used.

Before the operation occurs, any integer value that is not `0` is mapped to **verum**, and `0` is mapped to **falsum**. The output of the operation is always mapped to the logical type. This mapping ensures consistency, triviality and simplifies logical operations.

Furthermore, as stated above, the operations **equal**, **greater than**, and **less than** can only be used with integer operands. If a boolean value is provided, an error will be raised.


1. **Binary Operations:**
   - `1 && 0` → **falsum** (1 is mapped to **verum**, 0 to **falsum**, result is **falsum**)
   - `verum || falsum` → **verum** 
   - `1 -> 0` → **falsum** (1 maps to **verum**, 0 to **falsum**, implication is **falsum**)
   - `1 <-> verum` → **verum** (1 maps to **verum**, operands are equal)

2. **Unary Operations:**
   - `!1` → **falsum** (1 maps to **verum**, negation yields **falsum**)
   - `not falsum` → **verum** 
   - `¬0` → **verum** (0 maps to **falsum**, negation yields **verum**)

3. **Mixed Integer-Boolean Operations:**
   - `1 && verum` → **verum** 
   - `0 || falsum` → **falsum** 
   - `verum -> 0` → **falsum** 

These examples demonstrate how integers are mapped to logical values and how operations are performed consistently across different types.









