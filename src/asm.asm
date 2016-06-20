;TITLE TP Compilador 2016
.model small
.386
.stack 100h

.data
message db	'-- EOF --', '$'
overflow db	'Overflow!', '$'
diviz db	'Division by 0!', '$'
read db	'Ingrese valor por teclado...', '$'
MAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.
MAX_STRING_INT equ 65535 ;Tama�o maximo de ints.
aux1 dd ?
aux2 dd ?
cont dd 0.000000
filt dd 0.000000

_IGUALES dd ?

_FILTER dd ?
_d db ?

_c dd ?

_b dd ?

_a dd ?
_cte_5 dd 5.000000
_cte_3 dd 3.000000
_cte_8 dd 8.000000
_cte_2 dd 2.000000

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_5
fstp _a
fld _cte_3
fstp _b
fld _cte_8
fstp _c
fld _b
fstp aux1
fld _a
fstp aux2
fld aux2
fld aux1
fcomp
jne else_if1
fld _cte_3
fld _a
fadd
fstp aux1
jmp end_if1
else_if1:
fld _cte_2
fld _c
fdiv
fstp aux1
fld _cte_3
fld aux1
fmul
fstp aux1
fld aux1
fstp _b
end_if1:

mov AX, 4C00h
end;