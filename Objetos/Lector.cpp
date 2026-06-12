#include "Lector.h"
#include "Prestamo.h"
#include "Puntaje.h"
#include "Material.h"

Lector::Lector() : Usuario(), fechaRegistro(), prestamos(), puntajes() {}

Lector::Lector(const std::string& identificador, const std::string& nombre,
               const std::string& password, const DtFecha& fechaRegistro)
    : Usuario(identificador, nombre, password), fechaRegistro(fechaRegistro), prestamos(), puntajes() {}

Lector::~Lector() {}

DtFecha Lector::getFechaRegistro() const {
    return fechaRegistro;
}

std::set<Prestamo*> Lector::obtenerPrestamos() const {
    return prestamos;
}

void Lector::aniadirPrestamo(Prestamo* prestamo) {
    if (prestamo != nullptr) {
        prestamos.insert(prestamo);
    }
}

std::set<Puntaje*> Lector::obtenerPuntajes() const {
    return puntajes;
}

void Lector::aniadirPuntaje(Puntaje* puntaje) {
    if (puntaje != nullptr) {
        puntajes.insert(puntaje);
    }
}

Puntaje* Lector::obtenerPuntaje(Material* material) const {
    if (material == nullptr) {
        return nullptr;
    }

    for (Puntaje* puntaje : puntajes) {
        if (puntaje != nullptr && puntaje->getMaterial() == material) {
            return puntaje;
        }
    }
    return nullptr;
}

DtLector Lector::obtenerDatosLector() const {
    return DtLector(getIdentificador(), getNombre(), fechaRegistro);
}

DtUsuario Lector::obtenerDatos() const {
    return obtenerDatosLector();
}
