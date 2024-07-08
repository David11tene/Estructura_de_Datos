#ifndef NODO_CIRCULAR_DOBLE_H
#define NODO_CIRCULAR_DOBLE_H

#include "Empleado.h"

class NodoCircularDoble {
public:
    Empleado* data;
    NodoCircularDoble* next;
    NodoCircularDoble* prev;

    NodoCircularDoble(Empleado* emp);
};

#endif
