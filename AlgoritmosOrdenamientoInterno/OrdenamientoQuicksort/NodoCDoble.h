#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class NodoCDoble {
private:

public:
    Persona* persona;
    NodoCDoble* siguiente;
    NodoCDoble* anterior;
    // Constructor
    NodoCDoble(Persona* persona);

    // Getter
    Persona* getPersona() const;
    NodoCDoble* getSiguiente() const;
    NodoCDoble* getAnterior() const;

    // Setters
    void setPersona(Persona* persona); 
    void setSiguiente(NodoCDoble* siguiente);
    void setAnterior(NodoCDoble* anterior);
};

#endif // NODO_H

