flex lex.l

bison -dyv syntax.y

gcc.exe lex.yy.c y.tab.c arbol.c -o final.exe