#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

template <typename T>
class NodoCircular {
private:
    T numCedula;
    T primerNombre;
    T apellido;
    NodoCircular* siguiente;

    T clave;
    T valor;
    NodoCircular* izquierda;
    NodoCircular* derecha;

public:
    NodoCircular(T, T, T);
    void setNumCedula(T);
    void setPrimerNombre(T);
    void setApellido(T);
    void setSiguiente(NodoCircular*);
    T getNumCedula();
    T getPrimerNombre();
    T getApellido();
    NodoCircular* getSiguiente();

        NodoCircular(T, T);
    void setClave(T);
    void setValor(T);
    void setIzquierda(NodoCircular*);
    void setDerecha(NodoCircular*);
    T getClave();
    T getValor();
    NodoCircular* getIzquierda();
    NodoCircular* getDerecha();
};

#include "NodoCircular.cpp"
#endif // NODOCIRCULAR_H
