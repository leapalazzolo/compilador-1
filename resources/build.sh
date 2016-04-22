#!/bin/bash

flex ../src/lex.l
bison -dyv ../src/sintax.y
gcc ../src/lex.yy.c ../src/y.tab.c -o compiler