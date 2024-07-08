#include "NodoDoble.h"

NodoDoble::NodoDoble(Persona* persona) : persona(persona), siguiente(nullptr), anterior(nullptr) {}

Persona* NodoDoble::getPersona() {
    return persona;
}

void NodoDoble::setPersona(Persona* persona) {
    this->persona = persona;
}

NodoDoble* NodoDoble::getSiguiente() {
    return siguiente;
}

void NodoDoble::setSiguiente(NodoDoble* siguiente) {
    this->siguiente = siguiente;
}

NodoDoble* NodoDoble::getAnterior() {
    return anterior;
}

void NodoDoble::setAnterior(NodoDoble* anterior) {
    this->anterior = anterior;
}
