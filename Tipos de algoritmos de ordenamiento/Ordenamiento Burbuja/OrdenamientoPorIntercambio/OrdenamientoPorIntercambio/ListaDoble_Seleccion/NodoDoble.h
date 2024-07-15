#ifndef NODODOBLE_H
#define NODODOBLE_H

template <typename T>
class NodoDoble {
private:
    T numCedula;
    T primerNombre;
    T apellido;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    T clave;
    T valor;
    NodoDoble* izquierda;
    NodoDoble* derecha;

public:
    NodoDoble(T, T, T);
    void setNumCedula(T);
    void setPrimerNombre(T);
    void setApellido(T);
    void setSiguiente(NodoDoble*);
    void setAnterior(NodoDoble*);
    T getNumCedula();
    T getPrimerNombre();
    T getApellido();
    NodoDoble* getSiguiente();
    NodoDoble* getAnterior();

        NodoDoble(T, T);
    void setClave(T);
    void setValor(T);
    void setIzquierda(NodoDoble*);
    void setDerecha(NodoDoble*);
    T getClave();
    T getValor();
    NodoDoble* getIzquierda();
    NodoDoble* getDerecha();
};

#include "NodoDoble.cpp"
#endif // NODODOBLE_H
