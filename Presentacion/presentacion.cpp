#include "presentacion.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
using namespace std;
void limpiarConsola() {
    std::cout << "\033[2J\033[H";
}
int desplegarOpciones(const vector<std::string>& opciones, int indice_min, int indice_max){
    if(indice_max > opciones.size()-1){
        cout << "\nEl indice maximo de la busqueda supera el tamaño de la coleccion de opciones.\n";
    }
    for(size_t i=indice_min; i < indice_max+1; i++){
        int contador=1;
        cout << contador << " - " << opciones[i] << endl;
    }
    cout << "0 -" << opciones[0] << endl;    
}
int manejarEntrada(){
    int opcion;
    while(!(cin >> opcion)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t>";
    }
    return opcion;
}
void presentarInicioSesion(ISistema* sistema) {
    vector<std::string> opciones = {
            "Salir",
            "Iniciar Sesión"
    };
    string identificador;
    string password;
    int entrada=-1;
    int reintentar;
    while(entrada!=0){
        limpiarConsola();
        desplegarOpciones(opciones, 1, 1);
        entrada = manejarEntrada();
        switch(entrada){
            case 0:
                cout << "\nAdios!";
                break;
            case 1:
                bool valido=false, cancelar=false;
                while(!valido && !cancelar){
                    limpiarConsola();
                    cout << "\n-- Inicio de sesion --";
                    cout << "\nIngrese su identificacion: ";
                    cin >> identificador;
                    cout << "\nIngrese su contraseña: ";
                    cin >> password;
                    valido = sistema->iniciarSesion(identificador, password);
                    if(valido)
                        cout << "\nSesion iniciada con exito!";
                        break;
                    while(reintentar!=0 || reintentar!=1){
                        cout << "\nDatos invalidos, desea reintentar?" << endl << "1 - Si / 0 - No" << endl;
                        reintentar = manejarEntrada();
                        if(reintentar==0){
                            cancelar=true;
                        }
                    }
                }
                break;
            default:
                cout << "Opción inválida." << endl;
                entrada = -1;
                break;
        }
    }
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
