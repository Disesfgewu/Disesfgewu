type 'a seq =
  | Elt of 'a               
  | Seq of 'a seq * 'a seq  


let (@@) x y = Seq( x , y )

(* hd *)
let rec hd = function
  | Elt x -> x 
  | Seq( left , _ ) -> hd left

(* tl *)
let rec tl = function
  | Elt _ -> failwith "Empty"
  | Seq( Elt _ , right ) -> right
  | Seq( left , right ) -> Seq( tl left , right )

(* mem *)
let rec mem x = function
  | Elt y -> x = y 
  | Seq( left , right ) -> mem x left || mem x right

(* rev *)
let rec rev = function
  | Elt x -> 
    Printf.printf "%d\n" x;
    Elt x  
  | Seq( left , right ) -> Seq( rev right , rev left )

(* map *)
let rec map f = function
  | Elt x -> Elt( f x )
  | Seq( left , right ) -> Seq( map f left , map f right )

(* fold_left *)
let rec fold_left f acc = function 
  | Elt x -> f acc x
  | Seq( left , right ) -> fold_left f ( fold_left f acc left ) right 

(* fold_right *)
let rec fold_right f seq acc = 
  match seq with
  | Elt x -> f x acc
  | Seq( left , right ) -> fold_right f left ( fold_right f right acc )
  
(* seq2list *)
let seq2list s =
  let rec aux s acc = match s with
    | Elt x -> x :: acc
    | Seq (l, r) -> aux l (aux r acc)
  in
  aux s []

(* find_opt *)
let rec find_opt x seq =
  let rec aux i = function
    | Elt target -> if x = target then Some i else None
    | Seq( left , right ) -> 
        match aux i left with
        | Some id -> Some id
        | None -> aux ( i + List.length( seq2list left ) ) right 
  in
  aux 0 seq

(* nth *)
let rec nth seq n =
  let rec aux i = function
   | Elt x -> if i = n then x else failwith "Index out of bound"
   | Seq( left , right ) ->
      let index = List.length( seq2list left ) in
      if n < i+index then
        aux i left
      else
        aux (i+index) right
  in
  aux 0 seq