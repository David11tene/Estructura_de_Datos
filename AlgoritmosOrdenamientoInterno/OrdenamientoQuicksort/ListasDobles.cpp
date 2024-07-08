#include "ListasDobles.h"

// Implementación de ListaDoble

ListaDoble::ListaDoble() : head(nullptr) {}

ListaDoble::~ListaDoble() {
    while (head != nullptr) {
        NodoDoble* temp = head;
        head = head->getSiguiente();
        delete temp;
    }
}

void ListaDoble::insertarInicio(Persona* persona) {
    NodoDoble* nuevoNodo = new NodoDoble(persona);
    if (estaVacia()) {
        head = nuevoNodo;
    }
    else {
        head->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(head);
        head = nuevoNodo;
    }
}

void ListaDoble::insertarFinal(Persona* persona) {
    NodoDoble* nuevoNodo = new NodoDoble(persona);
    if (estaVacia()) {
        head = nuevoNodo;
    }
    else {
        NodoDoble* temp = head;
        while (temp->getSiguiente() != nullptr) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(temp);
    }
}

void ListaDoble::eliminarPersonaPorCedula(const std::string& cedula) {
    if (estaVacia()) return;

    if (head->getPersona()->getCedula() == cedula) {
        NodoDoble* temp = head;
        head = head->getSiguiente();
        if (head != nullptr) {
            head->setAnterior(nullptr);
        }
        delete temp;
        return;
    }

    NodoDoble* temp = head;
    while (temp != nullptr && temp->getPersona()->getCedula() != cedula) {
        temp = temp->getSiguiente();
    }

    if (temp != nullptr) {
        NodoDoble* anterior = temp->getAnterior();
        NodoDoble* siguiente = temp->getSiguiente();

        if (anterior != nullptr) {
            anterior->setSiguiente(siguiente);
        }
        if (siguiente != nullptr) {
            siguiente->setAnterior(anterior);
        }
        delete temp;
    }
}

NodoDoble* ListaDoble::buscarPersona(const std::string& cedula) const {
    NodoDoble* temp = head;
    while (temp != nullptr) {
        if (temp->getPersona()->getCedula() == cedula) {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return nullptr;
}

void ListaDoble::mostrarLista() const {
    NodoDoble* temp = head;
    while (temp != nullptr) {
        temp->getPersona()->mostrarInformacion();
        temp = temp->getSiguiente();
    }
}

bool ListaDoble::estaVacia() const {
    return head == nullptr;
}
