#include <iostream>

using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

class nodo{
public://
    nodo(int v, nodo *sig = NULL, nodo *ant =NULL):
        valor(v), siguiente(sig), anterior(ant){}

private:
    int valor;
    nodo *siguiente;
    nodo *anterior;

    friend class lista;
};

typedef nodo *pnodo;

class lista{
public:
    ~lista();
//prototipo de funciones
        void Insertar(int v);
        void Borrar(int v);
        bool ListaVacia(){return plista == NULL;}
        void Mostrar(int);
        void Siguiente();
        void Anterior();
        void Primero();
        void Ultimo();
        bool Actual(){return plista != NULL;}
        int ValorActual(){return plista->valor;}

private:
    pnodo plista;

};

lista::~lista()
{
    pnodo aux;

    Primero();

    while(plista){
        aux = plista;
        plista = plista->siguiente;
        delete aux;
    }
}

void lista::Insertar(int v){
    pnodo nuevo;
    Primero();
    //si la lista esta vacia

    if(ListaVacia() || plista->valor > v){
            //asignamos ala lista un nuevo nodo devalor

        nuevo = new nodo(v, plista);
        if(!plista) plista = nuevo;
        else plista->anterior = nuevo;
    }
    else{
            //buscamos el nodo de valor v
            //avanzamos al suiguiente valor mayor que v
        while(plista->siguiente && plista->siguiente->valor<= v)Siguiente();
    //creamos un nuevo nodo despues del nodo actual

        nuevo = new nodo(v, plista->siguiente, plista);
        plista->siguiente = nuevo;
        if(nuevo->siguiente)nuevo->siguiente->anterior= nuevo;
    }

}

void lista::Borrar(int v)
{
    pnodo nodo;

    nodo = plista;
    while(nodo && nodo->valor < v) nodo = nodo->siguiente;
    while(nodo && nodo->valor > v) nodo = nodo->anterior;

    if(!nodo || nodo->valor != v) return;
    //borrar nodo

    if(nodo->anterior)
        nodo->anterior->siguiente = nodo->siguiente;
    if(nodo->siguiente)
        nodo->siguiente->anterior= nodo->anterior;
    delete nodo;
}

void lista::Mostrar(int orden)
{
    pnodo nodo;
    //mostramos nodo

    if(orden == ASCENDENTE){
        Primero();
        nodo = plista;

        while(nodo){
            printf("-> ",nodo->valor );
            nodo = nodo->siguiente;
        }
    }
    else{
        Ultimo();
        nodo = plista;

        while(nodo){
            printf("-> ",nodo->valor);
            nodo = nodo->anterior;
        }
    }
    printf("\n");
}

void lista::Siguiente(){
    if(plista) plista = plista->siguiente;
}

void lista::Anterior(){
    if(plista) plista->anterior;
}

void lista::Primero(){
    while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo(){
    while(plista && plista->siguiente) plista = plista->siguiente;
}

int main()
{

    lista lista;

    lista.Insertar(20);
    lista.Insertar(10);
    lista.Insertar(40);
    lista.Insertar(30);

    lista.Mostrar(ASCENDENTE);
    lista.Mostrar(DESCENDENTE);

    lista.Primero();
    printf("primero %d: ",lista.ValorActual());

    lista.Ultimo();
    printf("ultimo %d",lista.ValorActual());

    lista.Borrar(10);
    lista.Borrar(15);
    lista.Borrar(45);
    lista.Borrar(40);

    lista.Mostrar(ASCENDENTE);
    lista.Mostrar(DESCENDENTE);

    cin.get();
    return 0;
}

