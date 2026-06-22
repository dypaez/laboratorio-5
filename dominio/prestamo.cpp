#include "Prestamo.h"

using namespace std;

Prestamo::Prestamo() : fechaPrestamo(nullptr), diasPermitidos(0), material(nullptr) {}

Prestamo::Prestamo(DtFecha* fechaPrestamo, Material* material, int diasPermitidos) : fechaPrestamo(fechaPrestamo), diasPermitidos(diasPermitidos), material(material) {
}

Prestamo::~Prestamo() {
    delete fechaPrestamo;
}

DtFecha* Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

int Prestamo::getDiasPermitidos() const {
    return diasPermitidos;
}

Material* Prestamo::getMaterial() const {
    return material;
}

DtPrestamo* Prestamo::obtenerInfoPrestamo() const {
    string fecha = fechaPrestamo->toString();
    return new DtPrestamo(fecha, material->getCodigo() ,material->getTitulo(), diasPermitidos);
}
