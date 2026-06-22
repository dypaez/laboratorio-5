#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <set>
#include <string>
#include "../datatypes/datatypes.h"
using namespace std;

class ISistema {
public:

    virtual ~ISistema() {}
    virtual bool getSesionIniciada() const = 0;
    virtual string obtenerRol() const = 0;
    virtual DtFecha* obtenerFecha() const = 0;
    virtual string obtenerNombreDeUsuario() const = 0;
    virtual void ingresarDatosDePrueba() = 0;
    virtual bool iniciarSesion(const string& identificador, const string& password) = 0;
    virtual void cerrarSesion() = 0;
    virtual void listarMateriales() = 0;
    virtual void verInfoMaterial(const string& codigoMaterial) = 0;
    virtual void puntuarMaterial(const string& codigoMaterial, int valor) = 0;
    virtual void registrarRevista(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, int numeroEdicion, bool esMensual) = 0;
    virtual void registrarLibro(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, const string& autor, int cantPaginas) = 0;
    virtual void registrarPrestamo(const string& idUsuario, const string& codigoMaterial, DtFecha* fecha, int diasPermitidos) = 0;
    virtual void listarPrestamos(const string& id) = 0;
    virtual void registrarFuncionario(const string& id, const string& nombre, const string& password, int numeroEmpleado) = 0;
    virtual void registrarLector(const string&id, const string& nombre, const string& password, DtFecha* fecha) = 0;
    virtual void cambiarFecha(int dia, int mes, int anio, int hora, int minuto) = 0;

};

#endif
