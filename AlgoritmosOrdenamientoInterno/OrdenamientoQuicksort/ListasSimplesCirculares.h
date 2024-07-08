#ifndef LISTASSIMPLESCIRCULARES_H
#define LISTASSIMPLESCIRCULARES_H

#include "NodoSimpleCircular.h"
#include "Persona.h"
#include <iostream>
#include <string>

class ListaSimpleCircular {
private:
    NodoSimpleCircular* head;
public:
    ListaSimpleCircular();
    ~ListaSimpleCircular();

    void insertarInicio(Persona* persona);
    void insertarFinal(Persona* persona);
    void eliminarPersonaPorCedula(const std::string& cedula);
    NodoSimpleCircular* buscarPersona(const std::string& cedula) const;
    void mostrarLista() const;
    bool estaVacia() const;
};
#endif // LISTASSIMPLESCIRCULARES_H