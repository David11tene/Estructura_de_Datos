#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include "Persona.h"
#include <string>
#include <vector>
#include "ListaDobleCircular.h"

class ManejoArchivos {
public:
    // Guardar una persona en un archivo
    static void guardarPersona(const Persona& persona, const std::string& nombreArchivo, const std::string& contrasenaDesencriptada);

    // Cargar personas desde un archivo
    static std::vector<Persona> cargarPersonas(const std::string& nombreArchivo);

    // Guardar el reporte general en un archivo
    static void guardarReporte(const ListaDobleCircular& listaPersonas, const std::string& nombreArchivo);

    // Eliminar una persona de un archivo
    static void eliminarPersonaArchivo(const std::string& cedula, const std::string& nombreArchivo);
};

#endif // MANEJOARCHIVOS_H
