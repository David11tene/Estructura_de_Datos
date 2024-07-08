#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include "Empleado.h"
#include "NodoCircularDoble.h"
#include <vector>

class ListaCircular {
private:
    NodoCircularDoble* head;
    int size;

public:
    ListaCircular();
    ~ListaCircular();
    void append(Empleado* emp);
    std::vector<Empleado*> toVector();
    Empleado* buscarPorCedula(const std::string& cedula);
    void saveToFile(const std::string& filename);
};

#endif
