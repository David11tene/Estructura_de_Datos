#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

#include "Persona.h"

class NodoSimple {
private:
    Persona* persona;
    NodoSimple* siguiente;
public:
    NodoSimple(Persona* persona);
    Persona* getPersona();
    void setPersona(Persona* persona);
    NodoSimple* getSiguiente();
    void setSiguiente(NodoSimple* siguiente);
};

#endif // NODOSIMPLE_H
