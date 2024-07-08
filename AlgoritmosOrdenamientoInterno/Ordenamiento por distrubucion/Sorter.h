#ifndef SORTER_H
#define SORTER_H

#include <functional>
#include <string>
#include <type_traits>
#include <vector>

template<typename T, typename Nodo>
class Sorter {
public:
    static void countingSort(Nodo* &primero, const std::function<int(T*)>& obtenerClave, int rango);
    static void shellSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar);
    static void shellSortString(std::string& str);

private:
    static void convertirMinusculas(std::string& cadena);
};

#endif // SORTER_H
