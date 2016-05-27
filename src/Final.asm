TITLE TP Compilador 2016
.MODEL	small
.386
.STACK	300h

.DATA
message db	'-- EOF --', '$'
overflow db	'Overflow!', '$'
diviz db	'Division by 0!', '$'
MAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.
MAX_STRING_INT equ 65535 ;Tamaño maximo de ints.
AUX1 DD ?
AUX2 DD ?
AUX3 DD ?
AUX4 DD ?
AUX5 DD ?
OldCW DW ?
NewCW DW ?

.CODE