#include "ListaDobleCircular.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <string>


using namespace std;

// Constructor
ListaDobleCircular::ListaDobleCircular() : head(nullptr), contadorContrasenas(0) {}

// Destructor
ListaDobleCircular::~ListaDobleCircular() {
    if (head) {
        NodoCDoble* temp = head;
        do {
            NodoCDoble* next = temp->getSiguiente();
            delete temp;
            temp = next;
        } while (temp != head);
    }
}

// Insertar al inicio
void ListaDobleCircular::insertarInicio(Persona* persona) {
    NodoCDoble* nuevoNodo = new NodoCDoble(persona);
    if (estaVacia()) {
        head = nuevoNodo;
        head->setSiguiente(head);
        head->setAnterior(head);
    }
    else {
        NodoCDoble* tail = head->getAnterior();
        nuevoNodo->setSiguiente(head);
        nuevoNodo->setAnterior(tail);
        head->setAnterior(nuevoNodo);
        tail->setSiguiente(nuevoNodo);
        head = nuevoNodo;
    }
}

// Insertar al final
void ListaDobleCircular::insertarFinal(Persona* persona) {
    NodoCDoble* nuevoNodo = new NodoCDoble(persona);
    if (estaVacia()) {
        head = nuevoNodo;
        head->setSiguiente(head);
        head->setAnterior(head);
    }
    else {
        NodoCDoble* tail = head->getAnterior();
        tail->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(tail);
        nuevoNodo->setSiguiente(head);
        head->setAnterior(nuevoNodo);
    }
}

// Buscar persona
NodoCDoble* ListaDobleCircular::buscarPersona(const std::string& cedula) const {
    if (!estaVacia()) {
        NodoCDoble* actual = head;
        do {
            if (actual->getPersona()->getCedula() == cedula) {
                return actual;
            }
            actual = actual->getSiguiente();
        } while (actual != head);
    }
    return nullptr;
}

void ListaDobleCircular::mostrarLista() const
{
    if (estaVacia()) {
        std::cout << "No hay personas registradas." << std::endl;
        return;
    }

    NodoCDoble* actual = head;
    do {
        Persona* persona = actual->getPersona();
        persona->mostrarInformacion();
        actual = actual->getSiguiente();
    } while (actual != head);
}

        bool ListaDobleCircular::estaVacia() const {
            return head == nullptr;
        
}


// Generar contraseña
std::string ListaDobleCircular::generarContrasena(const std::string& primerNombre, const std::string& segundoNombre, const std::string& apellido) const {
    if (primerNombre.empty() || segundoNombre.empty() || apellido.empty()) {
        return "";
    }

    std::string contrasenaBase;
    contrasenaBase += apellido.back();
    contrasenaBase += toupper(segundoNombre[0]);
    contrasenaBase += toupper(primerNombre[0]);
    contrasenaBase += apellido.substr(1, 3);
    contrasenaBase += toupper(apellido[0]);
    contrasenaBase += std::to_string(contadorContrasenas);

    std::string contrasenaEncriptada;
    for (char c : contrasenaBase) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + 5) % 26 + base;
        }
        contrasenaEncriptada += c;
    }
    return contrasenaEncriptada;
}

// Desencriptar contraseña
std::string ListaDobleCircular::descifrarContrasena(const std::string& contrasenaEncriptada) const {
    std::string contrasenaDescifrada;
    for (char c : contrasenaEncriptada) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - 5 + 26) % 26 + base;
        }
        contrasenaDescifrada += c;
    }
    return contrasenaDescifrada;
}

