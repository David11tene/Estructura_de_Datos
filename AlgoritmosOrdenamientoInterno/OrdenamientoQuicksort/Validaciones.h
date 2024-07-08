#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

class Validaciones {
public:

    static bool leerFechaSinValidarEdad(const std::string& fecha);
    // Validar cédula
    static bool validarCedula(const std::string& cedula);

    // Validar correo electrónico con formato específico

    // Validar nombre y apellido (sin caracteres especiales, solo letras)
    static bool validarNombre(const std::string& nombre);

    // Validar fecha de nacimiento (formato YYYY-MM-DD)
    static bool validarFecha(const std::string& fecha);

    // Validar si un año es bisiesto

    // Leer entrada sin espacios ni letras (para cédula)
    static std::string leerCedula();

    // Leer entrada sin números ni espacios (para nombre y apellido)
    static std::string leerNombre();

    // Leer fecha con formato YYYY-MM-DD
    static std::string leerFecha();



private:
    static const std::set<std::string> provinciasValidas;
    static bool validarCaracter(const std::string& cedula);
};

#endif // VALIDACIONES_H
