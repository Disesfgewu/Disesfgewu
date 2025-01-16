open OUnit2

let test_split _ =
  assert_equal ( Ex4.split [] ) ( [] , [] );
  assert_equal ( Ex4.split [1]) ( [1] , [] );
  assert_equal ( Ex4.split [1; 2] ) ( [1] , [2] );
  assert_equal ( Ex4.split [1; 2; 3; 4] ) ( [1; 3] , [2; 4] );
  assert_equal ( Ex4.split [1; 2; 3; 4; 5] ) ( [1; 3; 5] , [2; 4] )

let test_merge _ =
  assert_equal ( Ex4.merge [] [] ) [];
  assert_equal ( Ex4.merge [1; 3; 5] [] ) [1; 3; 5];
  assert_equal ( Ex4.merge [] [2; 4; 6] ) [2; 4; 6];
  assert_equal ( Ex4.merge [1; 3; 5] [2; 4; 6] ) [1; 2; 3; 4; 5; 6];
  assert_equal ( Ex4.merge [1; 4] [2; 3] ) [1; 2; 3; 4]

let test_sort _ =
  assert_equal ( Ex4.sort [] ) [];
  assert_equal ( Ex4.sort [1] ) [1];
  assert_equal ( Ex4.sort [2; 1] ) [1; 2];
  assert_equal ( Ex4.sort [3; 2; 1] ) [1; 2; 3];
  assert_equal ( Ex4.sort [5; 3; 4; 1; 2] ) [1; 2; 3; 4; 5];
  assert_equal ( Ex4.sort [1; 2; 3; 4; 5] ) [1; 2; 3; 4; 5]

let suite =
  "Test Sorting Functions" >::: [
    "test_split" >:: test_split;
    "test_merge" >:: test_merge;
    "test_sort" >:: test_sort;
  ]

let () = 
  run_test_tt_main suite
