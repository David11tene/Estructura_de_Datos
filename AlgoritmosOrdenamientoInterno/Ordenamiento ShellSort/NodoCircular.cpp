#include "NodoCircular.h"
NodoCircular::NodoCircular(){
    siguiente = NULL;
    anterior = NULL;
}
NodoCircular::~NodoCircular(){
}
Persona* NodoCircular::getPersona(){
    return persona;
}
NodoCircular* NodoCircular::getSiguiente(){
    return siguiente;
}
NodoCircular* NodoCircular::getAnterior(){
    return anterior;
}
void NodoCircular::setPersona(Persona* persona){
    this->persona = persona;
}
void NodoCircular::setSiguiente(NodoCircular* siguiente){
    this->siguiente = siguiente;
}
void NodoCircular::setAnterior(NodoCircular* anterior){
    this->anterior = anterior;
}
