INCLUDE macro.asm
INCLUDE number.asm
.MODEL LARGE
.386
.STACK 500h

.CODE
START:

	MOV AX,@DATA	;inicializa el segmento de datos
	MOV DS,AX
	FNINIT 

	;REALIZAMOS LA OPERACION FADD
	FLD _1
	FLD _8
	FADD
	FSTP _@aux0

	;REALIZAMOS LA ASIGNACION
	FLD _@aux0
	FSTP _a

	;REALIZAMOS LA ASIGNACION
	FLD _&F3_16
	FSTP _b

	;REALIZAMOS LA ASIGNACION
	FLD _&01_2
	FSTP _c

	;REALIZAMOS LA CONCATENACION
	MOV AX,@DATA
	MOV ES,AX
	MOV SI,OFFSET _HOLA
	MOV DI,OFFSET _@aux1
	STRCPY

	MOV AX,@DATA
	MOV ES,AX
	MOV SI,OFFSET _Hola2
	MOV DI,OFFSET _@aux1
	STRCAT

	;REALIZAMOS LA ASIGNACION
	MOV AX,@DATA
	MOV ES,AX
	MOV SI,OFFSET _@aux1
	MOV DI,OFFSET _d
	STRCPY

	;REALIZAMOS LA ASIGNACION
	FLD _12_5
	FSTP _w

	;REALIZAMOS LA ASIGNACION
	FLD _&A_16
	FSTP _a

	;REALIZAMOS LA ASIGNACION
	FLD _2
	FSTP _r

	;REALIZAMOS LA CONCATENACION
	MOV AX,@DATA
	MOV ES,AX
	MOV SI,OFFSET _d
	MOV DI,OFFSET _@aux2
	STRCPY

	MOV AX,@DATA
	MOV ES,AX
	MOV SI,OFFSET _d
	MOV DI,OFFSET _@aux2
	STRCAT

	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _@aux2
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _d
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _Ingrese_Texto
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	;REALIZAMOS EL READ
	getString _d
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _Su_texto_fue
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _d
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	;REALIZAMOS LA ASIGNACION
	FLD _1
	FSTP _a

	;REALIZAMOS LA ASIGNACION
	FLD _5
	FSTP _b

	;REALIZAMOS LA ASIGNACION
	FLD _6
	FSTP _r

	;REALIZAMOS LA ASIGNACION
	FLD _0
	FSTP _@filter

	;REALIZAMOS LA CONDICION
	FLD _4
	FLD _a
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JBE @etiaux0
	FLD _TRUE
	FSTP _@aux3
	JMP @etiaux1
@etiaux0:
	FLD _FALSE
	FSTP _@aux3
@etiaux1:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux3
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO0
	;REALIZAMOS LA ASIGNACION
	FLD _a
	FSTP _@filter

	JMP SALTO1
SALTO0: 
	;REALIZAMOS LA CONDICION
	FLD _4
	FLD _b
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JBE @etiaux2
	FLD _TRUE
	FSTP _@aux4
	JMP @etiaux3
@etiaux2:
	FLD _FALSE
	FSTP _@aux4
@etiaux3:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux4
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO2
	;REALIZAMOS LA ASIGNACION
	FLD _b
	FSTP _@filter

	JMP SALTO3
SALTO2: 
	;REALIZAMOS LA CONDICION
	FLD _4
	FLD _r
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JBE @etiaux4
	FLD _TRUE
	FSTP _@aux5
	JMP @etiaux5
@etiaux4:
	FLD _FALSE
	FSTP _@aux5
@etiaux5:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux5
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO4
	;REALIZAMOS LA ASIGNACION
	FLD _r
	FSTP _@filter

	JMP SALTO5
SALTO4: 
SALTO5: 
SALTO3: 
SALTO1: 
	;REALIZAMOS LA ASIGNACION
	FLD _@filter
	FSTP _c

	;REALIZAMOS LA CONDICION
	FLD _b
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE @etiaux6
	FLD _TRUE
	FSTP _@aux6
	JMP @etiaux7
@etiaux6:
	FLD _FALSE
	FSTP _@aux6
