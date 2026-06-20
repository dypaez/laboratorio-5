#include "fabrica.h"
#include "sistema.h"

Fabrica* Fabrica::instancia=NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia==NULL)
        instancia= new Fabrica();
    return instancia;
}

ISistema* Fabrica::getISistema(){
    return Sistema::getInstancia();
}

Fabrica::~Fabrica(){}
