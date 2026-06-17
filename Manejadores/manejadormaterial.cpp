#include "manejadormaterial.h"

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
    auto it = materiales.find(codigo);

    if (it == materiales.end()) {
        return nullptr;
    }

    return it->second;
}

set<Material*> ManejadorMaterial::getMateriales() const {
    set<Material*> resultado;

    for (const auto& par : materiales) {
        resultado.insert(par.second);
    }

    return resultado;
}

void ManejadorMaterial::agregarMaterial(Material* material) {
    if (material != nullptr) {
        materiales[material->getCodigo()] = material;
    }
}

bool ManejadorMaterial::existeMaterial(const string& codigo) const {
    return materiales.find(codigo) != materiales.end();
}
