#ifndef NODOSIMPLECIRCULAR_H
#define NODOSIMPLECIRCULAR_H

#include "Persona.h"

class NodoSimpleCircular {
private:
    Persona* persona;
    NodoSimpleCircular* siguiente;
public:
    NodoSimpleCircular(Persona* persona);
    Persona* getPersona();
    void setPersona(Persona* persona);
    NodoSimpleCircular* getSiguiente();
    void setSiguiente(NodoSimpleCircular* siguiente);
};

#endif // NODOSIMPLECIRCULAR_H
