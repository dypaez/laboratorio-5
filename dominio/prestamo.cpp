#include "prestamo.h"
#include "lector.h"
#include "material.h"

using namespace std;

Prestamo::Prestamo() : fechaPrestamo(), diasPermitidos(0), lector(nullptr), material(nullptr) {}

Prestamo::Prestamo(const DtFecha& fechaPrestamo, Lector* lector, Material* material, int diasPermitidos) : fechaPrestamo(fechaPrestamo), diasPermitidos(diasPermitidos), lector(lector), material(material) {
}

Prestamo::~Prestamo() {
}

DtFecha Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

int Prestamo::getDiasPermitidos() const {
    return diasPermitidos;
}

Lector* Prestamo::getLector() const {
    return lector;
}

Material* Prestamo::getMaterial() const {
    return material;
}

void Prestamo::setFechaPrestamo(const DtFecha& fechaPrestamo) {
    this->fechaPrestamo = fechaPrestamo;
}

void Prestamo::setDiasPermitidos(int diasPermitidos) {
    this->diasPermitidos = diasPermitidos;
}

void Prestamo::setLector(Lector* lector) {
    this->lector = lector;
}

void Prestamo::setMaterial(Material* material) {
    this->material = material;
}

DtPrestamo Prestamo::obtenerInfoPrestamo() const {
    string idLector = "";
    string codigoMaterial = "";

    if (lector != nullptr) {
        idLector = lector->getIdentificador();
    }

    if (material != nullptr) {
        codigoMaterial = material->getCodigo();
    }

    return DtPrestamo(fechaPrestamo, idLector, codigoMaterial);
}