@etiaux7:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux6
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO6
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _B_BIEN
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	JMP SALTO7
SALTO6: 
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _B_MAL
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

SALTO7: 
	;REALIZAMOS LA CONDICION
	FLD _r
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE @etiaux8
	FLD _TRUE
	FSTP _@aux7
	JMP @etiaux9
@etiaux8:
	FLD _FALSE
	FSTP _@aux7
@etiaux9:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux7
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO8
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _R_BIEN
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	JMP SALTO9
SALTO8: 
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _R_MAL
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

SALTO9: 
	;REALIZAMOS LA CONDICION
	FLD _a
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE @etiaux10
	FLD _TRUE
	FSTP _@aux8
	JMP @etiaux11
@etiaux10:
	FLD _FALSE
	FSTP _@aux8
@etiaux11:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux8
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO10
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _ES_A
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	JMP SALTO11
SALTO10: 
SALTO11: 
	;REALIZAMOS LA ASIGNACION
	FLD _5
	FSTP _a

	;REALIZAMOS LA ASIGNACION
	FLD _7
	FSTP _b

	;REALIZAMOS LA OPERACION FADD
	FLD _a
	FLD _b
	FADD
	FSTP _@aux9

	;REALIZAMOS LA CONDICION
	FLD _5
	FLD _@aux9
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JAE @etiaux12
	FLD _TRUE
	FSTP _@aux10
	JMP @etiaux13
@etiaux12:
	FLD _FALSE
	FSTP _@aux10
@etiaux13:
	;VEMOS SI ENTRA AL IF O SI VA AL ELSE O ENDIF
	FLD _@aux10
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE SALTO12
	;REALIZAMOS LA ASIGNACION
	FLD _1
	FSTP _a

	JMP SALTO13
SALTO12: 
	;REALIZAMOS LA ASIGNACION
	FLD _1
	FSTP _b

SALTO13: 
	;REALIZAMOS LA ASIGNACION
	FLD _5
	FSTP _a

	;REALIZAMOS LA ASIGNACION
	FLD _4
	FSTP _b

	;REALIZAMOS LA ASIGNACION
	FLD _1
	FSTP _c

WHILE0: 
	;REALIZAMOS LA CONDICION
	FLD _a
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JAE @etiaux14
	FLD _TRUE
	FSTP _@aux11
	JMP @etiaux15
@etiaux14:
	FLD _FALSE
	FSTP _@aux11
@etiaux15:
	;REALIZAMOS LA CONDICION
	FLD _b
	FLD _c
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JAE @etiaux16
	FLD _TRUE
	FSTP _@aux12
	JMP @etiaux17
@etiaux16:
	FLD _FALSE
	FSTP _@aux12
@etiaux17:
	;REALIZAMOS LA CONDICION AND
	FLD _@aux11
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE @etiaux18
	FLD _TRUE
	FLD _@aux12
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE @etiaux18
	FLD _TRUE
	FSTP _@aux13
	JMP @etiaux19
@etiaux18:
	FLD _FALSE
	FSTP _@aux13
@etiaux19:
	;VEMOS SI ENTRA AL WHILE O SI SALTAMOS TODO
	FLD _@aux13
	FLD _TRUE
	FCOMP
	FSTSW AX
	SAHF
	FFREE ST(0)
	JNE WHILE1
	;REALIZAMOS LA OPERACION FADD
	FLD _a
	FLD _c
	FADD
	FSTP _@aux14

	;REALIZAMOS LA ASIGNACION
	FLD _@aux14
	FSTP _r

	;REALIZAMOS LA OPERACION FADD
	FLD _c
	FLD _1
	FADD
	FSTP _@aux15

	;REALIZAMOS LA ASIGNACION
	FLD _@aux15
	FSTP _c

	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _While
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	JMP WHILE0
WHILE1: 
	;REALIZAMOS EL WRITE
	MOV DX, OFFSET _Sali_del_while
	MOV ah,09
	int 21h

	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h


	mov DX, OFFSET _NEWLINE	;agrega newline
	mov ah,09
	int 21h

	mov dx,OFFSET @msgPRESIONE	;imprimir mensaje de espera
	mov ah,09
	int 21h

	mov ah, 1	;pausa, espera que oprima una tecla
	int 21h	;AH=1 es el servicio de lectura

	mov ax, 4C00h	;Indica que debe terminar la ejecución
	int 21h	;Int de servicios del Sistema Operativo (DOS)

