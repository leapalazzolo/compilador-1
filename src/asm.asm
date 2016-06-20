;TITLE TP Compilador 2016
.model small
.386
.stack 300h

.data
message db	'-- EOF --', '$'
overflow db	'Overflow!', '$'
diviz db	'Division by 0!', '$'
MAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.
MAX_STRING_INT equ 65535 ;Tama�o maximo de ints.
aux1 DD ?
aux2 DD ?
_IGUALES dd ?
_FILTER dd ?
_r dd ?
_d DD ?
_c dd ?
_b dd ?
_a dd ?
_cte_4 dd ?
_cte_3 dd ?
_cte_2 dd ?
_cte_5 dd ?

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_4
fstp _a
fld _cte_2
fld _b
fdiv
fstp aux1
fld _cte_3
fld _a
fadd
fstp aux2
fld aux2
fld aux1
fcomp
jne end_if1
fld _cte_5
fstp _b
fld _cte_3
fstp _a
end_if1:

mov AX, 4C00h
end;