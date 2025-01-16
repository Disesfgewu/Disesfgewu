echo "Compile Ex4"

as -o ex4.o ex4.s
gcc -o ex4 ex4.o -lc

./ex4