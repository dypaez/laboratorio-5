#include "ManejadorMaterial.h"

using namespace std;

ManejadorMaterial* ManejadorMaterial::instancia = nullptr;

ManejadorMaterial::ManejadorMaterial() {
}

ManejadorMaterial::~ManejadorMaterial() {
}

ManejadorMaterial* ManejadorMaterial::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorMaterial();
    }

    return instancia;
}

Material* ManejadorMaterial::getMaterial(const string& codigo) const {
    return nullptr;
}

set<Material*> ManejadorMaterial::getMateriales() const {
    return set<Material*>();
}

void ManejadorMaterial::agregarMaterial(Material* material) {
}

bool ManejadorMaterial::existeMaterial(const string& codigo) const {
    return false;
}