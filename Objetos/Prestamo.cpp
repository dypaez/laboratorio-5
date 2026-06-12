#include "Prestamo.h"
#include "Lector.h"
#include "Material.h"

Prestamo::Prestamo() : fechaPrestamo(), lector(nullptr), material(nullptr) {}

Prestamo::Prestamo(const DtFecha& fechaPrestamo, Lector* lector, Material* material)
    : fechaPrestamo(fechaPrestamo), lector(lector), material(material) {}

Prestamo::~Prestamo() {}

DtFecha Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

Lector* Prestamo::getLector() const {
    return lector;
}

Material* Prestamo::getMaterial() const {
    return material;
}

DtPrestamo Prestamo::obtenerInfoPrestamo() const {
    std::string idLector = lector == nullptr ? "" : lector->getIdentificador();
    std::string codigoMaterial = material == nullptr ? "" : material->getCodigo();
    return DtPrestamo(fechaPrestamo, idLector, codigoMaterial);
}
