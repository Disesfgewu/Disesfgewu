(* a *)

let rec split l = 
  match l with
  | [] -> ( [] , [] )
  | [x] -> ( [x] , [] )
  | h :: h2 :: t ->
    let ( l1 , l2 ) = split t in
    ( h :: l1 , h2 :: l2 )

(* b *)

let rec merge l1 l2 = 
  match ( l1 , l2 ) with
  | ( [] , l2 ) -> l2
  | ( l1 , [] ) -> l1
  | ( h1 :: t1 , h2 :: t2 ) -> 
    if h1 <= h2 then
      h1 :: merge t1 l2
    else
      h2 :: merge l1 t2

(* c *)

let rec sort l =
  match l with
  | [] -> []
  | [x] -> [x]
  | _ -> 
    let ( l1 , l2 ) = split l in 
    merge ( sort l1 ) ( sort l2 )