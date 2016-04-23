flex ../../src/lex.l

bison -dyv ../../src/sintax.y

gcc.exe lex.yy.c y.tab.c -o final.exe