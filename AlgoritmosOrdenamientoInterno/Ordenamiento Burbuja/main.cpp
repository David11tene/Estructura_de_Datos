/*Universidad de las Fuerzas Armadas ESPE
Tema: Metodo de ordenamiento Burbuja
Autor: Alexander Diaz, Samantha Martinez y Jhoan Salazar
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularDoublyLinkedList.h"
#include "Empleado.h"
#include "Persona.h"

using namespace std;

bool validarCedula(const string& cedula) {
    return cedula.size() == 10 && all_of(cedula.begin(), cedula.end(), ::isdigit);
}

bool validarNombreApellido(const string& nombre) {
    return all_of(nombre.begin(), nombre.end(), ::isalpha);
}

string ordenarCaracteres(const string& nombre) {
    string ordenado = nombre;
    sort(ordenado.begin(), ordenado.end());
    return ordenado;
}

template <typename Lista>
void agregarEmpleado(Lista& empleados, set<string>& cedulasExistentes, int& ultimoID) {
    string cedula, nombre, apellido;
    cout << "Ingrese la cédula (10 dígitos): ";
    cin >> cedula;
    if (!validarCedula(cedula) || cedulasExistentes.count(cedula)) {
        cout << "Cédula inválida o ya existente." << endl;
        return;
    }

    cout << "Ingrese el primer nombre: ";
    cin >> nombre;
    if (!validarNombreApellido(nombre)) {
        cout << "Nombre inválido." << endl;
        return;
    }

    cout << "Ingrese el apellido: ";
    cin >> apellido;
    if (!validarNombreApellido(apellido)) {
        cout << "Apellido inválido." << endl;
        return;
    }

    string nombreOrdenado = ordenarCaracteres(nombre + apellido);
    Empleado* nuevoEmpleado = new Empleado(cedula, nombre, apellido, nombreOrdenado);
    empleados.append(nuevoEmpleado);
    cedulasExistentes.insert(cedula);
}

template <typename Lista>
void cargarDatosExistentes(const string& filename, set<string>& cedulasExistentes, Lista& empleados, int& ultimoID) {
    ifstream file(filename);
    if (!file) {
        return;
    }

    string cedula, nombre, apellido, nombreOrdenado;
    while (file >> cedula >> nombre >> apellido >> nombreOrdenado) {
        Empleado* empleado = new Empleado(cedula, nombre, apellido, nombreOrdenado);
        empleados.append(empleado);
        cedulasExistentes.insert(cedula);
    }
}

template<typename Compare>
void bubbleSort(vector<Empleado*>& vec, Compare comp) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (comp(vec[j + 1], vec[j])) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

bool compareByCedula(Empleado* a, Empleado* b) {
    return a->cedula < b->cedula;
}

bool compareByNombre(Empleado* a, Empleado* b) {
    return a->nombre < b->nombre;
}

bool compareByApellido(Empleado* a, Empleado* b) {
    return a->apellido < b->apellido;
}

bool compareByNombreOrdenado(Empleado* a, Empleado* b) {
    return a->nombreOrdenado < b->nombreOrdenado;
}

template <typename Lista>
void ordenarEmpleados(Lista& empleados) {
    vector<Empleado*> vec = empleados.toVector();
    int opcion;
    cout << "Seleccione el criterio de ordenación:" << endl;
    cout << "1. Ordenar por cédula" << endl;
    cout << "2. Ordenar por nombre" << endl;
    cout << "3. Ordenar por apellido" << endl;
    cout << "4. Ordenar por nombre (caracteres ASCII)" << endl;
    cout << "Ingrese su opción: ";
    while (!(cin >> opcion) || opcion < 1 || opcion > 4) {
        cout << "Opción inválida. Ingrese un número del 1 al 4: ";
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    switch (opcion) {
    case 1:
        bubbleSort(vec, compareByCedula);
        break;
    case 2:
        bubbleSort(vec, compareByNombre);
        break;
    case 3:
        bubbleSort(vec, compareByApellido);
        break;
    case 4:
        bubbleSort(vec, compareByNombreOrdenado);
        break;
    }

    for (Empleado* emp : vec) {
        cout << emp->cedula << " "
             << emp->nombre << " "
             << emp->apellido << " "
             << emp->nombreOrdenado << endl;
    }
}

template <typename Lista>
void mostrarMenu(Lista& empleados, set<string>& cedulasExistentes, int& ultimoID) {
    int opcion;
    do {
        cout << "Menú de opciones:" << endl;
        cout << "1. Crear nuevo empleado" << endl;
        cout << "2. Buscar empleado por cédula y mostrar información" << endl;
        cout << "3. Ordenar empleados" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opción: ";
        while (!(cin >> opcion) || opcion < 1 || opcion > 4) {
            cout << "Opción inválida. Ingrese un número del 1 al 4: ";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
        case 1:
            agregarEmpleado(empleados, cedulasExistentes, ultimoID);
            empleados.saveToFile("empleados.txt");
            break;
        case 2: {
            string cedula;
            cout << "Ingrese la cédula del empleado: ";
            cin >> cedula;
            Empleado* empleado = empleados.buscarPorCedula(cedula);
            if (empleado) {
                cout << "Información del empleado:" << endl;
                cout << "Cédula: " << empleado->cedula << endl;
                cout << "Nombre: " << empleado->nombre << endl;
                cout << "Apellido: " << empleado->apellido << endl;
                cout << "Nombre ordenado: " << empleado->nombreOrdenado << endl;
            } else {
                cout << "Empleado no encontrado." << endl;
            }
            break;
        }
        case 3:
            ordenarEmpleados(empleados);
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        }
    } while (opcion != 4);
}

void seleccionarLista(int& opcionLista) {
    cout << "Seleccione el tipo de lista a utilizar:" << endl;
    cout << "1. Lista enlazada simple" << endl;
    cout << "2. Lista doblemente enlazada" << endl;
    cout << "3. Lista doblemente enlazada circular" << endl;

    int seleccion = 0;
    char c;
    while (true) {
        cout << "\033[H\033[J";  // Limpiar pantalla
        cout << "Seleccione el tipo de lista a utilizar:" << endl;
        cout << (seleccion == 0 ? "> " : "  ") << "1. Lista enlazada simple" << endl;
        cout << (seleccion == 1 ? "> " : "  ") << "2. Lista doblemente enlazada" << endl;
        cout << (seleccion == 2 ? "> " : "  ") << "3. Lista doblemente enlazada circular" << endl;

        c = cin.get();
        if (c == 'A') {  // Flecha arriba
            seleccion = (seleccion + 2) % 3;
        } else if (c == 'B') {  // Flecha abajo
            seleccion = (seleccion + 1) % 3;
        } else if (c == '\n') {
            opcionLista = seleccion + 1;
            break;
        }
    }
}

int main() {
    int opcionLista;
    seleccionarLista(opcionLista);

    set<string> cedulasExistentes;
    int ultimoID = 0;

    switch (opcionLista) {
    case 1: {
        SinglyLinkedList empleados;
        cargarDatosExistentes("empleados.txt", cedulasExistentes, empleados, ultimoID);
        mostrarMenu(empleados, cedulasExistentes, ultimoID);
        break;
    }
    case 2: {
        DoublyLinkedList empleados;
        cargarDatosExistentes("empleados.txt", cedulasExistentes, empleados, ultimoID);
        mostrarMenu(empleados, cedulasExistentes, ultimoID);
        break;
    }
    case 3: {
        CircularDoublyLinkedList empleados;
        cargarDatosExistentes("empleados.txt", cedulasExistentes, empleados, ultimoID);
        mostrarMenu(empleados, cedulasExistentes, ultimoID);
        break;
    }
    }

    return 0;
}


