  printf("Periodo: %d \n",  inicioLista->periodo);
    printf("Mes: %d \n",  inicioLista->mes);
    int i=0;
    while (i<18){
        printf(" %c ",  inicioLista->paisOrigen[i]);
        i++;
    }
    printf("Arancel: %d \n",  inicioLista->arancel);
    printf("TotalUS: %d \n",  inicioLista->totalCifItemUS);
    printf("Cant Mercancia: %d \n",  inicioLista->CantidadMercancia);
