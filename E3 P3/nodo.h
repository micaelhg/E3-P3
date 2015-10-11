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
  char paisOrigen[16];
  int arancel;
  int totalCifItemUS;
  int CantidadMercancia;
  struct TipoPreRegistro *sgte;
}preRegistro;

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


