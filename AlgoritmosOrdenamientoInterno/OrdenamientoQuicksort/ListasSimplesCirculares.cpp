#include "ListasSimplesCirculares.h"

ListaSimpleCircular::ListaSimpleCircular() : head(nullptr) {}

ListaSimpleCircular::~ListaSimpleCircular() {
    if (!estaVacia()) {
        NodoSimpleCircular* temp = head;
        do {
            NodoSimpleCircular* siguiente = temp->getSiguiente();
            delete temp;
            temp = siguiente;
        } while (temp != head);
    }
}

void ListaSimpleCircular::insertarInicio(Persona* persona) {
    NodoSimpleCircular* nuevoNodo = new NodoSimpleCircular(persona);
    if (estaVacia()) {
        head = nuevoNodo;
        head->setSiguiente(head);
    }
    else {
        NodoSimpleCircular* temp = head;
        while (temp->getSiguiente() != head) {
            temp = temp->getSiguiente();
        }
        nuevoNodo->setSiguiente(head);
        head = nuevoNodo;
        temp->setSiguiente(head);
    }
}

void ListaSimpleCircular::insertarFinal(Persona* persona) {
    NodoSimpleCircular* nuevoNodo = new NodoSimpleCircular(persona);
    if (estaVacia()) {
        head = nuevoNodo;
        head->setSiguiente(head);
    }
    else {
        NodoSimpleCircular* temp = head;
        while (temp->getSiguiente() != head) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
        nuevoNodo->setSiguiente(head);
    }
}

void ListaSimpleCircular::eliminarPersonaPorCedula(const std::string& cedula) {
    if (estaVacia()) return;

    if (head->getPersona()->getCedula() == cedula) {
        if (head->getSiguiente() == head) { // Solo un nodo en la lista
            delete head;
            head = nullptr;
        }
        else {
            NodoSimpleCircular* temp = head;
            while (temp->getSiguiente() != head) {
                temp = temp->getSiguiente();
            }
            NodoSimpleCircular* nodoEliminar = head;
            head = head->getSiguiente();
            temp->setSiguiente(head);
            delete nodoEliminar;
        }
        return;
    }

    NodoSimpleCircular* temp = head;
    while (temp->getSiguiente() != head && temp->getSiguiente()->getPersona()->getCedula() != cedula) {
        temp = temp->getSiguiente();
    }

    if (temp->getSiguiente() != head) {
        NodoSimpleCircular* nodoEliminar = temp->getSiguiente();
        temp->setSiguiente(nodoEliminar->getSiguiente());
        delete nodoEliminar;
    }
}

NodoSimpleCircular* ListaSimpleCircular::buscarPersona(const std::string& cedula) const {
    if (estaVacia()) return nullptr;

    NodoSimpleCircular* temp = head;
    do {
        if (temp->getPersona()->getCedula() == cedula) {
            return temp;
        }
        temp = temp->getSiguiente();
    } while (temp != head);

    return nullptr;
}

void ListaSimpleCircular::mostrarLista() const {
    if (estaVacia()) return;

    NodoSimpleCircular* temp = head;
    do {
        temp->getPersona()->mostrarInformacion();
        temp = temp->getSiguiente();
    } while (temp != head);
}

bool ListaSimpleCircular::estaVacia() const {
    return head == nullptr;
}

