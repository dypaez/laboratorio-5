#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <set>
#include <string>
#include "DataTypes.h"

class ISistema {
public:
    virtual ~ISistema() {}

    virtual bool iniciarSesion(const std::string& identificador, const std::string& password) = 0;
    virtual void cerrarSesion() = 0;
    virtual void cancelar() = 0;

    virtual DtLector ingresarLector(const std::string& identificador) = 0;
    virtual DtMaterial ingresarMaterial(const std::string& codigo) = 0;
    virtual DtPrestamo registrarPrestamo(const DtFecha& fecha, const std::string& codigoMaterial) = 0;
    virtual void confirmar() = 0;

    virtual std::set<DtMaterial> verMateriales() = 0;
    virtual DtMaterial verInfoMaterial(const std::string& codigoMaterial) = 0;
    virtual void puntuarMaterial(const std::string& codigoMaterial, int valor) = 0;

    virtual DtLibro ingresarDatosLibro(const std::string& codigo, const std::string& titulo,
                                       int anioPublicacion, int diasPermitidos,
                                       const std::string& autor, int cantPaginas) = 0;
    virtual void registrarMaterial(const DtLibro& datos) = 0;

    virtual DtRevista ingresarDatosRevista(const std::string& codigo, const std::string& titulo,
                                           int anioPublicacion, int diasPermitidos,
                                           int numeroEdicion, bool esMensual) = 0;
    virtual void registrarMaterial(const DtRevista& datos) = 0;

    virtual DtFuncionario ingresarDatosFuncionario(const std::string& identificador,
                                                   const std::string& nombre,
                                                   const std::string& password,
                                                   int numeroEmpleado) = 0;
    virtual void registrarFuncionario(const DtFuncionario& datos, const std::string& password) = 0;

    virtual DtLector ingresarDatosLector(const std::string& identificador,
                                         const std::string& nombre,
                                         const std::string& password,
                                         const DtFecha& fechaRegistro) = 0;
    virtual void registrarLector(const DtLector& datos, const std::string& password) = 0;
};

#endif
