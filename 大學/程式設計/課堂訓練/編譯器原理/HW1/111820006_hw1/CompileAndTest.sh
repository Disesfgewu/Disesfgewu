#!/bin/bash

for ((i=1; i<=7; i++))
do
    cd "ex${i}" 
    ./compile.sh
    echo ""
    cd ..
done
