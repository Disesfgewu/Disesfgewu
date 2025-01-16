echo "Compile Ex6"

as -o ex6.o ex6.s
gcc -o ex6 ex6.o -lc

./ex6