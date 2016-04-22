flex ../../src/lex.l

bison -dyv ../../src/sintax.y

gcc.exe ../../src/lex.yy.c ../../src/y.tab.c -o final.exe