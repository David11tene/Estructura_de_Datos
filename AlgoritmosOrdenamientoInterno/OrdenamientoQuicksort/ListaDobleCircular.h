#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include "NodoCDoble.h" 
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>

class ListaDobleCircular {
private:
    NodoCDoble* partition(NodoCDoble* low, NodoCDoble* high, const std::string& campo);
    void _quickSort(NodoCDoble* low, NodoCDoble* high, const std::string& campo);
public:
    NodoCDoble* head;
    int contadorContrasenas;
    std::map<std::string, int> contadorCorreos;

    // Constructor
    ListaDobleCircular();

    // Destructor
    ~ListaDobleCircular();

    // Métodos de la lista
    void insertarInicio(Persona* persona);
    void insertarFinal(Persona* persona);
    void eliminarPersonaPorCedula(const std::string& cedula);
    NodoCDoble* buscarPersona(const std::string& cedula) const;
    void mostrarLista() const;
    bool estaVacia() const;

    // Métodos adicionales
    std::string generarContrasena(const std::string& primerNombre, const std::string& segundoNombre, const std::string& apellido) const;
    std::string descifrarContrasena(const std::string& contrasenaEncriptada) const;
    void generarCorreos();
    std::string toLowerCase(const std::string& str) const;
    std::string toUpperCase(const std::string& str) const;
    std::string obtenerCorreo(const std::string& Nombre, const std::string& apellido);
    void cargarPersonasDesdeArchivo(const std::string& nombreArchivo);

    // Métodos de ordenamiento
    void quickSort();
    void invertirLista();
    void ordenarPorCampo(const std::string& campo);
    void ordenarCaracteresDeCampo(const std::string& campo) const;
    void ordenarCedulasAscendente();
    void ordenarCedulasCaracteres();
};

#endif // LISTADOBLECIRCULAR_H
