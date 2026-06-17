#include "DataTypes.h"

using namespace std;

DtFecha::DtFecha()
    : dia(1), mes(1), anio(1900) {
}

DtFecha::DtFecha(int dia, int mes, int anio)
    : dia(dia), mes(mes), anio(anio) {
}

DtUsuario::DtUsuario()
    : identificador(""), nombre("") {
}

DtUsuario::DtUsuario(const string& identificador, const string& nombre)
    : identificador(identificador), nombre(nombre) {
}

DtLector::DtLector()
    : DtUsuario(), fechaRegistro() {
}

DtLector::DtLector(const string& identificador, const string& nombre,
                   const DtFecha& fechaRegistro)
    : DtUsuario(identificador, nombre), fechaRegistro(fechaRegistro) {
}

DtFuncionario::DtFuncionario()
    : DtUsuario(), numeroEmpleado(0) {
}

DtFuncionario::DtFuncionario(const string& identificador, const string& nombre,
                             int numeroEmpleado)
    : DtUsuario(identificador, nombre), numeroEmpleado(numeroEmpleado) {
}

DtMaterial::DtMaterial()
    : codigo(""), titulo(""), anioPublicacion(0),
      puntajePromedio(0), cantPuntajes(0) {
}

DtMaterial::DtMaterial(const string& codigo, const string& titulo,
                       int anioPublicacion, float puntajePromedio,
                       int cantPuntajes)
    : codigo(codigo), titulo(titulo),
      anioPublicacion(anioPublicacion),
      puntajePromedio(puntajePromedio),
      cantPuntajes(cantPuntajes) {
}

DtLibro::DtLibro()
    : DtMaterial(), autor(""), cantPaginas(0) {
}

DtLibro::DtLibro(const string& codigo, const string& titulo,
                 int anioPublicacion, float puntajePromedio,
                 int cantPuntajes, const string& autor,
                 int cantPaginas)
    : DtMaterial(codigo, titulo, anioPublicacion,
                 puntajePromedio, cantPuntajes),
      autor(autor), cantPaginas(cantPaginas) {
}

DtRevista::DtRevista()
    : DtMaterial(), numeroEdicion(0), esMensual(false) {
}

DtRevista::DtRevista(const string& codigo, const string& titulo,
                     int anioPublicacion, float puntajePromedio,
                     int cantPuntajes, int numeroEdicion,
                     bool esMensual)
    : DtMaterial(codigo, titulo, anioPublicacion,
                 puntajePromedio, cantPuntajes),
      numeroEdicion(numeroEdicion), esMensual(esMensual) {
}

DtPrestamo::DtPrestamo()
    : fechaPrestamo(), idLector(""), codigoMaterial("") {
}

DtPrestamo::DtPrestamo(const DtFecha& fechaPrestamo,
                       const string& idLector,
                       const string& codigoMaterial)
    : fechaPrestamo(fechaPrestamo),
      idLector(idLector),
      codigoMaterial(codigoMaterial) {
}

DtPuntaje::DtPuntaje()
    : valor(0), idLector(""), codigoMaterial("") {
}

DtPuntaje::DtPuntaje(int valor, const string& idLector,
                     const string& codigoMaterial)
    : valor(valor),
      idLector(idLector),
      codigoMaterial(codigoMaterial) {
}

bool operator<(const DtMaterial& a, const DtMaterial& b) {
    return a.codigo < b.codigo;
}

bool operator<(const DtPrestamo& a, const DtPrestamo& b) {
    if (a.idLector != b.idLector) {
        return a.idLector < b.idLector;
    }

    if (a.codigoMaterial != b.codigoMaterial) {
        return a.codigoMaterial < b.codigoMaterial;
    }

    if (a.fechaPrestamo.anio != b.fechaPrestamo.anio) {
        return a.fechaPrestamo.anio < b.fechaPrestamo.anio;
    }

    if (a.fechaPrestamo.mes != b.fechaPrestamo.mes) {
        return a.fechaPrestamo.mes < b.fechaPrestamo.mes;
    }

    return a.fechaPrestamo.dia < b.fechaPrestamo.dia;
}

bool operator<(const DtPuntaje& a, const DtPuntaje& b) {
    if (a.codigoMaterial != b.codigoMaterial) {
        return a.codigoMaterial < b.codigoMaterial;
    }

    if (a.idLector != b.idLector) {
        return a.idLector < b.idLector;
    }

    return a.valor < b.valor;
}
