#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "../DataTypes/DataTypes.h"

using namespace std;

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
    Lector* getLector() const;
    Material* getMaterial() const;

    void setValor(int valor);
    void setLector(Lector* lector);
    void setMaterial(Material* material);

    DtPuntaje obtenerDatos() const;
};

#endif
