#ifndef MATERIAL_H
#define MATERIAL_H

#include <set>
#include <string>
#include "../datatypes/datatypes.h"

using namespace std;

class Prestamo;
class Puntaje;
class Lector;

class Material {
private:
    string codigo;
    string titulo;
    int anioPublicacion;
    float puntajePromedio;
    int cantPuntajes;
    int diasPermitidos;
    set<Puntaje*> puntajes;

public:
    Material();
    Material(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos);
    virtual ~Material();

    string getCodigo() const;
    string getTitulo() const;
    int getAnioPublicacion() const;
    float getPuntajePromedio() const;
    int getCantPuntajes() const;
    int getDiasPermitidos() const;

    void setCodigo(const string& codigo);
    void setTitulo(const string& titulo);
    void setAnioPublicacion(int anioPublicacion);
    void setPuntajePromedio(float puntajePromedio);
    void setCantPuntajes(int cantPuntajes);
    void setDiasPermitidos(int diasPermitidos);

    set<Prestamo*> obtenerPrestamos() const;
    void aniadirPrestamo(Prestamo* prestamo);

    set<Puntaje*> obtenerPuntajes() const;
    void aniadirPuntaje(Puntaje* puntaje);
    Puntaje* obtenerPuntaje(Lector* lector) const;
    virtual void imprimirDatos();
    void actualizarPP();
    void actualizarCP();

    virtual DtMaterial* obtenerDatos() const = 0;
};

#endif
