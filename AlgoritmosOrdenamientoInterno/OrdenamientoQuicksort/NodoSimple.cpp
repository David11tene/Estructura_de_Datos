#include "NodoSimple.h"

NodoSimple::NodoSimple(Persona* persona) : persona(persona), siguiente(nullptr) {}

Persona* NodoSimple::getPersona() {
    return persona;
}

void NodoSimple::setPersona(Persona* persona) {
    this->persona = persona;
}

NodoSimple* NodoSimple::getSiguiente() {
    return siguiente;
}

void NodoSimple::setSiguiente(NodoSimple* siguiente) {
    this->siguiente = siguiente;
}
