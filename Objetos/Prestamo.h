#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "DataTypes.h"

class Lector;
class Material;

class Prestamo {
private:
    DtFecha fechaPrestamo;
    Lector* lector;
    Material* material;

public:
    Prestamo();
    Prestamo(const DtFecha& fechaPrestamo, Lector* lector, Material* material);
    ~Prestamo();

    DtFecha getFechaPrestamo() const;
    Lector* getLector() const;
    Material* getMaterial() const;

    DtPrestamo obtenerInfoPrestamo() const;
};

#endif
