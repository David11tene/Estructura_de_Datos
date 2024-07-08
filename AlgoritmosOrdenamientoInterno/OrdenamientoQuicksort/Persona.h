#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>
#include <algorithm>
class Persona {
private:
    std::string cedula;
    std::string fechaNacimiento;
    std::string nombre;
    std::string apellido;
    std::string correo;
    std::string clave;
public:
    // Constructor
    Persona(const std::string& cedula, const std::string& fechaNacimiento, const std::string& nombre,
        const std::string& apellido, const std::string& correo, const std::string& clave);

    // Getters
    std::string getCedula() const;
    std::string getFechaNacimiento() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getCorreo() const;
    std::string getClave() const;

    // Setters
    void setCedula(const std::string& cedula);
    void setFechaNacimiento(const std::string& fechaNacimiento);
    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
    void setCorreo(const std::string& correo);
    void setClave(const std::string& clave);

    // Otros métodos
    void mostrarInformacion() const;
    static std::string ordenarCaracteres(const std::string& input);
    static std::string ordenarCedulaNumericamente(const std::string& cedula);
};

#endif // PERSONA_H
