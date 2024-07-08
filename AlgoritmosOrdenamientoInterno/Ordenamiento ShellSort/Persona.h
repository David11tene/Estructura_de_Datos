#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;
class Persona{
private:
    string primerNombre;
    string segundoNombre;
    string apellido;
    string cedula;
    string correo;
    string password;
public:
    Persona();
    ~Persona();
    string getPrimerNombre();
    string getSegundoNombre();
    string getApellido();
    string getCedula();
    string getCorreo();
    string getPassword();
    void setPrimerNombre(string primerNombre);
    void setSegundoNombre(string segundoNombre);
    void setApellido(string apellido);
    void setCedula(string cedula);
    void setCorreo(string correo);
    void setPassword(string password);
    char* ingresarNumeros(const char* msj, int longitud);
    string ingresarLetras(const char* msj);
    string validarSegundoNombre(const char* msj, bool permitirVacio);
    string convertirMinusculas(string cadena);
    string datos(string primerNombre,string segundoNombre,string apellido);
    void disable_echo_mode(struct termios *old_attr);
    void restore_echo_mode(const struct termios *old_attr);
    bool validarCedula(const char* cedula);
    bool cedulaRepetida(string cedula,string cadena);
    string generarCorreo(string cadena);
    string correoRepetido(string correo, string inicio, int contador, string cadena);
    char* generarContrasena(Persona* persona, string cadena);
    char* cifrarCesar(const char* texto, int desplazamiento);
    string contrasenaRepetida(string password,string cadena);
};
#endif //PERSONA_H