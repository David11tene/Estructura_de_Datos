/*Universidad de las Fuerzas Armadas ESPE
Método de ordenamiento por QuickSort
Autores: David Ramos, Estiven Oña, Carlos Carrasco
Fecha de creacion: 05/07/2024
Fecha de modificacion: 07/07/2024
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Persona.h"
#include "NodoCDoble.h"
#include "ListaDobleCircular.h"
#include "Validaciones.h"
#include "ManejoArchivos.h"
#include "ListasSimples.h"
#include "ListasDobles.h"

using namespace std;

int leerOpcionFlechas();
int leerListasFlechas();
void registrarPersona(ListaDobleCircular& listaPersonas);
void consultarPersona(ListaDobleCircular& listaPersonas);
void mostrarReporte(ListaDobleCircular& listaPersonas);
void eliminarPersona(ListaDobleCircular& listaPersonas);
std::string obtenerFechaActual();
void menuCDoble(int opcion);
void menuListas(int lista);


int main() {
    int lista;
    do {
        menuListas(lista = leerListasFlechas());
    } while (lista != 5);

    return 0;
}

void menuListas(int lista) {
    switch (lista) {
    case 1:
        int opcion1;
        do {
            opcion1 = leerOpcionFlechas();
            if (opcion1 == 7) {
                cout << "Regresando al menu principal..." << endl;
                break;
            }
            menuCDoble(opcion1);
            if (opcion1 != 7) {
                cout << "\nPresione cualquier tecla para volver al menu...";
                _getch();
            }
        } while (opcion1 != 7);
        break;
    case 2:
        int opcion2;
        do {
            opcion2 = leerOpcionFlechas();
            if (opcion2 == 7) {
                cout << "Regresando al menu principal..." << endl;
                break;
            }
            menuCDoble(opcion2);
            if (opcion2 != 7) {
                cout << "\nPresione cualquier tecla para volver al menu...";
                _getch();
            }
        } while (opcion2 != 7);
        break;
    case 3:
        int opcion3;
        do {
            opcion3 = leerOpcionFlechas();
            if (opcion3 == 7) {
                cout << "Regresando al menu principal..." << endl;
                break;
            }
            menuCDoble(opcion3);
            if (opcion3 != 7) {
                cout << "\nPresione cualquier tecla para volver al menu...";
                _getch();
            }
        } while (opcion3 != 7);
        break;
    case 4:
        int opcion4;
        do {
            opcion4 = leerOpcionFlechas();
            if (opcion4 == 7) {
                cout << "Regresando al menu principal..." << endl;
                break;
            }
            menuCDoble(opcion4);
            if (opcion4 != 7) {
                cout << "\nPresione cualquier tecla para volver al menu...";
                _getch();
            }
        } while (opcion4 != 7);
        break;
    case 5:
        cout << "Salir" << endl;
        break;
    default:
        cout << "Opcion no valida. Intente de nuevo." << endl;
        break;
    }
}

void menuCDoble(int opcion) {
    ListaDobleCircular listaPersonas;
    listaPersonas.cargarPersonasDesdeArchivo("personas.txt");
    switch (opcion) {
    case 1:
        cout << "Registrar persona" << endl;
        registrarPersona(listaPersonas);
        break;
    case 2:
        cout << "Consultar persona por cedula" << endl;
        consultarPersona(listaPersonas);
        break;
    case 3:
        cout << "Mostrar reporte general" << endl;
        listaPersonas.quickSort(); // Ordenar la lista antes de mostrarla
        mostrarReporte(listaPersonas);
        break;
    case 4:
        cout << "Eliminar persona por cedula" << endl;
        eliminarPersona(listaPersonas);
        break;
    case 5:
        cout << "Ordenar usuarios ascendente" << endl;
        listaPersonas.quickSort();
        listaPersonas.mostrarLista();
        ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
        break;
    case 6:
        cout << "Ordenar usuarios descendente" << endl;
        listaPersonas.quickSort();
        listaPersonas.invertirLista();
        listaPersonas.mostrarLista();
        ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
        break;
    case 7: 
        cout << "Ordenar caracteres del nombre" << endl;
        listaPersonas.ordenarCaracteresDeCampo("nombre");
        listaPersonas.mostrarLista();
        ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
        break;
    case 8:
        cout << "Ordenar caracteres del apellido" << endl;
        listaPersonas.ordenarCaracteresDeCampo("apellido");
        listaPersonas.mostrarLista();
        ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
        break;
    case 9:
        cout << "Ordenar caracteres de la cedula" << endl;
        listaPersonas.ordenarCedulasCaracteres();
        listaPersonas.mostrarLista();
        ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
        break;
    case 10:
        cout << "Regresar" << endl;
        break;
    default:
        cout << "Opcion no valida. Intente de nuevo." << endl;
        break;
    }
}

int leerOpcionFlechas() {
    int opcion = 1;
    int opciones = 10; 
    char key;

    while (true) {
        system("cls");
        cout << "Seleccione una opcion: \n";
        for (int i = 1; i <= opciones; i++) {
            if (i == opcion) {
                cout << " --> ";
            }
            else {
                cout << "     ";
            }
            switch (i) {
            case 1: cout << "Registrar persona" << endl; break;
            case 2: cout << "Consultar persona por cedula" << endl; break;
            case 3: cout << "Mostrar reporte general" << endl; break;
            case 4: cout << "Eliminar persona por cedula" << endl; break;
            case 5: cout << "Ordenar usuarios ascendente" << endl; break;
            case 6: cout << "Ordenar usuarios descendente" << endl; break;
            case 7: cout << "Ordenar caracteres del nombre" << endl; break;
            case 8: cout << "Ordenar caracteres del apellido" << endl; break;
            case 9: cout << "Ordenar caracteres de la cedula" << endl; break;
            case 10: cout << "Regresar" << endl; break;
            }
        }
        key = _getch();
        if (key == 'w' || key == 'W') {
            if (opcion > 1) {
                opcion--;
            }
        }
        else if (key == 's' || key == 'S') {
            if (opcion < opciones) {
                opcion++;
            }
        }
        else if (key == '\r') {
            break;
        }
    }
    return opcion;
}


int leerListasFlechas() {
    int opcion = 1;
    int opciones = 5;
    char key;

    while (true) {
        system("cls");
        cout << "Seleccione una opcion: \n";
        for (int i = 1; i <= opciones; i++) {
            if (i == opcion) {
                cout << " --> ";
            }
            else {
                cout << "     ";
            }
            switch (i) {
            case 1: cout << "Lista Simple" << endl; break;
            case 2: cout << "Lista Doble" << endl; break;
            case 3: cout << "Lista Circular Simple" << endl; break;
            case 4: cout << "Lista Circular Doble" << endl; break;
            case 5: cout << "Salir" << endl; break;
            }
        }
        key = _getch();
        if (key == 'w' || key == 'W') { // Letra 'w' para subir
            if (opcion > 1) {
                opcion--;
            }
        }
        else if (key == 's' || key == 'S') { // Letra 's' para bajar
            if (opcion < opciones) {
                opcion++;
            }
        }
        else if (key == '\r') { // Tecla Enter
            break;
        }
    }
    return opcion;
}



void registrarPersona(ListaDobleCircular& listaPersonas) {
    string cedula, fechaNacimiento, nombre, apellido, correo, clave;
    bool valido = false;

    do {
        cout << "Ingrese la cedula: ";
        cedula = Validaciones::leerCedula();
        if (Validaciones::validarCedula(cedula)) {
            if (listaPersonas.buscarPersona(cedula) != nullptr) {
                cout << "La persona ya esta registrada." << endl;
                return;
            }
            valido = true;
        }
        else {
            cout << "Cedula no valida. Intente nuevamente." << endl;
        }
    } while (!valido);

    valido = false;
    do {
        cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
        fechaNacimiento = Validaciones::leerFecha();
        if (Validaciones::validarFecha(fechaNacimiento)) {
            valido = true;
        }
        else {
            cout << "Fecha de nacimiento no valida. Intente nuevamente." << endl;
        }
    } while (!valido);

    valido = false;
    do {
        cout << "Ingrese el nombre: ";
        nombre = Validaciones::leerNombre();
        if (Validaciones::validarNombre(nombre)) {
            nombre = listaPersonas.toLowerCase(nombre);
            if (!nombre.empty()) {
                nombre[0] = toupper(nombre[0]);
            }
            valido = true;
        }
        else {
            cout << "Nombre no valido. Intente nuevamente." << endl;
        }
    } while (!valido);

    valido = false;
    do {
        cout << "Ingrese el apellido: ";
        apellido = Validaciones::leerNombre();
        if (Validaciones::validarNombre(apellido)) {
            apellido = listaPersonas.toLowerCase(apellido);
            if (!apellido.empty()) {
                apellido[0] = toupper(apellido[0]);
            }
            valido = true;
        }
        else {
            cout << "Apellido no valido. Intente nuevamente." << endl;
        }
    } while (!valido);

    correo = listaPersonas.obtenerCorreo(nombre, apellido);
    clave = listaPersonas.generarContrasena(nombre, apellido, correo);
    string claveDesencriptada = listaPersonas.descifrarContrasena(clave);

    Persona* nuevaPersona = new Persona(cedula, fechaNacimiento, nombre, apellido, correo, clave);
    listaPersonas.insertarFinal(nuevaPersona);

    ManejoArchivos::guardarPersona(*nuevaPersona, "personas.txt", claveDesencriptada);

    cout << "Persona registrada exitosamente." << endl;
    cout << "Correo: " << correo << endl;
    cout << "Clave Encriptada: " << clave << endl;
    cout << "Clave Desencriptada: " << claveDesencriptada << endl;
}

std::string obtenerFechaActual() {
    std::time_t t = std::time(nullptr);
    std::tm* tm = std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d");
    return oss.str();
}

void consultarPersona(ListaDobleCircular& listaPersonas) {
    string cedula;
    cout << "Ingrese la cedula de la persona a consultar: ";
    cedula = Validaciones::leerCedula();

    if (!Validaciones::validarCedula(cedula)) {
        cout << "Cedula no valida. Intente nuevamente." << endl;
        return;
    }

    NodoCDoble* nodoPersona = listaPersonas.buscarPersona(cedula);
    if (nodoPersona == nullptr) {
        cout << "Cedula no encontrada. Registrando nueva persona." << endl;
        registrarPersona(listaPersonas);
        nodoPersona = listaPersonas.buscarPersona(cedula);
        if (nodoPersona == nullptr) {
            cout << "Error en el registro. Intente nuevamente." << endl;
            return;
        }
    }

    Persona* persona = nodoPersona->getPersona();
    persona->mostrarInformacion();
}

void mostrarReporte(ListaDobleCircular& listaPersonas) {
    std::cout << "Generando el reporte general de personas registradas en el archivo general.txt..." << std::endl;
    ManejoArchivos::guardarReporte(listaPersonas, "general.txt");
    std::cout << "Reporte generado exitosamente." << std::endl;
    listaPersonas.mostrarLista();
}

void eliminarPersona(ListaDobleCircular& listaPersonas) {
    string cedula;
    cout << "Ingrese la cedula de la persona a eliminar: ";
    cedula = Validaciones::leerCedula();
    if (Validaciones::validarCedula(cedula)) {
        listaPersonas.eliminarPersonaPorCedula(cedula);
        ManejoArchivos::eliminarPersonaArchivo(cedula, "personas.txt");
        cout << "Persona eliminada exitosamente." << endl;
    }
    else {
        cout << "Cedula no valida. Intente nuevamente." << endl;
    }
}

