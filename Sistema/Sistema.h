#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "ISistema.h"
#include "../Manejadores/ManejadorMaterial.h"
#include "../Manejadores/ManejadorPersona.h"
using namespace std;

class Sistema : public ISistema {
private:
    static Sistema* instancia;

    ManejadorPersona* manejadorPersona;
    ManejadorMaterial* manejadorMaterial;
    bool sesionIniciada;
    string idUsuarioSesion;
    Sistema();

public:

static ISistema* getInstancia();
~Sistema() override;

bool iniciarSesion(const string& identificador, const string& password) override;
void cerrarSesion() override;
void cancelar() override;

DtLector ingresarLector(const string& identificador) override;
DtMaterial ingresarMaterial(const string& codigo) override;
DtPrestamo registrarPrestamo(const DtFecha& fecha, const string& codigoMaterial) override;
void confirmar() override;

set<DtMaterial> verMateriales() override;
DtMaterial verInfoMaterial(const string& codigoMaterial) override;
void puntuarMaterial(const string& codigoMaterial, int valor) override;

DtLibro ingresarDatosLibro(const string& codigo, const string& titulo,
                           int anioPublicacion, int diasPermitidos,
                           const string& autor, int cantPaginas) override;
void registrarMaterial(const DtLibro& datos) override;

DtRevista ingresarDatosRevista(const string& codigo, const string& titulo,
                               int anioPublicacion, int diasPermitidos,
                               int numeroEdicion, bool esMensual) override;
void registrarMaterial(const DtRevista& datos) override;

DtFuncionario ingresarDatosFuncionario(const string& identificador,
                                       const string& nombre,
                                       const string& password,
                                       int numeroEmpleado) override;
void registrarFuncionario(const DtFuncionario& datos, const string& password) override;

DtLector ingresarDatosLector(const string& identificador,
                             const string& nombre,
                             const string& password,
                             const DtFecha& fechaRegistro) override;
void registrarLector(const DtLector& datos, const string& password) override;
};

#endif
