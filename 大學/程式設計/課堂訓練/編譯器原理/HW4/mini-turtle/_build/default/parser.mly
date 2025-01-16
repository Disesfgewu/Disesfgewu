/* Parsing for mini-Turtle */

%{
  open Ast
%}

/* Declaration of tokens */
%token EOF
%token <int> INT
%token <string> IDENT
%token FORWARD PENUP PENDOWN TURNLEFT TURNRIGHT
%token REPEAT DEF IF ELSE
%token PLUS MINUS TIMES DIV
%token LPAREN RPAREN LBRACE RBRACE COMMA
%token COLOR BLACK WHITE RED GREEN BLUE

/* Priorities and associativity of tokens */
%left PLUS MINUS
%left TIMES DIV
%right NEG

/* Axiom of the grammar */
%start prog

/* Type of values ​​returned by the parser */
%type <Ast.program> prog

%%

/* Production rules of the grammar */

prog:
  | stmts EOF { { defs = []; main = Sblock $1 } }
  | defs stmts EOF
    { { defs = $1; main = Sblock $2 } }
  | defs stmt_block EOF
      { { defs = $1; main = $2 } }
;


defs:
  | { [] }
  | defs def { $1 @ [$2] }
;

def:
  | IDENT LPAREN args RPAREN stmt_block
      { { name = $1; formals = $3; body = $5 } }
  | DEF IDENT LPAREN args RPAREN stmt_block
      { Printf.printf "Parser matched def: %s with args %s\n%!" $2 (String.concat ", " $4); 
        { name = $2; formals = $4; body = $6 } }
  | DEF IDENT LPAREN args RPAREN stmt
      { Printf.printf "Parser matched single-line def: %s with args %s\n%!" $2 (String.concat ", " $4); 
        { name = $2; formals = $4; body = Sblock [$6] } }
;


args:
  | { [] }
  | IDENT { [$1] }
  | args COMMA IDENT { $1 @ [$3] }
;

stmt_block:
  | LBRACE stmts RBRACE { Printf.printf "Matched stmt_block: { stmts }\n%!"; Sblock $2 }
  | stmts { Printf.printf "Matched stmt_block: single stmt\n%!"; Sblock $1 }
;

stmts:
  | { [] }
  | stmts stmt { $1 @ [$2] }
;

stmt:
  | FORWARD expr
      { Printf.printf "Matched stmt: FORWARD %s\n%!" (Ast.string_of_expr $2); Sforward $2 }
  | REPEAT expr stmt_block
      { Printf.printf "Matched stmt: REPEAT %s\n%!" (Ast.string_of_expr $2); Srepeat ($2, $3) }
  | PENUP
      { Printf.printf "Matched stmt: PENUP\n%!"; Spenup }
  | PENDOWN
      { Printf.printf "Matched stmt: PENDOWN\n%!"; Spendown }
  | TURNLEFT expr
      { Printf.printf "Matched stmt: TURNLEFT %s\n%!" (Ast.string_of_expr $2); Sturn $2 }
  | TURNRIGHT expr
      { Printf.printf "Matched stmt: TURNRIGHT %s\n%!" (Ast.string_of_expr $2); Sturnright $2 }
  | COLOR color
      { Printf.printf "Matched stmt: COLOR\n%!"; Scolor $2 }
  | IDENT LPAREN exprs RPAREN
      { Printf.printf "Parser matched function call: %s with args %s\n%!" $1 (String.concat ", " (List.map Ast.string_of_expr $3)); 
        Scall ($1, $3) }
  | IF expr stmt_block ELSE stmt_block
      { Printf.printf "Parser matched: IF %s THEN ... ELSE ...\n%!" (Ast.string_of_expr $2); Sif ($2, $3, $5) }
  | IF expr stmt_block
      { Printf.printf "Parser matched: IF %s THEN ...\n%!" (Ast.string_of_expr $2); Sif ($2, $3, Sblock []) }
;
color:
  BLACK { Turtle.black }
| WHITE { Turtle.white }
| RED { Turtle.red }
| GREEN { Turtle.green }
| BLUE { Turtle.blue }
;


exprs:
  | { [] }
  | expr { [$1] }
  | exprs COMMA expr { $1 @ [$3] }
;

expr:
  | INT { Printf.printf "Parser matched expr: INT(%d)\n%!" $1; Econst $1 }
  | LPAREN expr RPAREN { $2 }
  | IDENT { Evar $1 }
  | expr PLUS expr { Ebinop (Add, $1, $3) }
  | expr MINUS expr { Ebinop (Sub, $1, $3) }
  | expr TIMES expr { Ebinop (Mul, $1, $3) }
  | expr DIV expr { Ebinop (Div, $1, $3) }
  | MINUS expr %prec NEG { Ebinop (Sub, Econst 0, $2) }
;


