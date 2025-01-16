type buffer = { text: string; mutable current: int; mutable last: int }
let next_char b =
  if b.current = String.length b.text then raise End_of_file;
  let c = b.text.[b.current] in
  b.current <- b.current + 1;
  c

let rec state1 b =
  try
    match next_char b with
    | _ -> failwith "Failure(\"lexical error\")"
  with End_of_file -> failwith "End_of_file"
and state2 b =
  try
    b.last <- b.current;
    match next_char b with
    | '#' -> 
        b.last <- b.current;
        state1 b
    | _ -> ()
  with End_of_file -> ()
and state3 b =
  try
    match next_char b with
    | 'a' -> 
        b.last <- b.current;
        state3 b
    | 'b' -> 
        b.last <- b.current;
        state2 b
    | _ -> failwith "Failure(\"lexical error\")"
  with End_of_file -> failwith "End_of_file"
let start = state3
