#include "Simbolo.h"
#include <cstring>
using namespace std;

Simbolo::Simbolo(char simbolo) {
    this->simbolo = simbolo;
}

Simbolo::~Simbolo() {}

void Simbolo::setSimbolo(char simbolo) {
    this->simbolo = simbolo;
}

char Simbolo::getSimbolo() {
    return this->simbolo;
}

string Simbolo::toString() {
    string cadena = "";
    cadena += simbolo;
    return cadena;
}

bool Simbolo::equals(Object* item) {
    return this == item;
}