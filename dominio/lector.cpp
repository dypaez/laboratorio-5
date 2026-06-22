#include "Lector.h"
#include <stdexcept>
using namespace std;

Lector::Lector()
    : Usuario(), fechaRegistro(nullptr), prestamos(), puntajes() {
}

Lector::Lector(const string& identificador, const string& nombre,
               const string& password, DtFecha* fechaRegistro)
    : Usuario(identificador, nombre, password, "Lector"),
      fechaRegistro(fechaRegistro){
}

Lector::~Lector() {
    delete fechaRegistro;

}

DtFecha* Lector::getFechaRegistro() const {
    return fechaRegistro;
}



set<DtPrestamo*> Lector::obtenerPrestamos() const {
    if(prestamos.empty()){
        return {};
    }
    set<DtPrestamo*> resultado;
    for(auto p: prestamos){
        resultado.insert(p->obtenerInfoPrestamo());
    }
    return resultado;
}
Prestamo* Lector::crearPrestamo(DtFecha* fecha, Material* material, int diasPermitidos){
    if(!existePrestamo(material)){
        return new Prestamo(fecha, material, diasPermitidos);
    }else{
        throw invalid_argument("Ya existe un prestamo de este material a este lector.");
    }
}
bool Lector::existePrestamo(Material* material){
    for(Prestamo* p : prestamos){
        if(p->getMaterial() == material){
            return true;
        }
    }
    return false;
}
void Lector::aniadirPrestamo(Prestamo* prestamo) {
    if(!prestamo){
        throw invalid_argument("Se recibió un puntero a 'Prestamo' vacío.");
    }
    prestamos.insert(prestamo);
}

set<Puntaje*> Lector::obtenerPuntajes() const {
    return set<Puntaje*>();
}

void Lector::aniadirPuntaje(Puntaje* puntaje) {
}

Puntaje* Lector::obtenerPuntaje(Material* material) const {
    return nullptr;
}


DtUsuario* Lector::obtenerDatos() const {
    return new DtLector(
        this->getIdentificador(),
        this->getNombre(),
        this->fechaRegistro->toString()
    );
}
