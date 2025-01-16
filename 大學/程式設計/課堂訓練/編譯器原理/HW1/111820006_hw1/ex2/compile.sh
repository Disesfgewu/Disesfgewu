echo "Compile Ex2"

as -o ex2.o ex2.s
gcc -o ex2 ex2.o -lc

./ex2