.DATA
	MAXTEXTSIZE equ 50

	@msgPRESIONE db 0DH,0AH,"Presione una tecla para continuar...",'$' ;mensaje de espera 
	_NEWLINE db 0Dh,0Ah,'$' ;salto de linea 
	_TRUE dq 0
	_FALSE dq 1
	_a dq ?
	_b dq ?
	_c dq ?
	_r dq ?
	_d db MAXTEXTSIZE dup (?),'$'
	_w dq ?
	_x db MAXTEXTSIZE dup (?),'$'
	_1 dq 1
	_8 dq 8
	_&F3_16 dq 243
	_&01_2 dq 1
	_HOLA db "HOLA",'$', 46 dup (?)
	_Hola2 db "Hola2",'$', 45 dup (?)
	_12_5 dq 12.5
	_&A_16 dq 10
	_2 dq 2
	_Ingrese_Texto db "Ingrese Texto",'$', 37 dup (?)
	_Su_texto_fue db "Su texto fue",'$', 38 dup (?)
	_5 dq 5
	_6 dq 6
	_4 dq 4
	_@filter dq ?
	_0 dq 0
	_B_BIEN db "B BIEN",'$', 44 dup (?)
	_B_MAL db "B MAL",'$', 45 dup (?)
	_R_BIEN db "R BIEN",'$', 44 dup (?)
	_R_MAL db "R MAL",'$', 45 dup (?)
	_ES_A db "ES A",'$', 46 dup (?)
	_7 dq 7
	_While db "While",'$', 45 dup (?)
	_Sali_del_while db "Sali del while",'$', 36 dup (?)
	_@aux0 dq ?
	_@aux1 db MAXTEXTSIZE dup (?),'$'
	_@aux2 db MAXTEXTSIZE dup (?),'$'
	_@aux3 dq ?
	_@etiaux0 db MAXTEXTSIZE dup (?),'$'
	_@etiaux1 db MAXTEXTSIZE dup (?),'$'
	_@aux4 dq ?
	_@etiaux2 db MAXTEXTSIZE dup (?),'$'
	_@etiaux3 db MAXTEXTSIZE dup (?),'$'
	_@aux5 dq ?
	_@etiaux4 db MAXTEXTSIZE dup (?),'$'
	_@etiaux5 db MAXTEXTSIZE dup (?),'$'
	_@aux6 dq ?
	_@etiaux6 db MAXTEXTSIZE dup (?),'$'
	_@etiaux7 db MAXTEXTSIZE dup (?),'$'
	_@aux7 dq ?
	_@etiaux8 db MAXTEXTSIZE dup (?),'$'
	_@etiaux9 db MAXTEXTSIZE dup (?),'$'
	_@aux8 dq ?
	_@etiaux10 db MAXTEXTSIZE dup (?),'$'
	_@etiaux11 db MAXTEXTSIZE dup (?),'$'
	_@aux9 dq ?
	_@aux10 dq ?
	_@etiaux12 db MAXTEXTSIZE dup (?),'$'
	_@etiaux13 db MAXTEXTSIZE dup (?),'$'
	_@aux11 dq ?
	_@etiaux14 db MAXTEXTSIZE dup (?),'$'
	_@etiaux15 db MAXTEXTSIZE dup (?),'$'
	_@aux12 dq ?
	_@etiaux16 db MAXTEXTSIZE dup (?),'$'
	_@etiaux17 db MAXTEXTSIZE dup (?),'$'
	_@aux13 dq ?
	_@etiaux18 db MAXTEXTSIZE dup (?),'$'
	_@etiaux19 db MAXTEXTSIZE dup (?),'$'
	_@aux14 dq ?
	_@aux15 dq ?
END START
