#ifndef BUSCADOR_H
#define BUSCADOR_H

#include "../OrdenamientoPorIntercambio(1)/ListaSimple_Seleccion/NodoSimple.h"
#include "../OrdenamientoPorIntercambio(1)/ListaDoble_Seleccion/NodoDoble.h"
#include "../OrdenamientoPorIntercambio(1)/ListaCircular_Seleccion/NodoCircular.h"
#include <string>

template <typename Nodo>
class Buscador {
public:
    static void buscarSecuencial(Nodo* cabeza, const std::string& valor, const std::string& atributo);
};

#include "Buscador.cpp"
#endif // BUSCADOR_H