/*Universidad de las Fuerzas Armadas Espe
Tema: Ordenamiento ShellSort
Autor: Christian Donoso, Stalin Roche, Joselin Villegas
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/
#ifndef SORTER_H
#define SORTER_H

#include <functional>

template <typename T, typename Nodo>
class Sorter {
public:
    static void shellSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar);
    static void shellSortString(string& str);
};
#endif // SORTER_H
