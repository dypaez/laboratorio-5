#include "Sistema/Fabrica.h"
#include "Sistema/ISistema.h"
#include "Presentacion/Presentacion.h"

int main() {
    Fabrica fabrica;

    ISistema* sistema = fabrica.getISistema();

    presentarInicioSesion(sistema);

    return 0;
}