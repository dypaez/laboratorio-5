#include "ManejadorPersona.h"

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
    return nullptr;
}

set<Usuario*> ManejadorPersona::getPersonas() const {
    return set<Usuario*>();
}

void ManejadorPersona::agregarPersona(Usuario* persona) {
}

bool ManejadorPersona::existePersona(const string& id) const {
    return false;
}