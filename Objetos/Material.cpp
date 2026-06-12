#include "Material.h"
#include "Prestamo.h"
#include "Puntaje.h"
#include "Lector.h"

Material::Material()
    : codigo(""), titulo(""), anioPublicacion(0), puntajePromedio(0), cantPuntajes(0),
      diasPermitidos(0), prestamos(), puntajes() {}

Material::Material(const std::string& codigo, const std::string& titulo, int anioPublicacion, int diasPermitidos)
    : codigo(codigo), titulo(titulo), anioPublicacion(anioPublicacion), puntajePromedio(0),
      cantPuntajes(0), diasPermitidos(diasPermitidos), prestamos(), puntajes() {}

Material::~Material() {}

std::string Material::getCodigo() const {
    return codigo;
}

std::string Material::getTitulo() const {
    return titulo;
}

int Material::getAnioPublicacion() const {
    return anioPublicacion;
}

float Material::getPuntajePromedio() const {
    return puntajePromedio;
}

int Material::getCantPuntajes() const {
    return cantPuntajes;
}

int Material::getDiasPermitidos() const {
    return diasPermitidos;
}

std::set<Prestamo*> Material::obtenerPrestamos() const {
    return prestamos;
}

void Material::aniadirPrestamo(Prestamo* prestamo) {
    if (prestamo != nullptr) {
        prestamos.insert(prestamo);
    }
}

std::set<Puntaje*> Material::obtenerPuntajes() const {
    return puntajes;
}

void Material::aniadirPuntaje(Puntaje* puntaje) {
    if (puntaje != nullptr) {
        puntajes.insert(puntaje);
        actualizarCP();
        actualizarPP();
    }
}

Puntaje* Material::obtenerPuntaje(Lector* lector) const {
    if (lector == nullptr) {
        return nullptr;
    }

    for (Puntaje* puntaje : puntajes) {
        if (puntaje != nullptr && puntaje->getLector() == lector) {
            return puntaje;
        }
    }
    return nullptr;
}

void Material::actualizarCP() {
    cantPuntajes = static_cast<int>(puntajes.size());
}

void Material::actualizarPP() {
    if (puntajes.empty()) {
        puntajePromedio = 0;
        return;
    }

    int suma = 0;
    int cantidad = 0;
    for (Puntaje* puntaje : puntajes) {
        if (puntaje != nullptr) {
            suma += puntaje->getValor();
            cantidad++;
        }
    }

    puntajePromedio = cantidad == 0 ? 0 : static_cast<float>(suma) / cantidad;
}

DtMaterial Material::obtenerDatos() const {
    return DtMaterial(codigo, titulo, anioPublicacion, puntajePromedio, cantPuntajes);
}
