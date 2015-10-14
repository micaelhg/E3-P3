//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cargaDatos.h"
#define TAM 6260

typedef struct tabHash{
     nodo *arreglo[TAM]; //Arreglo de punteros a tipo nodo
}tablaHash;

int fxHash(preRegistro *inicioLista){
    int var_1=inicioLista->arancel;
    int var_2=inicioLista->totalCifItemUS;
    int var_3=inicioLista->CantidadMercancia;
    if (var_3==0){ var_3=1;}
    int k=(var_1*var_2*0,3)/var_3;
    return (k%TAM);
}

int copiaDatos(registro *auxiliar, preRegistro *lista){
    auxiliar->arancel=lista->arancel;
    auxiliar->CantidadMercancia=lista->CantidadMercancia;
    auxiliar->mes=lista->mes;
    auxiliar->periodo=lista->periodo;
    auxiliar->totalCifItemUS=lista->totalCifItemUS;
     int contador=0;
        while (contador<18){
            auxiliar->paisOrigen[contador]=lista->paisOrigen[contador];
            contador++;
        }
    auxiliar->sgte=NULL;
}
int insertaTotabla(int clave_key,nodo arreglo[],int elementos, preRegistro *lista){
    registro *auxiliar=(registro *)malloc(sizeof(registro));
    copiaDatos(auxiliar, lista);
    if (elementos==0){
        arreglo[clave_key].elementos=1;
        arreglo[clave_key].primerElemento=auxiliar;
    }else{
        registro *aux=arreglo[clave_key].primerElemento;
        while(aux->sgte!=NULL){
            aux=aux->sgte;
        }
        aux->sgte=auxiliar;
    }

}

tablaHash *devuelveTablaHash(preRegistro *inicioLista){
    tablaHash *tabla;
    tabla=(tablaHash*)malloc(sizeof(tablaHash));
    while (inicioLista->sgte!=NULL){
        int clave_key=fxHash(inicioLista);
        insertaTotabla(clave_key, tabla->arreglo,tabla->arreglo[clave_key]->elementos ,inicioLista);
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
    tabla=devuelveTablaHash(inicioLista);
    return 0;
}
