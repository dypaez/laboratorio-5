#include "Usuario.h"

using namespace std;

Usuario::Usuario()
    : identificador(""), nombre(""), password("") {
}

Usuario::Usuario(const string& identificador, const string& nombre, const string& password, const string& rol)
    : identificador(identificador), nombre(nombre), password(password), rol(rol) {
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
string Usuario::getRol() const{
    return rol;
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
