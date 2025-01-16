type ichar = char * int

type regexp =
| Epsilon
| Character of ichar
| Union of regexp * regexp
| Concat of regexp * regexp
| Star of regexp

let rec null r = match r with
  | Epsilon -> true
  | Character _ -> false
  | Union (r1, r2) -> null r1 || null r2
  | Concat (r1, r2) -> null r1 && null r2
  | Star _ -> true

module Cset = Set.Make(struct 
  type t = ichar 
  let compare = Stdlib.compare 
end)

let rec first = function
  | Epsilon -> Cset.empty
  | Character c -> Cset.singleton c
  | Union (r1, r2) -> Cset.union (first r1) (first r2)
  | Concat (r1, r2) -> if null r1 then Cset.union (first r1) (first r2) else first r1
  | Star r -> first r

let rec last = function
| Epsilon -> Cset.empty
| Character c -> Cset.singleton c
| Union (r1, r2) -> Cset.union (last r1) (last r2)
| Concat (r1, r2) -> if null r2 then Cset.union (last r1) (last r2) else last r2
| Star r -> last r

let rec follow c r =
  match r with
  | Epsilon | Character _ -> Cset.empty
  | Union (r1, r2) -> Cset.union (follow c r1) (follow c r2)
  | Concat (r1, r2) ->
      let follow_in_r2 = if Cset.mem c (last r1) then first r2 else Cset.empty in
      Cset.union follow_in_r2 (Cset.union (follow c r1) (follow c r2))
  | Star r1 ->
      let follow_in_star = if Cset.mem c (last r1) then first r1 else Cset.empty in
      Cset.union follow_in_star (follow c r1)

type state = Cset.t
module Cmap = Map.Make(Char)
module Smap = Map.Make(Cset)

type autom = {
  start : state;
  trans : state Cmap.t Smap.t;
}

let eof = ('#', -1)

let next_state (r: regexp) (q: state) (c: char) : state =
  Cset.fold (fun ci acc ->
    if fst ci = c then
      Cset.union acc (follow ci r)
    else acc
  ) q Cset.empty

let make_dfa r =
  let r = Concat (r, Character eof) in
  let trans = ref Smap.empty in
  let rec transitions q =
    if not (Smap.mem q !trans ) then begin
      let cmap = Cset.fold (fun (c, _) cmap ->
        let q_next = next_state r q c in
        if not (Cset.is_empty q_next ) || c = '#'  then 
          Cmap.add c q_next cmap else cmap
      ) q Cmap.empty in
      trans := Smap.add q cmap !trans;
      Cmap.iter (fun _ q_next-> transitions q_next) cmap
    end
  in
  let q0 = first r in
  transitions q0;
  { start = q0; trans = !trans }

let fprint_state fmt q =
  Cset.iter (fun (c,i) ->
    if c = '#' then Format.fprintf fmt "# " 
    else Format.fprintf fmt "%c%i " c i) q

let fprint_transition fmt q c q' =
  Format.fprintf fmt "\"%a\" -> \"%a\" [label=\"%c\"];@\n"
    fprint_state q
    fprint_state q'
    c

let fprint_autom fmt a =
  Format.fprintf fmt "digraph A {@\n";
  Format.fprintf fmt " \"%a\" [ shape = \"rect\"];@\n" fprint_state a.start;
  Smap.iter
    (fun q t -> Cmap.iter (fun c q' -> fprint_transition fmt q c q') t)
    a.trans;
  Format.fprintf fmt "@]@\n}@."

let save_autom file a =
  let ch = open_out file in
  Format.fprintf (Format.formatter_of_out_channel ch) "%a" fprint_autom a;
  close_out ch

let r = Concat (Star (Union (Character ('a', 1), Character ('b', 1))),
                Concat (Character ('a', 2),
                        Union (Character ('a', 3), Character ('b', 2))))
let a = make_dfa r
let () = save_autom "autom.dot" a

