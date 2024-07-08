#include <iostream>
#include <ncurses.h>
#include <cstring>
#include <algorithm>
#include "ListaSimple.h"
#include "ListaDoble.h"
#include "ListaCircular.h"
#include "Persona.h"

using namespace std;

void insertarEnTodas(Persona* persona, ListaSimple* listaSimple, ListaDoble* listaDoble, ListaCircular* listaCircular) {
    listaSimple->insertar(persona);
    listaDoble->insertar(persona);
    listaCircular->insertar(persona);
}

int mostrarMenuPrincipal() {
    int opcion = 1;
    while (true) {
        clear();
        printw("MENU PRINCIPAL LISTAS\n");
        for (int i = 1; i <= 4; ++i) {
            if (i == opcion) {
                attron(A_REVERSE);
                printw("%d. ", i);
                attroff(A_REVERSE);
                switch (i) {
                    case 1:
                        printw("Listas Simples\n");
                        break;
                    case 2:
                        printw("Listas Dobles\n");
                        break;
                    case 3:
                        printw("Listas Circulares\n");
                        break;
                    case 4:
                        printw("Salir\n");
                        break;
                }
            } else {
                printw("%d. ", i);
                switch (i) {
                    case 1:
                        printw("Listas Simples\n");
                        break;
                    case 2:
                        printw("Listas Dobles\n");
                        break;
                    case 3:
                        printw("Listas Circulares\n");
                        break;
                    case 4:
                        printw("Salir\n");
                        break;
                }
            }
        }
        refresh();
        int tecla = getch();
        switch (tecla) {
            case KEY_UP:
                if (opcion > 1)
                    opcion--;
                break;
            case KEY_DOWN:
                if (opcion < 4)
                    opcion++;
                break;
            case '\n':
                return opcion;
        }
    }
}

void menuListaSimple(ListaSimple* lista, ListaDoble* listaDoble, ListaCircular* listaCircular) {
    int opcion = 1;
    bool validacion1, validacion2;
    char* dato;
    string primerNombre, segundoNombre, apellido, cedula, correo, password;
    while (opcion != 6) {
        clear();
        printw("MENU PRINCIPAL LISTA SIMPLE\n");
        for (int i = 1; i <= 6; ++i) {
            if (i == opcion) {
                attron(A_REVERSE);
                printw("%d. ", i);
                attroff(A_REVERSE);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar Por Caracter\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            } else {
                printw("%d. ", i);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar Por Caracter\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            }
        }
        refresh();
        int tecla = getch();
        switch (tecla) {
            case KEY_UP:
                if (opcion > 1)
                    opcion--;
                break;
            case KEY_DOWN:
                if (opcion < 6)
                    opcion++;
                break;
            case '\n':
                switch (opcion) {
                    case 1: {
                        string archivo = "Personas.txt";
                        Persona* persona = new Persona();
                        do {
                            dato = persona->ingresarNumeros("Ingrese el numero de cedula: ", 10);
                            cedula = dato;
                            validacion1 = persona->validarCedula(dato);
                            validacion2 = persona->cedulaRepetida(dato, archivo);
                            if (!validacion1) {
                                printw("Cédula incorrecta. Vuelva a ingresar.\n");
                            } else if (validacion2) {
                                printw("Cédula repetida, vuelva a ingresar otra.\n");
                            }
                            free(dato);
                        } while (!validacion1 || validacion2);
                        persona->setCedula(cedula);
                        primerNombre = persona->ingresarLetras("Ingrese el primer nombre: ");
                        segundoNombre = persona->validarSegundoNombre("Ingrese el segundo nombre: ", false);
                        apellido = persona->ingresarLetras("Ingrese el apellido: ");
                        persona->setPrimerNombre(primerNombre);
                        persona->setSegundoNombre(segundoNombre);
                        persona->setApellido(apellido);
                        correo = persona->generarCorreo(persona->datos(primerNombre, segundoNombre, apellido));
                        persona->setCorreo(correo);
                        password = persona->generarContrasena(persona, archivo);
                        persona->setPassword(password);
                        insertarEnTodas(persona, lista, listaDoble, listaCircular);
                        lista->guardarDatosPersona(persona);
                        break;
                    }
                    case 2: {
                        lista->ordenar([](Persona* p1, Persona* p2) {
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            if (nombre1 == nombre2) {
                                if (segundoNombre1 == segundoNombre2) {
                                    return apellido1 < apellido2;
                                }
                                return segundoNombre1 < segundoNombre2;
                            }
                            return nombre1 < nombre2;
                        });
                        break;
                    }
                    case 3: {
                        lista->ordenar([](Persona* p1, Persona* p2) {
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            if (apellido1 == apellido2) {
                                if (nombre1 == nombre2) {
                                    return segundoNombre1 < segundoNombre2;
                                }
                                return nombre1 < nombre2;
                            }
                            return apellido1 < apellido2;
                        });
                        break;
                    }
                    case 4:
                        lista->ordenar([](Persona* p1, Persona* p2) {
                            return p1->getCedula() < p2->getCedula();
                        });
                        break;
                    case 5: {
                        lista->ordenarPorCaracter();
                    }
                    case 6: {
                        break;
                    }
                }
                getch();
                break;
        }
    }
}

