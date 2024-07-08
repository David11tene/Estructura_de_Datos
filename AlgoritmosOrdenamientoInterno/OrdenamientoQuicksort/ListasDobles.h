#pragma once
#ifndef LISTASDOBLES_H
#define LISTASDOBLES_H

#include "NodoDoble.h"
#include "Persona.h"
#include <iostream>
#include <string>

class ListaDoble {
private:
    NodoDoble* head;
public:
    ListaDoble();
    ~ListaDoble();

    void insertarInicio(Persona* persona);
    void insertarFinal(Persona* persona);
    void eliminarPersonaPorCedula(const std::string& cedula);
    NodoDoble* buscarPersona(const std::string& cedula) const;
    void mostrarLista() const;
    bool estaVacia() const;
};
#endif // LISTASDOBLES_H

