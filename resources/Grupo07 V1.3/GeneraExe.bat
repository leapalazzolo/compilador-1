D:\GnuWin32\bin\flex Lexico.l
pause
D:\GnuWin32\bin\bison -dyv Sintactico.y
pause
D:\MinGW\bin\gcc.exe lex.yy.c y.tab.c -o Final.exe
pause
pause
Final.exe pruebal.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del Final.exe
pause