#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <termios.h>
#include <sstream>
#include <functional>
#include <limits>
#include <curses.h>
#include <ncurses.h>
#include "Persona.h"
#include <algorithm>
using namespace std;

Persona::Persona() {
    primerNombre = "";
    segundoNombre = "";
    apellido = "";
    cedula = "";
    correo = "";
    password = "";
}

string Persona::getPrimerNombre() {
    return primerNombre;
}
string Persona::getSegundoNombre() {
    return segundoNombre;
}
string Persona::getApellido() {
    return apellido;
}
string Persona::getCedula() {
    return cedula;
}
string Persona::getCorreo() {
    return correo;
}
string Persona::getPassword() {
    return password;
}

void Persona::setPrimerNombre(string primerNombre) {
    this->primerNombre = primerNombre;
}
void Persona::setSegundoNombre(string segundoNombre) {
    this->segundoNombre = segundoNombre;
}
void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}
void Persona::setCedula(string cedula) {
    this->cedula = cedula;
}
void Persona::setCorreo(string correo) {
    this->correo = correo;
}
void Persona::setPassword(string password) {
    this->password = password;
}

string Persona::generarCorreo(string nombre) {
    string nombreArchivo = "Personas.txt"; // Agregue el nombre del archivo
    int contador = 0;
    string correo = nombre + "@espe.edu.ec";
    return correoRepetido(correo, nombre, contador, nombreArchivo);
}

string Persona::correoRepetido(string correo, string inicio, int contador, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.find(correo) != string::npos) {
            encontrado = true;
            break;
        }
    }
    archivo.close();
    if (encontrado) {
        do {
            contador++;
            correo = inicio + to_string(contador) + "@espe.edu.ec";
            encontrado = false;
            archivo.open(nombreArchivo);
            while (getline(archivo, linea)) {
                if (linea.find(correo) != string::npos) {
                    encontrado = true;
                    break;
                }
            }
            archivo.close();
        } while (encontrado);
    }
    return correo;
}

string Persona::convertirMinusculas(string cadena) {
    for (size_t i = 0; i < cadena.length(); ++i) {
        *(cadena.data() + i) = tolower(*(cadena.data() + i));
    }
    return cadena;
}

string Persona::datos(string primerNombre, string segundoNombre, string apellido) {
    string cadena;
    if (!primerNombre.empty()) {
        char inicialPrimerNombre = tolower(*(primerNombre.c_str()));
        cadena += inicialPrimerNombre;
    }
    if (!segundoNombre.empty()) {
        char inicialSegundoNombre = tolower(*(segundoNombre.c_str()));
        cadena += inicialSegundoNombre;
    }
    string apellidoMinusculas = convertirMinusculas(apellido);
    cadena += apellidoMinusculas;
    return cadena;
}

bool Persona::cedulaRepetida(string cedula, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.find(cedula) != string::npos) {
            encontrado = true;
            break;
        }
    }
    archivo.close();
    return encontrado;
}

bool Persona::validarCedula(const char* cedula) {
    int longitud = strlen(cedula);
    if (longitud != 10) {
        printf("Error: La cédula debe tener 10 dígitos.\n");
        return false;
    }
    int* digitos = (int*)malloc(9 * sizeof(int));
    if (digitos == nullptr) {
        cerr << "Error: No se pudo asignar memoria." << endl;
        return false;
    }
    const char* ptr = cedula;
    for (int i = 0; i < 9; ++i) {
        if (*(ptr + i) < '0' || *(ptr + i) > '9') {
            cerr << "Error: La cédula debe contener solo dígitos." << endl;
            free(digitos);
            return false;
        }
        *(digitos + i) = *(ptr + i) - '0';
    }
    int digitoVerificador = *(ptr + 9) - '0';
    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int multiplicador = (i % 2 == 0) ? 2 : 1;
        int resultado = *(digitos + i) * multiplicador;
        suma += (resultado > 9) ? resultado - 9 : resultado;
    }
    int residuo = suma % 10;
    int resultado = (residuo == 0) ? 0 : 10 - residuo;
    free(digitos);
    if (resultado == digitoVerificador) {
        printf("La cédula es válida.\n");
        return true;
    } else {
        printf("La cédula no es válida.\n");
        return false;
    }
}

