#include "Fabrica.h"
#include "Sistema.h"
#include "ISistema.h"

ISistema* Fabrica::getSistema() {
    static Sistema sistema;
    return &sistema;
}
