
(* Abstract syntax for mini-Turtle

   Note : The abstract syntax below intentionally contains fewer
   constructions than the concrete syntax. It will therefore be
   necessary to translate certain constructions at the time of
   syntactic analysis (sugar)

*)

(* integer expressions *)

type binop = Add | Sub | Mul | Div

type expr =
  | Econst of int
  | Evar   of string
  | Ebinop of binop * expr * expr

(* instructions *)

type stmt =
  | Spenup
  | Spendown
  | Sforward of expr
  | Sturn    of expr (* turn left *)
  | Sturnright of expr
  | Scolor   of Turtle.color
  | Sif      of expr * stmt * stmt
  | Srepeat  of expr * stmt
  | Sblock   of stmt list
  | Scall    of string * expr list

(* definition of procedure *)

type def = {
  name    : string;
  formals : string list; (* arguments *)
  body    : stmt; }

(* program *)

type program = {
  defs : def list;
  main : stmt; }

let rec string_of_expr = function
| Econst n -> string_of_int n
| Evar v -> v
| Ebinop (Add, e1, e2) -> Printf.sprintf "(%s + %s)" (string_of_expr e1) (string_of_expr e2)
| Ebinop (Sub, e1, e2) -> Printf.sprintf "(%s - %s)" (string_of_expr e1) (string_of_expr e2)
| Ebinop (Mul, e1, e2) -> Printf.sprintf "(%s * %s)" (string_of_expr e1) (string_of_expr e2)
| Ebinop (Div, e1, e2) -> Printf.sprintf "(%s / %s)" (string_of_expr e1) (string_of_expr e2)


