let rev lst =
  let rec aux acc = function
    | [] -> acc
    | h :: t -> aux (h :: acc) t
  in
  aux [] lst
let map f lst =
  let rec aux acc = function
    | [] -> rev acc
    | h :: t -> aux (f h :: acc) t
  in
  aux [] lst