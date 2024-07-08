#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

class Validaciones {
public:

    static bool leerFechaSinValidarEdad(const std::string& fecha);
    // Validar c�dula
    static bool validarCedula(const std::string& cedula);

    // Validar correo electr�nico con formato espec�fico

    // Validar nombre y apellido (sin caracteres especiales, solo letras)
    static bool validarNombre(const std::string& nombre);

    // Validar fecha de nacimiento (formato YYYY-MM-DD)
    static bool validarFecha(const std::string& fecha);

    // Validar si un a�o es bisiesto

    // Leer entrada sin espacios ni letras (para c�dula)
    static std::string leerCedula();

    // Leer entrada sin n�meros ni espacios (para nombre y apellido)
    static std::string leerNombre();

    // Leer fecha con formato YYYY-MM-DD
    static std::string leerFecha();



private:
    static const std::set<std::string> provinciasValidas;
    static bool validarCaracter(const std::string& cedula);
};

#endif // VALIDACIONES_H
