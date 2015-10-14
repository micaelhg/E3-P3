#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif

#ifndef stdlib_h
#include <stdlib.h>
#define stdio_h
#endif


typedef long int key;
//Tipo Preregistro para cargar los datos en la memoria para trabajar con ellos
typedef struct TipoPreRegistro{
  int periodo;
  int mes;
  char paisOrigen[18];
  int arancel;
  int totalCifItemUS;
  int CantidadMercancia;
  struct TipoPreRegistro *sgte;
}preRegistro;

typedef struct TipoRegistro{
  int periodo;
  int mes;
  char *paisOrigen[18];
  int arancel;
  int totalCifItemUS;
  int CantidadMercancia;
  struct TipoRegistro *sgte;
}registro;

typedef struct TipoNodo{
    int elementos;
    registro *primerElemento;
}nodo;



