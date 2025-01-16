echo "Compile Ex5"

as -o ex5.o ex5.s
gcc -o ex5 ex5.o -lc

./ex5