char* Persona::generarContrasena(Persona* persona, string nombreArchivo) {
    int desplazamiento = 3;
    char* contrasena = cifrarCesar(persona->getCedula().c_str(), desplazamiento);
    string contrasenaFinal = contrasenaRepetida(contrasena, nombreArchivo);
    return contrasenaFinal;
}

char* Persona::cifrarCesar(const char* texto, int desplazamiento) {
    int longitud = strlen(texto);
    char* cifrado = (char*)malloc((longitud + 1) * sizeof(char));
    if (cifrado == nullptr) {
        cerr << "Error: No se pudo asignar memoria." << endl;
        return nullptr;
    }
    const char* ptrTexto = texto;
    for (int i = 0; i < longitud; ++i) {
        *(cifrado + i) = (*(ptrTexto + i) - '0' + desplazamiento) % 10 + '0';
    }
    *(cifrado + longitud) = '\0';
    return cifrado;
}

string Persona::contrasenaRepetida(string contrasena, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea.find(contrasena) != string::npos) {
            encontrado = true;
            break;
        }
    }
    archivo.close();
    if (encontrado) {
        int contador = 1;
        do {
            stringstream ss;
            ss << contrasena << contador;
            contrasena = ss.str();
            encontrado = false;
            archivo.open(nombreArchivo);
            while (getline(archivo, linea)) {
                if (linea.find(contrasena) != string::npos) {
                    encontrado = true;
                    break;
                }
            }
            archivo.close();
            contador++;
        } while (encontrado);
    }
    return contrasena;
}

void Persona::disable_echo_mode(struct termios* old_attr) {
    struct termios new_attr;
    tcgetattr(STDIN_FILENO, old_attr);
    new_attr = *old_attr;
    new_attr.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
}

void Persona::restore_echo_mode(const struct termios* old_attr) {
    tcsetattr(STDIN_FILENO, TCSANOW, old_attr);
}

char* Persona::ingresarNumeros(const char* msj, int max_length) {
    char* entrada = (char*)malloc((max_length + 1) * sizeof(char));
    if (entrada == nullptr) {
        cerr << "Error: No se pudo asignar memoria." << endl;
        return nullptr;
    }
    int index = 0;
    int ch;
    do {
        printw("%s", msj);
        refresh();
        ch = getch();
        if (isdigit(ch)) {
            *(entrada + index++) = ch;
            printw("%c", ch);
            refresh();
        } else if (ch == KEY_BACKSPACE && index > 0) {
            --index;
            printw("\b \b");
            refresh();
        }
    } while (ch != '\n' && index < max_length);
    *(entrada + index) = '\0';
    return entrada;
}

string Persona::ingresarLetras(const char* msj, bool allowEmpty) {
    string entrada;
    int ch;
    while (true) {
        printw("%s", msj);
        refresh();
        ch = getch();
        if (isalpha(ch)) {
            entrada += ch;
            printw("%c", ch);
            refresh();
        } else if (ch == KEY_BACKSPACE && !entrada.empty()) {
            entrada.pop_back();
            printw("\b \b");
            refresh();
        } else if (ch == '\n') {
            if (!entrada.empty() || allowEmpty) {
                break;
            }
        }
    }
    return entrada;
}

string Persona::validarSegundoNombre(const char* msj, bool allowEmpty) {
    string entrada;
    int ch;
    while (true) {
        printw("%s", msj);
        refresh();
        ch = getch();
        if (isalpha(ch)) {
            entrada += ch;
            printw("%c", ch);
            refresh();
        } else if (ch == KEY_BACKSPACE && !entrada.empty()) {
            entrada.pop_back();
            printw("\b \b");
            refresh();
        } else if (ch == '\n') {
            if (!entrada.empty() || allowEmpty) {
                break;
            }
        }
    }
    return entrada;
}
