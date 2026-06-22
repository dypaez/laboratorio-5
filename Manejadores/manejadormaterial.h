#ifndef MANEJADOR_MATERIAL_H
#define MANEJADOR_MATERIAL_H

#include <map>
#include <set>
#include <string>
#include "../dominio/material.h"
#include "../dominio/revista.h"
#include "../dominio/libro.h"
using namespace std;

class ManejadorMaterial {
private:
    static ManejadorMaterial* instancia;
    map<string, Material*> materiales;

    ManejadorMaterial() = default;

public:
    ~ManejadorMaterial();

    static ManejadorMaterial* getInstancia();
    DtMaterial* getDatosMaterial(const string& codigo) const;
    set<DtMaterial*> getDatosMateriales() const;
    Material* getMaterial(const string& codigo) const;
    Libro* crearLibro(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, const string& autor, int cantPaginas);
    Revista* crearRevista(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, int numeroEdicion, bool esMensual);
    void agregarMaterial(Material* material);
    bool existeMaterial(const string& codigo) const;
};

#endif
