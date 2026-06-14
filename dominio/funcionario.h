#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "usuario.h"
#include "../datatypes/datatypes.h"

using namespace std;

class Funcionario : public Usuario {
private:
    int numeroEmpleado;

public:
    Funcionario();
    Funcionario(const string& identificador, const string& nombre,
                const string& password, int numeroEmpleado);
    ~Funcionario() override;

    int getNumeroEmpleado() const;
    void setNumeroEmpleado(int numeroEmpleado);

    DtFuncionario obtenerDatosFuncionario() const;
    DtUsuario obtenerDatos() const override;
};

#endif
