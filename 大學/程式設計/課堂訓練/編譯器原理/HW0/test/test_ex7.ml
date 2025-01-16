open OUnit2
open Ex7

let test_hd _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal 1 (Ex7.hd s)

let test_tl _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal (Ex7.Elt 2 @@ Ex7.Elt 3) (Ex7.tl s)

let test_mem _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal true (Ex7.mem 2 s);
  assert_equal false (Ex7.mem 4 s)

let test_rev _ =
  let s = Ex7.Seq( Ex7.Seq( Ex7.Elt 1 , Ex7.Elt 2 ), Ex7.Elt 3 ) in
  assert_equal ( Ex7.Seq( Ex7.Elt 3 , Ex7.Seq( Ex7.Elt 2 , Ex7.Elt 1 ))) (Ex7.rev s)

let test_map _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal (Ex7.Elt 2 @@ Ex7.Elt 3 @@ Ex7.Elt 4) (Ex7.map ((+) 1) s)

let test_find_opt _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal (Some 1) (Ex7.find_opt 2 s);
  assert_equal None (Ex7.find_opt 4 s)

let test_nth _ =
  let s = Ex7.Elt 1 @@ Ex7.Elt 2 @@ Ex7.Elt 3 in
  assert_equal 2 (Ex7.nth s 1);
  assert_raises (Failure "Index out of bound") (fun () -> Ex7.nth s 3)

let suite =
  "Test Suite" >:::
  [
    "test_hd" >:: test_hd;
    "test_tl" >:: test_tl;
    "test_mem" >:: test_mem;
    "test_rev" >:: test_rev;
    "test_map" >:: test_map;
    "test_find_opt" >:: test_find_opt;
    "test_nth" >:: test_nth;
  ]

let () =
  run_test_tt_main suite
