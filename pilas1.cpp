#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertar(Nodo *&, int);
void quitar(Nodo *&, int &);
void modificarNodo(Nodo *&);
void buscarNodo(Nodo *&);
void eliminimarNodo(Nodo *&);
void imprimir(Nodo *);
int menu();
int numero;
Nodo *pila=NULL;
int main(){
    menu();
    return 0;
}
int menu(){
    char opcion;
    int opc;
    printf("\n****\t****\tMenu\t****\t*****\n");
    printf("\n1.Crear pila");
    printf("\n2.Eliminar pila");
    printf("\n3.Modificar nodo");
    printf("\n4.Buscar nodo");
    printf("\n5.Eliminar nodo");
    printf("\n6.Imprimir pila\n");
    scanf("%d",&opc);
    switch(opc){
        case 0:
            printf("******\tBay\t******");
            exit(0);
        break;
        case 1:
            printf("\n--------Crear pila---------\n");
            do{
            printf("\n Ingrese un dato: ");
            scanf("%d", &numero);
            insertar(pila, numero);
            printf("\n Presione (s /n ) para continuar: ");
            scanf(" %c", &opcion);
            }while(opcion == 's');
            system("cls");
            menu();
        break;
        case 2:
            printf("\n--------Eliminar pila--------\n");
            while(pila != NULL){
            quitar(pila, numero);
            printf("%d ", numero);
            menu();
        break;
        case 3:
            printf("\n--------Modificar nodo--------\n");
            modificarNodo(pila);
            menu();
        break;
        case 4:
            printf("\n--------Buscar nodo--------\n");
            buscarNodo(pila);
            menu();
        break;
        case 5:
            printf("\n--------Eliminar nodo--------\n");
            eliminimarNodo(pila);
            menu();
        break;
        case 6:
            printf("\n--------Imprimir pila--------\n");
            imprimir(pila);
            menu();
        break;
        default:
            printf("\nOpcion no valida\n");
            menu();
    }
    }
}

void insertar(Nodo *&pila, int numero){
    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->dato = numero;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    printf("\nEl dato %d fue insertado correctamente", numero);
}

void quitar(Nodo *&pila, int &numero){
    Nodo *aux = pila;
    numero = aux->dato;
    pila = aux->siguiente;
    free(aux);
}
void buscarNodo(Nodo *&pila){
    int datobuscar,encontrado=0;
    if(pila!=NULL){
        printf("\nIngrese dato a buscar: ");
        scanf("%d",&datobuscar);
        Nodo *aux=reservar_memoria;
        aux=pila;
        while(aux!=NULL){
            if(aux->dato==datobuscar){
                encontrado==1;
            }
            aux=aux->siguiente;
        }
        if(encontrado==1){
            printf("\nDato encontrado\n");
        }else{
            printf("\nEl dato no fue encontrado\n");
        }
    }else{
        printf("\nEl  dato no puede ser encontrado por que la pila esta vacia\n");
    }
}
void modificarNodo(Nodo *&pila){
    int datomodificar,encontado=0,nuevo;
    if(pila!=NULL){
        printf("\nIngrese el numero a modificar: ");
        scanf("%d",&datomodificar);
        Nodo *aux=reservar_memoria;
        aux=pila;
        while(pila!=NULL){
            if(pila->dato==datomodificar){
                printf("\nIngrese dato nuevo: ");
                scanf("%d",&nuevo);
                pila->dato=nuevo;
            }
            pila=pila->siguiente;
        }
        pila=aux;
    }else{
        printf("\nPila vacia\n");
    }
}
void eliminimarNodo(Nodo *&pila){
    int datoeliminar,encontrado;
    Nodo *anterior=reservar_memoria;
    if(pila!=NULL){
        printf("\nIngrese el numero a eliminar: ");
        scanf("%d",&datoeliminar);
        Nodo *aux=reservar_memoria;
        aux=pila;
        while(pila!=NULL){
            if(pila->dato==datoeliminar){
                if(aux==pila){
                    pila=aux->siguiente;
                    free(aux);
                }else{
                    aux=pila;
                    anterior->siguiente=aux->siguiente;
                    pila=anterior;
                free(aux);
                }
            }
        }
    }else{
        printf("\nPila vacia\n");
    }
}
void imprimir(Nodo *pila){
    Nodo *aux=reservar_memoria;
    aux=pila;
    if(pila!=NULL){
        while(aux!=NULL){
            printf("%d ",aux->dato);
            aux=aux->siguiente;
        }
    }else{
        printf("\nPila Vacia\n");
    }
}
