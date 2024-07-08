#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <functional>
#include "Nodo.cpp"
using namespace std;
class ListaSimple{
private:
    Nodo* primero;
public:
    ListaSimple();
    ~ListaSimple();
    Nodo* getPrimero();
    void insertar(Persona* persona);
    void guardarDatosPersona(Persona* persona);
    bool cargarDatosPersona();
    void mostrarDatosOrdenados();
    void imprimir();
    void ordenar(const std::function<bool(Persona*, Persona*)>& comparar);
    void guardarDatosOrdenadosEnArchivo();
    void ordenarPorCaracter();
};
#endif //LISTASIMPLE_H