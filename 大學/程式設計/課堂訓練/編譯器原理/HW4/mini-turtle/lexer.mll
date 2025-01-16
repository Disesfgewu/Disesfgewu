{
  open Lexing
  open Parser

  (* raise exception to report a lexical error *)
  exception Lexing_error of string

  (* Debug function to print current token *)
  let debug_token t =
    Printf.printf "Matched token: %s\n%!" t
}

rule token = parse
  | '\n' { Lexing.new_line lexbuf; token lexbuf }
  | ['0'-'9']+ as n { debug_token (Printf.sprintf "INT(%s)" n); INT (int_of_string n) }
  | "forward" { debug_token "FORWARD"; FORWARD }
  | "turnleft" { debug_token "TURNLEFT"; TURNLEFT }
  | "color" { debug_token "COLOR"; COLOR }
  | "turnright" { debug_token "TURNRIGHT"; TURNRIGHT }
  | "def" { Printf.printf "Lexer matched: DEF\n%!"; DEF }
  | "if" { Printf.printf "Lexer matched: IF\n%!"; IF }
  | "else" { Printf.printf "Lexer matched: ELSE\n%!"; ELSE }
  | "//" { debug_token "LINE_COMMENT"; skip_line lexbuf }
  | "(*" { debug_token "BLOCK_COMMENT"; skip_comment lexbuf }
  | eof { debug_token "EOF"; EOF }
  (* 關鍵字 *)
  | "penup" { debug_token "PENUP"; PENUP }
  | "pendown" { debug_token "PENDOWN"; PENDOWN }
  | "turnleft" { debug_token "TURNLEFT"; TURNLEFT }
  | "turnright" { debug_token "TURNRIGHT"; TURNRIGHT }
  | "repeat" { debug_token "REPEAT"; REPEAT }
  | "color" { debug_token "COLOR"; COLOR }
  | "black" { debug_token "BLACK"; BLACK }
  | "white" { debug_token "WHITE"; WHITE }
  | "red" { debug_token "RED"; RED }
  | "green" { debug_token "GREEN"; GREEN }
  | "blue" { debug_token "BLUE"; BLUE }

  (* 數字 *)

  (* 標識符 *)
  | ['a'-'z' 'A'-'Z']['a'-'z' 'A'-'Z' '0'-'9' '_']* as id { debug_token (Printf.sprintf "IDENT(%s)" id); IDENT id }

  (* 運算符和括號 *)
  | "+" { debug_token "PLUS"; PLUS }
  | "-" { debug_token "MINUS"; MINUS }
  | "*" { debug_token "TIMES"; TIMES }
  | "/" { debug_token "DIV"; DIV }
  | "(" { debug_token "LPAREN"; LPAREN }
  | ")" { debug_token "RPAREN"; RPAREN }
  | "{" { debug_token "LBRACE"; LBRACE }
  | "}" { debug_token "RBRACE"; RBRACE }
  | "," { debug_token "COMMA"; COMMA }

  (* 未知字符 *)
  | [' ' '\t'] { debug_token "space"; token lexbuf }
  | _ as c { raise (Lexing_error (Printf.sprintf "Unexpected character: %c" c)) }

and skip_line = parse
  | '\n' { Lexing.new_line lexbuf; token lexbuf }
  | eof { EOF }
  | _ { skip_line lexbuf }

and skip_comment = parse
  | "*)" { token lexbuf }
  | '\n' { Lexing.new_line lexbuf; skip_comment lexbuf }
  | eof { raise (Lexing_error "Unclosed comment") }
  | _ { skip_comment lexbuf }
