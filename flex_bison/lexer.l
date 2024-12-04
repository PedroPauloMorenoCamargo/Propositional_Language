%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

%}

%option noyywrap
DIGIT           [0-9]
LETTER          [a-zA-Z]
ID              {LETTER}({LETTER}|{DIGIT}|_)*
NUMBER          {DIGIT}+
STRING          \"([^\"\\]|\\[\"\\nt])*\"


WHITESPACE      [ \t\r\n]+
BICONDITIONAL_OP    "↔"|"<->"|"biconditional"
IMPLICATION_OP      "→"|"->"|"implies"
OR_OP               "∨"|"||"|"or"
AND_OP              "∧"|"&&"|"and"
NOT_OP              "¬"|"!"|"~"|"not"
COMMENT_LINE        "//"[^\n]*

%%

"exhibit"                     { return EXHIBIT; }
"branch"                      { return BRANCH; }
"else"                        { return ELSE; }
"while"                       { return WHILE; }
"for"                         { return FOR; }
"int"                         { return INT_TYPE; }
"log"                         { return LOG_TYPE; }
"verum"                       { return VERUM; }
"falsum"                      { return FALSUM; }

"("                         { return LPAREN; }
")"                         { return RPAREN; }
"{"                         { return LBRACE; }
"}"                         { return RBRACE; }
":"                         { return COLON; }
";"                         { return SEMICOLON; }
","                         { return COMMA; }
"=="                        { return EQ; }
"<"                         { return LT; }
">"                         { return GT; }
"="                         { return ASSIGN; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return TIMES; }
"/"                         { return DIVIDE; }

{BICONDITIONAL_OP}          { return BICONDITIONAL; }
{IMPLICATION_OP}            { return IMPLICATION; }
{OR_OP}                     { return OR; }
{AND_OP}                    { return AND; }
{NOT_OP}                    { return NOT; }

{ID}                        { yylval.str = strdup(yytext); return IDENTIFIER; }
{NUMBER}                    { yylval.num = atoi(yytext); return NUMBER; }
{STRING}                    { yylval.str = strdup(yytext); return STRING; }

{WHITESPACE}                {} 
{COMMENT_LINE}              {} // Ignore comments
.                           { fprintf(stderr, "Unrecognized character: %s\n", yytext); exit(1); }

%%
