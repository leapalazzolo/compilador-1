;TITLE TP Compilador 2016
include macros2.asm      ;incluye macros

include number.asm       ;incluye el asm para impresion de numeros

.model small
.386
.stack 200h

.data
message db  '-- EOF --', '$'
overflow db 'Overflow!', '$'
diviz db    'Division by 0!', '$'
read db 'Ingrese valor por teclado...', '$'
MAX_STRING_LENGTH equ 30 ;Longitud maxima de los string.
MAX_STRING_INT equ 65535 ;Tama?o maximo de ints.
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
_cte_1 dd 1.000000
_cte_8 dd 8.000000
_cte_2 dd 2.000000
_cte_7 dd 7.000000

.code
main:
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_1
fstp _a
fld _cte_8
fstp _c
fld _cte_2
fld _a
fadd
fstp aux1
fld aux1
fstp _b
fld _cte_8
fstp aux1
fld _c
fstp aux2
fld aux2
fld aux1
fcomp
fstsw ax
sahf
ffree st(0)
jb end_if1
fld _cte_1
fld _a
fadd
fstp aux1
fld aux1
fstp _a
end_if1:
DisplayFloat _a 2
newLine 1

mov AX, 4C00h
end main