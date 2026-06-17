#include "Lector.h"

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
    return set<Prestamo*>();
}

void Lector::aniadirPrestamo(Prestamo* prestamo) {
}

set<Puntaje*> Lector::obtenerPuntajes() const {
    return set<Puntaje*>();
}

void Lector::aniadirPuntaje(Puntaje* puntaje) {
}

Puntaje* Lector::obtenerPuntaje(Material* material) const {
    return nullptr;
}

DtLector Lector::obtenerDatosLector() const {
    return DtLector();
}

DtUsuario Lector::obtenerDatos() const {
    return DtUsuario();
}
