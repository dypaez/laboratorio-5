#include "Fabrica.h"
#include "Sistema.h"

Fabrica* Fabrica::instancia=NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia==NULL)
        instancia= new Fabrica();
    return instancia;
}

IControladorAltaProducto* Fabrica::getISistema(){
    return new Sistema();
}

Fabrica::~Fabrica(){}