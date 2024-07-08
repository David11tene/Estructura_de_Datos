#include "NodoDoble.h"
NodoDoble::NodoDoble(){
    persona =nullptr;
    siguiente = nullptr;
    anterior = nullptr;
}
NodoDoble::~NodoDoble(){
}
NodoDoble* NodoDoble::getSiguiente(){
    return siguiente;
}
Persona* NodoDoble::getPersona(){
    return persona;
}
void NodoDoble::setSiguiente(NodoDoble* siguiente){
    this->siguiente = siguiente;
}
void NodoDoble::setPersona(Persona* persona){
    this->persona = persona;
}
NodoDoble* NodoDoble::getAnterior(){
    return anterior;
}
void NodoDoble::setAnterior(NodoDoble* anterior){
    this->anterior = anterior;
}
