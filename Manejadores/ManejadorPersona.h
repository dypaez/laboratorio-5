#ifndef MANEJADOR_PERSONA_H
#define MANEJADOR_PERSONA_H

#include <map>
#include <set>
#include <string>

class Usuario;

class ManejadorPersona {
private:
    static ManejadorPersona* instancia;
    std::map<std::string, Usuario*> personas;

    ManejadorPersona();

public:
    ~ManejadorPersona();

    static ManejadorPersona* getInstancia();
    Usuario* getPersona(const std::string& id) const;
    std::set<Usuario*> getPersonas() const;
    void agregarPersona(Usuario* persona);
    bool existePersona(const std::string& id) const;
};

#endif
