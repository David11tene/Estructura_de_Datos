#include "ListasSimples.h"

// Implementación de ListaSimple

ListaSimple::ListaSimple() : head(nullptr) {}

ListaSimple::~ListaSimple() {
    while (head != nullptr) {
        NodoSimple* temp = head;
        head = head->getSiguiente();
        delete temp;
    }
}

void ListaSimple::insertarInicio(Persona* persona) {
    NodoSimple* nuevoNodo = new NodoSimple(persona);
    nuevoNodo->setSiguiente(head);
    head = nuevoNodo;
}

void ListaSimple::insertarFinal(Persona* persona) {
    NodoSimple* nuevoNodo = new NodoSimple(persona);
    if (estaVacia()) {
        head = nuevoNodo;
    }
    else {
        NodoSimple* temp = head;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
    }
}

void ListaSimple::eliminarPersonaPorCedula(const std::string& cedula) {
    if (estaVacia()) return;

    if (head->getPersona()->getCedula() == cedula) {
        NodoSimple* temp = head;
        head = head->getSiguiente();
        delete temp;
        return;
    }

    NodoSimple* temp = head;
    while (temp->getSiguiente() != nullptr && temp->getSiguiente()->getPersona()->getCedula() != cedula) {
        temp = temp->getSiguiente();
    }

    if (temp->getSiguiente() != nullptr) {
        NodoSimple* nodoEliminar = temp->getSiguiente();
        temp->setSiguiente(nodoEliminar->getSiguiente());
        delete nodoEliminar;
    }
}

NodoSimple* ListaSimple::buscarPersona(const std::string& cedula) const {
    NodoSimple* temp = head;
    while (temp != nullptr) {
        if (temp->getPersona()->getCedula() == cedula) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return nullptr;
}

void ListaSimple::mostrarLista() const {
    NodoSimple* temp = head;
    while (temp != nullptr) {
        temp->getPersona()->mostrarInformacion();
        temp = temp->getSiguiente();
    }
}

bool ListaSimple::estaVacia() const {
    return head == nullptr;
}

