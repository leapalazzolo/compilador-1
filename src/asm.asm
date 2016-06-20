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
_cte_2 dd 2.000000
_cte_5 dd 5.000000
_cte_1 dd 1.000000
_cte_3 dd 3.000000

.code
mov AX,@DATA ;
mov DS,AX ;
finit ;

fld _cte_2
fstp _a
fld aux2
fld aux1
fcomp
jge end_while1
while1:
fld _cte_1
fld _a
fadd
fstp aux1
fld aux1
fstp _a
fld aux2
fld aux1
fcomp
jl while1
end_while1:
fld _cte_2
fld _cte_3
fadd
fstp aux1
fld aux1
fstp _b

mov AX, 4C00h
end;