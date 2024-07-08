#include "NodoSimpleCircular.h"

NodoSimpleCircular::NodoSimpleCircular(Persona* persona) : persona(persona), siguiente(nullptr) {}

Persona* NodoSimpleCircular::getPersona() {
    return persona;
}

void NodoSimpleCircular::setPersona(Persona* persona) {
    this->persona = persona;
}

NodoSimpleCircular* NodoSimpleCircular::getSiguiente() {
    return siguiente;
}

void NodoSimpleCircular::setSiguiente(NodoSimpleCircular* siguiente) {
    this->siguiente = siguiente;
}
