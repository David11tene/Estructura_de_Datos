#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

template <typename T>
class NodoSimple {
private:
    T numCedula;
    T primerNombre;
    T apellido;
    NodoSimple* siguiente;

    T clave;
    T valor;
    NodoSimple* izquierda;
    NodoSimple* derecha;

public:
    NodoSimple(T, T, T);
    void setNumCedula(T);
    void setPrimerNombre(T);
    void setApellido(T);
    void setSiguiente(NodoSimple*);
    T getNumCedula() const;
    T getPrimerNombre() const;
    T getApellido() const;
    NodoSimple* getSiguiente() const;

    NodoSimple(T, T);
    void setClave(T);
    void setValor(T);
    void setIzquierda(NodoSimple*);
    void setDerecha(NodoSimple*);
    T getClave() const;
    T getValor() const;
    NodoSimple* getIzquierda() const;
    NodoSimple* getDerecha() const;
};

#include "NodoSimple.cpp"
#endif // NODOSIMPLE_H
