#ifndef NODODOBLE_H
#define NODODOBLE_H

#include "Persona.h"

class NodoDoble {
private:
    Persona* persona;
    NodoDoble* siguiente;
    NodoDoble* anterior;
public:
    NodoDoble(Persona* persona);
    Persona* getPersona();
    void setPersona(Persona* persona);
    NodoDoble* getSiguiente();
    void setSiguiente(NodoDoble* siguiente);
    NodoDoble* getAnterior();
    void setAnterior(NodoDoble* anterior);
};

#endif // NODODOBLE_H
