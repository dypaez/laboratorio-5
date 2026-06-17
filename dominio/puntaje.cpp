#include "puntaje.h"

using namespace std;

Puntaje::Puntaje()
    : valor(0), lector(nullptr), material(nullptr) {
}

Puntaje::Puntaje(int valor, Lector* lector, Material* material)
    : valor(valor), lector(lector), material(material) {
}

Puntaje::~Puntaje() {
}

int Puntaje::getValor() const {
    return valor;
}

Lector* Puntaje::getLector() const {
    return lector;
}

Material* Puntaje::getMaterial() const {
    return material;
}

void Puntaje::setValor(int valor) {
    this->valor = valor;
}

void Puntaje::setLector(Lector* lector) {
    this->lector = lector;
}

void Puntaje::setMaterial(Material* material) {
    this->material = material;
}

DtPuntaje Puntaje::obtenerDatos() const {
    string idLector = "";
    string codigoMaterial = "";

    if (lector != nullptr) {
        idLector = lector->getIdentificador();
    }

    if (material != nullptr) {
        codigoMaterial = material->getCodigo();
    }

    return DtPuntaje(valor, idLector, codigoMaterial);
}
