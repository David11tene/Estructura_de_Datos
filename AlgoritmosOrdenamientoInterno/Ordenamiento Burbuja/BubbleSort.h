/*Universidad de las Fuerzas Armadas ESPE
Tema: Metodo de ordenamiento Burbuja
Autor: Alexander Diaz, Samantha Martinez y Jhoan Salazar
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <functional>
#include <string>
using namespace std;

template <typename T, typename Nodo>
class BubbleSort {
public:
    static void bubbleSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar);
    static void bubbleSortString(string& str);
};

#include "BubbleSort.cpp" // Include the implementation to avoid linker errors

#endif  // BUBBLESORT_H
