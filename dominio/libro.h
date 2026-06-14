#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Material.h"
#include "../datatypes/datatypes.h"

using namespace std;

class Libro : public Material {
private:
    string autor;
    int cantPaginas;

public:
    Libro();
    Libro(const string& codigo, const string& titulo, int anioPublicacion,
          int diasPermitidos, const string& autor, int cantPaginas);
    ~Libro() override;

    string getAutor() const;
    int getCantPaginas() const;

    void setAutor(const string& autor);
    void setCantPaginas(int cantPaginas);

    DtLibro obtenerDatosLibro() const;
    DtMaterial obtenerDatos() const override;
};

#endif
