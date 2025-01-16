open OUnit2
open Str

let palindrome_test _ =
  assert_equal true ( Ex3.palindrome "level" );
  assert_equal true ( Ex3.palindrome "madam" );
  assert_equal false ( Ex3.palindrome "hello" )

let compare_test _ =
  assert_equal true ( Ex3.compare "apple" "banana" );
  assert_equal false ( Ex3.compare "banana" "apple" );
  assert_equal false ( Ex3.compare "apple" "apple" )

let factor_test _ =
  assert_equal true ( Ex3.factor "hello" "hello world" );
  assert_equal false ( Ex3.factor "foo" "bar" );
  assert_equal true ( Ex3.factor "bar" "barfoo" )

let suite =
  "Test Suite" >:::
  [
    "test_palindrome" >:: palindrome_test;
    "test_compare" >:: compare_test;
    "test_factor" >:: factor_test; 
  ]

let () =
  run_test_tt_main suite
