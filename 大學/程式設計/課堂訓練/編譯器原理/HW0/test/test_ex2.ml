open OUnit2

let test_fibo _ =
  assert_equal 0 ( Ex2.fibo 0 ) ~msg: "fibo 0 should be 0";
  assert_equal 1 ( Ex2.fibo 1 ) ~msg: "fibo 1 should be 1";
  assert_equal 1 ( Ex2.fibo 2 ) ~msg: "fibo 2 should be 1";
  assert_equal 2 ( Ex2.fibo 3 ) ~msg: "fibo 3 should be 2";
  assert_equal 3 ( Ex2.fibo 4 ) ~msg: "fibo 4 should be 3";
  assert_equal 5 ( Ex2.fibo 5 ) ~msg: "fibo 5 should be 5";
  assert_equal 8 ( Ex2.fibo 6 ) ~msg: "fibo 6 should be 8"

let suite =
  "Test Fibonacci" >::: [
    "test_fibo" >:: test_fibo;
  ]

let () =
  run_test_tt_main suite
