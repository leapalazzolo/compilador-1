#!/bin/bash

flex lex.l
bison -dyv syntax.y
gcc lex.yy.c y.tab.c arbol.c -o compiler
rm lex.yy.c
rm y.tab.c
rm y.output
rm y.tab.h