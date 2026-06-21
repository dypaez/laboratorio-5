#include "ManejadorMaterial.h"
#include <stdexcept>
using namespace std;

ManejadorMaterial* ManejadorMaterial::instancia = nullptr;

ManejadorMaterial::~ManejadorMaterial() {
    /* Al eliminarse el manejador, se eliminan todos los elementos
    que estén en su colección */
    for(auto &par: materiales){
        delete par.second;
    }
}

ManejadorMaterial* ManejadorMaterial::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorMaterial();
    }

    return instancia;
}

DtMaterial* ManejadorMaterial::getDatosMaterial(const string& codigo) const {
    auto it = materiales.find(codigo);
    if(it != materiales.end())
        return it->second->obtenerDatos();
    throw invalid_argument("El material especificado no existe.");
}

set<DtMaterial*> ManejadorMaterial::getDatosMateriales() const {
    set<DtMaterial*> resultado;
    for(auto &par: materiales){
        resultado.insert(par.second->obtenerDatos());
    }
    return resultado;
}

void ManejadorMaterial::agregarMaterial(Material* material) {
    if(!material)
        //Si el puntero a Material es nulo, dar error.
        throw invalid_argument("Se recibio un puntero a 'Material' nulo.");

    if(existeMaterial(material->getCodigo()))
        throw invalid_argument("El material ingresado ya está registrado en el sistema.");
    
    this->materiales.insert({material->getCodigo(),material});
    //Si todo sale bien, insertar material al sistema
}

bool ManejadorMaterial::existeMaterial(const string& codigo) const {
    return materiales.find(codigo) != materiales.end();
}
