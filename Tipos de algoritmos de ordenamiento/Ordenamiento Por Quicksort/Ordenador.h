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
    
    static void ordenarCaracteresEnAtributo(Nodo*& cabeza, const std::string& atributo);
    static void ordenarCaracteresEnAtributoCircular(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteres(std::string str);
    static void guardarCaracteresEnArchivo(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo);
    static void guardarCaracteresEnArchivoCircular(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo);
    static void ordenarCaracteresEnAtributoShellSort(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteresShellSort(std::string str);
    static void ordenarCaracteresShellSortCircular(Nodo*& cabeza, const std::string& atributo);
    static void intercambiarDatos(Nodo* a, Nodo* b);

    template <typename Compare>
    static void quickSort(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static void quickSortCircular(Nodo*& cabeza, Compare comp);

    template <typename Compare>
    static Nodo* particionar(Nodo* inicio, Nodo* fin, Compare comp);

    template <typename Compare>
    static void quickSortRec(Nodo* inicio, Nodo* fin, Compare comp);

    template <typename Compare>
    static void quickSortRecCircular(Nodo* inicio, Nodo* fin, Nodo* cabeza, Compare comp);
    static void ordenarCaracteresEnAtributoQuickSort(Nodo*& cabeza, const std::string& atributo);
    static std::string ordenarCaracteresQuickSort(std::string str);
    static void ordenarCaracteresQuickSortCircular(Nodo*& cabeza, const std::string& atributo);
    static void ordenarCaracteresEnAtributoQuickSortCircular(Nodo*& cabeza, const std::string& atributo);
 private:
};

#include "Ordenador.cpp"
#endif // ORDENADOR_H
