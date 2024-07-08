#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Empleado.h"
#include "NodoDoble.h"
#include <vector>

class DoublyLinkedList {
private:
    NodoDoble* head;
    NodoDoble* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(Empleado* emp);
    std::vector<Empleado*> toVector();
    Empleado* buscarPorCedula(const std::string& cedula);
    void saveToFile(const std::string& filename);
};

#endif
