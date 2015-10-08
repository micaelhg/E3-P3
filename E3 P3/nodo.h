
typedef long int key;

typedef struct TipoRegistro{
  int rut;
}registro;

typedef struct TipoNodo{
    registro datos;
    key clave;
    struct TipoNodo *sgte;
}nodo;


