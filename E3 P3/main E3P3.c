//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


#define m 10


typedef struct tabHash{
     nodo *arreglo[m]; //Arreglo de punteros a tipo nodo
}tablaHash;


int main()
{
    //abriendo el archivo
    FILE *ptr = fopen("import.csv","r");
    if (ptr!=NULL){
        printf("Se ha abierto el archivo");
    }else{
        printf("Error al abrir archivo! \n");
    }
    //Leyendo
    char caracter=fgetc(ptr);
    char consumir;
    while (caracter != ','){
        caracter=fgetc(ptr);
        if (caracter =='"'){
            consumir=getc(ptr);
        }
        printf("%c  ", caracter);
   }
    return 0;
}
