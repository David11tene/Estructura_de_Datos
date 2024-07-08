#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <functional>
#include "NodoDoble.h"
using namespace std;

class ListaDoble {
private:
    NodoDoble* primero;
    NodoDoble* ultimo;
public:
    ListaDoble();
    ~ListaDoble();
    void insertar(Persona* persona);
    void guardarDatosPersona(Persona* persona);
    bool cargarDatosPersona();
    void mostrarDatosOrdenados();
    void imprimir();
    void ordenar(const function<int(Persona*)>& obtenerClave, int rango);
    void guardarDatosOrdenadosEnArchivo();
    void ordenarPorCaracter();
};
#endif // LISTADOBLE_H
