#include "sistema.h"
#include <iostream>
#include <sstream>
Sistema* Sistema::instancia = nullptr;

Sistema::Sistema()
    : manejadorPersona(ManejadorPersona::getInstancia()),
      manejadorMaterial(ManejadorMaterial::getInstancia()),
      sesionIniciada(false),
      idUsuarioSesion(""),
      fechaActual(5, 6, 2026, 8, 0) {
}

Sistema::~Sistema() {
    delete manejadorMaterial;
    delete manejadorPersona;
}

ISistema* Sistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Sistema();
    }

    return instancia;
}
bool Sistema::getSesionIniciada() const{
    return sesionIniciada;
}
string Sistema::obtenerRol() const{
    return rol;
}
DtFecha* Sistema::obtenerFecha() const{
    return new DtFecha(fechaActual);
}
string Sistema::obtenerNombreDeUsuario() const{
    return nombreSesion;
}
void Sistema::ingresarDatosDePrueba(){
    registrarLector("11111111", "Lector de prueba", "1234", obtenerFecha());
    registrarFuncionario("22222222", "Funcionario de prueba", "1234", 1);
    registrarRevista("R001", "Spider-Man", 1999, 10, 1, true);
    registrarRevista("R002", "Spider-Man 2", 1999, 10, 2, true);
    registrarRevista("R003", "Spider-Man 3", 1999, 10, 3, true);
    registrarLibro("L001", "Luna de Pluton", 2015, 7, "Dross", 100);
}
bool Sistema::iniciarSesion(const string& identificador, const string& password) {
    Usuario* u = manejadorPersona->getPersona(identificador);
    sesionIniciada = manejadorPersona->validarSesion(u, password);
    nombreSesion = manejadorPersona->getNombreUsuario(identificador);
    rol = manejadorPersona->getRolUsuario(identificador);
    idUsuarioSesion = identificador;
    return sesionIniciada;
}

void Sistema::cerrarSesion() {
    idUsuarioSesion = "";
    nombreSesion = "";
    sesionIniciada = false;
}
void Sistema::listarPrestamos(const string& id){
    if(!manejadorPersona->existePersona(id))
        throw invalid_argument("El usuario especificado no existe.");
    Lector* lector = manejadorPersona->buscarLector(id);
    if(!lector)
        throw invalid_argument("El usuario especificado no es un lector.");
    
    set<DtPrestamo*> dtps = lector->obtenerPrestamos();
    if(dtps.empty()){
        cout << "\nNo hay prestamos registrados para este lector.\n";
    }
    for(auto dt : dtps){
        cout << "\n========================================\n";
        dt->imprimir();
        delete dt;
    }
    cout << "========================================\n";
}
void Sistema::listarMateriales(){
    set<DtMaterial*> dtms = manejadorMaterial->getDatosMateriales();
    if(dtms.empty()){
        cout << "\nNo hay materiales registrados.\n";
    }
    for(auto dt : dtms){
        cout << "\n========================================\n";
        dt->imprimir();
        delete dt;
    }
    cout << "========================================\n";
}
void Sistema::verInfoMaterial(const string& codigoMaterial) {
    DtMaterial* dtm;
    dtm = manejadorMaterial->getDatosMaterial(codigoMaterial);
    dtm->imprimir();
    delete dtm;
}

void Sistema::puntuarMaterial(const string& codigoMaterial, int valor) {
}

void Sistema::registrarRevista(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, int numeroEdicion, bool esMensual){
    Material* m = manejadorMaterial->crearRevista(codigo, titulo, anioPublicacion, diasPermitidos, numeroEdicion, esMensual);
    manejadorMaterial->agregarMaterial(m);
}
void Sistema::registrarLibro(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, const string& autor, int cantPaginas){
        Material* m = manejadorMaterial->crearLibro(codigo, titulo, anioPublicacion, diasPermitidos, autor, cantPaginas);
        manejadorMaterial->agregarMaterial(m);
}

void Sistema::registrarPrestamo(const string& idUsuario, const string& codigoMaterial, DtFecha* fecha, int diasPermitidos) {
    if(!manejadorPersona->existePersona(idUsuario))
        throw invalid_argument("El usuario especificado no existe.");
    if(!manejadorPersona->buscarLector(idUsuario))
        throw invalid_argument("El usuario especificado no es un lector.");
    if(!manejadorMaterial->existeMaterial(codigoMaterial))
        throw invalid_argument("El material especificado no existe.");
    Lector* lector = manejadorPersona->buscarLector(idUsuario);
    Material* mat = manejadorMaterial->getMaterial(codigoMaterial);
    manejadorPersona->crearPrestamo(lector, mat, fecha, diasPermitidos);
}
void Sistema::cambiarFecha(int dia, int mes, int anio, int hora, int minuto){
    fechaActual = DtFecha(dia, mes, anio, hora, minuto);
}

void Sistema::registrarFuncionario(const string& id, const string& nombre, const string& password, int numeroEmpleado){
    Usuario* u = manejadorPersona->crearFuncionario(id, nombre, password, numeroEmpleado);
    manejadorPersona->agregarPersona(u);
}
void Sistema::registrarLector(const string&id, const string& nombre, const string& password, DtFecha* fecha){
    Usuario* u = manejadorPersona->crearLector(id, nombre, password, fecha);
    manejadorPersona->agregarPersona(u);
}
