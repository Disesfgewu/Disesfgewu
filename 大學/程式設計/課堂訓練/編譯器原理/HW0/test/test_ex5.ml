open OUnit2

let square_sum_test _ =
  assert_equal 14 ( Ex5.square_sum [ 1; 2; 3 ] );
  assert_equal 0 ( Ex5.square_sum [] );
  assert_equal 1 ( Ex5.square_sum [ 1 ] );
  assert_equal 9 ( Ex5.square_sum [ 1; -2; 2 ] )

let find_opt_test _ =
  assert_equal ( Some 2 ) ( Ex5.find_opt 3 [ 1; 2; 3; 4 ] );
  assert_equal ( Some 0 ) ( Ex5.find_opt 1 [ 1; 2; 3 ] );
  assert_equal None ( Ex5.find_opt 5 [ 1; 2; 3 ] );
  assert_equal None ( Ex5.find_opt 1 [] )

let suite =
  "Test Suite" >:::
  [
    "test_square_sum" >:: square_sum_test;
    "test_find_opt" >:: find_opt_test;
  ]

let () =
  run_test_tt_main suite