std::string ListaDobleCircular::toLowerCase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Transformar a mayusculas
std::string ListaDobleCircular::toUpperCase(const std::string& str) const {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

// Obtener correo
std::string ListaDobleCircular::obtenerCorreo(const std::string& Nombre, const std::string& apellido) {
    std::string siglas = std::string(1, tolower(Nombre[0])) + toLowerCase(apellido);
    std::string correo = siglas;
    if (contadorCorreos[siglas] > 0) {
        correo += std::to_string(contadorCorreos[siglas]);
    }
    contadorCorreos[siglas]++;
    return correo + "@espe.edu.ec";
}

// Generar correos
void ListaDobleCircular::generarCorreos() {
    NodoCDoble* actual = head;

    if (actual != nullptr) {
        do {
            if (actual->getPersona()->getCorreo().empty()) {
                std::string correo = obtenerCorreo(actual->getPersona()->getNombre(), actual->getPersona()->getApellido());
                actual->getPersona()->setCorreo(correo);
                std::cout << "Correo: " << correo << std::endl;
            }
            actual = actual->getSiguiente();
        } while (actual != head);
    }
}

// Buscar vehículo por placa

void ListaDobleCircular::eliminarPersonaPorCedula(const std::string& cedula) {
    if (estaVacia()) {
        std::cout << "No hay personas registradas." << std::endl;
        return;
    }

    NodoCDoble* actual = head;
    NodoCDoble* anterior = nullptr;
    do {
        if (actual->getPersona()->getCedula() == cedula) {
            NodoCDoble* siguiente = actual->getSiguiente();

            if (actual == head) {
                if (head->getSiguiente() == head) { // Solo un NodoCDoble en la lista
                    head = nullptr;
                }
                else {
                    NodoCDoble* tail = head->getAnterior();
                    head = siguiente;
                    tail->setSiguiente(head);
                    head->setAnterior(tail);
                }
            }
            else {
                anterior->setSiguiente(siguiente);
                siguiente->setAnterior(anterior);
            }

            delete actual;
            std::cout << "Persona con cedula " << cedula << " eliminada correctamente." << std::endl;
            return;
        }
        anterior = actual;
        actual = actual->getSiguiente();
    } while (actual != head);

    std::cout << "Persona con cedula " << cedula << " no encontrada." << std::endl;
}

bool archivoExiste(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

void ListaDobleCircular::cargarPersonasDesdeArchivo(const std::string& nombreArchivo) {
    if (!archivoExiste(nombreArchivo)) {
        std::cout << "El archivo " << nombreArchivo << " no existe." << std::endl;
        return;
    }

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de personas." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("Cedula: ") != std::string::npos) {
            std::string cedula = linea.substr(8);

            std::getline(archivo, linea);
            std::string fechaNacimiento = linea.substr(19);

            std::getline(archivo, linea);
            std::string nombre = linea.substr(8);

            std::getline(archivo, linea);
            std::string apellido = linea.substr(10);

            std::getline(archivo, linea);
            std::string correo = linea.substr(8);

            std::getline(archivo, linea);
            std::string clave = linea.substr(18);

            Persona* nuevaPersona = new Persona(cedula, fechaNacimiento, nombre, apellido, correo, clave);
            insertarFinal(nuevaPersona);

            // Leer la línea de separación
            std::getline(archivo, linea);
        }
    }
    archivo.close();
}

NodoCDoble* ListaDobleCircular::partition(NodoCDoble* low, NodoCDoble* high, const std::string& campo) {
    std::string pivot;
    if (campo == "cedula") {
        pivot = high->getPersona()->getCedula();
    }
    else if (campo == "nombre") {
        pivot = high->getPersona()->getNombre();
    }
    else if (campo == "apellido") {
        pivot = high->getPersona()->getApellido();
    }

    NodoCDoble* i = low->getAnterior();

    for (NodoCDoble* j = low; j != high; j = j->getSiguiente()) {
        std::string valorJ;
        if (campo == "cedula") {
            valorJ = j->getPersona()->getCedula();
        }
        else if (campo == "nombre") {
            valorJ = j->getPersona()->getNombre();
        }
        else if (campo == "apellido") {
            valorJ = j->getPersona()->getApellido();
        }

        if (valorJ <= pivot) {
            i = (i == nullptr) ? low : i->getSiguiente();
            std::swap(i->persona, j->persona);
        }
    }
    i = (i == nullptr) ? low : i->getSiguiente();
    std::swap(i->persona, high->persona);
    return i;
}

void ListaDobleCircular::_quickSort(NodoCDoble* low, NodoCDoble* high, const std::string& campo) {
    if (high != nullptr && low != high && low != high->getSiguiente()) {
        NodoCDoble* p = partition(low, high, campo);
        _quickSort(low, p->getAnterior(), campo);
        _quickSort(p->getSiguiente(), high, campo);
    }
}

void ListaDobleCircular::quickSort() {
    if (!estaVacia()) {
        NodoCDoble* tail = head->getAnterior();
        _quickSort(head, tail, "cedula");
    }
}
void ListaDobleCircular::invertirLista() {
    if (estaVacia()) return;

    NodoCDoble* actual = head;
    NodoCDoble* temp = nullptr;

    do {
        temp = actual->getAnterior();
        actual->setAnterior(actual->getSiguiente());
        actual->setSiguiente(temp);
        actual = actual->getAnterior();
    } while (actual != head);

    if (temp != nullptr) {
        head = temp->getAnterior();
    }
}

void ListaDobleCircular::ordenarPorCampo(const std::string& campo) {
    if (!estaVacia()) {
        NodoCDoble* tail = head->getAnterior();
        _quickSort(head, tail, campo);
    }
}

void ListaDobleCircular::ordenarCaracteresDeCampo(const std::string& campo) const {
    if (estaVacia()) return;

    NodoCDoble* actual = head;
    do {
        if (campo == "nombre") {
            std::string nombreOrdenado = Persona::ordenarCaracteres(actual->getPersona()->getNombre());
            actual->getPersona()->setNombre(nombreOrdenado);
        }
        else if (campo == "apellido") {
            std::string apellidoOrdenado = Persona::ordenarCaracteres(actual->getPersona()->getApellido());
            actual->getPersona()->setApellido(apellidoOrdenado);
        }
        actual = actual->getSiguiente();
    } while (actual != head);
}

void ListaDobleCircular::ordenarCedulasCaracteres() {
    if (estaVacia()) return;

    NodoCDoble* actual = head;
    do {
        std::string cedulaOrdenada = Persona::ordenarCedulaNumericamente(actual->getPersona()->getCedula());
        actual->getPersona()->setCedula(cedulaOrdenada);
        actual = actual->getSiguiente();
    } while (actual != head);
}
