# Propositional_Language 

# Made by Pedro Paulo Moreno Camargo and Pedro Henrique Colpas

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

term               ::= factor { ("*" | "/") factor } ;

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

The logical type accepts either the Latin concepts of truth and falsehood, **`verum`** (true) and **`falsum`** (false).
#### Integer Type

The integer type supports both positive and negative integer values.

---


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

Furthermore, as stated above, the operations `equal`, `greater than`, and `less than` can only be used with integer operands. If a boolean value is provided, an error will be raised.


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

#### Arithmetical Operators

Arithmetical operations in **Prop** can only be performed on integers to ensure mathematical consistency and triviality. The supported arithmetical operations are listed below:

##### Plus:

- The `plus` operator adds two integer operands and returns their sum. This operation follows standard mathematical rules. The behavior is illustrated in the example below:

  **Examples:**
  - `3 + 2` → `5`
  - `-1 + 4` → `3`
  - `0 + 7` → `7`

- Additionally, it can be represented in code using the following formats:
  1. `A + B`

##### Minus:

- The `minus` operator subtracts the second integer operand from the first and returns the result. The behavior is illustrated in the example below:

  **Examples:**
  - `5 - 3` → `2`
  - `-1 - 4` → `-5`
  - `7 - 7` → `0`

- Additionally, it can be represented in code using the following formats:
  1. `A - B`

##### Multiplication:

- The `multiplication` operator multiplies two integer operands and returns their product. The behavior is illustrated in the example below:

  **Examples:**
  - `3 * 2` → `6`
  - `-2 * 4` → `-8`
  - `0 * 5` → `0`

- Additionally, it can be represented in code using the following formats:
  1. `A * B`

##### Division:

- The `division` operator divides the first integer operand by the second. It performs integer division, truncating any decimal part. If the second operand is `0`, an error is raised. The behavior is illustrated in the example below:

  **Examples:**
  - `6 / 2` → `3`
  - `-8 / 4` → `-2`
  - `7 / 3` → `2` (integer division truncates the decimal part)

- Additionally, it can be represented in code using the following formats:
  1. `A / B`

##### Unary Plus:

- The `unary plus` operator is used to explicitly indicate that a number is positive. While it does not change the value of the operand, it can improve code readability. The behavior is illustrated in the example below:

  **Examples:**
  - `+5` → `5`
  - `+(-3)` → `-3`
  - `+0` → `0`

- Additionally, it can be represented in code using the following format:
  1. `+A`

##### Unary Minus:

- The `unary minus` operator negates the value of the operand, effectively multiplying it by `-1`. The behavior is illustrated in the example below:

  **Examples:**
  - `-5` → `-5`
  - `-(-3)` → `3`
  - `-0` → `0`

- Additionally, it can be represented in code using the following format:
  1. `-A`

#### Characteristics:

As mentioned above, integer operations can only be performed on integer types and will always result in an integer type. This restriction ensures that our propositional logic subset remains trivial, consistent, and complete.

### Precedence Table

The precedence of operations in **Prop** is defined as follows, from the highest to the lowest level:

| Precedence Level | Type                  | Operators                                             |
|-------------------|-----------------------|------------------------------------------------------|
| 1 (Highest)       | Atom                  | Variables, integers, logical types (`verum`, `falsum`), parentheses `()` |
| 2                 | Unary                 | Unary plus `+`, unary minus `-`, negation (`¬`, `!`, `~`, `not`) |
| 3                 | Multiplication/Division | `*`, `/`                                            |
| 4                 | Addition/Subtraction  | `+`, `-`                                            |
| 5                 | Relational/Equality   | Equal `==`, greater than `>`, lesser than `<`       |
| 6                 | Conjunction           | `∧`, `&&`, `and`                                    |
| 7                 | Disjunction           | `∨`, `or`                                     |
| 8                 | Implication           | `->`, `→`, `implies`                                |
| 9 (Lowest)        | Biconditional         | `↔`, `<->`, `biconditional`                         |

This precedence ensures that operations are evaluated in a logical and consistent order, reflecting their importance and function in propositional logic and arithmetic.

### Example

Consider the following expression:

`(3 + 5) * -2 > 4 ∨ verum ∧ falsum`

**Step-by-step evaluation:**
1. Evaluate the **atom** `(3 + 5)` → `8`.
2. Apply the **unary minus** to `-2` → `-2`.
3. Perform **multiplication**: `8 * -2` → `-16`.
4. Compare using **relational/equality**: `-16 > 4` → `falsum`.
5. Evaluate the **conjunction**: `verum ∧ falsum` → `falsum`.
6. Evaluate the **disjunction**: `falsum ∨ falsum` → `falsum`.

