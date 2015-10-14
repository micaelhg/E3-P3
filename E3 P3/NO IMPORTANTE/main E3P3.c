//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#define m 10

typedef struct tabHash{
     nodo *arreglo[m]; //Arreglo de punteros a tipo nodo
}tablaHash;

void *consumirNombresCampos(FILE *ptr){
    char consumir[85];
    fgets(consumir,85,ptr);
    //return ptr;
}

int leerPeriodo(FILE *ptr){
        //leer archivo
    char consumir;
    consumir=fgetc(ptr); //pasa por alto caracter "
    char cadena[6];
    fgets(cadena, 5, ptr);
    int numero=atoi(cadena); //convierte cadena numerica a int

    return numero;
}
int leerMes(FILE *ptr){
    //leer archivo
    char consumir;
    consumir=fgetc(ptr); //pasa por alto caracter "
    consumir=fgetc(ptr); //pasa por alto caracter ,
    consumir=fgetc(ptr); //pasa por alto caracter "
    char cadena[3];
    fgets(cadena, 3, ptr);
    int numero=atoi(cadena); //convieprintf("%c", consumir);rte cadena numerica a int
    return numero;
}

void leerPais(FILE *ptr, char cadena[]){
    FILE *ptrAux=ptr;
    char consumir;
    consumir=fgetc(ptrAux); //pasa por alto caracter "
    consumir=fgetc(ptrAux); //pasa por alto caracter ,
    consumir=fgetc(ptrAux); //pasa por alto caracter "
   int contador=0;
    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    while (caracter != ','){
        printf("   %c   ", fgetc(ptrAux));
        caracter=fgetc(ptrAux);
        if (caracter =='"'){
            caracter=getc(ptrAux);
        }
        if (caracter != ',') {
                cadena[contador]=caracter;
                contador++;
                printf("01");
        }
    }
    //los lugares que quedan del arreglo se dejan en caracter ESPACIO
    while (contador<18){
        cadena[contador]='-';
        contador++;
    }
}

int leerArancel(FILE *ptr){
    char consumir;
    consumir=fgetc(ptr); //pasa por alto caracter "
    char cadena[9];
    fgets(cadena, 9, ptr);
    int numero=atoi(cadena); //convierte cadena numerica a int
    return numero;
}

int leeTotalUS(FILE *ptr){
    FILE *ptrAux=ptr;
    char consumir;
    consumir=fgetc(ptrAux); //pasa por alto caracter "
    consumir=fgetc(ptrAux); //pasa por alto caracter ,
char cadena[10]={'0','0','0','0','0','0','0','0','0','0'};
   int contador=0;
    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    while (caracter != ','){
        caracter=fgetc(ptrAux);
        if (caracter =='"'){
            caracter=getc(ptrAux);
        }
        if (caracter != ',') {
                printf("%c", caracter);
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
        char cadena[8];
    fgets(cadena, 8, ptr);
    int numero=atoi(cadena); //convierte cadena numerica a int
    return numero;
}

//Devuelve un puntero al primer elemento de la lista
//PROBLEMA DE ENLAZAMIENTO
preRegistro *cargandoDatos(FILE *ptr){

    consumirNombresCampos(ptr);//consume primera linea del archivo
    preRegistro *auxiliar=(preRegistro *)malloc(sizeof(preRegistro));
    if feof(ptr){
        auxiliar->sgte=NULL;
         return auxiliar;
    }else{
        auxiliar->periodo=leerPeriodo(ptr);
        auxiliar->mes=leerMes(ptr);
        leerPais(ptr, auxiliar->paisOrigen);
        auxiliar->arancel=leerArancel(ptr);
        auxiliar->totalCifItemUS=leeTotalUS(ptr);
        auxiliar->CantidadMercancia=cantMerc(ptr);
        auxiliar->sgte=cargandoDatos(ptr);
        return auxiliar;
    }

}

int main()
{

    //abriendo el archivo
    FILE *ptr = fopen("import.csv","r");
    if (ptr!=NULL){
        printf("Se ha abierto el archivo \n");
    }else{
        printf("Error al abrir archivo! \n");
    }
    //Leyendo
    preRegistro *inicioLista;
    inicioLista=cargandoDatos(ptr);
   // insertarToTablaHash();
    return 0;
}
