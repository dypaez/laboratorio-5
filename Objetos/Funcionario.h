#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Usuario.h"
#include "DataTypes.h"

class Funcionario : public Usuario {
private:
    int numeroEmpleado;

public:
    Funcionario();
    Funcionario(const std::string& identificador, const std::string& nombre,
                const std::string& password, int numeroEmpleado);
    ~Funcionario() override;

    int getNumeroEmpleado() const;
    DtFuncionario obtenerDatosFuncionario() const;
    DtUsuario obtenerDatos() const override;
};

#endif
