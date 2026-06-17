#include "Presentacion.h"
#include "../Sistema/ISistema.h"

#include <iostream>
#include <string>

using namespace std;

void presentarInicioSesion(ISistema* sistema) {
    string identificador;
    string password;

}

void presentarSesionLector(ISistema* sistema) {
    int opcion = -1;

    do {
        

        switch (opcion) {
            case 1:
               
                break;

            case 2:
                
                break;

            case 3:
                
                break;

            case 0:
                sistema->cerrarSesion();
                break;

            default:
                
                break;
        }

    } while (opcion != 0);
}

void presentarSesionFuncionario(ISistema* sistema) {
    int opcion = -1;

    do {
        

        switch (opcion) {
            case 1:
                
                break;

            case 2:
                
                break;

            case 3:
               
                break;

            case 4:
                
                break;

            case 5:
                
                break;

            case 0:
                sistema->cerrarSesion();
                break;

            default:
                
                break;
        }

    } while (opcion != 0);
}