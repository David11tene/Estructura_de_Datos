#include "ListaDoble.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ncurses.h>
#include "Sorter.h"
using namespace std;

ListaDoble::ListaDoble() {
    primero = nullptr;
    ultimo = nullptr;
}

ListaDoble::~ListaDoble() {
    NodoDoble* actual = primero;
    while (actual != nullptr) {
        NodoDoble* temp = actual;
        actual = actual->getSiguiente();
        delete temp;
    }
}

void ListaDoble::insertar(Persona* persona) {
    NodoDoble* nuevo = new NodoDoble();
    nuevo->setPersona(persona);
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

void ListaDoble::guardarDatosPersona(Persona* persona) {
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

bool ListaDoble::cargarDatosPersona() {
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
            getline(ss, nombreCompleto, '\t');

            string correo, password;
            ss >> temp >> correo >> temp >> password;

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

            Persona* persona = new Persona();
            persona->setCedula(cedula);
            persona->setPrimerNombre(primerNombre);
            persona->setSegundoNombre(segundoNombre);
            persona->setApellido(apellido);
            persona->setCorreo(correo);
            persona->setPassword(password);

            insertar(persona);
            hayPersonas = true;
        }
        archivo.close();
    }
    return hayPersonas;
}

void ListaDoble::mostrarDatosOrdenados() {
    clear();
    NodoDoble* actual = primero;
    int row = 0;
    
    while (actual != nullptr) {
        Persona* persona = actual->getPersona();
        mvprintw(row++, 0, "Cedula: %s\tNombre: %s %s %s", 
                 persona->getCedula().c_str(), 
                 persona->getPrimerNombre().c_str(),
                 persona->getSegundoNombre().c_str(),
                 persona->getApellido().c_str());

        actual = actual->getSiguiente();
    }
    
    refresh();
    printw("Presione una tecla para continuar...");
    refresh();
    getch();
    clear();
}

void ListaDoble::imprimir() {
    clear();
    NodoDoble* actual = primero;
    while (actual != nullptr) {
        Persona* persona = actual->getPersona();
        printw("Cedula: %s      Nombre: %s %s %s\n",
               persona->getCedula().c_str(),
               persona->getPrimerNombre().c_str(),
               persona->getSegundoNombre().c_str(),
               persona->getApellido().c_str());
        actual = actual->getSiguiente();
    }
    refresh();
}

void ListaDoble::ordenar(const function<int(Persona*)>& obtenerClave, int rango) {
    Sorter<Persona, NodoDoble>::countingSort(primero, obtenerClave, rango);
    guardarDatosOrdenadosEnArchivo();
}

void ListaDoble::guardarDatosOrdenadosEnArchivo() {
    ofstream archivo("Personas.txt", ios::trunc);
    if (archivo.is_open()) {
        NodoDoble* actual = primero;
        while (actual != nullptr) {
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
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

void ListaDoble::ordenarPorCaracter() {
    ofstream archivo("PersonasOrdenadasPorCaracter.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de salida." << endl;
        return;
    }

    NodoDoble* actual = primero;
    while (actual != nullptr) {
        Persona* persona = actual->getPersona();

        std::string primerNombre = persona->getPrimerNombre();
        std::string segundoNombre = persona->getSegundoNombre();
        std::string apellido = persona->getApellido();

        std::transform(primerNombre.begin(), primerNombre.end(), primerNombre.begin(), ::tolower);
        std::transform(segundoNombre.begin(), segundoNombre.end(), segundoNombre.begin(), ::tolower);
        std::transform(apellido.begin(), apellido.end(), apellido.begin(), ::tolower);

        Sorter<char, NodoDoble>::countingSortString(primerNombre);
        Sorter<char, NodoDoble>::countingSortString(segundoNombre);
        Sorter<char, NodoDoble>::countingSortString(apellido);

        archivo << "Cedula: " << persona->getCedula()
                << "\tNombre: " << primerNombre << " "
                << segundoNombre << " "
                << apellido
                << "\tCorreo: " << persona->getCorreo()
                << "\tContrasena: " << persona->getPassword()
                << std::endl;

        actual = actual->getSiguiente();
    }
    archivo.close();
}
