    char caracter='x'; //Solo para que sea una variable valida para entrar en el sgte while
    while (caracter != ','){
        caracter=fgetc(ptr);
        if (caracter =='"'){
            caracter=getc(ptr);
        }
        if (caracter != ',') {
                printf("%c", caracter);
                cadena[i]=caracter;

        }
    }

