#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <string>

template <typename Nodo>
class Ordenador {
public:
    template <typename Compare>
    static void ordenarPorSeleccion(Nodo*& cabeza, Compare comp);

    static void ordenarCaracteresEnAtributo(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteres(std::string str);
    static void guardarCaracteresEnArchivo(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo);

private:
    static void intercambiarDatos(Nodo* a, Nodo* b);
};

#include "Ordenador.cpp"
#endif // ORDENADOR_H
