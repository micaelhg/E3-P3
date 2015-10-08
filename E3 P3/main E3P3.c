//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include <"nodo.h">

#define m 10


int main()
{
    nodo *tabla[m]; //Arreglo de punteros a tipo nodo
    FILE *datos = fopen("PDPE.csv","r");
    if (datos!=NULL){

    }else{
        printf("Error al abrir archivo! \n");
    }

    return 0;
}
