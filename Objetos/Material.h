#ifndef MATERIAL_H
#define MATERIAL_H

#include <set>
#include <string>
#include "DataTypes.h"

class Prestamo;
class Puntaje;
class Lector;

class Material {
private:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    float puntajePromedio;
    int cantPuntajes;
    int diasPermitidos;
    std::set<Prestamo*> prestamos;
    std::set<Puntaje*> puntajes;

public:
    Material();
    Material(const std::string& codigo, const std::string& titulo, int anioPublicacion, int diasPermitidos);
    virtual ~Material();

    std::string getCodigo() const;
    std::string getTitulo() const;
    int getAnioPublicacion() const;
    float getPuntajePromedio() const;
    int getCantPuntajes() const;
    int getDiasPermitidos() const;

    std::set<Prestamo*> obtenerPrestamos() const;
    void aniadirPrestamo(Prestamo* prestamo);

    std::set<Puntaje*> obtenerPuntajes() const;
    void aniadirPuntaje(Puntaje* puntaje);
    Puntaje* obtenerPuntaje(Lector* lector) const;

    void actualizarPP();
    void actualizarCP();
    virtual DtMaterial obtenerDatos() const;
};

#endif
