#ifndef DEFINES_H
#define DEFINES_H
#define COTA_ID 30
#define COTA_REAL 30
#define COTA_STR 30
#define MAX_VARIABLES 50
#define MAX_INT 65535
#define RENGLONES_IMPRESION_ARBOL 30
#define CARACTERES_RENGLON_ARBOL 255

#define PATH_TABLA_SIMBOLOS "ts.txt"
#define ERROR_ABRIR_TABLA_SIMBOLOS "No se pudo crear la tabla de simbolos. Verifique que tenga permisos de escritura"

#define PREFIJO_ID "_"
#define PREFIJO_INT "\%"
#define PREFIJO_FLOAT "$"
#define PREFIJO_STRING "&"


#define VARIABLE_REPETIDA "Ya existe una variable con el nombre %s en la linea %d\n"
#define VARIABLE_INEXISTENTE "La variable %s no esta definida. Primera aparicion en la linea %d\n"
#define VARIABLE_ERROR_TIPOS "Error de tipos. No se puede operar entre el tipo %s y %s en la linea %d\n"
#define OPERACION_INVALIDA_TIPOS "Operacion invalida. No puede realizar la operacion %s entre %s y %s porque son del tipo %s en la linea %d\n"






#endif
