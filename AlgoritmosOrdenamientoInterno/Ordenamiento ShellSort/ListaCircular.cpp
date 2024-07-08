#include "ListaCircular.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ncurses.h>
#include <functional>
#include <curses.h>
#include "Sorter.h"
using namespace std;
ListaCircular::ListaCircular() {
    primero = nullptr;
    ultimo = nullptr;
}
ListaCircular::~ListaCircular() {
}
void ListaCircular::insertar(Persona* persona) {
    NodoCircular* nuevo = new NodoCircular();
    nuevo->setPersona(persona);
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
        primero->setSiguiente(ultimo);
        primero->setAnterior(ultimo);
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(primero);
        primero->setAnterior(nuevo);
        ultimo = nuevo;
        primero->setAnterior(ultimo);
    }
}
void ListaCircular::guardarDatosPersona(Persona* persona) {
    ofstream archivo("Personas.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Cedula: " << persona->getCedula()
                << "\tNombre: " << persona->getPrimerNombre();
        if (!persona->getSegundoNombre().empty()) {
            archivo << " " << persona->getSegundoNombre();
        }
        archivo << " " << persona->getApellido()
                << "\tCorreo: " << persona->getCorreo()
                << "\tContrasena: " << persona->getPassword() << endl;
        archivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}
bool ListaCircular::cargarDatosPersona() {
    bool hayPersonas = false;
    ifstream archivo("Personas.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string temp;
            ss >> temp;
            string cedula;
            ss >> cedula;
            ss >> temp;
            string nombreCompleto;
            getline(ss, nombreCompleto, '\t'); // Leer hasta el próximo tabulador

            // Leer correo y contraseña
            string correo, password;
            ss >> temp >> correo >> temp >> password;

            // Separar nombre completo en primer nombre, segundo nombre y apellido
            string primerNombre, segundoNombre, apellido;
            istringstream nombreStream(nombreCompleto);
            nombreStream >> primerNombre;
            if (nombreStream >> segundoNombre) {
                nombreStream >> apellido;
            } else {
                segundoNombre = "";
                apellido = primerNombre;
                primerNombre = "";
            }

            // Crear objeto Persona y establecer los valores
            Persona* persona = new Persona();
            persona->setCedula(cedula);
            persona->setPrimerNombre(primerNombre);
            persona->setSegundoNombre(segundoNombre);
            persona->setApellido(apellido);
            persona->setCorreo(correo);
            persona->setPassword(password);

            // Insertar persona en la lista
            insertar(persona);
            hayPersonas = true;
        }
        archivo.close();
    }
    return hayPersonas;
}

void ListaCircular::mostrarDatosOrdenados() {
    clear();
    NodoCircular* actual = primero;
    int row = 0;

    if (primero != nullptr) {
        do {
            Persona* persona = actual->getPersona();
            mvprintw(row++, 0, "Cedula: %s\tNombre: %s %s %s",
                     persona->getCedula().c_str(),
                     persona->getPrimerNombre().c_str(),
                     persona->getSegundoNombre().c_str(),
                     persona->getApellido().c_str());

            actual = actual->getSiguiente();
        } while (actual != primero);
        refresh();
        printw("Presione una tecla para continuar...");
        refresh();
        getch();
        clear();
    } else {
        printw("La lista está vacía.\nPresione una tecla para continuar...");
        refresh();
        getch();
        clear();
    }
}
void ListaCircular::imprimir() {
    clear();
    if (primero == nullptr) {
        printw("La lista está vacía.\n");
    } else {
        NodoCircular* actual = primero;
        do {
            Persona* persona = actual->getPersona();
            printw("Cedula: %s      Nombre: %s %s %s\n",
                   persona->getCedula().c_str(),
                   persona->getPrimerNombre().c_str(),
                   persona->getSegundoNombre().c_str(),
                   persona->getApellido().c_str());
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    refresh();
}

void ListaCircular::ordenar(const function<bool(Persona*, Persona*)>& comparar) {
    Sorter<Persona, NodoCircular>::shellSort(primero, comparar);
    guardarDatosOrdenadosEnArchivo();
}

void ListaCircular::guardarDatosOrdenadosEnArchivo() {
    ofstream archivo("Personas.txt", ios::trunc);  // Abrir el archivo en modo truncar para sobrescribir su contenido
    if (archivo.is_open()) {
        NodoCircular* actual = primero;
        if (actual != nullptr) {
            do {
                Persona* persona = actual->getPersona();
                archivo << "Cedula: " << persona->getCedula()
                        << "\tNombre: " << persona->getPrimerNombre();
                if (!persona->getSegundoNombre().empty()) {
                    archivo << " " << persona->getSegundoNombre();
                }
                archivo << " " << persona->getApellido()
                        << "\tCorreo: " << persona->getCorreo()
                        << "\tContrasena: " << persona->getPassword() << endl;
                actual = actual->getSiguiente();
            } while (actual != primero);
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}
void ListaCircular::ordenarPorCaracter() {
    // Abre un archivo para guardar los datos ordenados por caracter
    ofstream archivo("PersonasOrdenadasPorCaracter.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return;
    }

    if (primero == nullptr) {
        archivo.close();
        return;
    }

    NodoCircular* actual = primero;
    do {
        Persona* persona = actual->getPersona();

        // Obtener copias temporales de los nombres y convertir a minúsculas
        std::string primerNombre = persona->getPrimerNombre();
        std::string segundoNombre = persona->getSegundoNombre();
        std::string apellido = persona->getApellido();

        std::transform(primerNombre.begin(), primerNombre.end(), primerNombre.begin(), ::tolower);
        std::transform(segundoNombre.begin(), segundoNombre.end(), segundoNombre.begin(), ::tolower);
        std::transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);

        // Ordenar copias temporales por caracteres
        Sorter<char, NodoCircular>::shellSortString(primerNombre);
        Sorter<char, NodoCircular>::shellSortString(segundoNombre);
        Sorter<char, NodoCircular>::shellSortString(apellido);

        // Guardar en el archivo de salida ordenado por caracteres
        archivo << "Cedula: " << persona->getCedula()
                << "\tNombre: " << primerNombre << " "
                << segundoNombre << " "
                << apellido
                << "\tCorreo: " << persona->getCorreo()
                << "\tContrasena: " << persona->getPassword()
                << std::endl;

        actual = actual->getSiguiente();
    } while (actual != primero);
    archivo.close();
}

