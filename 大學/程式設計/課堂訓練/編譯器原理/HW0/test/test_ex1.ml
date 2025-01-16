open OUnit2

let test_factorial _ =
  assert_equal ( Ex1.factorial 0 ) 1;
  assert_equal ( Ex1.factorial 1 ) 1;
  assert_equal ( Ex1.factorial 5 ) 120;
  assert_equal ( Ex1.factorial 6 ) 720;
  assert_raises ( Failure "negative input" ) ( fun () -> Ex1.factorial ( -1 ) )

let test_nb_bit_pos _ =
  assert_equal ( Ex1.nb_bit_pos 0 ) 0;
  assert_equal ( Ex1.nb_bit_pos 1 ) 1;
  assert_equal ( Ex1.nb_bit_pos 2 ) 1;
  assert_equal ( Ex1.nb_bit_pos 3 ) 2;
  assert_equal ( Ex1.nb_bit_pos 255 ) 8

let suite =
  "Test Suite for factorial and nb_bit_pos" >::: [
    "test_factorial" >:: test_factorial;
    "test_nb_bit_pos" >:: test_nb_bit_pos;
  ]

let () =
  run_test_tt_main suite
