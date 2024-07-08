#include "Sorter.h"
#include <cctype>

template<typename T, typename Nodo>
void Sorter<T, Nodo>::countingSort(Nodo* &primero, const std::function<int(T*)>& obtenerClave, int rango) {
    // Implementación de Counting Sort
}

template<typename T, typename Nodo>
void Sorter<T, Nodo>::shellSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar) {
    // Implementación de Shell Sort
}

template<typename T, typename Nodo>
void Sorter<T, Nodo>::shellSortString(std::string& str) {
    int n = str.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = str[i];
            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) {
                str[j] = str[j - gap];
            }
            str[j] = temp;
        }
    }
}

template<typename T, typename Nodo>
void Sorter<T, Nodo>::convertirMinusculas(std::string& cadena) {
    for (auto& c : cadena) {
        c = std::tolower(c);
    }
}

// Instanciaciones explícitas para los tipos requeridos
template class Sorter<Persona, Nodo>;
template class Sorter<Persona, NodoDoble>;
template class Sorter<Persona, NodoCircular>;
template class Sorter<char, Nodo>;
template class Sorter<char, NodoDoble>;
template class Sorter<char, NodoCircular>;
