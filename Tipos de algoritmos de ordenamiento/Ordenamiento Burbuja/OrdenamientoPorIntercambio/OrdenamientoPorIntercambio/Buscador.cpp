#include "Buscador.h"

template <typename Nodo>
void Buscador<Nodo>::buscarSecuencial(Nodo* cabeza, const std::string& valor, const std::string& atributo) {
    if (!cabeza) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    Nodo* actual = cabeza;
    bool encontrado = false;
    bool esCircular = false;

    Nodo* temp = cabeza;
    while (temp != nullptr) {
        if (temp->getSiguiente() == cabeza) {
            esCircular = true;
            break;
        }
        temp = temp->getSiguiente();
    }

    do {
        if ((atributo == "cedula" && actual->getNumCedula() == valor) ||
            (atributo == "nombre" && actual->getPrimerNombre() == valor) ||
            (atributo == "apellido" && actual->getApellido() == valor)) {
            std::cout << "Usuario encontrado: " << actual->getNumCedula() << " " << actual->getPrimerNombre() << " " << actual->getApellido() << std::endl;
            encontrado = true;
        }
        actual = actual->getSiguiente();
    } while (actual != nullptr && (!esCircular || actual != cabeza));

    if (!encontrado) {
        std::cout << "Usuario no encontrado." << std::endl;
    }
}


//BUSCADOR BINARIO
template <typename Nodo>
void Buscador<Nodo>::buscarBinario(Nodo* cabeza, const std::string& valor, const std::string& atributo) {
    if (!cabeza) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    // Contar el número de nodos en la lista
    int length = 0;
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        ++length;
        temp = temp->getSiguiente();
    }

    int inicio = 0;
    int fin = length - 1;
    bool encontrado = false;

    // Función interna para avanzar un número dado de pasos en la lista
    auto avanzar = [](Nodo* nodo, int pasos) -> Nodo* {
        while (pasos-- > 0 && nodo != nullptr) {
            nodo = nodo->getSiguiente();
        }
        return nodo;
    };

    // Función interna para comparar el valor de un atributo del nodo con el valor buscado
    auto comparar = [](Nodo* nodo, const std::string& valor, const std::string& atributo) -> int {
        if (atributo == "cedula") {
            return nodo->getNumCedula().compare(valor);
        } else if (atributo == "nombre") {
            return nodo->getPrimerNombre().compare(valor);
        } else if (atributo == "apellido") {
            return nodo->getApellido().compare(valor);
        }
        return 1; // Asumimos que los atributos válidos siempre serán "cedula", "nombre" o "apellido"
    };

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        Nodo* nodoMedio = avanzar(cabeza, medio);
        int comp = comparar(nodoMedio, valor, atributo);

        if (comp == 0) {
            std::cout << "Usuario encontrado: " << nodoMedio->getNumCedula() << " " << nodoMedio->getPrimerNombre() << " " << nodoMedio->getApellido() << std::endl;
            encontrado = true;
            break;
        } else if (comp < 0) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (!encontrado) {
        std::cout << "Usuario no encontrado." << std::endl;
    }
}

template class Buscador<NodoSimple<std::string>>;
template class Buscador<NodoDoble<std::string>>;
template class Buscador<NodoCircular<std::string>>;

// Especialización de la plantilla para compilar el código
//template void Buscador<Nodo>::buscarBinario<Nodo>(Nodo* cabeza, const std::string& valor, const std::string& atributo);
