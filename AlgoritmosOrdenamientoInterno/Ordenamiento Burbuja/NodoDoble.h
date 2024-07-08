#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

#include "Empleado.h"

class NodoDoble {
public:
    Empleado* data;
    NodoDoble* next;
    NodoDoble* prev;

    NodoDoble(Empleado* emp);
};

#endif
