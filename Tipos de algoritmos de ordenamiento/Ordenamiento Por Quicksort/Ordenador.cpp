#include "Ordenador.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>

template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::ordenarPorSeleccion(Nodo*& cabeza, Compare comp) {
    if (!cabeza) return;
    Nodo* i = cabeza;
    while (i) {
        Nodo* min = i;
        Nodo* j = i->getSiguiente();
        while (j) {
            if (comp(j, min)) {
                min = j;
            }
            j = j->getSiguiente();
        }
        if (min != i) {
            intercambiarDatos(i, min);
        }
        i = i->getSiguiente();
    }
}

template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::ordenarPorSeleccionCircular(Nodo*& cabeza, Compare comp) {
    if (!cabeza) return;
    Nodo* i = cabeza;
    do {
        Nodo* min = i;
        Nodo* j = i->getSiguiente();
        do {
            if (comp(j, min)) {
                min = j;
            }
            j = j->getSiguiente();
        } while (j != cabeza);

        if (min != i) {
            intercambiarDatos(i, min);
        }
        i = i->getSiguiente();
    } while (i != cabeza);
}

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

template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresEnAtributo(Nodo*& cabeza, const std::string& atributo) {
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            aux->setNumCedula(ordenarCaracteres(aux->getNumCedula()));
        } else if (atributo == "nombre") {
            aux->setPrimerNombre(ordenarCaracteres(aux->getPrimerNombre()));
        } else if (atributo == "apellido") {
            aux->setApellido(ordenarCaracteres(aux->getApellido()));
        }
        aux = aux->getSiguiente();
    }
}

template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresEnAtributoCircular(Nodo*& cabeza, const std::string& atributo) {
    if (!cabeza) return;
    Nodo* aux = cabeza;
    do {
        if (atributo == "cedula") {
            aux->setNumCedula(ordenarCaracteres(aux->getNumCedula()));
        } else if (atributo == "nombre") {
            aux->setPrimerNombre(ordenarCaracteres(aux->getPrimerNombre()));
        } else if (atributo == "apellido") {
            aux->setApellido(ordenarCaracteres(aux->getApellido()));
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);
}

template <typename Nodo>
std::string Ordenador<Nodo>::ordenarCaracteres(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::sort(str.begin(), str.end());
    return str;
}

template <typename Nodo>
void Ordenador<Nodo>::guardarCaracteresEnArchivo(Nodo* cabeza, const std::string& nombreArchivo, const std::string& atributo) {
    std::ofstream archivo(nombreArchivo);
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            archivo << ordenarCaracteres(aux->getNumCedula()) << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "nombre") {
            archivo << aux->getNumCedula() << "|" << ordenarCaracteres(aux->getPrimerNombre()) << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "apellido") {
            archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << ordenarCaracteres(aux->getApellido()) << std::endl;
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
            archivo << ordenarCaracteres(aux->getNumCedula()) << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "nombre") {
            archivo << aux->getNumCedula() << "|" << ordenarCaracteres(aux->getPrimerNombre()) << "|" << aux->getApellido() << std::endl;
        } else if (atributo == "apellido") {
            archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << ordenarCaracteres(aux->getApellido()) << std::endl;
        }
        aux = aux->getSiguiente();
    } while (aux != cabeza);
    archivo.close();
}
//Metodos de ordenamiento shell sort
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


// Partition function for circular linked list
template <typename Nodo>
template <typename Compare>
Nodo* Ordenador<Nodo>::particionar(Nodo* inicio, Nodo* fin, Compare comp) {
    Nodo* pivot = fin;
    Nodo* i = inicio;

    for (Nodo* j = inicio; j != fin; j = j->getSiguiente()) {
        if (comp(j, pivot)) {
            intercambiarDatos(i, j);
            i = i->getSiguiente();
        }
    }
    intercambiarDatos(i, fin);
    return i;
}

