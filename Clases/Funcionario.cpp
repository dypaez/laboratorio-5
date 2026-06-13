#include "Funcionario.h"

using namespace std;

Funcionario::Funcionario()
    : Usuario(), numeroEmpleado(0) {
}

Funcionario::Funcionario(const string& identificador, const string& nombre,
                         const string& password, int numeroEmpleado)
    : Usuario(identificador, nombre, password), numeroEmpleado(numeroEmpleado) {
}

Funcionario::~Funcionario() {
}

int Funcionario::getNumeroEmpleado() const {
    return numeroEmpleado;
}

void Funcionario::setNumeroEmpleado(int numeroEmpleado) {
    this->numeroEmpleado = numeroEmpleado;
}

DtFuncionario Funcionario::obtenerDatosFuncionario() const {
    return DtFuncionario();
}

DtUsuario Funcionario::obtenerDatos() const {
    return DtUsuario();
}
