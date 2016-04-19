flex lex.l

bison -dyv sintax.y

gcc.exe lex.yy.c y.tab.c -o final.exe