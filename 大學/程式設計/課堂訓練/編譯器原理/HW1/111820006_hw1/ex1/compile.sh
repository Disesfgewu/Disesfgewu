echo "Ex1"

as -o ex1.o ex1.s
gcc -o ex1 ex1.o -lc

./ex1