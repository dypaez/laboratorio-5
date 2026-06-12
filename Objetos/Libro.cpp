#include "Libro.h"

Libro::Libro() : Material(), autor(""), cantPaginas(0) {}

Libro::Libro(const std::string& codigo, const std::string& titulo, int anioPublicacion,
             int diasPermitidos, const std::string& autor, int cantPaginas)
    : Material(codigo, titulo, anioPublicacion, diasPermitidos), autor(autor), cantPaginas(cantPaginas) {}

Libro::~Libro() {}

std::string Libro::getAutor() const {
    return autor;
}

int Libro::getCantPaginas() const {
    return cantPaginas;
}

DtLibro Libro::obtenerDatosLibro() const {
    return DtLibro(getCodigo(), getTitulo(), getAnioPublicacion(), getPuntajePromedio(),
                   getCantPuntajes(), autor, cantPaginas);
}

DtMaterial Libro::obtenerDatos() const {
    return obtenerDatosLibro();
}
