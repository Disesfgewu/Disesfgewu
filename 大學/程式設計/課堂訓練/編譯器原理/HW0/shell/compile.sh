cd ../src

ocamlfind ocamlc -o ../out/test_ex1 -package ounit2 -linkpkg ../src/Ex1.ml ../test/test_ex1.ml
ocamlfind ocamlc -o ../out/test_ex2 -package ounit2 -linkpkg ../src/Ex2.ml ../test/test_ex2.ml
ocamlfind ocamlc -I +str -o ../out/test_ex3 -package str,ounit2 -linkpkg ../src/Ex3.ml ../test/test_ex3.ml
ocamlfind ocamlc -o ../out/test_ex4 -package ounit2 -linkpkg ../src/Ex4.ml ../test/test_ex4.ml
ocamlfind ocamlc -o ../out/test_ex5 -package ounit2 -linkpkg ../src/Ex5.ml ../test/test_ex5.ml
ocamlfind ocamlc -o ../out/test_ex6 -package ounit2 -linkpkg ../src/Ex6.ml ../test/test_ex6.ml
ocamlfind ocamlc -o ../out/test_ex7 -package ounit2 -linkpkg ../src/Ex7.ml ../test/test_ex7.ml

echo "Unit Test"

echo "Ex1"
../out/test_ex1

echo "Ex2"
../out/test_ex2

echo "Ex3"
../out/test_ex3

echo "Ex4"
../out/test_ex4

echo "Ex5"
../out/test_ex5

echo "Ex6"
../out/test_ex6

echo "Ex7"
../out/test_ex7



echo "End for test" 
rm -f *.log
rm -f *.cache