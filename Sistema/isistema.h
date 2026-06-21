#ifndef ISISTEMA_H
#define ISISTEMA_H

#include <set>
#include <string>
#include "../datatypes/datatypes.h"
using namespace std;

class ISistema {
public:

virtual ~ISistema() {}

virtual bool iniciarSesion(const string& identificador, const string& password) = 0;
virtual void cerrarSesion() = 0;
virtual DtLector ingresarLector(const string& identificador) = 0;
virtual DtMaterial ingresarMaterial(const string& codigo) = 0;
virtual DtPrestamo registrarPrestamo(const DtFecha& fecha, const string& codigoMaterial) = 0;
virtual void confirmar() = 0;

virtual set<DtMaterial> verMateriales() = 0;
virtual DtMaterial verInfoMaterial(const string& codigoMaterial) = 0;
virtual void puntuarMaterial(const string& codigoMaterial, int valor) = 0;

virtual DtLibro ingresarDatosLibro(const string& codigo, const string& titulo,
                                   int anioPublicacion, int diasPermitidos,
                                   const string& autor, int cantPaginas) = 0;
virtual void registrarMaterial(const DtLibro& datos) = 0;

virtual DtRevista ingresarDatosRevista(const string& codigo, const string& titulo,
                                       int anioPublicacion, int diasPermitidos,
                                       int numeroEdicion, bool esMensual) = 0;
virtual void registrarMaterial(const DtRevista& datos) = 0;

virtual DtFuncionario ingresarDatosFuncionario(const string& identificador,
                                               const string& nombre,
                                               const string& password,
                                               int numeroEmpleado) = 0;
virtual void registrarFuncionario(const DtFuncionario& datos, const string& password) = 0;

virtual DtLector ingresarDatosLector(const string& identificador,
                                     const string& nombre,
                                     const string& password,
                                     const DtFecha& fechaRegistro) = 0;
virtual void registrarLector(const DtLector& datos, const string& password) = 0;
};

#endif
