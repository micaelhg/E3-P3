#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif


typedef long int key;

typedef struct TipoRegistro{
  int periodo;
  int mes;
  char *paisOrigen[15];
  int arancel;
  int totalCifItemUS;
  int CantidadMercancia;
}registro;

typedef struct TipoNodo{
    registro datos;
    key clave;
    struct TipoNodo *sgte;
}nodo;


