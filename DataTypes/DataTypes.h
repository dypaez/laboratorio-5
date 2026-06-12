#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>

struct DtFecha {
    int dia;
    int mes;
    int anio;

    DtFecha();
    DtFecha(int dia, int mes, int anio);
};

struct DtUsuario {
    std::string identificador;
    std::string nombre;

    DtUsuario();
    DtUsuario(const std::string& identificador, const std::string& nombre);
};

struct DtLector : public DtUsuario {
    DtFecha fechaRegistro;

    DtLector();
    DtLector(const std::string& identificador, const std::string& nombre, const DtFecha& fechaRegistro);
};

struct DtFuncionario : public DtUsuario {
    int numeroEmpleado;

    DtFuncionario();
    DtFuncionario(const std::string& identificador, const std::string& nombre, int numeroEmpleado);
};

struct DtMaterial {
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    float puntajePromedio;
    int cantPuntajes;

    DtMaterial();
    DtMaterial(const std::string& codigo, const std::string& titulo, int anioPublicacion,
               float puntajePromedio, int cantPuntajes);
};

struct DtLibro : public DtMaterial {
    std::string autor;
    int cantPaginas;

    DtLibro();
    DtLibro(const std::string& codigo, const std::string& titulo, int anioPublicacion,
            float puntajePromedio, int cantPuntajes, const std::string& autor, int cantPaginas);
};

struct DtRevista : public DtMaterial {
    int numeroEdicion;
    bool esMensual;

    DtRevista();
    DtRevista(const std::string& codigo, const std::string& titulo, int anioPublicacion,
              float puntajePromedio, int cantPuntajes, int numeroEdicion, bool esMensual);
};

struct DtPrestamo {
    DtFecha fechaPrestamo;
    std::string idLector;
    std::string codigoMaterial;

    DtPrestamo();
    DtPrestamo(const DtFecha& fechaPrestamo, const std::string& idLector, const std::string& codigoMaterial);
};

struct DtPuntaje {
    int valor;
    std::string idLector;
    std::string codigoMaterial;

    DtPuntaje();
    DtPuntaje(int valor, const std::string& idLector, const std::string& codigoMaterial);
};


bool operator<(const DtMaterial& a, const DtMaterial& b);

#endif
