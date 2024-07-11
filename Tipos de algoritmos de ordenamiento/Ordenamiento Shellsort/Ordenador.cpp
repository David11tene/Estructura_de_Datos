#include "Ordenador.h"
#include <algorithm>
#include <cctype>
#include <fstream>
/*----------METODOS----------*/
template <typename Nodo>
void Ordenador<Nodo>::intercambiarDatos(Nodo* a, Nodo* b) {
    auto tempNumCedula = a->getNumCedula();
    auto tempPrimerNombre = a->getPrimerNombre();
    auto tempApellido = a->getApellido();

    a->setNumCedula(b->getNumCedula());
    a->setPrimerNombre(b->getPrimerNombre());
    a->setApellido(b->getApellido());

    b->setNumCedula(tempNumCedula);
    b->setPrimerNombre(tempPrimerNombre);
    b->setApellido(tempApellido);
}
/*----------METODO DE ORDENENAMIENTO SHELLSORT----------*/
template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::shellSort(Nodo*& cabeza, Compare comp) {
    if (!cabeza) return;

    int n = 0;
    Nodo* temp = cabeza;
    while (temp) {
        n++;
        temp = temp->getSiguiente();
    }

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            Nodo* current = cabeza;
            for (int j = 0; j < i; ++j) {
                current = current->getSiguiente();
            }

            Nodo* temp2 = current;
            Nodo* temp3 = nullptr;
            for (int j = i; j >= gap; j -= gap) {
                temp3 = cabeza;
                for (int k = 0; k < j - gap; ++k) {
                    temp3 = temp3->getSiguiente();
                }

                if (comp(temp2, temp3)) {
                    intercambiarDatos(temp2, temp3);
                } else {
                    break;
                }
                temp2 = temp3;
            }
        }
    }
}

template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::shellSortCircular(Nodo*& cabeza, Compare comp) {
    if (!cabeza) return;

    Nodo* ultimo = nullptr;
    Nodo* temp = cabeza;
    int n = 0;

    do {
        ultimo = temp;
        temp = temp->getSiguiente();
        n++;
    } while (temp != cabeza);

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            Nodo* current = cabeza;
            for (int j = 0; j < i; ++j) {
                current = current->getSiguiente();
            }

            Nodo* temp2 = current;
            Nodo* temp3 = nullptr;
            for (int j = i; j >= gap; j -= gap) {
                temp3 = cabeza;
                for (int k = 0; k < j - gap; ++k) {
                    temp3 = temp3->getSiguiente();
                }

                if (comp(temp2, temp3)) {
                    intercambiarDatos(temp2, temp3);
                } else {
                    break;
                }
                temp2 = temp3;
            }
        }
    }
}

template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresEnAtributoShellSort(Nodo*& cabeza, const std::string& atributo) {
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            aux->setNumCedula(ordenarCaracteresShellSort(aux->getNumCedula()));
        } else if (atributo == "nombre") {
            aux->setPrimerNombre(ordenarCaracteresShellSort(aux->getPrimerNombre()));
        } else if (atributo == "apellido") {
            aux->setApellido(ordenarCaracteresShellSort(aux->getApellido()));
        }
        aux = aux->getSiguiente();
    }
}
template <typename Nodo>
std::string Ordenador<Nodo>::ordenarCaracteresShellSort(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    char* char_ptr = &(*str.begin());
    int n = str.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            char temp = *(char_ptr + i);
            int j = i;
            for (; j >= gap && *(char_ptr + j - gap) > temp; j -= gap) {
                *(char_ptr + j) = *(char_ptr + j - gap);
            }
            *(char_ptr + j) = temp;
        }
    }
    
    return str;
}
template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresShellSortCircular(Nodo*& cabeza, const std::string& atributo) {
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            std::string cedulaOrdenada = ordenarCaracteresShellSort(aux->getNumCedula());
            aux->setNumCedula(cedulaOrdenada);
        } else if (atributo == "nombre") {
            std::string nombreOrdenado = ordenarCaracteresShellSort(aux->getPrimerNombre());
            aux->setPrimerNombre(nombreOrdenado);
        } else if (atributo == "apellido") {
            std::string apellidoOrdenado = ordenarCaracteresShellSort(aux->getApellido());
            aux->setApellido(apellidoOrdenado);
        }
        aux = aux->getSiguiente();
        if (aux == cabeza) break;
    }
}
template <typename Nodo>
void Ordenador<Nodo>::guardarCaracteresEnArchivo(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo) {
    std::ofstream archivo(nombreArchivo);
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            archivo << ordenarCaracteresShellSort(aux->getNumCedula()) << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "nombre") {
            archivo << aux->getNumCedula() << "|" << ordenarCaracteresShellSort(aux->getPrimerNombre()) << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "apellido") {
            archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << ordenarCaracteresShellSort(aux->getApellido()) << std::endl;
        }
        aux = aux->getSiguiente();
    }
    archivo.close();
}

template <typename Nodo>
void Ordenador<Nodo>::guardarCaracteresEnArchivoCircular(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo) {
    std::ofstream archivo(nombreArchivo);
    Nodo* aux = cabeza;
    do {
        if (atributo == "cedula") {
            archivo << ordenarCaracteresShellSort(aux->getNumCedula()) << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "nombre") {
            archivo << aux->getNumCedula() << "|" << ordenarCaracteresShellSort(aux->getPrimerNombre()) << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "apellido") {
            archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << ordenarCaracteresShellSort(aux->getApellido()) << std::endl;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);
    archivo.close();
}