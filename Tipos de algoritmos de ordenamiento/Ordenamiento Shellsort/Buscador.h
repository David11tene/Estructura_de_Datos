#ifndef BUSCADOR_H
#define BUSCADOR_H

#include "../OrdenamientoShellsort/ListaSimple/NodoSimple.h"
#include "../OrdenamientoShellsort/ListaDoble/NodoDoble.h"
#include "../OrdenamientoShellsort/ListaCircular/NodoCircular.h"
#include <string>

template <typename Nodo>
class Buscador {
public:
    static void buscarTablasHash(Nodo* cabeza, const std::string& valor, const std::string& atributo);
};

#include "Buscador.cpp"
#endif // BUSCADOR_H
