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
aux1 dd ?
aux2 dd ?

_IGUALES dd ?

_FILTER dd ?
_d db ?

_c dd ?

_b dd ?

_a dd ?

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;


mov AX, 4C00h
end;