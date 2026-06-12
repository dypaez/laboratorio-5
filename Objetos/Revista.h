#ifndef REVISTA_H
#define REVISTA_H

#include <string>
#include "Material.h"
#include "DataTypes.h"

class Revista : public Material {
private:
    int numeroEdicion;
    bool esMensual;

public:
    Revista();
    Revista(const std::string& codigo, const std::string& titulo, int anioPublicacion,
            int diasPermitidos, int numeroEdicion, bool esMensual);
    ~Revista() override;

    int getNumeroEdicion() const;
    bool getEsMensual() const;

    DtRevista obtenerDatosRevista() const;
    DtMaterial obtenerDatos() const override;
};

#endif
