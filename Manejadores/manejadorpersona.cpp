#include "ManejadorPersona.h"
#include <stdexcept>
using namespace std;

ManejadorPersona* ManejadorPersona::instancia = nullptr;

ManejadorPersona::~ManejadorPersona() {
    /* Al eliminarse el manejador, se eliminan todos los elementos
    que estén en su colección */
    for(auto &par: personas){
        delete par.second;
    }
}

ManejadorPersona* ManejadorPersona::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorPersona();
    }
    return instancia;
}
Lector* ManejadorPersona::crearLector(const string&id, const string& nombre, const string& password, DtFecha* fechaRegistro){
    if(!existePersona(id))
        return new Lector(id, nombre, password, fechaRegistro);
    throw invalid_argument("El usuario especificado ya esta registrado.");
}
Funcionario* ManejadorPersona::crearFuncionario(const string& id, const string& nombre, const string& password, int numeroEmpleado){
    if(!existePersona(id))
        return new Funcionario(id, nombre, password, numeroEmpleado);
    throw invalid_argument("El usuario especificado ya esta registrado.");
}
DtUsuario* ManejadorPersona::getDatosPersona(const string& id) const {
    auto it = personas.find(id);
    if(it != personas.end())
        return it->second->obtenerDatos();
    throw invalid_argument("La persona especificada no existe.");
}
void ManejadorPersona::crearPrestamo(Lector* lector, Material* material, DtFecha* fecha, int diasPermitidos){
    Prestamo* p = lector->crearPrestamo(fecha, material, diasPermitidos);
    lector->aniadirPrestamo(p); 
}
set<DtUsuario*> ManejadorPersona::getDatosPersonas() const {
    set<DtUsuario*> resultado;
    for(auto &par: personas){
        resultado.insert(par.second->obtenerDatos());
    }
    return resultado;
}
Usuario* ManejadorPersona::getPersona(const string& id) const{
    auto it = personas.find(id);
    if(it!=personas.end()){
        return it->second;
    }
    throw invalid_argument("La persona especificada no existe.");
}
Lector* ManejadorPersona::buscarLector(const string& id){
    
    auto it = personas.find(id);

    if(it == personas.end())
        return nullptr;

    return dynamic_cast<Lector*>(it->second);
}
string ManejadorPersona::getNombreUsuario(const string& id) const{
    return getPersona(id)->getNombre();
}
string ManejadorPersona::getRolUsuario(const string &id) const{
    return getPersona(id)->getRol();
}
void ManejadorPersona::agregarPersona(Usuario* persona) {
    if(!persona)
        //Si el puntero a persona es nulo, dar error.
        throw invalid_argument("Se recibio un puntero a 'Usuario' nulo.");

    if(existePersona(persona->getIdentificador()))
        throw invalid_argument("La persona ingresada ya está registrada en el sistema.");

    //Si todo sale bien, insertar persona al sistema
    this->personas.insert({persona->getIdentificador(), persona});
}

bool ManejadorPersona::existePersona(const string& id) const {
    /*Si al buscar a la persona que se desea ingresar en el sistema, no se llega al final del map,
    esto significa que esta persona ya existe en el sistema. Por tanto, se devuelve true.*/
    return personas.find(id) != personas.end();
}
bool ManejadorPersona::validarSesion(const Usuario* u, const string &password) const{
    return u->validarPassword(password);
}
