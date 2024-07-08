#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
private:
    string primerNombre;
    string segundoNombre;
    string apellido;
    string cedula;
    string correo;
    string password;

public:
    Persona();
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
    string generarCorreo(string nombre);
    string correoRepetido(string correo, string inicio, int contador, string nombreArchivo);
    string convertirMinusculas(string cadena);
    string datos(string primerNombre, string segundoNombre, string apellido);
    bool cedulaRepetida(string cedula, string nombreArchivo);
    bool validarCedula(const char* cedula);
    char* generarContrasena(Persona* persona, string nombreArchivo);
    char* cifrarCesar(const char* texto, int desplazamiento);
    string contrasenaRepetida(string contrasena, string nombreArchivo);
    void disable_echo_mode(struct termios* old_attr);
    void restore_echo_mode(const struct termios* old_attr);
    char* ingresarNumeros(const char* msj, int max_length);
    string ingresarLetras(const char* msj);
    string validarSegundoNombre(const char* msj, bool allowEmpty);
};

#endif // PERSONA_H
