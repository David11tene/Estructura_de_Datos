#include "NodoDoble.h"

template <typename T>
NodoDoble<T>::NodoDoble(T numCedula, T primerNombre, T apellido) {
    this->numCedula = numCedula;
    this->primerNombre = primerNombre;
    this->apellido = apellido;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

template <typename T>
void NodoDoble<T>::setNumCedula(T numCedula) {
    this->numCedula = numCedula;
}

template <typename T>
void NodoDoble<T>::setPrimerNombre(T primerNombre) {
    this->primerNombre = primerNombre;
}

template <typename T>
void NodoDoble<T>::setApellido(T apellido) {
    this->apellido = apellido;
}

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble* siguiente) {
    this->siguiente = siguiente;
}

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble* anterior) {
    this->anterior = anterior;
}

template <typename T>
T NodoDoble<T>::getNumCedula() {
    return numCedula;
}

template <typename T>
T NodoDoble<T>::getPrimerNombre() {
    return primerNombre;
}

template <typename T>
T NodoDoble<T>::getApellido() {
    return apellido;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente() {
    return siguiente;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior() {
    return
     anterior;
}


template <typename T>
NodoDoble<T>::NodoDoble(T clave, T valor) : clave(clave), valor(valor), izquierda(nullptr), derecha(nullptr) {}

template <typename T>
void NodoDoble<T>::setClave(T clave) {
    this->clave = clave;
}

template <typename T>
void NodoDoble<T>::setValor(T valor) {
    this->valor = valor;
}

template <typename T>
void NodoDoble<T>::setIzquierda(NodoDoble* izquierda) {
    this->izquierda = izquierda;
}

template <typename T>
void NodoDoble<T>::setDerecha(NodoDoble* derecha) {
    this->derecha = derecha;
}

template <typename T>
T NodoDoble<T>::getClave() {
    return clave;
}

template <typename T>
T NodoDoble<T>::getValor() {
    return valor;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getIzquierda() {
    return izquierda;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getDerecha() {
    return derecha;
}
