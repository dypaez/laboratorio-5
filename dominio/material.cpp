#include "material.h"
#include "puntaje.h"

using namespace std;

Material::Material()
    : codigo(""), titulo(""), anioPublicacion(0), puntajePromedio(0), cantPuntajes(0), diasPermitidos(0), prestamos(), puntajes() {
}

Material::Material(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos)
    : codigo(codigo), titulo(titulo), anioPublicacion(anioPublicacion), puntajePromedio(0), cantPuntajes(0), diasPermitidos(diasPermitidos), prestamos(), puntajes() {
}

Material::~Material() {
}

string Material::getCodigo() const {
    return codigo;
}

string Material::getTitulo() const {
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

void Material::setCodigo(const string& codigo) {
    this->codigo = codigo;
}

void Material::setTitulo(const string& titulo) {
    this->titulo = titulo;
}

void Material::setAnioPublicacion(int anioPublicacion) {
    this->anioPublicacion = anioPublicacion;
}

void Material::setPuntajePromedio(float puntajePromedio) {
    this->puntajePromedio = puntajePromedio;
}

void Material::setCantPuntajes(int cantPuntajes) {
    this->cantPuntajes = cantPuntajes;
}

void Material::setDiasPermitidos(int diasPermitidos) {
    this->diasPermitidos = diasPermitidos;
}

set<Prestamo*> Material::obtenerPrestamos() const {
    return prestamos;
}

void Material::aniadirPrestamo(Prestamo* prestamo) {
    if (prestamo != nullptr) {
        prestamos.insert(prestamo);
    }
}

set<Puntaje*> Material::obtenerPuntajes() const {
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

void Material::actualizarPP() {
    int suma = 0;
    int cantidad = 0;

    for (Puntaje* puntaje : puntajes) {
        if (puntaje != nullptr) {
            suma += puntaje->getValor();
            cantidad++;
        }
    }

    if (cantidad == 0) {
        puntajePromedio = 0;
    } else {
        puntajePromedio = (float)suma / cantidad;
    }
}

void Material::actualizarCP() {
    cantPuntajes = (int)puntajes.size();
}
