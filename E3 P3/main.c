//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef int clave;

typedef struct TipoRegistro{
  clave claveRut[8];
  int digitoVerificador;
  char nombre[10];
  char apellidoPaterno[10];
  char apellidoMaterno[10];
}registro;

typedef struct TipoNodo{
    registro datos;
    struct TipoNodo *sgte;
}nodo;

int hash(clave claveRut[]){
    int suma;
    suma = claveRut[1]+claveRut[8];

}

int insertaToRegistro(nodo tabla[], int indiceHash){


}

int main()
{
    nodo *tabla[m]; //Arreglo de punteros a tipo nodo
    printf("Ingrese Rut SIN digito verificador: \n");

    return 0;
}
