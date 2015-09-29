//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef char clave;

typedef struct TipoRegistro{
  clave claveRut;
  int digitoVerificador;
  char nombre[10];
  char apellidoPaterno[10];
  char apellidoMaterno[10];
}registro;

typedef struct TipoNodo{
    registro datos;
    struct TipoNodo *sgte;
}nodo;

int hash(clave claveRut){



}

int main()
{
    nodo *tabla[m]; //Arreglo de punteros a tipo nodo



    return 0;
}
