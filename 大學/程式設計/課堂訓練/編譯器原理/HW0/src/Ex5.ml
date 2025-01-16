(* a *)
let square_sum l = 
  List.fold_left ( fun sum i -> sum + i * i ) 0 l 

(* b *)
let find_opt x l =
  let includeIndexList = List.mapi ( fun i e -> ( i , e ) ) l in 
  match List.find_opt ( fun ( _ , e ) -> e = x ) includeIndexList with
  | Some ( i , _ ) -> Some i 
  | None -> None