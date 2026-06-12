#include "Funcionario.h"

Funcionario::Funcionario() : Usuario(), numeroEmpleado(0) {}

Funcionario::Funcionario(const std::string& identificador, const std::string& nombre,
                         const std::string& password, int numeroEmpleado)
    : Usuario(identificador, nombre, password), numeroEmpleado(numeroEmpleado) {}

Funcionario::~Funcionario() {}

int Funcionario::getNumeroEmpleado() const {
    return numeroEmpleado;
}

DtFuncionario Funcionario::obtenerDatosFuncionario() const {
    return DtFuncionario(getIdentificador(), getNombre(), numeroEmpleado);
}

DtUsuario Funcionario::obtenerDatos() const {
    return obtenerDatosFuncionario();
}
