#include "fabrica.h"
#include "sistema.h"

using namespace std;

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {
}

Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }

    return instancia;
}

ISistema* Fabrica::getISistema() {
    return Sistema::getInstancia();
}

Fabrica::~Fabrica() {
}
