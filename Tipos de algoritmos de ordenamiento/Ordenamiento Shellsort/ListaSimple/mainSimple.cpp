#include <iostream>
#include "ListaSimple.h"
#include "../Buscador.h"
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include "..\TipoOrdenamiento.h"
using namespace std;

void gotoxySimple(int x, int y);
void printMenuSimple(const char* menu[], int size, int currentSelection);
void menuOrdenarCaracteres(ListaSimple<string>& lista, TipoOrdenamiento tipoOrdenamiento);
void menuBuscar(int tipoBusqueda);
void menuBusqueda();

void mainSimple(TipoOrdenamiento tipoOrdenamiento) {
    system("cls");
    ListaSimple<string> lista;
    string numCedula, primerNombre, apellido, linea;

    const char* menu[] = {
        "Ingresar datos",
        "Buscar datos",
        "Eliminar datos",
        "Mostrar datos",
        "Ordenar por apellido",
        "Ordenar por nombre",
        "Ordenar por cedula",
        "Ordenar caracteres",
        "Salir"
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int currentSelection = 0;
    int key;
    
    do {
        system("cls");
        cout << "\t\t.:MENU DE REGISTRO DE USUARIO (Lista simple):." << endl;
        printMenuSimple(menu, size, currentSelection);

        key = _getch();

        switch (key) {
            case 72: 
                if (currentSelection > 0) {
                    currentSelection--;
                }
                break;
            case 80: 
                if (currentSelection < size - 1) {
                    currentSelection++;
                }
                break;
            case 13: 
                switch (currentSelection) {
                    case 0: { 
                        do {
                            numCedula = lista.ingresarCedula("Ingrese el numero de cedula");
                            if (!lista.esNumeroCedulaValido(numCedula)) {
                                cout << "\n>> El numero de cedula ingresado no corresponde a una cedula ecuatoriana.\n" << endl;
                                continue;
                            }

                            long int cedulaLong;
                            try {
                                cedulaLong = stol(numCedula);
                            } catch (const exception &e) {
                                cout << "\nEl numero de cedula no es valido. Intentalo de nuevo.\n" << endl;
                                continue;
                            }

                            if (!lista.validarCedula(cedulaLong)) {
                                cout << "\nEl numero de cedula no es valido. Intentalo de nuevo.\n" << endl;
                                continue;
                            }
                            if (lista.cedulaRepetida(numCedula)) {
                                cout << "\nEl numero de cedula ya existe. No se puede insertar.\n" << endl;
                                continue;
                            }
                            break;
                        } while (true);

                        primerNombre = lista.ingresarLetras("Ingrese el nombre");
                        apellido = lista.ingresarLetras("Ingrese el apellido");

                        lista.insertar(numCedula, primerNombre, apellido);
                        cout << "Datos ingresados correctamente." << endl;
                        break;
                    }
                    case 1: { 
                        menuBusqueda();
                        break;
                    }
                    case 2: { 
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            numCedula = lista.ingresarCedula("Ingrese el numero de cedula a eliminar");
                            if (!lista.esNumeroCedulaValido(numCedula)) {
                                cout << "\nEl numero de cedula debe contener solo digitos y tener exactamente 10 digitos.\n" << endl;
                            } else {
                                lista.eliminar(numCedula);
                            }
                        }
                        break;
                    }
                    case 3: { 
                        lista.mostrar();
                        break;
                    }
                    case 4: { 
                        lista.resetLista();
                        lista.cargarDesdeArchivo();
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarConShellSort([](NodoSimple<string>* a, NodoSimple<string>* b) {
                                    return a->getApellido() < b->getApellido();
                                });
                            }
                            cout << "Lista ordenada por apellidos." << endl;
                        }
                        break;
                    }
                    case 5: { 
                        lista.resetLista();
                        lista.cargarDesdeArchivo();
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarConShellSort([](NodoSimple<string>* a, NodoSimple<string>* b) {
                                    return a->getPrimerNombre() < b->getPrimerNombre();
                                });
                            }
                            cout << "Lista ordenada por primer nombre." << endl;
                        }
                        break;
                    }
                    case 6: { 
                        lista.resetLista();
                        lista.cargarDesdeArchivo();
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarConShellSort([](NodoSimple<string>* a, NodoSimple<string>* b) {
                                    return a->getNumCedula() < b->getNumCedula();
                                });
                            }
                            cout << "Lista ordenada por cedula." << endl;
                        }
                        break;
                    }
                    case 7: { 
                        menuOrdenarCaracteres(lista, tipoOrdenamiento);
                        break;
                    }
                    case 8: 
                        cout << "Saliendo del programa..." << endl;
                        return; 
                    default:
                        cout << "Opcion invalida. Intentalo nuevamente." << endl;
                        break;
                }
                if (currentSelection != 8) {
                    cout << "Presione cualquier tecla para continuar..." << endl;
                    _getch();
                }
                break;
        }
    } while (true);
}

