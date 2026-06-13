#include "Revista.h"

using namespace std;

Revista::Revista()
    : Material(), numeroEdicion(0), esMensual(false) {
}

Revista::Revista(const string& codigo, const string& titulo, int anioPublicacion,
                 int diasPermitidos, int numeroEdicion, bool esMensual)
    : Material(codigo, titulo, anioPublicacion, diasPermitidos),
      numeroEdicion(numeroEdicion), esMensual(esMensual) {
}

Revista::~Revista() {
}

int Revista::getNumeroEdicion() const {
    return numeroEdicion;
}

bool Revista::getEsMensual() const {
    return esMensual;
}

void Revista::setNumeroEdicion(int numeroEdicion) {
    this->numeroEdicion = numeroEdicion;
}

void Revista::setEsMensual(bool esMensual) {
    this->esMensual = esMensual;
}

DtRevista Revista::obtenerDatosRevista() const {
    return DtRevista();
}

DtMaterial Revista::obtenerDatos() const {
    return DtMaterial();
}
