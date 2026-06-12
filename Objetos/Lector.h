#ifndef LECTOR_H
#define LECTOR_H

#include <set>
#include <string>
#include "Usuario.h"
#include "DataTypes.h"

class Prestamo;
class Puntaje;
class Material;

class Lector : public Usuario {
private:
    DtFecha fechaRegistro;
    std::set<Prestamo*> prestamos;
    std::set<Puntaje*> puntajes;

public:
    Lector();
    Lector(const std::string& identificador, const std::string& nombre,
           const std::string& password, const DtFecha& fechaRegistro);
    ~Lector() override;

    DtFecha getFechaRegistro() const;

    std::set<Prestamo*> obtenerPrestamos() const;
    void aniadirPrestamo(Prestamo* prestamo);

    std::set<Puntaje*> obtenerPuntajes() const;
    void aniadirPuntaje(Puntaje* puntaje);
    Puntaje* obtenerPuntaje(Material* material) const;

    DtLector obtenerDatosLector() const;
    DtUsuario obtenerDatos() const override;
};

#endif
