#include "DataTypes.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

DtFecha::DtFecha()
    : dia(1), mes(1), anio(1900), hora(1), minuto(0) {
}
DtFecha::DtFecha(const DtFecha& _fecha) : dia(_fecha.dia), mes(_fecha.mes), anio(_fecha.anio), hora(_fecha.hora), minuto(_fecha.minuto) {}
DtFecha::DtFecha(int dia, int mes, int anio, int hora, int minuto)
    : dia(dia), mes(mes), anio(anio), hora(hora), minuto(minuto) {
}
string DtFecha::toString() const{
    stringstream ss;

    ss << setfill('0')
       << setw(2) << dia << "/"
       << setw(2) << mes << "/"
       << setw(2) << anio << " "
       << setw(2) << hora << ":"
       << setw(2) << minuto;

    return ss.str();
}
DtUsuario::DtUsuario()
    : identificador(""), nombre("") {
}

DtUsuario::DtUsuario(const string& identificador, const string& nombre)
    : identificador(identificador), nombre(nombre) {
}

DtLector::DtLector()
    : DtUsuario(), fechaRegistro("") {
}

DtLector::DtLector(const string& identificador, const string& nombre,
                   const string& fechaRegistro)
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
    : fechaPrestamo(),codigoMaterial(""), nombreMaterial(""), diasPermitidos(0) {
}

DtPrestamo::DtPrestamo(const string& fechaPrestamo, const string& codigoMaterial, const string& nombreMaterial, int diasPermitidos) : fechaPrestamo(fechaPrestamo),codigoMaterial(codigoMaterial), nombreMaterial(nombreMaterial), diasPermitidos(diasPermitidos){}
void DtPrestamo::imprimir(){
    cout << "Fecha del prestamo: " << fechaPrestamo << endl;
    cout << "Codigo del material prestado: " << codigoMaterial << endl;
    cout << "Titulo del material prestado: " << nombreMaterial << endl;
    cout << "Duracion del prestamo: " << diasPermitidos << endl;
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
void DtMaterial::imprimir(){
    cout << "Codigo: " << codigo << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Año de publicacion: " << anioPublicacion << endl;
    cout << "Puntaje promedio: " << puntajePromedio << endl;
    cout << "Cantidad de puntajes: " << cantPuntajes << endl;
}
void DtRevista::imprimir(){
    DtMaterial::imprimir();
    cout << "Numero de edicion: " << numeroEdicion << endl;
    cout << "Es mensual? " << (esMensual ? "Si" : "No") << endl; 
}
void DtLibro::imprimir(){
    DtMaterial::imprimir();
    cout << "Autor: " << autor << endl;
    cout << "Cantidad de paginas: " << cantPaginas << endl; 
}
bool operator<(const DtMaterial& a, const DtMaterial& b) {
    return a.codigo < b.codigo;
}
