#include "Material.h"

using namespace std;
//Constructor vacío
Material::Material() : codigo(""), titulo(""), anioPublicacion(0), puntajePromedio(0), cantPuntajes(0), diasPermitidos(0), prestamos(), puntajes() {}
//Constructor con atributos
Material::Material(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos) : codigo(codigo), titulo(titulo), anioPublicacion(anioPublicacion), puntajePromedio(0), cantPuntajes(0), diasPermitidos(diasPermitidos), prestamos(), puntajes() {}

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
    return set<Prestamo*>();
}

void Material::aniadirPrestamo(Prestamo* prestamo) {
}

set<Puntaje*> Material::obtenerPuntajes() const {
    return set<Puntaje*>();
}

void Material::aniadirPuntaje(Puntaje* puntaje) {
}

Puntaje* Material::obtenerPuntaje(Lector* lector) const {
    return nullptr;
}

void Material::actualizarPP() {
}

void Material::actualizarCP() {
}
