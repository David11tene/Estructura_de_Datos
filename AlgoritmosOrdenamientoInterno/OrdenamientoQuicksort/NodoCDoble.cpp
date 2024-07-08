#include "NodoCDoble.h"

// Constructor
NodoCDoble::NodoCDoble(Persona* persona) : persona(persona), siguiente(nullptr), anterior(nullptr) {}

// Getters
Persona* NodoCDoble::getPersona() const {
    return persona;
}

NodoCDoble* NodoCDoble::getSiguiente() const {
    return siguiente;
}

NodoCDoble* NodoCDoble::getAnterior() const {
    return anterior;
}

// Setters
void NodoCDoble::setSiguiente(NodoCDoble* siguiente) {
    this->siguiente = siguiente;
}

void NodoCDoble::setAnterior(NodoCDoble* anterior) {
    this->anterior = anterior;
}

void NodoCDoble::setPersona(Persona* persona) {
	this->persona = persona;
}

