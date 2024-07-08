#include "DoublyLinkedList.h"
#include <fstream>
#include <NodoDoble.h>
#include "NodoCircularDoble.h"
#include "NodoSimple.h"
#include <CircularDoublyLinkedList.h>
#include "ListaCircular.h"
#include "ListaDoble.h"
#include "ListaSimple.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    NodoDoble* current = head;
    while (current != nullptr) {
        NodoDoble* nextNode = current->next;
        delete current->data;
        delete current;
        current = nextNode;
    }
}

void DoublyLinkedList::append(Empleado* emp) {
    NodoDoble* newNode = new NodoDoble(emp);
    if (!head) {
        head = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    ++size;
}

std::vector<Empleado*> DoublyLinkedList::toVector() {
    std::vector<Empleado*> vec;
    NodoDoble* current = head;
    while (current != nullptr) {
        vec.push_back(current->data);
        current = current->next;
    }
    return vec;
}

Empleado* DoublyLinkedList::buscarPorCedula(const std::string& cedula) {
    NodoDoble* current = head;
    while (current != nullptr) {
        if (current->data->cedula == cedula) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void DoublyLinkedList::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    NodoDoble* current = head;
    while (current != nullptr) {
        file << current->data->cedula << " "
             << current->data->nombre << " "
             << current->data->apellido << " "
             << current->data->nombreOrdenado << std::endl;
        current = current->next;
    }
}
