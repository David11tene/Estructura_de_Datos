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
using namespace std;
Persona::Persona(){
    primerNombre = "";
    segundoNombre = "";
    apellido = "";
    cedula = "";
    correo = "";
    password = "";
}
string Persona::getPrimerNombre(){
    return primerNombre;
}
string Persona::getSegundoNombre(){
    return segundoNombre;
}
string Persona::getApellido(){
    return apellido;
}
string Persona::getCedula(){
    return cedula;
}
string Persona::getCorreo(){
    return correo;
}
string Persona::getPassword(){
    return password;
}
void Persona::setPrimerNombre(string primerNombre){
    this->primerNombre = primerNombre;
}
void Persona::setSegundoNombre(string segundoNombre){
    this->segundoNombre = segundoNombre;
}
void Persona::setApellido(string apellido){
    this->apellido = apellido;
}
void Persona::setCedula(string cedula){
    this->cedula = cedula;
}
void Persona::setCorreo(string correo){
    this->correo = correo;
}
void Persona::setPassword(string password){
    this->password = password;
}
string Persona::generarCorreo(string nombre) {
    string nombreArchivo;
    int contador = 0;
    string correo = nombre + "@espe.edu.ec";
    return correoRepetido(correo, nombre, contador,nombreArchivo);
};
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
};
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
bool Persona::cedulaRepetida(string cedula,string nombreArchivo) {
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
};
bool Persona::validarCedula(const char *cedula) {
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
        if (*(ptr + i) >= '0' && *(ptr + i) <= '9') {
            *(digitos + i) = *(ptr + i) - '0';
        } else {
            printf("\nError: La cédula debe contener solo dígitos.\n");
            free(digitos);
            return false;
        }
    }
    int* coef = (int*)malloc(9 * sizeof(int));
    if (coef == nullptr) {
        cerr << "Error: No se pudo asignar memoria." << endl;
        free(digitos);
        return false;
    }
    for (int i = 0; i < 9; ++i) {
        if (i % 2 == 0) {
            *(coef + i) = 2;
        } else {
            *(coef + i) = 1;
        }
    }
    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int prod = *(digitos + i) * *(coef + i);
        if (prod > 9) prod -= 9;
        suma += prod;
    }
    int digitoVerificador = (10 - (suma % 10)) % 10;
    free(digitos);
    free(coef);
    return (*(ptr + 9) - '0') == digitoVerificador;
}
char* Persona::generarContrasena(Persona* persona,string nombreArchivo) {
    const char* primerNombre = persona->getPrimerNombre().c_str();
    const char* segundoNombre = persona->getSegundoNombre().c_str();
    const char* apellido = persona->getApellido().c_str();
    if(!primerNombre||!apellido){
        return nullptr;
    }
    int tamanoPrimerNombre = strlen(primerNombre);
    int tamanoApellido = strlen(apellido);
    if(tamanoPrimerNombre==0||tamanoApellido==0){
        return nullptr;
    }
    const char* segundoNombreReal = segundoNombre && strlen(segundoNombre) > 0 ? segundoNombre : "_"; 
    int lenContrasena = 3 + tamanoApellido - 1;
    char* contrasenaBase = (char*)malloc((lenContrasena + 1)*sizeof(char));
    if (!contrasenaBase) {
        cerr << "Error: No se pudo asignar memoria para la contraseña." << endl;
        return nullptr;
    }
    *contrasenaBase = *(apellido + tamanoApellido -1);
    *(contrasenaBase + 2) = *primerNombre;
    *(contrasenaBase + 1) = *segundoNombreReal;
    for (int i = 0; i < tamanoApellido - 1; i++) {
        *(contrasenaBase + 3 + i) = *(apellido + tamanoApellido - 2 - i);
    }
    *(contrasenaBase + lenContrasena) = '\0';
    char* contrasenaCifrada = cifrarCesar(contrasenaBase, 2);
    free(contrasenaBase);
    string contrasenaFinal = contrasenaCifrada;
    free(contrasenaCifrada);
    ifstream archivo(nombreArchivo);
    string linea;
    bool encontrada = false;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("Contrasena: " + contrasenaFinal);
        if (pos != string::npos) {
            encontrada = true;
            break;
        }
    }
    archivo.close();
    if (encontrada) {
        contrasenaFinal = contrasenaRepetida(contrasenaFinal,nombreArchivo);
    }
    char* resultado = (char*)malloc((contrasenaFinal.length() + 1) * sizeof(char));
    strcpy(resultado, contrasenaFinal.c_str());
    return resultado;
}
char* Persona::cifrarCesar(const char* texto, int desplazamiento) {
    int longitud = strlen(texto);
    char* textoCifrado = (char*)malloc((longitud + 1) * sizeof(char));
    if (!textoCifrado) {
        return nullptr;
    }
    const char* ptrTexto = texto;
    char* ptrCifrado = textoCifrado;
    while (*ptrTexto != '\0') {
        char c = *ptrTexto;
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            *ptrCifrado = (c - base + desplazamiento) % 26 + base;
        } else if (isdigit(c)) {
            *ptrCifrado = (c - '0' + desplazamiento) % 10 + '0';
        } else {
            *ptrCifrado = c;
        }
        ptrTexto++;
        ptrCifrado++;
    }
    *ptrCifrado = '\0';
    return textoCifrado;
}
string Persona::contrasenaRepetida(string contrasena,string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    int maxSufijo = -1;
    while (getline(archivo, linea)) {
        size_t pos = linea.find("Contrasena: " + contrasena);
        if (pos != string::npos) {
            size_t inicio = pos + 12 + contrasena.length();
            if (inicio < linea.length() && isdigit(linea[inicio])) {
                string sufijo = linea.substr(inicio);
                for (char &c : sufijo) {
                    if (isdigit(c)) {
                        char cifraOriginal = ((c - '0' - 5 + 10) % 10) + '0'; // Decifrar el sufijo numérico
                        c = cifraOriginal;
                    }
                }
                int sufijoInt = stoi(sufijo);
                if (sufijoInt > maxSufijo) {
                    maxSufijo = sufijoInt;
                }
            }
        }
    }
    archivo.close();
    int newSufijo = maxSufijo + 1;
    stringstream ss;
    ss << newSufijo;
    string sufijoString = ss.str();
    for (char &c : sufijoString) {
        char cifraCifrada = ((c - '0' + 5) % 10) + '0';
        c = cifraCifrada;
    }
    contrasena += sufijoString;
    return contrasena;
}

