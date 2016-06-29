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

_IGUALES dd 0

_FILTER dd 0
_d db ?

_c dd 0

_b dd 0

_a dd 0

.code
main:
mov AX,@DATA ;
mov DS,AX ;
finit ;

mov dx, OFFSET read
mov ah, 9
int 21h
newLine 1
GetFloat _a
newLine 1
DisplayFloat _a 2
newLine 1

mov AX, 4C00h
end main