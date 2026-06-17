#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "../datatypes/datatypes.h"
#include "lector.h"
#include "material.h"
using namespace std;
class Puntaje {
private:
    int valor;
    Lector* lector;
    Material* material;

public:
    Puntaje();
    Puntaje(int valor, Lector* lector, Material* material);
    ~Puntaje();

    int getValor() const;
    Lector* getLector() const;
    Material* getMaterial() const;

    void setValor(int valor);
    void setLector(Lector* lector);
    void setMaterial(Material* material);

    DtPuntaje obtenerDatos() const;
};

#endif
