//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#define m 10

typedef struct tabHash{
     nodo *arreglo[m]; //Arreglo de punteros a tipo nodo
}tablaHash;

void *consumirNombresCampos(FILE *ptr){
    char consumir[71];
    fgets(consumir,71,ptr);

    //return ptr;
}

int leerPeriodo(FILE *ptr){
        //leer archivo
    char cadena[6];
    fgets(cadena, 5, ptr);
    //printf("%c%c%c%c%c", cadena[0],cadena[1],cadena[2],cadena[3],cadena[4]);
    int numero=atoi(cadena); //convierte cadena numerica a int
    //printf("%d", numero);
    return numero;
}
int leerMes(FILE *ptr){
    //leer archivo
    char consumir;
    consumir=fgetc(ptr); //pasa por alto caracter ,
    char cadena[3];
    fgets(cadena, 3, ptr);
    /*int i;
    for (i=0;i<=3;i++){printf(" %c ", cadena[i]);}
    printf("\n %c", fgetc(ptr));*/
    int numero=atoi(cadena); //convieprintf("%c", consumir);rte cadena numerica a int
    return numero;
}

void leerPais(FILE *ptr, char cadena[]){
    FILE *ptrAux=ptr;
    char consumir;
    consumir=fgetc(ptrAux); //pasa por alto caracter ,
   int contador=0;
    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    while (caracter != ','){
        //printf("   %c   ", fgetc(ptrAux));
        caracter=fgetc(ptrAux);
        if (caracter != ',') {
                cadena[contador]=caracter;
                contador++;
        }
    }
    //los lugares que quedan del arreglo se dejan en caracter ESPACIO
    while (contador<18){
        cadena[contador]='-';
        contador++;
    }

}

int leerArancel(FILE *ptr){
    char cadena[9];
    fgets(cadena, 9, ptr);
    int numero=atoi(cadena); //convierte cadena numerica a int

   /* int i;
    for (i=0;i<9;i++){printf(" %c ", cadena[i]);}
    return numero;*/
}

int leeTotalUS(FILE *ptr){

    FILE *ptrAux=ptr;
    char consumir=fgetc(ptrAux); //pasa por alto caracter ,
    char cadena[10]={'0','0','0','0','0','0','0','0','0','0'};
    int contador=0;
    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    while (caracter != ','){
        caracter=fgetc(ptrAux);
        if (caracter != ',') {
                //printf("%c", caracter);
                cadena[contador]=caracter;
                contador++;
        }
    }
    //Ordenar 0's a la Izquierda para la conversion a int
    int ultimo=10;
    while (contador>=0){
        cadena[ultimo]=cadena[contador];
        cadena[contador]='0';
        contador--;
        ultimo--;
    }
    int numero=0;
    numero=atoi(cadena);
    //printf(" %d ", numero);
    //printf(" %c ", fgetc(ptr));
    return numero;
}
int cantMerc(ptr){
    char caracter=fgetc(ptr);

    char cadena[8]={'0','0','0','0','0','0','0','0'};
    int contador=0;
    while (caracter != '\n'){
        //    printf("sdffdsf");
        cadena[contador]=caracter;
        caracter=fgetc(ptr);
        contador++;
    }

    int ultimo=8;
    while (contador>=0){
        cadena[ultimo]=cadena[contador];
        cadena[contador]='0';
        contador--;
        ultimo--;
    }

    int numero=atoi(cadena); //convierte cadena numerica a int
    return numero;
}

//Devuelve un puntero al primer elemento de la lista
//PROBLEMA DE ENLAZAMIENTO
preRegistro *cargandoDatos(FILE *ptr){
    preRegistro *auxiliar=(preRegistro *)malloc(sizeof(preRegistro));
    if (fgetc(ptr)=='.'){
        char noImportante = fgetc(ptr);
    }
    if (feof(ptr)){
        auxiliar->sgte=NULL;
    }else{
        auxiliar->periodo=leerPeriodo(ptr);
        auxiliar->mes=leerMes(ptr);
        leerPais(ptr, auxiliar->paisOrigen);
        auxiliar->arancel=leerArancel(ptr);
        auxiliar->totalCifItemUS=leeTotalUS(ptr);
        auxiliar->CantidadMercancia=cantMerc(ptr);
              // printf("\n%d", auxiliar->CantidadMercancia);

        auxiliar->sgte=cargandoDatos(ptr);


    }
    return auxiliar;
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


   // insertarToTablaHash();
    return 0;
}
