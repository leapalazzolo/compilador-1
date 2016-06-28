;TITLE TP Compilador 2016
include macros2.asm		 ;incluye macros

include number.asm		 ;incluye el asm para impresion de numeros

.model small
.386
.stack 200h

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

.code
main:
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_5
fstp _a
fld _cte_3
fstp _b
fld _cte_8
fstp _c
DisplayInteger _a

mov AX, 4C00h
end main