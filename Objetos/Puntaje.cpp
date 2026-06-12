#include "Puntaje.h"
#include "Lector.h"
#include "Material.h"

Puntaje::Puntaje() : valor(0), lector(nullptr), material(nullptr) {}

Puntaje::Puntaje(int valor, Lector* lector, Material* material)
    : valor(valor), lector(lector), material(material) {}

Puntaje::~Puntaje() {}

int Puntaje::getValor() const {
    return valor;
}

void Puntaje::setValor(int valor) {
    this->valor = valor;
}

Lector* Puntaje::getLector() const {
    return lector;
}

Material* Puntaje::getMaterial() const {
    return material;
}

DtPuntaje Puntaje::obtenerDatos() const {
    std::string idLector = lector == nullptr ? "" : lector->getIdentificador();
    std::string codigoMaterial = material == nullptr ? "" : material->getCodigo();
    return DtPuntaje(valor, idLector, codigoMaterial);
}
