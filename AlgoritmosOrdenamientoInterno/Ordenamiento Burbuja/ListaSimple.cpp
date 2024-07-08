#include "SinglyLinkedList.h"
#include <fstream>
#include "NodoSimple.h"
#include <DoublyLinkedList.h>
#include "ListaDoble.h"
#include "ListaSimple.h"

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    NodoSimple* current = head;
    while (current != nullptr) {
        NodoSimple* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
}

void SinglyLinkedList::append(Empleado* emp) {
    NodoSimple* newNode = new NodoSimple(emp);
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
    ++size;
}

std::vector<Empleado*> SinglyLinkedList::toVector() {
    std::vector<Empleado*> vec;
    NodoSimple* current = head;
    while (current != nullptr) {
        vec.push_back(current->data);
        current = current->next;
    }
    return vec;
}

Empleado* SinglyLinkedList::buscarPorCedula(const std::string& cedula) {
    NodoSimple* current = head;
    while (current != nullptr) {
        if (current->data->cedula == cedula) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void SinglyLinkedList::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    NodoSimple* current = head;
    while (current != nullptr) {
        file << current->data->cedula << " "
             << current->data->nombre << " "
             << current->data->apellido << " "
             << current->data->nombreOrdenado << std::endl;
        current = current->next;
    }
}
