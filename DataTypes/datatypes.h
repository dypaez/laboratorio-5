#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>

using namespace std;

struct DtFecha {
    int dia;
    int mes;
    int anio;

    DtFecha();
    DtFecha(int dia, int mes, int anio);
};

struct DtUsuario {
    string identificador;
    string nombre;

    DtUsuario();
    DtUsuario(const string& identificador, const string& nombre);
};

struct DtLector : public DtUsuario {
    DtFecha fechaRegistro;

    DtLector();
    DtLector(const string& identificador, const string& nombre,
             const DtFecha& fechaRegistro);
};

struct DtFuncionario : public DtUsuario {
    int numeroEmpleado;

    DtFuncionario();
    DtFuncionario(const string& identificador, const string& nombre,
                  int numeroEmpleado);
};

struct DtMaterial {
    string codigo;
    string titulo;
    int anioPublicacion;
    float puntajePromedio;
    int cantPuntajes;

    DtMaterial();
    DtMaterial(const string& codigo, const string& titulo,
               int anioPublicacion, float puntajePromedio,
               int cantPuntajes);
};

struct DtLibro : public DtMaterial {
    string autor;
    int cantPaginas;

    DtLibro();
    DtLibro(const string& codigo, const string& titulo,
            int anioPublicacion, float puntajePromedio,
            int cantPuntajes, const string& autor,
            int cantPaginas);
};

struct DtRevista : public DtMaterial {
    int numeroEdicion;
    bool esMensual;

    DtRevista();
    DtRevista(const string& codigo, const string& titulo,
              int anioPublicacion, float puntajePromedio,
              int cantPuntajes, int numeroEdicion,
              bool esMensual);
};

struct DtPrestamo {
    DtFecha fechaPrestamo;
    string idLector;
    string codigoMaterial;

    DtPrestamo();
    DtPrestamo(const DtFecha& fechaPrestamo, const string& idLector,
               const string& codigoMaterial);
};

struct DtPuntaje {
    int valor;
    string idLector;
    string codigoMaterial;

    DtPuntaje();
    DtPuntaje(int valor, const string& idLector,
              const string& codigoMaterial);
};

bool operator<(const DtMaterial& a, const DtMaterial& b);

#endif