**Result:** The final value of the expression is **falsum**.

Parentheses can be used to override precedence, ensuring that specific parts of an expression are evaluated first.

---

### Variable Declaration

#### Single Variable Declaration

A variable can be declared without an initial value or with an assignment. The syntax is shown below:

`<variable_name>: <variable_type> ; `

`<variable_name> = <variable_value> : <variable_type> ;`

**Examples:**
- `x : int;` (declares an integer variable `x` with no initial value)
- `isTrue = verum: int;` (declares a logical variable `isTrue` and assigns it the value `verum`)

#### Multiple Variable Declaration

Multiple variables can be declared on the same line, either without initial values or with assignments. However, you cannot mix different variable types in the same line. The syntax is shown below:

`<variable1>, <variable2>, ..., <variableN>:<variable_type>;` 

`<variable1> = <value1>,  <variable2> = <value2>, ..., <variableN> = <valueN>: <variable_type> ;`

**Examples:**
- `a, b, c : log;` (declares three integer variables `a`, `b`, and `c` with no initial values)
- `x = 1, y, z = 3 : int;` (declares three integer variables and assigns them values)
- **Invalid:** `a :int, isTrue : log;` (cannot mix `int` and `log` types in the same line)

**Note:**
- In a multiple variable declaration it's possible to assign variables and in the same line declare variables without assigning them..

---


### Variable Assignment

As seen above variable assignment follows the syntax below:

`<id> = <value>;`

**Note:**
- The variable assigned must correspond to the type declared.


**Note:**
- The value assigned to a variable must correspond to its declared type.
- A variable can only be assigned after a variable with the same id has been declared.

**Examples:**
- `x = 10 : int;` (assigns the integer value `10` to the variable `x`)
- `isTrue = verum : log;` (assigns the logical value `verum` to the variable `isTrue`)
- `x = 5;` (reassigns a new value to the already declared variable `x`)
- `isTrue = falsum;` (updates the value of the logical variable `isTrue` to `falsum`)

**Invalid Example:**
- `x = verum : int;` (error: `verum` is a logical value and cannot be assigned to an integer variable)

---

### Terminal Exhibition

Information can be displayed on the console using terminal exhibition. The output can be either a standalone string or a string with arguments embedded within it (e.g., `%d` for integers and `%l` for logical types).

Terminal exhibition follows the syntax below:



`exhibit(<String>);`

or 

`exhibit(<String>, <arg1>,<arg2>,<arg3>,...,<argN>);`


**Note:**
- The arguments embedded in the string must correspond to the same types as the arguments passed to the `exhibit` function.
- The number of embedded arguments in the string must match the number of arguments passed to the `exhibit` function.

**Examples:**
1. Standalone string:
    ```prop
    exhibit("Hello, World!");
    ```
  - Output: `Hello, World!`
2. String with arguments:
    ```prop
    exhibit("The value is %d.", 42);
    ```
  - Output: `The value is 42`.

    ```prop
    exhibit("Logical value: %l", verum);
    ```
  - Output: `Logical value: verum`
4. Multiple arguments:
    ```prop
    exhibit("Values: %d, %l, %d", 10, falsum, 20);
    ```
  - Output: `Values: 10, falsum, 20`

**Invalid Examples:**

1. Mismatched types:
    ```prop
    exhibit("Value: %d", verum);
   ```
2. Mismatched number of arguments:
    ```prop
    exhibit("Values: %d, %l", 10);
    ```

---


### Branch Flux Control

For flux control, the `branch` command evaluates a condition and, based on the result, executes a specific block of code. The condition in a branch must evaluate to a logical variable.

Branch flux control follows the syntax below:


`branch(<condition>){<statement1>,<statement2>,...}`

or 

`branch(<condition>){<statement1>,<statement2>,...} else {<statement3>,<statement4>,...}`


**Examples:**

1. **Branch without `else`:**
    ```prop
    isTrue = verum : log;
    branch(isTrue) {
        exhibit("Condition is true!");
    }
    ```
  - Output: `Condition is true!`
2. Branch with else:
    ```prop
    isFalse = falsum : log;
    branch(isFalse) {
        exhibit("Condition is false!");
    } else {
        exhibit("Condition is true!");
    }
    ```
  - Output: `Condition is true!`

