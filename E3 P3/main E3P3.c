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
    //los lugares que quedan del arreglo se dejan en caracter ESPACIO
    while (contador<=16){
        cadena[contador]=' ';
        contador++;
    }
}

int leerArancel(FILE *ptr){
    char consumir;
    consumir=fgetc(ptr); //pasa por alto caracter "
    printf("\n%c\n", consumir);
    consumir=fgetc(ptr); //pasa por alto caracter ,
      printf("\n%c\n", consumir);
    consumir=fgetc(ptr); //pasa por alto caracter "
      printf("\n%c\n", consumir);
    char cadena[10];
    fgets(cadena, 10, ptr);
    int i=0;
    while (i<=10 ){
        printf("%c",cadena[i]);
        i++;
    }
    int numero=atoi(cadena); //convieprintf("%c", consumir);rte cadena numerica a int
   printf("%d", numero);
    return numero;
}


//Devuelve un puntero al primer elemento de la lista
preRegistro *cargandoDatos(FILE *ptr){
    consumirNombresCampos(ptr);//consume primera linea del archivo
    preRegistro *auxiliar=(preRegistro *)malloc(sizeof(preRegistro));
    auxiliar->periodo=leerPeriodo(ptr);
    auxiliar->mes=leerMes(ptr);
    leerPais(ptr, auxiliar->paisOrigen);
    auxiliar->arancel=leerArancel(ptr);

return auxiliar;
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

    return 0;
}
