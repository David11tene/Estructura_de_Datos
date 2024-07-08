#include "Persona.h"

Persona::Persona(const std::string& cedula, const std::string& nombre, const std::string& apellido)
    : cedula(cedula), nombre(nombre), apellido(apellido) {}

std::string Persona::getCedula() const {
    return cedula;
}

std::string Persona::getNombre() const {
    return nombre;
}

std::string Persona::getApellido() const {
    return apellido;
}

void Persona::setCedula(const std::string& cedula) {
    this->cedula = cedula;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Persona::setApellido(const std::string& apellido) {
    this->apellido = apellido;
}
