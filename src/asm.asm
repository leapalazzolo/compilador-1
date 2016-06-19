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
_cte_4.5000 DD ?

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_4
fstp _a
fld _cte_4.5000
fstp _d
fld "hola"
fstp _r

mov AX, 4C00h
end;