#include "Usuario.h"

using namespace std;

Usuario::Usuario()
    : identificador(""), nombre(""), password("") {
}

Usuario::Usuario(const string& identificador, const string& nombre, const string& password)
    : identificador(identificador), nombre(nombre), password(password) {
}

Usuario::~Usuario() {
}

string Usuario::getIdentificador() const {
    return identificador;
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getPassword() const {
    return password;
}

void Usuario::setIdentificador(const string& identificador) {
    this->identificador = identificador;
}

void Usuario::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Usuario::setPassword(const string& password) {
    this->password = password;
}

bool Usuario::validarPassword(const string& password) const {
    return this->password == password;
}
