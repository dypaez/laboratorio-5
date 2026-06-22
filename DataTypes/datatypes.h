#ifndef DATATYPES_H
#define DATATYPES_H
#include <string>

using namespace std;

struct DtFecha {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

    DtFecha();
    DtFecha(const DtFecha& _fecha);
    DtFecha(int dia, int mes, int anio, int hora, int minuto);
    string toString() const;
};

struct DtUsuario {
    string identificador;
    string nombre;

    DtUsuario();
    DtUsuario(const string& identificador, const string& nombre);
    virtual ~DtUsuario() = default;
};

struct DtLector : public DtUsuario {
    string fechaRegistro;

    DtLector();
    DtLector(const string& identificador, const string& nombre, const string& fechaRegistro);
};

struct DtFuncionario : public DtUsuario {
    int numeroEmpleado;

    DtFuncionario();
    DtFuncionario(const string& identificador, const string& nombre, int numeroEmpleado);
};

struct DtMaterial {
    string codigo;
    string titulo;
    int anioPublicacion;
    float puntajePromedio;
    int cantPuntajes;

    DtMaterial();
    DtMaterial(const string& codigo, const string& titulo, int anioPublicacion, float puntajePromedio, int cantPuntajes);
    virtual void imprimir();
    virtual ~DtMaterial() = default;
};

struct DtLibro : public DtMaterial {
    string autor;
    int cantPaginas;

    DtLibro();
    void imprimir() override;
    DtLibro(const string& codigo, const string& titulo, int anioPublicacion, float puntajePromedio, int cantPuntajes, const string& autor, int cantPaginas);
};

struct DtRevista : public DtMaterial {
    int numeroEdicion;
    bool esMensual;

    DtRevista();
    void imprimir() override;
    DtRevista(const string& codigo, const string& titulo, int anioPublicacion, float puntajePromedio, int cantPuntajes, int numeroEdicion, bool esMensual);
};

struct DtPrestamo {
    string fechaPrestamo;
    string codigoMaterial;
    string nombreMaterial;
    int diasPermitidos;

    DtPrestamo();
    DtPrestamo(const string& fechaPrestamo, const string& codigoMaterial, const string& nombreMaterial, int diasPermitidos);
    void imprimir();
};

struct DtPuntaje {
    int valor;
    string idLector;
    string codigoMaterial;

    DtPuntaje();
    DtPuntaje(int valor, const string& idLector, const string& codigoMaterial);
};

bool operator<(const DtMaterial& a, const DtMaterial& b);

#endif