template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresEnAtributoQuickSort(Nodo*& cabeza, const std::string& atributo) {
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            aux->setNumCedula(ordenarCaracteresQuickSort(aux->getNumCedula()));
        }
        else if (atributo == "nombre") {
            aux->setPrimerNombre(ordenarCaracteresQuickSort(aux->getPrimerNombre()));
        }
        else if (atributo == "apellido") {
            aux->setApellido(ordenarCaracteresQuickSort(aux->getApellido()));
        }
        aux = aux->getSiguiente();
    }
}

template <typename Nodo>
std::string Ordenador<Nodo>::ordenarCaracteresQuickSort(std::string str) {
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
void Ordenador<Nodo>::ordenarCaracteresQuickSortCircular(Nodo*& cabeza, const std::string& atributo) {
    Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
            std::string cedulaOrdenada = ordenarCaracteresQuickSort(aux->getNumCedula());
            aux->setNumCedula(cedulaOrdenada);
        }
        else if (atributo == "nombre") {
            std::string nombreOrdenado = ordenarCaracteresQuickSort(aux->getPrimerNombre());
            aux->setPrimerNombre(nombreOrdenado);
        }
        else if (atributo == "apellido") {
            std::string apellidoOrdenado = ordenarCaracteresQuickSort(aux->getApellido());
            aux->setApellido(apellidoOrdenado);
        }
        aux = aux->getSiguiente();
        if (aux == cabeza) break;
    }
}

template <typename Nodo>
void Ordenador<Nodo>::ordenarCaracteresEnAtributoQuickSortCircular(Nodo*& cabeza, const std::string& atributo) {
	Nodo* aux = cabeza;
    while (aux) {
        if (atributo == "cedula") {
			aux->setNumCedula(ordenarCaracteresQuickSort(aux->getNumCedula()));
		}
        else if (atributo == "nombre") {
			aux->setPrimerNombre(ordenarCaracteresQuickSort(aux->getPrimerNombre()));
		}
        else if (atributo == "apellido") {
			aux->setApellido(ordenarCaracteresQuickSort(aux->getApellido()));
		}
		aux = aux->getSiguiente();
		if (aux == cabeza) break;
	}
}
// Quick Sort for singly linked list
template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::quickSort(Nodo*& cabeza, Compare comp) {
    if (!cabeza || !cabeza->getSiguiente()) return;
    Nodo* fin = cabeza;
    while (fin->getSiguiente()) fin = fin->getSiguiente();
    quickSortRec(cabeza, fin, comp);
}

template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::quickSortRec(Nodo* inicio, Nodo* fin, Compare comp) {
    if (fin != nullptr && inicio != fin && inicio != fin->getSiguiente()) {
        Nodo* pivot = particionar(inicio, fin, comp);
        if (pivot != inicio) {
            Nodo* prev = inicio;
            while (prev->getSiguiente() != pivot) {
                prev = prev->getSiguiente();
            }
            quickSortRec(inicio, prev, comp);
        }
        if (pivot != fin) {
            quickSortRec(pivot->getSiguiente(), fin, comp);
        }
    }
}

template <typename Nodo>
template <typename Compare>
void Ordenador<Nodo>::quickSortCircular(Nodo*& cabeza, Compare comp) {
    Nodo* high = nullptr;
    Nodo* traverse = cabeza;
    int length = 0;

    do {
        high = traverse;
        traverse = traverse->getSiguiente();
        length++;
    } while (traverse != cabeza);

    if (!cabeza) return;

    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; ++i) {
            Nodo* current = cabeza;
            for (int j = 0; j < i; ++j) {
                current = current->getSiguiente();
            }

            Nodo* left = current;
            Nodo* right = nullptr;
            for (int j = i; j >= gap; j -= gap) {
                right = cabeza;
                for (int k = 0; k < j - gap; ++k) {
                    right = right->getSiguiente();
                }

                if (comp(left, right)) {
                    intercambiarDatos(left, right);
                }
                else {
                    break;
                }
                left = right;
            }
        }
    }
}