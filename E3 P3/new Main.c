//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cargaDatos.h"
#define m 10

typedef struct tabHash{
     nodo *arreglo[m]; //Arreglo de punteros a tipo nodo
}tablaHash;


int main()
{

    //abriendo el archivo
    FILE *ptr = fopen("datos.txt","r");
    if (ptr!=NULL){
        printf("Se ha abierto el archivo \n");
    }else{
        printf("Error al abrir archivo! \n");
    }
    //Leyendo
    preRegistro *inicioLista;
    consumirNombresCampos(ptr);//consume primera linea del archivo
    inicioLista=cargandoDatos(ptr);
//    insertarToTablaHash();
    return 0;
}
