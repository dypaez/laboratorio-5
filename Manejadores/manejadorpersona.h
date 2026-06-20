#ifndef MANEJADOR_PERSONA_H
#define MANEJADOR_PERSONA_H
#include "../dominio/usuario.h"
#include <map>
#include <set>
#include <string>
using namespace std;

class ManejadorPersona {
private:
    static ManejadorPersona* instancia;
    map<string, Usuario*> personas;
    ManejadorPersona() = default;

public:
    ~ManejadorPersona();

    static ManejadorPersona* getInstancia();
    DtUsuario* getPersona(const string& id) const;
    set<DtUsuario*> getPersonas() const;
    void agregarPersona(Usuario* persona);
    bool existePersona(const string& id) const;
};

#endif
