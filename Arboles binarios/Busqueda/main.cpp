#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

//Prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);

//Creamos el arbol y se inicial en NULL
Nodo *arbol = NULL;

int main(void) {
    menu();

    return 0;
}

//Funcion para crear nodo
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo -> dato = n;
    nuevo_nodo -> der = NULL;
    nuevo_nodo -> izq = NULL;

    return nuevo_nodo; 
}

//Funcion para insertar nodos al arbol
void insertarNodo(Nodo *&arbol, int n){
    if(arbol == NULL){ //Si el arbol esta vacio
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{ //Si el arbol tiene un nodo o mas
        int valorRaiz = arbol -> dato; //Obtenemos el valor de la raiz
        if(n < valorRaiz) { // Si el elemento es menor a la raiz, insertamos en izq
            insertarNodo(arbol -> izq, n);
        }
        else { //Si el elemento es mayor a la raiz, insertamos en der
            insertarNodo(arbol -> der, n);
        }
    }
}

//Menu
void menu() {
    int dato, opcion;

    do{
        cout << "0. Salir" << endl;
        cout << "1. Crear nodo" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Digite un numero";
            cin >> dato;
            insertarNodo(arbol, dato);
            cout << "\n";
            system("pause");
            break;
        }
        system("cls");
    } while(opcion != 0);
}