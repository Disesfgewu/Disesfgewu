echo "Compile Ex3"

as -o ex3.o ex3.s
gcc -o ex3 ex3.o -lc

./ex3