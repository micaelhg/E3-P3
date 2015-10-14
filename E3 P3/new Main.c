//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cargaDatos.h"
#define TAM 6260

typedef struct tabHash{
     nodo arreglo[TAM]; //Arreglo de punteros a tipo nodo
}tablaHash;

int fxHash(registro *inicioLista){
    int var_1=inicioLista->arancel;
    int var_2=inicioLista->totalCifItemUS;
    int var_3=inicioLista->CantidadMercancia;
    if (var_3==0){ var_3=1;}
    float k= ((var_1*var_2*0.3) /var_3);
    int clave=(int)k;  //cast
    return (clave%TAM);
}

int copiaDatos(registro *auxiliar, registro *lista){
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
int insertaTotabla(int clave_key,tablaHash *tabla, registro *lista,int elementos){
    if (elementos==0){
        tabla->arreglo[clave_key].primerElemento =lista;
        tabla->arreglo[clave_key].elementos=1;
    }else{
        registro *actual=tabla->arreglo[clave_key].primerElemento;
        while((actual->sgte)!=NULL){
            actual=actual->sgte;
        }
        actual->sgte=lista;
        tabla->arreglo[clave_key].elementos++;
    }
}

void inicializarTabla(tablaHash *tabla){
    int contador = 0;
    while (contador <=TAM){
        tabla->arreglo[contador].elementos=0;
        tabla->arreglo[contador].primerElemento=NULL;
        contador++;
    }
}

tablaHash *devuelveTablaHash(registro *inicioLista){
    tablaHash *tabla;
    tabla=(tablaHash*)malloc(sizeof(tablaHash));
    inicializarTabla(tabla);
    while (inicioLista->sgte!=NULL){
        int clave_key=fxHash(inicioLista);
        printf("clave: %d", clave_key);
        insertaTotabla(clave_key, tabla , inicioLista, tabla->arreglo[clave_key].elementos);
        inicioLista=inicioLista->sgte;
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
    registro *inicioLista;
    consumirNombresCampos(ptr);//consume primera linea del archivo
    inicioLista=cargandoDatos(ptr);

    //se declara puntero a tipo tablahash
    tablaHash *tabla;
    tabla=devuelveTablaHash(inicioLista);
    return 0;
}
