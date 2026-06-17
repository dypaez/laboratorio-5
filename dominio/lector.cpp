#include "lector.h"
#include "puntaje.h"

using namespace std;

Lector::Lector()
    : Usuario(), fechaRegistro(), prestamos(), puntajes() {
}

Lector::Lector(const string& identificador, const string& nombre,
               const string& password, const DtFecha& fechaRegistro)
    : Usuario(identificador, nombre, password),
      fechaRegistro(fechaRegistro), prestamos(), puntajes() {
}

Lector::~Lector() {
}

DtFecha Lector::getFechaRegistro() const {
    return fechaRegistro;
}

void Lector::setFechaRegistro(const DtFecha& fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

set<Prestamo*> Lector::obtenerPrestamos() const {
    return prestamos;
}

void Lector::aniadirPrestamo(Prestamo* prestamo) {
    if (prestamo != nullptr) {
        prestamos.insert(prestamo);
    }
}

set<Puntaje*> Lector::obtenerPuntajes() const {
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

DtUsuario* Lector::obtenerDatos() const {
    return new DtLector(getIdentificador(), getNombre(), fechaRegistro);
}
