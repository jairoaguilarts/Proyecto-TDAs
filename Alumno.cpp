#include "Alumno.h"
#include <cstring>
using namespace std;

Alumno::Alumno(string nombre, string cuenta) {
    this->nombre= nombre;
    this->cuenta = cuenta;
}

Alumno::~Alumno() {}

void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}

string Alumno::getNombre() {
    return this->nombre;
}

void Alumno::setCuenta(string cuenta) {
    this->cuenta = cuenta;
}

string Alumno::getCuenta() {
    return this->cuenta;
}

string Alumno::toString() {
    return nombre + " - " + cuenta;
}

bool Alumno::equals(Object* item) {
    return this == item;
}