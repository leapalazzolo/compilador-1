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
_d dd ?
_c dd ?
_b dd ?
_a dd ?
_cte_4 dd 4.000000

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld 4
fstp _a

mov AX, 4C00h
end;