let recognize (autom : autom) (word : string) : bool =
  let rec aux current_state idx =
    if idx = String.length word then
      Cset.mem eof current_state
    else
      let c = word.[idx] in
      let next_state = 
        try 
          Cmap.find c (Smap.find current_state autom.trans)
        with Not_found -> Cset.empty
      in
      aux next_state (idx + 1)
  in
  aux autom.start 0

let () = assert (recognize a "aa")
let () = assert (recognize a "ab")
let () = assert (recognize a "abababaab")
let () = assert (recognize a "babababab")
let () = assert (recognize a (String.make 1000 'b' ^ "ab"))

let () = assert (not (recognize a ""))
let () = assert (not (recognize a "a"))
let () = assert (not (recognize a "b"))
let () = assert (not (recognize a "ba"))
let () = assert (not (recognize a "aba"))
let () = assert (not (recognize a "abababaaba"))

let r = Star (Union (Star (Character ('a', 1)),
            Concat (Character ('b', 1),
                Concat (Star (Character ('a',2)),
                    Character ('b', 2)))))
let a = make_dfa r
let () = save_autom "autom2.dot" a

let () = assert (recognize a "")
let () = assert (recognize a "bb")
let () = assert (recognize a "aaa")
let () = assert (recognize a "aaabbaaababaaa")
let () = assert (recognize a "bbbbbbbbbbbbbb")
let () = assert (recognize a "bbbbabbbbabbbabbb")

let () = assert (not (recognize a "b"))
let () = assert (not (recognize a "ba"))
let () = assert (not (recognize a "ab"))
let () = assert (not (recognize a "aaabbaaaaabaaa"))
let () = assert (not (recognize a "bbbbbbbbbbbbb"))
let () = assert (not (recognize a "bbbbabbbbabbbabbbb"))


let generate filename autom =
  let ch = open_out filename in
  let fmt = Format.formatter_of_out_channel ch in

  Format.fprintf fmt "type buffer = { text: string; mutable current: int; mutable last: int }@\n";
  Format.fprintf fmt "let next_char b =@\n";
  Format.fprintf fmt "  if b.current = String.length b.text then raise End_of_file;@\n";
  Format.fprintf fmt "  let c = b.text.[b.current] in@\n";
  Format.fprintf fmt "  b.current <- b.current + 1;@\n";
  Format.fprintf fmt "  c@\n@\n";
  
  let state_map = ref Smap.empty in
  let _ = Smap.fold (fun s _ acc -> 
    state_map := Smap.add s acc !state_map; 
    acc + 1
  ) autom.trans 1 in

  Smap.iter (fun q trans ->
    let state_id = Smap.find q !state_map in
    if state_id = 1 then
      Format.fprintf fmt "let rec state%d b =@\n" state_id
    else
      Format.fprintf fmt "and state%d b =@\n" state_id;
  
    Format.fprintf fmt "  try@\n";

    if Cset.mem eof q then
      Format.fprintf fmt "    b.last <- b.current;@\n";
    
    Format.fprintf fmt "    match next_char b with@\n";

    Cmap.iter (fun c next_state ->
      try
        let next_num = Smap.find next_state !state_map in
        Format.fprintf fmt "    | '%c' -> @\n" c;
        Format.fprintf fmt "        b.last <- b.current;@\n";
        Format.fprintf fmt "        state%i b@\n" next_num;
      with Not_found -> ()
    ) trans;
  
    if Cset.mem eof q then begin
      Format.fprintf fmt "    | _ -> ()@\n";
      Format.fprintf fmt "  with End_of_file -> ()@\n";
    end
    else begin
      Format.fprintf fmt "    | _ -> failwith \"Failure(\\\"lexical error\\\")\"@\n";
      Format.fprintf fmt "  with End_of_file -> failwith \"End_of_file\"@\n";
    end
  ) autom.trans;
  
  let start_state = Smap.find autom.start !state_map in
  Format.fprintf fmt "let start = state%i@\n" start_state;
  close_out ch

let r3 = Concat (Star (Character ('a', 1)), Character ('b', 1))
let a = make_dfa r3
let () = generate "a.ml" a