void gotoxySimple(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printMenuSimple(const char* menu[], int size, int currentSelection) {
    for (int i = 0; i < size; ++i) {
        if (i == currentSelection) {
            cout << "> " << menu[i] << " <" << endl;
        } else {
            cout << "  " << menu[i] << endl;
        }
    }
}

void menuOrdenarCaracteres(ListaSimple<string>& lista, TipoOrdenamiento tipoOrdenamiento) {
    const char* menu[] = {
        "Ordenar caracteres de cedula",
        "Ordenar caracteres de nombre",
        "Ordenar caracteres de apellido",
        "Mostrar caracteres ordenados",
        "Volver"
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int currentSelection = 0;
    int key;

    do {
        system("cls");
        cout << "\t\t.:MENU ORDENAR CARACTERES:." << endl;
        printMenuSimple(menu, size, currentSelection);

        key = _getch();

        switch (key) {
            case 72: 
                if (currentSelection > 0) {
                    currentSelection--;
                }
                break;
            case 80: 
                if (currentSelection < size - 1) {
                    currentSelection++;
                }
                break;
            case 13:
                switch (currentSelection) {
                    case 0: { 
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarCaracteresShellSort("cedula");
                            }
                            cout << "Caracteres de las cedulas ordenados y guardados en usuariosCaracteres.txt." << endl;
                        }
                        break;
                    }
                    case 1: { 
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarCaracteresShellSort("nombre");
                            }
                            cout << "Caracteres de los nombres ordenados y guardados en usuariosCaracteres.txt." << endl;
                        }
                        break;
                    }
                    case 2: { 
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoOrdenamiento == SHELLSORT) {
                                lista.ordenarCaracteresShellSort("apellido");
                            }
                            cout << "Caracteres de los apellidos ordenados y guardados en usuariosCaracteres.txt." << endl;
                        }
                        break;
                    }
                    case 3: { 
                        lista.mostrarCaracteresOrdenados();
                        break;
                    }
                    case 4: 
                        return;
                    default:
                        cout << "Opcion invalida. Intentalo nuevamente." << endl;
                        break;
                }
                if (currentSelection != 4) {
                    cout << "Presione cualquier tecla para continuar..." << endl;
                    _getch();
                }
                break;
        }
    } while (true);
}
void menuBuscar(int tipoBusqueda) {
    ListaSimple<string> lista;
    const char* menu[] = {
        "Buscar por cedula",
        "Buscar por nombre",
        "Buscar por apellido",
        "Volver"
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int currentSelection = 0;
    int key;

    do {
        system("cls");
        cout << "\t\t.:MENU DE BUSQUEDA:." << endl;
        printMenuSimple(menu, size, currentSelection);

        key = _getch();

        switch (key) {
            case 72: 
                if (currentSelection > 0) {
                    currentSelection--;
                }
                break;
            case 80: 
                if (currentSelection < size - 1) {
                    currentSelection++;
                }
                break;
            case 13:
                switch (currentSelection) {
                    case 0: {
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if(tipoBusqueda == HASH){
                                string numCedula = lista.ingresarCedula("Ingrese el numero de cedula a buscar");
                                Buscador<NodoSimple<string>>::buscarTablasHash(lista.getPrimero(), numCedula, "cedula");
                            } else {
                                cout << "Busqueda Binaria" << endl;
                            }
                        }
                        break;
                    }
                    case 1: {
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoBusqueda == HASH) {
                                string primerNombre = lista.ingresarLetras("Ingrese el nombre a buscar");
                                primerNombre = lista.convertirMayusculas(primerNombre);
                                Buscador<NodoSimple<string>>::buscarTablasHash(lista.getPrimero(), primerNombre, "nombre");
                            }
                        }   
                        break;
                    }
                    case 2: {
                        if (lista.listaVacia()) {
                            cout << "Lista vacia. No se ha registrado ningun usuario." << endl;
                        } else {
                            if (tipoBusqueda == HASH) {
                                string apellido = lista.ingresarLetras("Ingrese el apellido a buscar");
                                apellido = lista.convertirMayusculas(apellido);
                                Buscador<NodoSimple<string>>::buscarTablasHash(lista.getPrimero(), apellido, "apellido");
                            }
                        }
                        break;
                    }
                    case 3:
                        return;
                }
                if (currentSelection != 3) {
                    cout << "Presione cualquier tecla para continuar..." << endl;
                    _getch();
                }
                break;
        }
    } while (true);
}
void menuBusqueda(){
    const char* menu[] = {
        "Busqueda Hash",
        "Volver"
    };
    int size = sizeof(menu) / sizeof(menu[0]);
    int currentSelection = 0;
    int key;

    do {
        system("cls");
        cout << "\t\t.:MENU DE BUSQUEDA:." << endl;
        printMenuSimple(menu, size, currentSelection);

        key = _getch();

        switch (key) {
            case 72: 
                if (currentSelection > 0) {
                    currentSelection--;
                }
                break;
            case 80: 
                if (currentSelection < size - 1) {
                    currentSelection++;
                }
                break;
            case 13:
                if(currentSelection == 1){
                    return;
                } else {
                    menuBuscar(currentSelection);
                }
                break;
        }
    } while (true);
}
