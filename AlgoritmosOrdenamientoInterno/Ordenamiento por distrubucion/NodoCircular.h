#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H
#include "Persona.h"
#include <iostream>
using namespace std;
class NodoCircular {
private:
    Persona* persona;
    NodoCircular* siguiente;
    NodoCircular* anterior;
public:
    NodoCircular();
    ~NodoCircular();
    Persona* getPersona();
    NodoCircular* getSiguiente();
    NodoCircular* getAnterior();
    void setPersona(Persona* persona);
    void setSiguiente(NodoCircular* siguiente);
    void setAnterior(NodoCircular* anterior);
};
#endif //NODOCIRCULAR_H
