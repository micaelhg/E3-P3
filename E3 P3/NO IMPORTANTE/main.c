//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef long int clave;

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
    long int k;
    k=claveRut;
    return (k % m);
}

int insertaToRegistro(nodo tabla[], int indiceHash){


}

int buscaEnRegistro(nodo tabla[]...){
}

int main()
{
    nodo *tabla[m]; //Arreglo de punteros a tipo nodo
    long int rut;
    scanf("%li", &rut);
    printf("hash devolvio: %d", hash(rut) );
    return 0;
}
