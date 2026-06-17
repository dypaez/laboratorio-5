#ifndef MANEJADOR_PERSONA_H
#define MANEJADOR_PERSONA_H
#include "../Clases/Usuario.h"
#include <map>
#include <set>
#include <string>
using namespace std;

class ManejadorPersona {
private:
    static ManejadorPersona* instancia;
    map<string, Usuario*> personas;

    ManejadorPersona();

public:
    ~ManejadorPersona();

    static ManejadorPersona* getInstancia();
    Usuario* getPersona(const string& id) const;
    set<Usuario*> getPersonas() const;
    void agregarPersona(Usuario* persona);
    bool existePersona(const string& id) const;
};

#endif
