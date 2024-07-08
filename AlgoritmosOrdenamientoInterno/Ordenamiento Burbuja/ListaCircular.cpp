#include "ListaCircular.h"
#include <fstream>
#include "NodoCircularDoble.h"
#include <Empleado.h>
#include "Persona.h"
//#include <NodoCarro.h>

ListaCircular::ListaCircular() : head(nullptr), size(0) {}

ListaCircular::~ListaCircular() {
    if (head) {
        NodoCircularDoble* current = head;
        do {
            NodoCircularDoble* nextNode = current->next;
            delete current->data;
            delete current;
            current = nextNode;
        } while (current != head);
    }
}

void ListaCircular::append(Empleado* emp) {
    NodoCircularDoble* newNode = new NodoCircularDoble(emp);
    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        NodoCircularDoble* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    ++size;
}

std::vector<Empleado*> ListaCircular::toVector() {
    std::vector<Empleado*> vec;
    if (head) {
        NodoCircularDoble* current = head;
        do {
            vec.push_back(current->data);
            current = current->next;
        } while (current != head);
    }
    return vec;
}

Empleado* ListaCircular::buscarPorCedula(const std::string& cedula) {
    if (head) {
        NodoCircularDoble* current = head;
        do {
            if (current->data->cedula == cedula) {
                return current->data;
            }
            current = current->next;
        } while (current != head);
    }
    return nullptr;
}

void ListaCircular::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (head) {
        NodoCircularDoble* current = head;
        do {
            file << current->data->cedula << " "
                 << current->data->nombre << " "
                 << current->data->apellido << " "
                 << current->data->nombreOrdenado << std::endl;
            current = current->next;
        } while (current != head);
    }
}
