#include "Nodo.h"
Nodo::Nodo(){
    siguiente = nullptr;
    persona = nullptr;
}
Nodo::~Nodo(){
}
Nodo* Nodo::getSiguiente(){
    return siguiente;
}
Persona* Nodo::getPersona(){
    return persona;
}
void Nodo::setSiguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}
void Nodo::setPersona(Persona* persona){
    this->persona = persona;
}
