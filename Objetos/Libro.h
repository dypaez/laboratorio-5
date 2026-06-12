#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Material.h"
#include "DataTypes.h"

class Libro : public Material {
private:
    std::string autor;
    int cantPaginas;

public:
    Libro();
    Libro(const std::string& codigo, const std::string& titulo, int anioPublicacion,
          int diasPermitidos, const std::string& autor, int cantPaginas);
    ~Libro() override;

    std::string getAutor() const;
    int getCantPaginas() const;

    DtLibro obtenerDatosLibro() const;
    DtMaterial obtenerDatos() const override;
};

#endif
