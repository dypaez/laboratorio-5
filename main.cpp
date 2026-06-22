#include "Sistema/fabrica.h"
#include "Sistema/isistema.h"
#include "Presentacion/presentacion.h"

using namespace std;
Fabrica* fabrica;
ISistema* sistema;
int main() {
    fabrica = Fabrica::getInstancia();
    sistema = fabrica->getISistema();
    bool inicioSesion=true;
    do{
        inicioSesion = presentarInicioSesion(sistema);
        string rol = sistema->obtenerRol();
        while(sistema->getSesionIniciada()){
                if(rol=="Lector")
                presentarSesionLector(sistema);
            else
                presentarSesionFuncionario(sistema);
        };
    }while(!sistema->getSesionIniciada() && inicioSesion);
    return 0;
}
