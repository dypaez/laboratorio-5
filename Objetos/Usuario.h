#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DataTypes.h"

class Usuario {
private:
    std::string identificador;
    std::string nombre;
    std::string password;

public:
    Usuario();
    Usuario(const std::string& identificador, const std::string& nombre, const std::string& password);
    virtual ~Usuario();

    std::string getIdentificador() const;
    std::string getNombre() const;
    std::string getPassword() const;

    void setNombre(const std::string& nombre);
    void setPassword(const std::string& password);

    bool validarPassword(const std::string& password) const;
    virtual DtUsuario obtenerDatos() const;
};

#endif
