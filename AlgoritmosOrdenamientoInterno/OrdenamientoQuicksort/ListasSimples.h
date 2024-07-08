#ifndef LISTASSIMPLES_H
#define LISTASSIMPLES_H

#include "NodoSimple.h"
#include "NodoSimpleCircular.h"
#include "Persona.h"
#include <iostream>
#include <string>

class ListaSimple {
private:
    NodoSimple* head;
public:
    ListaSimple();
    ~ListaSimple();

    void insertarInicio(Persona* persona);
    void insertarFinal(Persona* persona);
    void eliminarPersonaPorCedula(const std::string& cedula);
    NodoSimple* buscarPersona(const std::string& cedula) const;
    void mostrarLista() const;
    bool estaVacia() const;
};
#endif // LISTASSIMPLES_H
