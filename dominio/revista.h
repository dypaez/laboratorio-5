#ifndef REVISTA_H
#define REVISTA_H

#include <string>
#include "material.h"
#include "../datatypes/datatypes.h"

using namespace std;

class Revista : public Material {
private:
    int numeroEdicion;
    bool esMensual;

public:
    Revista();
    Revista(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, int numeroEdicion, bool esMensual);
    ~Revista() override;

    int getNumeroEdicion() const;
    bool getEsMensual() const;

    void setNumeroEdicion(int numeroEdicion);
    void setEsMensual(bool esMensual);

    DtMaterial* obtenerDatos() const override;
};

#endif
