#ifndef LECTOR_H
#define LECTOR_H

#include <set>
#include <string>
#include "Usuario.h"
#include "DataTypes.h"

using namespace std;

class Prestamo;
class Puntaje;
class Material;

class Lector : public Usuario {
private:
    DtFecha fechaRegistro;
    set<Prestamo*> prestamos;
    set<Puntaje*> puntajes;

public:
    Lector();
    Lector(const string& identificador, const string& nombre,
           const string& password, const DtFecha& fechaRegistro);
    ~Lector() override;

    DtFecha getFechaRegistro() const;
    void setFechaRegistro(const DtFecha& fechaRegistro);

    set<Prestamo*> obtenerPrestamos() const;
    void aniadirPrestamo(Prestamo* prestamo);

    set<Puntaje*> obtenerPuntajes() const;
    void aniadirPuntaje(Puntaje* puntaje);
    Puntaje* obtenerPuntaje(Material* material) const;

    DtLector obtenerDatosLector() const;
    DtUsuario obtenerDatos() const override;
};

#endif
