#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NodoCircular.h"
#include <iostream>
#include <functional>
using namespace std;

class ListaCircular {
private:
    NodoCircular* primero;
    NodoCircular* ultimo;
public:
    ListaCircular();
    ~ListaCircular();
    void insertar(Persona* persona);
    void guardarDatosPersona(Persona* persona);
    bool cargarDatosPersona();
    void mostrarDatosOrdenados();
    void imprimir();
    void ordenar(const function<int(Persona*)>& obtenerClave, int rango);
    void guardarDatosOrdenadosEnArchivo();
    void ordenarPorCaracter();
};
#endif // LISTACIRCULAR_H
