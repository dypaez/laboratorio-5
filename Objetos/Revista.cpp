#include "Revista.h"

Revista::Revista() : Material(), numeroEdicion(0), esMensual(false) {}

Revista::Revista(const std::string& codigo, const std::string& titulo, int anioPublicacion,
                 int diasPermitidos, int numeroEdicion, bool esMensual)
    : Material(codigo, titulo, anioPublicacion, diasPermitidos),
      numeroEdicion(numeroEdicion), esMensual(esMensual) {}

Revista::~Revista() {}

int Revista::getNumeroEdicion() const {
    return numeroEdicion;
}

bool Revista::getEsMensual() const {
    return esMensual;
}

DtRevista Revista::obtenerDatosRevista() const {
    return DtRevista(getCodigo(), getTitulo(), getAnioPublicacion(), getPuntajePromedio(),
                     getCantPuntajes(), numeroEdicion, esMensual);
}

DtMaterial Revista::obtenerDatos() const {
    return obtenerDatosRevista();
}
