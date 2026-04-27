#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return crearNodo(valor);

    if (valor < raiz->dato)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else
        raiz->derecho = insertar(raiz->derecho, valor);

    return raiz;
}

void inOrden(Nodo* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inOrden(raiz->derecho);
    }
}

void preOrden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierdo);
        preOrden(raiz->derecho);
    }
}

void postOrden(Nodo* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierdo);
        postOrden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz = NULL;
    int op, valor;

    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Insertar valor";
        cout << "\n2. Mostrar InOrden";
        cout << "\n3. Mostrar PreOrden";
        cout << "\n4. Mostrar PostOrden";
        cout << "\n5. Mostrar todos";
        cout << "\n6. Salir";
        cout << "\nSeleccione: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;

            case 2:
                if (!raiz) cout << "Arbol vacio\n";
                else {
                    cout << "InOrden: ";
                    inOrden(raiz);
                }
                break;

            case 3:
                if (!raiz) cout << "Arbol vacio\n";
                else {
                    cout << "PreOrden: ";
                    preOrden(raiz);
                }
                break;

            case 4:
                if (!raiz) cout << "Arbol vacio\n";
                else {
                    cout << "PostOrden: ";
                    postOrden(raiz);
                }
                break;

            case 5:
                if (!raiz) cout << "Arbol vacio\n";
                else {
                    cout << "InOrden: ";
                    inOrden(raiz);
                    cout << "\nPreOrden: ";
                    preOrden(raiz);
                    cout << "\nPostOrden: ";
                    postOrden(raiz);
                }
                break;
        }

    } while (op != 6);

    return 0;
}