void menuListaDoble(ListaDoble* listaDoble, ListaSimple* listaSimple, ListaCircular* listaCircular) {
    int opcion = 1;
    bool validacion1, validacion2;
    char* dato;
    string primerNombre, segundoNombre, apellido, cedula, correo, password;
    while (opcion != 6) {
        clear();
        printw("MENU PRINCIPAL LISTAS DOBLES\n");
        for (int i = 1; i <= 6; ++i) {
            if (i == opcion) {
                attron(A_REVERSE);
                printw("%d. ", i);
                attroff(A_REVERSE);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar por caracteres\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            } else {
                printw("%d. ", i);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar por caracteres\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            }
        }
        refresh();
        int tecla = getch();
        switch (tecla) {
            case KEY_UP:
                if (opcion > 1)
                    opcion--;
                break;
            case KEY_DOWN:
                if (opcion < 6)
                    opcion++;
                break;
            case '\n':
                switch (opcion) {
                    case 1: {
                        string archivo = "Personas.txt";
                        Persona* persona = new Persona();
                        do {
                            dato = persona->ingresarNumeros("Ingrese el numero de cedula: ", 10);
                            cedula = dato;
                            validacion1 = persona->validarCedula(dato);
                            validacion2 = persona->cedulaRepetida(dato, archivo);
                            if (!validacion1) {
                                printw("Cédula incorrecta. Vuelva a ingresar.\n");
                            } else if (validacion2) {
                                printw("Cédula repetida, vuelva a ingresar otra.\n");
                            }
                            free(dato);
                        } while (!validacion1 || validacion2);
                        persona->setCedula(cedula);
                        primerNombre = persona->ingresarLetras("Ingrese el primer nombre: ");
                        segundoNombre = persona->validarSegundoNombre("Ingrese el segundo nombre: ", false);
                        apellido = persona->ingresarLetras("Ingrese el apellido: ");
                        persona->setPrimerNombre(primerNombre);
                        persona->setSegundoNombre(segundoNombre);
                        persona->setApellido(apellido);
                        correo = persona->generarCorreo(persona->datos(primerNombre, segundoNombre, apellido));
                        persona->setCorreo(correo);
                        password = persona->generarContrasena(persona, archivo);
                        persona->setPassword(password);
                        insertarEnTodas(persona, listaSimple, listaDoble, listaCircular);
                        listaDoble->guardarDatosPersona(persona);
                        break;
                    }
                    case 2: {
                        listaDoble->ordenar([](Persona* p1, Persona* p2) {
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            if (nombre1 == nombre2) {
                                if (segundoNombre1 == segundoNombre2) {
                                    return apellido1 < apellido2;
                                }
                                return segundoNombre1 < segundoNombre2;
                            }
                            return nombre1 < nombre2;
                        });
                        break;
                    }
                    case 3: {
                        listaDoble->ordenar([](Persona* p1, Persona* p2) {
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            if (apellido1 == apellido2) {
                                if (nombre1 == nombre2) {
                                    return segundoNombre1 < segundoNombre2;
                                }
                                return nombre1 < nombre2;
                            }
                            return apellido1 < apellido2;
                        });
                        break;
                    }
                    case 4:
                        listaDoble->ordenar([](Persona* p1, Persona* p2) {
                            return p1->getCedula() < p2->getCedula();
                        });
                        break;
                    case 5: {
                        listaDoble->ordenarPorCaracter();
                        break;
                    }
                    case 6:
                        break;
                }
                getch();
                break;
        }
    }
}

