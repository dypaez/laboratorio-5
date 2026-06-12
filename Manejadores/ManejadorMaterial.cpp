#include "ManejadorMaterial.h"
#include "Material.h"

ManejadorMaterial* ManejadorMaterial::instancia = nullptr;

ManejadorMaterial::ManejadorMaterial() : materiales() {}

ManejadorMaterial::~ManejadorMaterial() {
    for (auto& par : materiales) {
        delete par.second;
    }
    materiales.clear();
}

ManejadorMaterial* ManejadorMaterial::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorMaterial();
    }
    return instancia;
}

Material* ManejadorMaterial::getMaterial(const std::string& codigo) const {
    auto it = materiales.find(codigo);
    if (it == materiales.end()) {
        return nullptr;
    }
    return it->second;
}

std::set<Material*> ManejadorMaterial::getMateriales() const {
    std::set<Material*> resultado;
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

bool ManejadorMaterial::existeMaterial(const std::string& codigo) const {
    return materiales.find(codigo) != materiales.end();
}
