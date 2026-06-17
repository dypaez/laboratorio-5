#include "Sistema/fabrica.h"
#include "Sistema/isistema.h"
#include "Presentacion/presentacion.h"

using namespace std;

int main() {
    Fabrica* fabrica = Fabrica::getInstancia();
    ISistema* sistema = fabrica->getISistema();

    presentarInicioSesion(sistema);

    return 0;
}