void menuListaCircular(ListaCircular* ListaCircular, ListaSimple* listaSimple, ListaDoble* listaDoble) {
    int opcion = 1;
    bool validacion1, validacion2;
    char* dato;
    string primerNombre, segundoNombre, apellido, cedula, correo, password;
    while (opcion != 6) {
        clear();
        printw("MENU PRINCIPAL LISTA CIRCULAR\n");
        for (int i = 1; i <= 6; ++i) {
            if (i == opcion) {
                attron(A_REVERSE);
                printw("%d. ", i);
                attroff(A_REVERSE);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar por caracteres\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            } else {
                printw("%d. ", i);
                switch (i) {
                    case 1:
                        printw("Registrar Persona\n");
                        break;
                    case 2:
                        printw("Mostrar Personas Ordenadas Por Nombre\n");
                        break;
                    case 3:
                        printw("Mostrar Personas Ordenadas Por Apellido\n");
                        break;
                    case 4:
                        printw("Mostrar Personas Ordenadas Por Cedula\n");
                        break;
                    case 5:
                        printw("Ordenar por caracteres\n");
                        break;
                    case 6:
                        printw("Salir\n");
                        break;
                }
            }
        }
        refresh();
        int tecla = getch();
        switch (tecla) {
            case KEY_UP:
                if (opcion > 1)
                    opcion--;
                break;
            case KEY_DOWN:
                if (opcion < 6)
                    opcion++;
                break;
            case '\n':
                switch (opcion) {
                    case 1: {
                        string archivo = "Personas.txt";
                        Persona* persona = new Persona();
                        do {
                            dato = persona->ingresarNumeros("Ingrese el numero de cedula: ", 10);
                            cedula = dato;
                            validacion1 = persona->validarCedula(dato);
                            validacion2 = persona->cedulaRepetida(dato, archivo);
                            if (!validacion1) {
                                printw("Cédula incorrecta. Vuelva a ingresar.\n");
                            } else if (validacion2) {
                                printw("Cédula repetida, vuelva a ingresar otra.\n");
                            }
                            free(dato);
                        } while (!validacion1 || validacion2);
                        persona->setCedula(cedula);
                        primerNombre = persona->ingresarLetras("Ingrese el primer nombre: ");
                        segundoNombre = persona->validarSegundoNombre("Ingrese el segundo nombre: ", false);
                        apellido = persona->ingresarLetras("Ingrese el apellido: ");
                        persona->setPrimerNombre(primerNombre);
                        persona->setSegundoNombre(segundoNombre);
                        persona->setApellido(apellido);
                        correo = persona->generarCorreo(persona->datos(primerNombre, segundoNombre, apellido));
                        persona->setCorreo(correo);
                        password = persona->generarContrasena(persona, archivo);
                        persona->setPassword(password);
                        insertarEnTodas(persona, listaSimple, listaDoble, ListaCircular);
                        ListaCircular->guardarDatosPersona(persona);
                        break;
                    }
                    case 2: {
                        ListaCircular->ordenar([](Persona* p1, Persona* p2) {
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            if (nombre1 == nombre2) {
                                if (segundoNombre1 == segundoNombre2) {
                                    return apellido1 < apellido2;
                                }
                                return segundoNombre1 < segundoNombre2;
                            }
                            return nombre1 < nombre2;
                        });
                        break;
                    }
                    case 3: {
                        ListaCircular->ordenar([](Persona* p1, Persona* p2) {
                            string apellido1 = p1->getApellido();
                            string apellido2 = p2->getApellido();
                            string nombre1 = p1->getPrimerNombre();
                            string nombre2 = p2->getPrimerNombre();
                            string segundoNombre1 = p1->getSegundoNombre();
                            string segundoNombre2 = p2->getSegundoNombre();
                            transform(apellido1.begin(), apellido1.end(), apellido1.begin(), ::tolower);
                            transform(apellido2.begin(), apellido2.end(), apellido2.begin(), ::tolower);
                            transform(nombre1.begin(), nombre1.end(), nombre1.begin(), ::tolower);
                            transform(nombre2.begin(), nombre2.end(), nombre2.begin(), ::tolower);
                            transform(segundoNombre1.begin(), segundoNombre1.end(), segundoNombre1.begin(), ::tolower);
                            transform(segundoNombre2.begin(), segundoNombre2.end(), segundoNombre2.begin(), ::tolower);
                            if (apellido1 == apellido2) {
                                if (nombre1 == nombre2) {
                                    return segundoNombre1 < segundoNombre2;
                                }
                                return nombre1 < nombre2;
                            }
                            return apellido1 < apellido2;
                        });
                        break;
                    }
                    case 4:
                        ListaCircular->ordenar([](Persona* p1, Persona* p2) {
                            return p1->getCedula() < p2->getCedula();
                        });
                        break;
                    case 5:
                        ListaCircular->ordenarPorCaracter();
                        break;
                    case 6:
                        break;
                }
                getch();
                break;
        }
    }
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    ListaSimple* listaSimple = new ListaSimple();
    ListaDoble* listaDoble = new ListaDoble();
    ListaCircular* listaCircular = new ListaCircular();
    listaSimple->cargarDatosPersona();
    listaDoble->cargarDatosPersona();
    listaCircular->cargarDatosPersona();
    while (true) {
        int opcion = mostrarMenuPrincipal();
        if (opcion == 4) {
            break;
        }
        switch (opcion) {
            case 1: {
                menuListaSimple(listaSimple, listaDoble, listaCircular);
                break;
            }
            case 2: {
                menuListaDoble(listaDoble, listaSimple, listaCircular);
                break;
            }
            case 3: {
                menuListaCircular(listaCircular, listaSimple, listaDoble);
                break;
            }
        }
    }
    endwin();
    delete listaSimple;
    delete listaDoble;
    delete listaCircular;
    return 0;
}