#ifndef BUSCADOR_H
#define BUSCADOR_H

#include "../OrdenamientoPorIntercambio/ListaSimple_Seleccion/NodoSimple.h"
#include "../OrdenamientoPorIntercambio/ListaDoble_Seleccion/NodoDoble.h"
#include "../OrdenamientoPorIntercambio/ListaCircular_Seleccion/NodoCircular.h"
#include <string>

template <typename Nodo>
class Buscador {
public:
    static void buscarSecuencial(Nodo* cabeza, const std::string& valor, const std::string& atributo);
    static void buscarBinario(Nodo* cabeza, const std::string& valor, const std::string& atributo);

};

#include "Buscador.cpp"
#endif // BUSCADOR_H