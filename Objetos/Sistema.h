#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "ISistema.h"

class Lector;
class Material;

class Sistema : public ISistema {
private:
    Lector* lectorSeleccionado;
    Material* materialSeleccionado;
    bool sesionIniciada;
    std::string idUsuarioSesion;

public:
    Sistema();
    ~Sistema() override;

    bool iniciarSesion(const std::string& identificador, const std::string& password) override;
    void cerrarSesion() override;
    void cancelar() override;

    DtLector ingresarLector(const std::string& identificador) override;
    DtMaterial ingresarMaterial(const std::string& codigo) override;
    DtPrestamo registrarPrestamo(const DtFecha& fecha, const std::string& codigoMaterial) override;
    void confirmar() override;

    std::set<DtMaterial> verMateriales() override;
    DtMaterial verInfoMaterial(const std::string& codigoMaterial) override;
    void puntuarMaterial(const std::string& codigoMaterial, int valor) override;

    DtLibro ingresarDatosLibro(const std::string& codigo, const std::string& titulo,
                               int anioPublicacion, int diasPermitidos,
                               const std::string& autor, int cantPaginas) override;
    void registrarMaterial(const DtLibro& datos) override;

    DtRevista ingresarDatosRevista(const std::string& codigo, const std::string& titulo,
                                   int anioPublicacion, int diasPermitidos,
                                   int numeroEdicion, bool esMensual) override;
    void registrarMaterial(const DtRevista& datos) override;

    DtFuncionario ingresarDatosFuncionario(const std::string& identificador,
                                           const std::string& nombre,
                                           const std::string& password,
                                           int numeroEmpleado) override;
    void registrarFuncionario(const DtFuncionario& datos, const std::string& password) override;

    DtLector ingresarDatosLector(const std::string& identificador,
                                 const std::string& nombre,
                                 const std::string& password,
                                 const DtFecha& fechaRegistro) override;
    void registrarLector(const DtLector& datos, const std::string& password) override;
};

#endif