void Persona::disable_echo_mode(struct termios *old_attr) {
    struct termios new_attr;
    tcgetattr(STDIN_FILENO, old_attr);
    new_attr = *old_attr;
    new_attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
}

void Persona::restore_echo_mode(const struct termios *old_attr) {
    tcsetattr(STDIN_FILENO, TCSANOW, old_attr);
}
char* Persona::ingresarNumeros(const char *msj, int max_length) {
    printw("%s", msj);
    refresh();
    char *dato = (char *)malloc((max_length + 1) * sizeof(char));
    if (dato == nullptr) {
        cerr << "Error: No se pudo asignar memoria." << endl;
        return nullptr;
    }
    int i = 0;
    while (true) {
        int c = getch();
        if (c >= '0' && c <= '9' && i < max_length) {
            dato[i++] = c;
            printw("%c", c);
            refresh();
        } else if (c == KEY_BACKSPACE || c == 127) {
            if (i > 0) {
                i--;
                mvprintw(getcury(stdscr), getcurx(stdscr) - 1, " ");
                move(getcury(stdscr), getcurx(stdscr) - 1);
                refresh();
            }
        } else if (c == '\n') {
            break;
        }
    }
    dato[i] = '\0';
    printw("\n");
    refresh();
    return dato;
}
string Persona::ingresarLetras(const char* msj) {
    printw("%s", msj);  // Imprime el mensaje
    refresh();
    
    string dato;

    while (true) {
        int c = getch();

        if (isalpha(c) || c == ' ') {
            dato += static_cast<char>(c);
            printw("%c", c);
            refresh();
        } else if (c == KEY_BACKSPACE || c == 127) {
            if (!dato.empty()) {
                dato.pop_back();
                mvprintw(getcury(stdscr), getcurx(stdscr) - 1, " ");
                move(getcury(stdscr), getcurx(stdscr) - 1);
                refresh();
            }
        } else if (c == '\n') {
            if (!dato.empty()) {
                break;  // Rompe el bucle si hay datos ingresados
            }
            // No hace nada si se presiona Enter sin datos ingresados
        }
    }

    printw("\n");
    refresh();
    return dato;
}
string Persona::validarSegundoNombre(const char* msj, bool allowEmpty) {
    printw("%s", msj);
    refresh();
    string dato;
    while (true) {
        int c = getch();
        if (isalpha(c) || (allowEmpty && c == '\n')) {
            dato += static_cast<char>(c);
            printw("%c", c);
            refresh();
        } else if (c == KEY_BACKSPACE || c == 127) {
            if (!dato.empty()) {
                dato.pop_back();
                mvprintw(getcury(stdscr), getcurx(stdscr) - 1, " ");
                move(getcury(stdscr), getcurx(stdscr) - 1);
                refresh();
            }
        } else if (c == '\n') {
            break;
        }
    }
    printw("\n");
    refresh();
    return dato;
}
