/*Universidad de las Fuerzas Armadas Espe
Tema: Ordenamiento ShellSort
Autor: Christian Donoso, Stalin Roche, Joselin Villegas
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/
#include "Sorter.h"
#include "NodoCircular.h"
template <typename T, typename Nodo>
void Sorter<T, Nodo>::shellSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar) {
    if (primero == nullptr || primero->getSiguiente() == nullptr) {
        return;
    }

    // Variables para determinar el final de la lista
    Nodo* temp = primero;
    int longitud = 0;

    // Calcular la longitud de la lista
    if constexpr (std::is_same_v<Nodo, NodoCircular>) {
        // Lista circular
        do {
            longitud++;
            temp = temp->getSiguiente();
        } while (temp != primero);
    } else {
        // Listas simples y dobles
        while (temp != nullptr) {
            longitud++;
            temp = temp->getSiguiente();
        }
    }

    // Inicializar la brecha para shell sort
    int brecha = longitud / 2;
    while (brecha > 0) {
        temp = primero;
        // Avanzar a la posición de la brecha
        for (int i = 0; i < brecha; ++i) {
            temp = temp->getSiguiente();
        }

        do {
            Nodo* temp2 = primero;
            T* valor = temp->getPersona();
            // Avanzar a la posición de inicio de comparación
            while (temp2 != temp && comparar(temp2->getPersona(), valor)) {
                temp2 = temp2->getSiguiente();
            }
            while (temp2 != temp) {
                T* siguienteValor = temp2->getPersona();
                temp2->setPersona(valor);
                valor = siguienteValor;
                temp2 = temp2->getSiguiente();
            }
            temp2->setPersona(valor);
            temp = temp->getSiguiente();
        } while (temp != primero && temp != nullptr);

        brecha = (brecha == 2) ? 1 : static_cast<int>(brecha / 2.2);
    }
}
template <typename T, typename Nodo>
void Sorter<T, Nodo>::shellSortString(string& str) {
    int n = str.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            char temp = *(str.data() + i);
            int j;
            for (j = i; j >= gap && *(str.data() + j - gap) > temp; j -= gap) {
                *(str.data() + j) = *(str.data() + j - gap);
            }
            *(str.data() + j) = temp;
        }
    }
}


