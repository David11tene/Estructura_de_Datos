#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
protected:
    std::string cedula;
    std::string nombre;
    std::string apellido;

public:
    Persona(const std::string& cedula, const std::string& nombre, const std::string& apellido);
    virtual ~Persona() = default;

    std::string getCedula() const;
    std::string getNombre() const;
    std::string getApellido() const;

    void setCedula(const std::string& cedula);
    void setNombre(const std::string& nombre);
    void setApellido(const std::string& apellido);
};

#endif
