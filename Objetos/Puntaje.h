#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "DataTypes.h"

class Lector;
class Material;

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
    void setValor(int valor);
    Lector* getLector() const;
    Material* getMaterial() const;

    DtPuntaje obtenerDatos() const;
};

#endif
