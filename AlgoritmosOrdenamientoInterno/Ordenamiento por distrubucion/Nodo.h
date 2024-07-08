#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Persona.h"
using namespace std;
class Nodo{
private:
    Nodo* siguiente;
    Persona* persona;
public:
    Nodo();
    ~Nodo();
    Nodo* getSiguiente();
    Persona* getPersona();
    void setSiguiente(Nodo* siguiente);
    void setPersona(Persona* persona);
};
#endif //NODO_H
