#include "Usuario.h"

Usuario::Usuario() : identificador(""), nombre(""), password("") {}

Usuario::Usuario(const std::string& identificador, const std::string& nombre, const std::string& password)
    : identificador(identificador), nombre(nombre), password(password) {}

Usuario::~Usuario() {}

std::string Usuario::getIdentificador() const {
    return identificador;
}

std::string Usuario::getNombre() const {
    return nombre;
}

std::string Usuario::getPassword() const {
    return password;
}

void Usuario::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Usuario::setPassword(const std::string& password) {
    this->password = password;
}

bool Usuario::validarPassword(const std::string& password) const {
    return this->password == password;
}

DtUsuario Usuario::obtenerDatos() const {
    return DtUsuario(identificador, nombre);
}
