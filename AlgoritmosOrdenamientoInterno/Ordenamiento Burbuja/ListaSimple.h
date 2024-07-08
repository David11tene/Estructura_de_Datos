#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "Empleado.h"
#include "NodoSimple.h"
#include <vector>

class SinglyLinkedList {
private:
    NodoSimple* head;
    NodoSimple* tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void append(Empleado* emp);
    std::vector<Empleado*> toVector();
    Empleado* buscarPorCedula(const std::string& cedula);
    void saveToFile(const std::string& filename);
};

#endif
