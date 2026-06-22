#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "../datatypes/datatypes.h"
#include "material.h"
using namespace std;

class Prestamo {
private:
    DtFecha* fechaPrestamo;
    int diasPermitidos;
    Material* material;

public:
    Prestamo();
    Prestamo(DtFecha* fechaPrestamo, Material* material, int diasPermitidos);
    ~Prestamo();

    DtFecha* getFechaPrestamo() const;
    int getDiasPermitidos() const;
    Material* getMaterial() const;


    DtPrestamo* obtenerInfoPrestamo() const;
};

#endif
