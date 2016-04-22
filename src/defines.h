#define COTA_ID 30
#define COTA_REAL 30
#define COTA_STR 30
#define PR_AS 1
#define PR_BEGIN 2
#define PR_FLOAT 3
#define PR_STRING 4
#define PR_IF 5
#define PR_THEN 6
#define PR_INT 7
#define PR_ELSE 8
#define PR_ENDIF 9
#define PR_WHILE 10
#define PR_DO 11
#define PR_ENDWHILE 12
#define OPMAS 13
#define OPMENOS 14
#define OPMULTI 15
#define OPDIV 16
#define MAYOR 17
#define MAYOR_IGUAL 18
#define MENOR 19
#define MENOR_IGUAL 20
#define DISTINTO 21
#define IGUAL 22
#define OP_AND 23
#define OP_OR 24
#define OP_NEGADO 25
#define ASIGNA 26
#define P_ABRE 27
#define P_CIERRA 28
#define COR_ABRE 29
#define COR_CIERRA 30
#define PR_GET 31
#define PR_PUT 32
#define COMA 33
#define PUNTO_Y_COMA 34
#define OPCONCAT 35
#define TOKEN_ID 36
#define CADENA 37
#define COMENTARIO 38
#define CONST_INT 39
#define CONST_FLOAT 40
#define CONST_STR 41
#define PR_DIM 42


typedef struct
{
 char *cNombre;
 char *cTipo;
 char *cValor;
 int iLongitud;
 char *cAlias;
} t_tablaSimbolos;

