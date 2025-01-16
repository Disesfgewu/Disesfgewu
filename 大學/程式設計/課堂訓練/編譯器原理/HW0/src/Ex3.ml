open Str;;

(* a *)

let palindrome m =
  let endval = String.length m in
  let is_palindrome = ref true in  
  for i = 0 to (endval / 2) - 1 do  
    if m.[i] <> m.[endval - 1 - i] then
      is_palindrome := false  
    done;
  !is_palindrome


(* b *)

let compare m1 m2 = 
  String.compare m1 m2 < 0

(* c *)

let factor m1 m2 = 
  try
    let re = Str.regexp_string m1 in
    Str.search_forward re m2 0 >= 0 
  with Not_found -> false