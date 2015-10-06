//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef long int key;

typedef struct TipoRegistro{
  int rut;

}registro;

typedef struct TipoNodo{
    registro datos;
    key clave;
    struct TipoNodo *sgte;
}nodo;

int hash(clave claveRut){

    return (k % m);
}
/* ************************************************* */
int insertaToRegistro(nodo tabla[], int indiceHash){


}

int buscaEnRegistro(nodo tabla[]...){
}
/* ********************* MAIN *********************** */
int main()
{
    nodo *tabla[m]; //Arreglo de punteros a tipo nodo

    return 0;
}
