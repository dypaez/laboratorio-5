#ifndef LECTOR_H
#define LECTOR_H

#include <set>
#include <string>
#include "usuario.h"
#include "../datatypes/datatypes.h"
#include "prestamo.h"

using namespace std;


class Puntaje;


class Lector : public Usuario {
private:
    DtFecha* fechaRegistro;
    set<Prestamo*> prestamos;
    set<Puntaje*> puntajes;

public:
    Lector();
    Lector(const string& identificador, const string& nombre, const string& password, DtFecha* fechaRegistro);
    ~Lector() override;

    DtFecha* getFechaRegistro() const;

    set<DtPrestamo*> obtenerPrestamos() const;
    void aniadirPrestamo(Prestamo* prestamo);

    set<Puntaje*> obtenerPuntajes() const;
    Prestamo* crearPrestamo(DtFecha* fecha, Material* material, int diasPermitidos);
    bool existePrestamo(Material * material);
    void aniadirPuntaje(Puntaje* puntaje);
    Puntaje* obtenerPuntaje(Material* material) const;

    DtUsuario* obtenerDatos() const override;
};

#endif
