#include "sistema.h"

Sistema* Sistema::instancia = nullptr;

Sistema::Sistema()
    : manejadorPersona(ManejadorPersona::getInstancia()),
      manejadorMaterial(ManejadorMaterial::getInstancia()),
      sesionIniciada(false),
      idUsuarioSesion("") {
}

Sistema::~Sistema() {
}

ISistema* Sistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Sistema();
    }

    return instancia;
}

bool Sistema::iniciarSesion(const string& identificador, const string& password) {
    return false;
}

void Sistema::cerrarSesion() {
}

void Sistema::cancelar() {
}

DtLector Sistema::ingresarLector(const string& identificador) {
    return DtLector();
}

DtMaterial Sistema::ingresarMaterial(const string& codigo) {
    return DtMaterial();
}

DtPrestamo Sistema::registrarPrestamo(const DtFecha& fecha, const string& codigoMaterial) {
    return DtPrestamo();
}

void Sistema::confirmar() {
}

set<DtMaterial> Sistema::verMateriales() {
    return set<DtMaterial>();
}

DtMaterial Sistema::verInfoMaterial(const string& codigoMaterial) {
    return DtMaterial();
}

void Sistema::puntuarMaterial(const string& codigoMaterial, int valor) {
}

DtLibro Sistema::ingresarDatosLibro(const string& codigo,
                                    const string& titulo,
                                    int anioPublicacion,
                                    int diasPermitidos,
                                    const string& autor,
                                    int cantPaginas) {
    return DtLibro();
}

void Sistema::registrarMaterial(const DtLibro& datos) {
}

DtRevista Sistema::ingresarDatosRevista(const string& codigo,
                                        const string& titulo,
                                        int anioPublicacion,
                                        int diasPermitidos,
                                        int numeroEdicion,
                                        bool esMensual) {
    return DtRevista();
}

void Sistema::registrarMaterial(const DtRevista& datos) {
}

DtFuncionario Sistema::ingresarDatosFuncionario(const string& identificador,
                                                const string& nombre,
                                                const string& password,
                                                int numeroEmpleado) {
    return DtFuncionario();
}

void Sistema::registrarFuncionario(const DtFuncionario& datos,
                                   const string& password) {
}

DtLector Sistema::ingresarDatosLector(const string& identificador,
                                      const string& nombre,
                                      const string& password,
                                      const DtFecha& fechaRegistro) {
    return DtLector();
}

void Sistema::registrarLector(const DtLector& datos,
                              const string& password) {
}
