#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "../datatypes/datatypes.h"

using namespace std;

class Usuario {
private:
    string identificador;
    string nombre;
    string password;
    string rol;

public:
    Usuario();
    Usuario(const string& identificador, const string& nombre, const string& password, const string&rol);
    virtual ~Usuario();

    string getIdentificador() const;
    string getNombre() const;
    string getPassword() const;
    string getRol() const;
    void setIdentificador(const string& identificador);
    void setNombre(const string& nombre);
    void setPassword(const string& password);
    
    bool validarPassword(const string& password) const;
    virtual DtUsuario* obtenerDatos() const = 0;
};

#endif
