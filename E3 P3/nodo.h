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
  char paisOrigen[18];
  int arancel;
  int totalCifItemUS;
  int CantidadMercancia;
  struct TipoRegistro *sgte;
}registro;

typedef struct TipoNodo{
    int elementos;
    registro *primerElemento;
}nodo;



