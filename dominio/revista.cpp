#include "Revista.h"
#include <iostream>
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
void Revista::imprimirDatos(){
    Material::imprimirDatos();
    cout << "Numero de edicion: " << numeroEdicion << endl;
    cout << "Es mensual? " << (esMensual ? "Si" : "No") << endl; 
}
DtMaterial* Revista::obtenerDatos() const {
    return new DtRevista(this->getCodigo(),
    this->getTitulo(),
    this->getAnioPublicacion(),
    this->getPuntajePromedio(),
    this->getCantPuntajes(),
    this->numeroEdicion,
    this->esMensual);
}
