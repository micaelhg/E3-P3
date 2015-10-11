//Hash Encadenado

#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


#define m 10


typedef struct tabHash{
     nodo *arreglo[m]; //Arreglo de punteros a tipo nodo
}tablaHash;

int cargandoDatos(){
return 0;
}

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
    //registro ArrayDatos[36260];
    //cargandoDatos();
    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    char consumir;
    while (caracter != ','){
        caracter=fgetc(ptr);
        if (caracter =='"'){
            caracter=getc(ptr);
        }
        if (caracter != ',') {printf("%c", caracter);}
   }
    return 0;
}
