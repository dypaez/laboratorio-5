#include "Sistema.h"
#include "ManejadorPersona.h"
#include "ManejadorMaterial.h"
#include "Usuario.h"
#include "Lector.h"
#include "Funcionario.h"
#include "Material.h"
#include "Libro.h"
#include "Revista.h"
#include "Prestamo.h"
#include "Puntaje.h"

Sistema::Sistema()
    : lectorSeleccionado(nullptr), materialSeleccionado(nullptr), sesionIniciada(false), idUsuarioSesion("") {}

Sistema::~Sistema() {}

bool Sistema::iniciarSesion(const std::string& identificador, const std::string& password) {
    Usuario* usuario = ManejadorPersona::getInstancia()->getPersona(identificador);
    if (usuario == nullptr || !usuario->validarPassword(password)) {
        return false;
    }

    sesionIniciada = true;
    idUsuarioSesion = identificador;
    return true;
}

void Sistema::cerrarSesion() {
    sesionIniciada = false;
    idUsuarioSesion = "";
    cancelar();
}

void Sistema::cancelar() {
    lectorSeleccionado = nullptr;
    materialSeleccionado = nullptr;
}

DtLector Sistema::ingresarLector(const std::string& identificador) {
    Usuario* usuario = ManejadorPersona::getInstancia()->getPersona(identificador);
    Lector* lector = dynamic_cast<Lector*>(usuario);
    lectorSeleccionado = lector;

    if (lector == nullptr) {
        return DtLector();
    }
    return lector->obtenerDatosLector();
}

DtMaterial Sistema::ingresarMaterial(const std::string& codigo) {
    Material* material = ManejadorMaterial::getInstancia()->getMaterial(codigo);
    materialSeleccionado = material;

    if (material == nullptr) {
        return DtMaterial();
    }
    return material->obtenerDatos();
}

DtPrestamo Sistema::registrarPrestamo(const DtFecha& fecha, const std::string& codigoMaterial) {
    Material* material = ManejadorMaterial::getInstancia()->getMaterial(codigoMaterial);
    materialSeleccionado = material;

    if (lectorSeleccionado == nullptr || materialSeleccionado == nullptr) {
        return DtPrestamo();
    }

    Prestamo* prestamo = new Prestamo(fecha, lectorSeleccionado, materialSeleccionado);
    lectorSeleccionado->aniadirPrestamo(prestamo);
    materialSeleccionado->aniadirPrestamo(prestamo);
    return prestamo->obtenerInfoPrestamo();
}

void Sistema::confirmar() {
    cancelar();
}

std::set<DtMaterial> Sistema::verMateriales() {
    std::set<DtMaterial> datos;
    std::set<Material*> materiales = ManejadorMaterial::getInstancia()->getMateriales();

    for (Material* material : materiales) {
        if (material != nullptr) {
            datos.insert(material->obtenerDatos());
        }
    }
    return datos;
}

DtMaterial Sistema::verInfoMaterial(const std::string& codigoMaterial) {
    Material* material = ManejadorMaterial::getInstancia()->getMaterial(codigoMaterial);
    if (material == nullptr) {
        return DtMaterial();
    }
    return material->obtenerDatos();
}

void Sistema::puntuarMaterial(const std::string& codigoMaterial, int valor) {
    Usuario* usuario = ManejadorPersona::getInstancia()->getPersona(idUsuarioSesion);
    Lector* lector = dynamic_cast<Lector*>(usuario);
    Material* material = ManejadorMaterial::getInstancia()->getMaterial(codigoMaterial);

    if (!sesionIniciada || lector == nullptr || material == nullptr) {
        return;
    }

    Puntaje* puntajeExistente = lector->obtenerPuntaje(material);
    if (puntajeExistente != nullptr) {
        puntajeExistente->setValor(valor);
        material->actualizarPP();
        return;
    }

    Puntaje* puntaje = new Puntaje(valor, lector, material);
    lector->aniadirPuntaje(puntaje);
    material->aniadirPuntaje(puntaje);
}

DtLibro Sistema::ingresarDatosLibro(const std::string& codigo, const std::string& titulo,
                                    int anioPublicacion, int diasPermitidos,
                                    const std::string& autor, int cantPaginas) {
    return DtLibro(codigo, titulo, anioPublicacion, 0, 0, autor, cantPaginas);
}

void Sistema::registrarMaterial(const DtLibro& datos) {
    Libro* libro = new Libro(datos.codigo, datos.titulo, datos.anioPublicacion,
                             0, datos.autor, datos.cantPaginas);
    ManejadorMaterial::getInstancia()->agregarMaterial(libro);
}

DtRevista Sistema::ingresarDatosRevista(const std::string& codigo, const std::string& titulo,
                                        int anioPublicacion, int diasPermitidos,
                                        int numeroEdicion, bool esMensual) {
    return DtRevista(codigo, titulo, anioPublicacion, 0, 0, numeroEdicion, esMensual);
}

void Sistema::registrarMaterial(const DtRevista& datos) {
    Revista* revista = new Revista(datos.codigo, datos.titulo, datos.anioPublicacion,
                                   0, datos.numeroEdicion, datos.esMensual);
    ManejadorMaterial::getInstancia()->agregarMaterial(revista);
}

DtFuncionario Sistema::ingresarDatosFuncionario(const std::string& identificador,
                                                const std::string& nombre,
                                                const std::string& password,
                                                int numeroEmpleado) {
    return DtFuncionario(identificador, nombre, numeroEmpleado);
}

void Sistema::registrarFuncionario(const DtFuncionario& datos, const std::string& password) {
    Funcionario* funcionario = new Funcionario(datos.identificador, datos.nombre, password, datos.numeroEmpleado);
    ManejadorPersona::getInstancia()->agregarPersona(funcionario);
}

DtLector Sistema::ingresarDatosLector(const std::string& identificador,
                                      const std::string& nombre,
                                      const std::string& password,
                                      const DtFecha& fechaRegistro) {
    return DtLector(identificador, nombre, fechaRegistro);
}

void Sistema::registrarLector(const DtLector& datos, const std::string& password) {
    Lector* lector = new Lector(datos.identificador, datos.nombre, password, datos.fechaRegistro);
    ManejadorPersona::getInstancia()->agregarPersona(lector);
}
