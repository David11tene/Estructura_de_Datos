#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <string>

template <typename Nodo>
class Ordenador {
public:
    template <typename Compare>
    static void ordenarPorSeleccion(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static void ordenarPorSeleccionCircular(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static void shellSort(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static void shellSortCircular(Nodo*& cabeza, Compare comp);

        template <typename Compare>
    static void burbuja(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static void burbujaCircular(Nodo*& cabeza, Compare comp);
    
    static void ordenarCaracteresEnAtributo(Nodo*& cabeza, const std::string& atributo);
    static void ordenarCaracteresEnAtributoCircular(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteres(std::string str);
    static void guardarCaracteresEnArchivo(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo);
    static void guardarCaracteresEnArchivoCircular(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo);
    static void ordenarCaracteresEnAtributoShellSort(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteresShellSort(std::string str);
    static void ordenarCaracteresShellSortCircular(Nodo*& cabeza, const std::string& atributo);
     static void ordenarCaracteresEnAtributoBurbuja(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteresBurbuja(std::string str);
    static void ordenarCaracteresBurbujaCircular(Nodo*& cabeza, const std::string& atributo);
    
private:
    static void intercambiarDatos(Nodo* a, Nodo* b);
};

#include "Ordenador.cpp"
#endif // ORDENADOR_H
