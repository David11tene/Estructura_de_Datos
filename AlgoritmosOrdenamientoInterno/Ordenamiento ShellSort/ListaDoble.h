#include "NodoDoble.cpp"
#include <functional>

class ListaDoble {
private:
    NodoDoble* primero;
    NodoDoble* ultimo;

public:
    ListaDoble();
    ~ListaDoble();
    void insertar(Persona* persona);
    void guardarDatosPersona(Persona* persona);
    bool cargarDatosPersona();
    void mostrarDatosOrdenados();
    void imprimir();
    void ordenar(const std::function<bool(Persona*, Persona*)>& comparar);
    void guardarDatosOrdenadosEnArchivo();
    void ordenarPorCaracter();
};
