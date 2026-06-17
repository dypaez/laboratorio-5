#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "../datatypes/datatypes.h"

using namespace std;

class Lector;
class Material;

class Prestamo {
private:
    DtFecha fechaPrestamo;
    int diasPermitidos;
    Lector* lector;
    Material* material;

public:
    Prestamo();
    Prestamo(const DtFecha& fechaPrestamo, Lector* lector, Material* material, int diasPermitidos = 0);
    ~Prestamo();

    DtFecha getFechaPrestamo() const;
    int getDiasPermitidos() const;
    Lector* getLector() const;
    Material* getMaterial() const;

    void setFechaPrestamo(const DtFecha& fechaPrestamo);
    void setDiasPermitidos(int diasPermitidos);
    void setLector(Lector* lector);
    void setMaterial(Material* material);

    DtPrestamo obtenerInfoPrestamo() const;
};

#endif
