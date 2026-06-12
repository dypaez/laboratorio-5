#ifndef MANEJADOR_MATERIAL_H
#define MANEJADOR_MATERIAL_H

#include <map>
#include <set>
#include <string>

class Material;

class ManejadorMaterial {
private:
    static ManejadorMaterial* instancia;
    std::map<std::string, Material*> materiales;

    ManejadorMaterial();

public:
    ~ManejadorMaterial();

    static ManejadorMaterial* getInstancia();
    Material* getMaterial(const std::string& codigo) const;
    std::set<Material*> getMateriales() const;
    void agregarMaterial(Material* material);
    bool existeMaterial(const std::string& codigo) const;
};

#endif