3. Branch with a logical expression:
    ```prop
    x = 5, y = 10 : int;
    branch(x < y) {
        exhibit("x is less than y.");
    } else {
        exhibit("x is not less than y.");
    }
    ```
  - Output: `x is less than y`.

**Invalid Examples:**

1. Condition is not a logical value:
    ```prop
    x = 5 : int;
    branch(x) {
        exhibit("Invalid condition.");
    }

    ```

---


### While

### While Flux Control

The `while` command evaluates a condition and continuously executes the assigned block of code as long as the condition evaluates to **verum**.

While flux control follows the syntax below:




`while(<condition>){<statement1>,<statement2>,...}`


**Examples:**

1. **Basic while loop:**
    ```prop
    counter = 0: int;
    while(counter < 5) {
        exhibit("Counter: %d", counter);
        counter = counter + 1;
    }
    ```
  - Output:
    ```prop
    Counter: 0
    Counter: 1
    Counter: 2
    Counter: 3
    Counter: 4
    ```

2. **Using a logical condition:**
    ```prop
    isRunning = verum : log;
    x = 10 : int;
    while(isRunning) {
        exhibit("x = %d", x);
        x = x - 1;
        branch(x == 0) {
            isRunning = falsum;
        }
    }
    ```
  - Output:
    ```prop
    x = 10
    x = 9
    x = 8
    x = 7
    x = 6
    x = 5
    x = 4
    x = 3
    x = 2
    x = 1
    x = 0
    ```

**Invalid Examples:**

1. **Condition is not a logical value:**
    ```prop
    x = 5 : int;
    while(x) {
        exhibit("Invalid condition.");
    }
    ```

---


### For

### For Flux Control

The `for` command is used to iterate a block of code. It requires an initial assignment, a condition, and an update assignment. The variable used in the assignment must be declared prior to the `for` initialization, and the condition must evaluate to a logical type.

For flux control follows the syntax below:

`for(<assignment>;<condition>;<assignment>){<statement1>,<statement2>,...}`

**Examples:**

1. **Basic for loop:**
    ```prop
    i : int;
    for(i = 0; i < 5; i = i + 1) {
       exhibit("Iteration: %d", i);
    }
    ```
  - Output:
    ```prop
    Counter: 0
    Counter: 1
    Counter: 2
    Counter: 3
    Counter: 4
    ```

2. **Using a logical condition:**
    ```prop
    counter : int;
    continueLoop = verum : log;
    for(counter = 0; continueLoop; counter = counter + 1) {
        exhibit("Counter: %d", counter);
        branch(counter == 4) {
            continueLoop = falsum;
        }
    }

    ```
  - Output:
    ```prop
    Counter: 0
    Counter: 1
    Counter: 2
    Counter: 3
    Counter: 4

    ```

**Invalid Examples:**

1. **Condition is not a logical value:**
    ```prop
    i : int;
    for(i = 0; i; i = i + 1) {
        exhibit("Invalid condition.");  // Error: `i` is not a logical variable
    }
    ```

2. **Variable not declared prior to for:**
    ```prop
    for(i = 0, i, i = i + 1) {
        exhibit("Invalid condition.");  // Error: `i` is not a logical variable
    }
    ```

---

## Program Examples

### Modus Tolens Proof
```prop
exhibit("Demonstrando o modus tollens:\n");

// Definindo P e Q
P = 1 : log;
Q = falsum : log;

// Avaliando P -> Q e negando Q
exhibit("Se assumimos P como verdade (P = %l) e Q como falso (Q = %l):\n", P, Q);
exhibit("A implicação P -> Q é: %l.\n", P -> Q);
exhibit("Agora, assumimos ¬Q como verdade (¬Q = %l):\n", ¬Q);

// Concluímos ¬P
exhibit("Com P -> Q e ¬Q, a conclusão lógica é ¬P:\n");
exhibit("¬P = %l.\n", ¬P);
```

- Output:
```prop
Demonstrando o modus tollens:

Se assumimos P como verdade (P = verum) e Q como falso (Q = falsum):

A implicação P -> Q é: falsum.

Agora, assumimos ¬Q como verdade (¬Q = verum):

Com P -> Q e ¬Q, a conclusão lógica é ¬P:

¬P = falsum.
```

## How to Run

Run the following command in the `flex_bison` directory to compile the lexer and parser:

```bash
sudo make
```

Use the executable created with your test file:

```bash
./parser < test_file.prop
```

This will create an abstract syntax tree as a .yaml file.

Finally, run in the terminal the following command:

```bash
python3 main.py output.yaml

```













