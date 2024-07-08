/*Universidad de las Fuerzas Armadas ESPE
Tema: Metodo de ordenamiento Burbuja
Autor: Alexander Diaz, Samantha Martinez y Jhoan Salazar
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/

#include "BubbleSort.h"
#include <type_traits>
#include "NodoCircularDoble.h"

template <typename T, typename Nodo>
void BubbleSort<T, Nodo>::bubbleSort(Nodo* primero, const std::function<bool(T*, T*)>& comparar) {
    if (primero == nullptr || primero->next == nullptr) {
        return;
    }

    bool swapped;
    Nodo* ptr1;
    Nodo* lptr = nullptr;

    // Verificar si la lista es circular
    bool esCircular = std::is_same_v<Nodo, NodoCircularDoble>;

    do {
        swapped = false;
        ptr1 = primero;

        while ((ptr1->next != lptr) && (esCircular || ptr1->next != nullptr)) {
            Nodo* siguiente = ptr1->next;
            if (comparar(ptr1->data, siguiente->data)) {
                T* temp = ptr1->data;
                ptr1->data = siguiente->data;
                siguiente->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped && (!esCircular || lptr != primero));
}

template <typename T, typename Nodo>
void BubbleSort<T, Nodo>::bubbleSortString(string& str) {
    int n = str.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}
