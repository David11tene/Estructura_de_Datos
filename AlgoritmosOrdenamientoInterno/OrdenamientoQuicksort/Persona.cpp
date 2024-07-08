#include "Persona.h"
#include <iostream>

// Constructor
Persona::Persona(const std::string& cedula, const std::string& fechaNacimiento, const std::string& nombre,
    const std::string& apellido, const std::string& correo, const std::string& clave)
    : cedula(cedula), fechaNacimiento(fechaNacimiento), nombre(nombre),
    apellido(apellido), correo(correo), clave(clave) {}

// Getters
std::string Persona::getCedula() const {
    return cedula;
}

std::string Persona::getFechaNacimiento() const {
    return fechaNacimiento;
}

std::string Persona::getNombre() const {
    return nombre;
}

std::string Persona::getApellido() const {
    return apellido;
}

std::string Persona::getCorreo() const {
    return correo;
}

std::string Persona::getClave() const {
    return clave;
}
// Setters
void Persona::setCedula(const std::string& cedula) {
    this->cedula = cedula;
}

void Persona::setFechaNacimiento(const std::string& fechaNacimiento) {
    this->fechaNacimiento = fechaNacimiento;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}


void Persona::setApellido(const std::string& apellido) {
    this->apellido = apellido;
}

void Persona::setCorreo(const std::string& correo) {
    this->correo = correo;
}

void Persona::setClave(const std::string& clave) {
    this->clave = clave;
}

// Methods to manage vehicles

// Otros métodos
void Persona::mostrarInformacion() const {
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<"Informacion de la persona con cedula "<<cedula<< std::endl;
    std::cout << "Fecha de Nacimiento: " << fechaNacimiento << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << "Correo: " << correo << std::endl;
    std::cout<<"-----------------------------"<<std::endl;
}

std::string Persona::ordenarCaracteres(const std::string& input) {
    std::string sortedInput = input;
    std::transform(sortedInput.begin(), sortedInput.end(), sortedInput.begin(), ::tolower);
    std::sort(sortedInput.begin(), sortedInput.end());
    std::transform(sortedInput.begin(), sortedInput.end(), sortedInput.begin(), ::toupper);
    return sortedInput;
}

std::string Persona::ordenarCedulaNumericamente(const std::string& cedula) {
    std::string sortedCedula = cedula;
    std::sort(sortedCedula.begin(), sortedCedula.end());
    return sortedCedula;
}