#include "Validaciones.h"
#include <regex>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <set>

using namespace std;

bool Validaciones::validarCaracter(const std::string& cedula) {
    for (char c : cedula) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool Validaciones::validarCedula(const std::string& cedula) {
    if (cedula.size() != 10 || !validarCaracter(cedula)) {
        return false;
    }
    int suma = 0;
    int aux = 0;
    int verificador = 0;
    for (int i = 0; i < cedula.size() - 1; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            aux = digito * 2;
            if (aux > 9) {
                aux -= 9;
            }
        }
        else {
            aux = digito;
        }
        suma += aux;
    }
    verificador = 10 - (suma % 10);
    if (verificador == 10) {
        verificador = 0;
    }
    return verificador == (cedula.back() - '0');
}

// Validar nombre y apellido (sin caracteres especiales, solo letras)
bool Validaciones::validarNombre(const std::string& nombre) {
    const std::regex pattern(R"([A-Za-z]+)");
    return std::regex_match(nombre, pattern);
}

// Leer entrada sin espacios ni letras (para cédula)
std::string Validaciones::leerCedula() {
    std::string entrada;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r') {
            if (!entrada.empty()) {
                break;  // Solo permite enviar si hay algo en la entrada
            }
        }
        else if (isdigit(ch)) {
            entrada += ch;
            std::cout << ch;
        }
        else if (ch == '\b' && !entrada.empty()) {
            entrada.pop_back();
            std::cout << "\b \b";
        }
    }
    std::cout << std::endl;
    return entrada;
}

std::string Validaciones::leerNombre() {
    std::string entrada;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r') {
            if (!entrada.empty()) {
                break;  // Solo permite enviar si hay algo en la entrada
            }
        }
        else if (isalpha(ch)) {
            entrada += ch;
            std::cout << ch;
        }
        else if (ch == '\b' && !entrada.empty()) {
            entrada.pop_back();
            std::cout << "\b \b";
        }
    }
    std::cout << std::endl;
    return entrada;
}

// Función para verificar si un año es bisiesto
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

// Validar fecha de nacimiento (formato YYYY-MM-DD)
bool Validaciones::validarFecha(const std::string& fecha) {
    // Verificar longitud y formato
    if (fecha.size() != 10 && fecha.size() != 9 && fecha.size() != 8) return false;  // La longitud debe ser mínimo 8 máximo 10
    if (fecha[4] != '-' || (fecha.size() == 10 && fecha[7] != '-') || (fecha.size() == 9 && fecha[6] != '-')) return false;

    int anio, mes, dia;
    char delim;
    std::stringstream ss(fecha);
    ss >> anio >> delim >> mes >> delim >> dia;

    // Validar el rango de año, mes y día
    if (anio < 1900 || anio > 2024) return false;
    if (mes < 1 || mes > 12) return false;

    // Días válidos para cada mes
    int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajustar febrero para años bisiestos
    if (mes == 2 && esBisiesto(anio)) {
        diasEnMes[1] = 29;
    }

    if (dia < 1 || dia > diasEnMes[mes - 1]) return false;

    // Convertir la fecha ingresada a un struct tm
    std::tm fechaIngresada = {};
    fechaIngresada.tm_year = anio - 1900;
    fechaIngresada.tm_mon = mes - 1;
    fechaIngresada.tm_mday = dia;

    // Obtener la fecha actual
    std::time_t t = std::time(nullptr);
    std::tm* fechaActual = std::localtime(&t);

    // Fecha límite para ser mayor de edad (18 años antes de la fecha actual)
    std::tm fechaLimite = *fechaActual;
    fechaLimite.tm_year -= 18;

    // Convertir las fechas a tiempo epoch para comparar
    std::time_t tiempoIngresado = std::mktime(&fechaIngresada);
    std::time_t tiempoLimite = std::mktime(&fechaLimite);

    // Comparar las fechas para verificar mayoría de edad
    if (difftime(tiempoLimite, tiempoIngresado) < 0) return false;

    return true;
}



// Leer fecha con formato YYYY-MM-DD
std::string Validaciones::leerFecha() {
    std::string entrada;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r') {
            if (!entrada.empty()) {
                break;  // Solo permite enviar si hay algo en la entrada
            }
        }
        else if (isdigit(ch) || ch == '-') {
            entrada += ch;
            std::cout << ch;
        }
        else if (ch == '\b' && !entrada.empty()) {
            entrada.pop_back();
            std::cout << "\b \b";
        }
    }
    std::cout << std::endl;
    return entrada;
}
bool Validaciones::leerFechaSinValidarEdad(const std::string& fecha) {
    // Verificar longitud y formato
    if (fecha.size() != 10 && fecha.size() != 9 && fecha.size() != 8) return false;  // La longitud debe ser mínimo 8 máximo 10
    if (fecha[4] != '-' || (fecha.size() == 10 && fecha[7] != '-') || (fecha.size() == 9 && fecha[6] != '-')) return false;

    int anio, mes, dia;
    char delim;
    std::stringstream ss(fecha);
    ss >> anio >> delim >> mes >> delim >> dia;

    // Validar el rango de año, mes y día
    if (anio < 1900 || anio > 2024) return false;
    if (mes < 1 || mes > 12) return false;

    // Días válidos para cada mes
    int diasEnMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajustar febrero para años bisiestos
    if (mes == 2 && esBisiesto(anio)) {
        diasEnMes[1] = 29;
    }

    if (dia < 1 || dia > diasEnMes[mes - 1]) return false;

    return true;
}
