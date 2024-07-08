#ifndef NODO_SIMPLE_H
#define NODO_SIMPLE_H

#include "Empleado.h"

class NodoSimple {
public:
    Empleado* data;
    NodoSimple* next;

    NodoSimple(Empleado* emp);
};

#endif
