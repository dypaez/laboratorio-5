#ifndef MANEJADOR_MATERIAL_H
#define MANEJADOR_MATERIAL_H

#include <map>
#include <set>
#include <string>
#include "../dominio/material.h"
using namespace std;

class ManejadorMaterial {
private:
    static ManejadorMaterial* instancia;
    map<string, Material*> materiales;

    ManejadorMaterial() = default;

public:
    ~ManejadorMaterial();

    static ManejadorMaterial* getInstancia();
    DtMaterial* getMaterial(const string& codigo) const;
    set<DtMaterial*> getMateriales() const;
    void agregarMaterial(Material* material);
    bool existeMaterial(const string& codigo) const;
};

#endif
