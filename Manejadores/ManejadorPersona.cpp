#include "ManejadorPersona.h"
#include "Usuario.h"

ManejadorPersona* ManejadorPersona::instancia = nullptr;

ManejadorPersona::ManejadorPersona() : personas() {}

ManejadorPersona::~ManejadorPersona() {
    for (auto& par : personas) {
        delete par.second;
    }
    personas.clear();
}

ManejadorPersona* ManejadorPersona::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorPersona();
    }
    return instancia;
}

Usuario* ManejadorPersona::getPersona(const std::string& id) const {
    auto it = personas.find(id);
    if (it == personas.end()) {
        return nullptr;
    }
    return it->second;
}

std::set<Usuario*> ManejadorPersona::getPersonas() const {
    std::set<Usuario*> resultado;
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

bool ManejadorPersona::existePersona(const std::string& id) const {
    return personas.find(id) != personas.end();
}
