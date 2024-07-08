#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
#include <string>

class ExcepcionBase : public std::exception {
protected:
    std::string mensaje;

public:
    ExcepcionBase(const std::string& mensaje) : mensaje(mensaje) {}
    virtual const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class ExcepcionPersonaNoEncontrada : public ExcepcionBase {
public:
    ExcepcionPersonaNoEncontrada(const std::string& cedula)
        : ExcepcionBase("Persona con cedula " + cedula + " no encontrada.") {}
};

class ExcepcionPlacaYaRegistrada : public ExcepcionBase {
public:
    ExcepcionPlacaYaRegistrada(const std::string& placa)
        : ExcepcionBase("Placa " + placa + " ya registrada.") {}
};

#endif // EXCEPCIONES_H

