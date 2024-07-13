#include "Ordenador.h"
#include <algorithm>
#include <cctype>
#include <fstream>

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
/*
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
}*/