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

template class Buscador<NodoSimple<std::string>>;
template class Buscador<NodoDoble<std::string>>;
template class Buscador<NodoCircular<std::string>>;
