#include "NodoSimple.h"

template <typename T>
NodoSimple<T>::NodoSimple(T numCedula, T primerNombre, T apellido) {
    this->numCedula = numCedula;
    this->primerNombre = primerNombre;
    this->apellido = apellido;
    this->siguiente = nullptr;
}

template <typename T>
void NodoSimple<T>::setNumCedula(T numCedula) {
    this->numCedula = numCedula;
}

template <typename T>
void NodoSimple<T>::setPrimerNombre(T primerNombre) {
    this->primerNombre = primerNombre;
}

template <typename T>
void NodoSimple<T>::setApellido(T apellido) {
    this->apellido = apellido;
}

template <typename T>
void NodoSimple<T>::setSiguiente(NodoSimple* siguiente) {
    this->siguiente = siguiente;
}

template <typename T>
T NodoSimple<T>::getNumCedula() const {
    return numCedula;
}

template <typename T>
T NodoSimple<T>::getPrimerNombre() const {
    return primerNombre;
}

template <typename T>
T NodoSimple<T>::getApellido() const {
    return apellido;
}

template <typename T>
NodoSimple<T>* NodoSimple<T>::getSiguiente() const {
    return siguiente;
}

template <typename T>
NodoSimple<T>::NodoSimple(T clave, T valor) : clave(clave), valor(valor), izquierda(nullptr), derecha(nullptr) {}

template <typename T>
void NodoSimple<T>::setClave(T clave) {
    this->clave = clave;
}

template <typename T>
void NodoSimple<T>::setValor(T valor) {
    this->valor = valor;
}

template <typename T>
void NodoSimple<T>::setIzquierda(NodoSimple* izquierda) {
    this->izquierda = izquierda;
}

template <typename T>
void NodoSimple<T>::setDerecha(NodoSimple* derecha) {
    this->derecha = derecha;
}

template <typename T>
T NodoSimple<T>::getClave() const {
    return clave;
}

template <typename T>
T NodoSimple<T>::getValor() const {
    return valor;
}

template <typename T>
NodoSimple<T>* NodoSimple<T>::getIzquierda() const {
    return izquierda;
}

template <typename T>
NodoSimple<T>* NodoSimple<T>::getDerecha() const {
    return derecha;
}
