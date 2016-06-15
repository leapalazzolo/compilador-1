;TITLE TP Compilador 2016
.MODEL	small
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
_IGUALES DD ?
_FILTER DD ?
_r DD ?
_d DD ?
_c DD ?
_b DD ?
_a DD ?

.code
MOV AX,@DATA ;
MOV DS,AX ;
FINIT ;

fld 1
fstp _a
fld 2
fstp _a
fld 3
fstp _a
fld aux2
fld aux1
fcomp
jne end_if1
fld 4
fstp _a
end_if1
fld 6
fstp _a

MOV AX, 4C00h
end;