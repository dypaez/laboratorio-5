#include "Libro.h"

using namespace std;

Libro::Libro()
    : Material(), autor(""), cantPaginas(0) {
}

Libro::Libro(const string& codigo, const string& titulo, int anioPublicacion,
             int diasPermitidos, const string& autor, int cantPaginas)
    : Material(codigo, titulo, anioPublicacion, diasPermitidos),
      autor(autor), cantPaginas(cantPaginas) {
}

Libro::~Libro() {
}

string Libro::getAutor() const {
    return autor;
}

int Libro::getCantPaginas() const {
    return cantPaginas;
}

void Libro::setAutor(const string& autor) {
    this->autor = autor;
}

void Libro::setCantPaginas(int cantPaginas) {
    this->cantPaginas = cantPaginas;
}

DtMaterial* Libro::obtenerDatos() const {
    return new DtLibro(this->getCodigo(),
    this->getTitulo(),
    this->getAnioPublicacion(),
    this->getPuntajePromedio(),
    this->getCantPuntajes(),
    this->autor,
    this->cantPaginas);
}
