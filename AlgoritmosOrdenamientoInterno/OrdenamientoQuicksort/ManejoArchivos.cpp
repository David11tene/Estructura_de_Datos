#include "ManejoArchivos.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "ListaDobleCircular.h"

using namespace std;

// Guardar una persona en un archivo
void ManejoArchivos::guardarPersona(const Persona& persona, const std::string& nombreArchivo, const std::string& contrasenaDesencriptada) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        archivo << "Cedula: " << persona.getCedula() << "\n";
        archivo << "Fecha de Nacimiento: " << persona.getFechaNacimiento() << "\n";
        archivo << "Nombre: " << persona.getNombre() << "\n";
        archivo << "Apellido: " << persona.getApellido() << "\n";
        archivo << "Correo: " << persona.getCorreo() << "\n";
        archivo << "Clave Encriptada: " << persona.getClave() << "\n";
        archivo << "Clave Desencriptada: " << contrasenaDesencriptada << "\n";
        archivo << "-----------------------------\n";
        archivo.close();
    }
}

// Cargar personas desde un archivo
std::vector<Persona> ManejoArchivos::cargarPersonas(const std::string& nombreArchivo) {
    std::vector<Persona> personas;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (archivo.is_open()) {
        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);
            std::string cedula, fechaNacimiento, nombre, apellido, correo, clave;

            std::getline(ss, cedula, ',');
            std::getline(ss, fechaNacimiento, ',');
            std::getline(ss, nombre, ',');
            std::getline(ss, apellido, ',');
            std::getline(ss, correo, ',');
            std::getline(ss, clave, ',');

            personas.emplace_back(cedula, fechaNacimiento, nombre, apellido, correo, clave);
        }
        archivo.close();
    }
    return personas;
}

void ManejoArchivos::guardarReporte(const ListaDobleCircular& listaPersonas, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        if (listaPersonas.estaVacia()) {
            archivo << "No hay personas registradas." << std::endl;
        }
        else {
            NodoCDoble* actual = listaPersonas.head;
            do {
                Persona* persona = actual->getPersona();
                archivo << "Cedula: " << persona->getCedula() << "\n";
                archivo << "Fecha de Nacimiento: " << persona->getFechaNacimiento() << "\n";
                archivo << "Nombre: " << persona->getNombre() << "\n";
                archivo << "Apellido: " << persona->getApellido() << "\n";
                archivo << "Correo: " << persona->getCorreo() << "\n";
                archivo << "-----------------------------\n";
                actual = actual->getSiguiente();
            } while (actual != listaPersonas.head);
        }
        archivo.close();
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escritura." << std::endl;
    }
}

// Eliminar una persona del archivo
void ManejoArchivos::eliminarPersonaArchivo(const std::string& cedula, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::ofstream archivoTemporal("temp.txt");
    std::string linea;

    if (archivo.is_open() && archivoTemporal.is_open()) {
        while (std::getline(archivo, linea)) {
            if (linea.find("Cedula: " + cedula) != std::string::npos) {
                // Skip the next 6 lines (persona data and separator)
                for (int i = 0; i < 6; ++i) {
                    std::getline(archivo, linea);
                }
            }
            else {
                archivoTemporal << linea << "\n";
            }
        }
        archivo.close();
        archivoTemporal.close();
        std::remove(nombreArchivo.c_str());
        std::rename("temp.txt", nombreArchivo.c_str());
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para lectura o escritura." << std::endl;
    }
}
