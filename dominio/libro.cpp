#include "libro.h"

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

DtLibro Libro::obtenerDatosLibro() const {
    return DtLibro(getCodigo(), getTitulo(), getAnioPublicacion(), getPuntajePromedio(), getCantPuntajes(), autor, cantPaginas);
}

DtMaterial Libro::obtenerDatos() const {
    return obtenerDatosLibro();
}
