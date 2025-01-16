(* a *)

let rec factorial n =
  if n < 0 then failwith "negative input"
  else if n = 0 then 1
  else n * factorial (n - 1)

  
(* b *)
let rec nb_bit_pos n =
  if n = 0 then 0
  else (n land 1) + nb_bit_pos (n lsr 1)