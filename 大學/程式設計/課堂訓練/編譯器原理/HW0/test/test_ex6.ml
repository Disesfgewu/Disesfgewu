open OUnit2

let rev_test _ =
  assert_equal [ 3; 2; 1 ] ( Ex6.rev [ 1; 2; 3 ] );
  assert_equal [] ( Ex6.rev [] );
  assert_equal [ "c"; "b"; "a" ] ( Ex6.rev [ "a"; "b"; "c" ] );
  assert_equal [ 1 ] ( Ex6.rev [ 1 ] )

let map_test _ =
  let square x = x * x in
  assert_equal [ 1; 4; 9 ] ( Ex6.map square [ 1; 2; 3 ] );
  assert_equal [] ( Ex6.map square [] );
  assert_equal [ 0; 1; 4; 9 ] ( Ex6.map square [ 0; 1; 2; 3 ] );
  assert_equal [ 1 ] ( Ex6.map square [ 1 ] )

let suite =
  "Test Suite" >:::
  [
    "test_rev" >:: rev_test;
    "test_map" >:: map_test;
  ]

let () =
  run_test_tt_main suite
