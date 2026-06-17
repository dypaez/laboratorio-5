#include "manejadorpersona.h"

using namespace std;

ManejadorPersona* ManejadorPersona::instancia = nullptr;

ManejadorPersona::ManejadorPersona() {
}

ManejadorPersona::~ManejadorPersona() {
}

ManejadorPersona* ManejadorPersona::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorPersona();
    }

    return instancia;
}

Usuario* ManejadorPersona::getPersona(const string& id) const {
    auto it = personas.find(id);

    if (it == personas.end()) {
        return nullptr;
    }

    return it->second;
}

set<Usuario*> ManejadorPersona::getPersonas() const {
    set<Usuario*> resultado;

    for (const auto& par : personas) {
        resultado.insert(par.second);
    }

    return resultado;
}

void ManejadorPersona::agregarPersona(Usuario* persona) {
    if (persona != nullptr) {
        personas[persona->getIdentificador()] = persona;
    }
}

bool ManejadorPersona::existePersona(const string& id) const {
    return personas.find(id) != personas.end();
}
