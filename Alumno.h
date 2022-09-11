#ifndef ALUMNO_H
#define ALUMNO_H

#include "Object.h"
#include <cstring>
using std::string;

class Alumno : public Object {
    private:
        string nombre, cuenta;
    public:
        Alumno(string, string);
        ~Alumno();
        void setNombre(string);
        string getNombre();
        void setCuenta(string);
        string getCuenta();
        string toString();
        bool equals(Object*);
};

#endif