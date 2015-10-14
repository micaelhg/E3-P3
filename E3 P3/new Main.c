//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cargaDatos.h"
#define TAM 6260

typedef struct tabHash{
     nodo *arreglo[TAM]; //Arreglo de punteros a tipo nodo
}tablaHash;

tablaHash *devuelveTablaHash(tablaHash *tabla,preRegistro *inicioLista){
    tabla=(tablaHash*)malloc(sizeof(tablaHash));
    while (inicioLista->sgte!=NULL){

    }
    return tabla;
}

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

    //se declara puntero a tipo tablahash
    tablaHash *tabla;
    tabla=devuelveTablaHash(tabla, inicioLista);
    return 0;
}
