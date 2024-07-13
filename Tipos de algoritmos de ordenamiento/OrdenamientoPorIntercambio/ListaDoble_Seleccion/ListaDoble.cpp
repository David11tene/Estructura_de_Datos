#include "ListaDoble.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
ListaDoble<T>::ListaDoble() {
    primero = nullptr;
    ultimo = nullptr;
    cargarDesdeArchivo();
}

template <typename T>
ListaDoble<T>::~ListaDoble() {
    while (primero != nullptr) {
        NodoDoble<T>* aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
}

template <typename T>
void ListaDoble<T>::insertar(T numcedula, T primerNombre, T apellido) {
    if (cedulaRepetida(numcedula)) {
        cout << "El numero de cedula ya existe. No se puede insertar." << endl;
        return;
    }

    primerNombre = convertirMayusculas(primerNombre);
    apellido = convertirMayusculas(apellido);

    NodoDoble<T>* nuevo = new NodoDoble<T>(numcedula, primerNombre, apellido);

    if (listaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        nuevo->setSiguiente(primero);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }

    guardarEnArchivo();
}

template <typename T>
bool ListaDoble<T>::cedulaRepetida(T numcedula) {
    NodoDoble<T>* aux = primero;
    while (aux != nullptr) {
        if (aux->getNumCedula() == numcedula) {
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

template <typename T>
bool ListaDoble<T>::listaVacia() {
    return primero == nullptr;
}

template <typename T>
void ListaDoble<T>::buscar(T numcedula) {
    NodoDoble<T>* aux = primero;
    while (aux != nullptr) {
        if (aux->getNumCedula() == numcedula) {
            cout << "El numero de cedula " << numcedula << " corresponde a " << aux->getPrimerNombre() << " " << aux->getApellido() << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El numero de cedula " << numcedula << " no se encuentra en la lista" << endl;
}

template <typename T>
void ListaDoble<T>::eliminar(T numcedula) {
    NodoDoble<T>* actual = primero;

    while (actual != nullptr) {
        if (actual->getNumCedula() == numcedula) {
            if (actual->getAnterior() == nullptr) {
                primero = actual->getSiguiente();
                if (primero != nullptr) {
                    primero->setAnterior(nullptr);
                }
            } else {
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
            }

            if (actual->getSiguiente() != nullptr) {
                actual->getSiguiente()->setAnterior(actual->getAnterior());
            }

            if (actual == ultimo) {
                ultimo = actual->getAnterior();
            }

            delete actual;
            cout << "El usuario con el numero de cedula " << numcedula << " ha sido eliminado" << endl;
            guardarEnArchivo();
            return;
        }
        actual = actual->getSiguiente();
    }
    cout << "El numero de cedula " << numcedula << " no se encuentra en la lista" << endl;
}

template <typename T>
void ListaDoble<T>::mostrar() {
    if (listaVacia()) {
        cout << "Lista vacia." << endl;
        return;
    }
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo usuarios.txt" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

template <typename T>
void ListaDoble<T>::guardarEnArchivo() {
    ofstream archivo("usuarios.txt");
    NodoDoble<T>* aux = primero;
    while (aux != nullptr) {
        archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << endl;
        aux = aux->getSiguiente();
    }
    archivo.close();
}

template <typename T>
void ListaDoble<T>::guardarCaracteresOrdenadosEnArchivo(const std::string& atributo) {
    ofstream archivo("usuariosCaracteres.txt");
    NodoDoble<T>* aux = primero;
    while (aux != nullptr) {
        if (atributo == "cedula") {
            archivo << Ordenador<NodoDoble<T>>::ordenarCaracteres(aux->getNumCedula()) << "|" << aux->getPrimerNombre() << "|" << aux->getApellido() << endl;
        } else if (atributo == "nombre") {
            archivo << aux->getNumCedula() << "|" << Ordenador<NodoDoble<T>>::ordenarCaracteres(aux->getPrimerNombre()) << "|" << aux->getApellido() << endl;
        } else if (atributo == "apellido") {
            archivo << aux->getNumCedula() << "|" << aux->getPrimerNombre() << "|" << Ordenador<NodoDoble<T>>::ordenarCaracteres(aux->getApellido()) << endl;
        }
        aux = aux->getSiguiente();
    }
    archivo.close();
}

template <typename T>
void ListaDoble<T>::cargarDesdeArchivo() {
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) return;

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        T numcedula, primerNombre, apellido;
        getline(iss, numcedula, '|');
        getline(iss, primerNombre, '|');
        getline(iss, apellido, '|');

        NodoDoble<T>* nuevo = new NodoDoble<T>(numcedula, primerNombre, apellido);
        if (listaVacia()) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            nuevo->setSiguiente(primero);
            primero->setAnterior(nuevo);
            primero = nuevo;
        }
    }
    archivo.close();
}

template <typename T>
void ListaDoble<T>::cargarCaracteresDesdeArchivo() {
    ifstream archivo("usuariosCaracteres.txt");
    if (!archivo.is_open()) return;

    string linea;
    NodoDoble<T>* ultimo = nullptr;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        T numcedula, primerNombre, apellido;
        getline(iss, numcedula, '|');
        getline(iss, primerNombre, '|');
        getline(iss, apellido, '|');

        NodoDoble<T>* nuevo = new NodoDoble<T>(numcedula, primerNombre, apellido);
        if (ultimo == nullptr) {
            primero = nuevo;
        } else {
            ultimo->setSiguiente(nuevo);
            nuevo->setAnterior(ultimo);
        }
        ultimo = nuevo;
    }
    archivo.close();
}

template <typename T>
bool ListaDoble<T>::validarCedula(long int cedula) {
    int i, A[10], res, mul, sumapares, sumaimpares, digito, sumatotal;
    long int cos;
    sumapares = 0;
    sumaimpares = 0;
    for (i = 9; i >= 0; i--) {
        cos = cedula / 10;
        res = cedula % 10;
        A[i] = res;
        cedula = cos;
    }
    for (i = 0; i < 9; i += 2) {
        mul = A[i] * 2;
        if (mul > 9)
            mul -= 9;
        sumapares += mul;
    }
    for (i = 1; i < 8; i += 2)
        sumaimpares += A[i];

    sumatotal = sumapares + sumaimpares;
    res = sumatotal % 10;
    digito = 10 - res;

    if (digito == 10)
        digito = 0;
    return digito == A[9];
}

template <typename T>
bool ListaDoble<T>::esNumeroCedulaValido(const T &numcedula) {
    if (numcedula.length() != 10) return false;
    for (char c : numcedula) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

template <typename T>
T ListaDoble<T>::ingresarOpcion(const std::string &msj, int minOpcion, int maxOpcion) {
    T dato = "";
    cout << msj << ": ";
    char c;
    while (true) {
        c = getch();
        if (isdigit(c) && dato.length() < 2) {
            dato += c;
            cout << c;
        } else if (c == 8 && !dato.empty()) {
            dato.pop_back();
            cout << "\b \b";
        } else if (c == 13 && !dato.empty()) {
            int opcion = stoi(dato);
            if (opcion >= minOpcion && opcion <= maxOpcion) {
                cout << endl;
                return dato;
            } else {
                cout << "\n>> Opcion invalida. Ingrese nuevamente." << endl;
                dato = "";
                cout << msj << ": ";
            }
        }
    }
}

template <typename T>
T ListaDoble<T>::ingresarCedula(const std::string &msj) {
    T dato = "";
    cout << msj << ": ";
    char c;
    while (true) {
        c = getch();
        if (isdigit(c) && c != ' ') {
            if (dato.length() < 10) {
                dato += c;
                cout << c;
            }
        } else if (c == 8) {
            if (!dato.empty()) {
                dato.pop_back();
                cout << "\b \b";
            }
        } else if (c == 13) {
            if (dato.length() == 10) {
                cout << endl;
                break;
            } else {
                cout << "\n>> Debe ingresar exactamente 10 numeros. Intente nuevamente." << endl;
                dato = "";
                cout << msj << ": ";
            }
        }
    }
    return dato;
}

template <typename T>
T ListaDoble<T>::ingresarNumeros(const std::string &msj) {
    T dato = "";
    cout << msj << ": ";
    char c;
    while ((c = getch()) != 13) {
        if (isdigit(c)) {
            dato += c;
            cout << c;
        } else if (c == 8) { 
            if (!dato.empty()) {
                dato.pop_back();
                cout << "\b \b";
            }
        }
        else if (c == ' ') {
            
        }
    }
    cout << endl;
    return dato;
}

template <typename T>
T ListaDoble<T>::ingresarLetras(const std::string &msj) {
    T dato = "";
    cout << msj << ": ";
    char c;
    while ((c = getch()) != 13) {
        if (isalpha(c)) {
            dato += c;
            cout << c;
        } else if (c == 8) { 
            if (!dato.empty()) {
                dato.pop_back();
                cout << "\b \b";
            }
        }
    }
    cout << endl;
    return dato;
}

template <typename T>
T ListaDoble<T>::convertirMayusculas(T str) {
    if (str.empty()) return str;
    *str.begin() = toupper(*str.begin());
    for (auto it = str.begin() + 1; it != str.end(); ++it) {
        *it = tolower(*it);
    }
    return str;
}

/******************METODO DE ORDENAMIENTO*******************/

template <typename T>
template <typename Compare>
void ListaDoble<T>::ordenar(Compare comp) {
    Ordenador<NodoDoble<T>>::ordenarPorSeleccion(primero, comp);
    guardarEnArchivo();
}

template <typename T>
void ListaDoble<T>::ordenarCaracteresEnAtributo(const std::string& atributo) {
    Ordenador<NodoDoble<T>>::ordenarCaracteresEnAtributo(primero, atributo);
    guardarCaracteresOrdenadosEnArchivo(atributo); // Guardar solo en usuariosCaracteres.txt
}

template <typename T>
void ListaDoble<T>::mostrarCaracteresOrdenados() {
    if (listaVacia()) {
        cout << "Lista vacia." << endl;
        return;
    }
    ifstream archivo("usuariosCaracteres.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo usuariosCaracteres.txt" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

template <typename T>
void ListaDoble<T>::resetLista() {
    while (primero != nullptr) {
        NodoDoble<T>* aux = primero;
        primero = primero->getSiguiente();
        delete aux;
    }
    ultimo = nullptr;
}
