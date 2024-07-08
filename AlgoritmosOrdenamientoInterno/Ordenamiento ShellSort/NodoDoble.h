#ifndef NODODOBLE_H
#define NODODOBLE_H
#include <iostream>
#include "Persona.h"
using namespace std;
class NodoDoble {
private:
    Persona* persona;
    NodoDoble* siguiente;
    NodoDoble* anterior;

public:
    NodoDoble();
    ~NodoDoble();
    NodoDoble* getSiguiente();
    Persona* getPersona();
    void setSiguiente(NodoDoble* siguiente);
    void setPersona(Persona* persona);
    NodoDoble* getAnterior();
    void setAnterior(NodoDoble* anterior);
};
#endif //NODODOBLE_H