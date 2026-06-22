#include "presentacion.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <sstream>

using namespace std;
void limpiarConsola(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    fflush(stdout);
}
bool datosPruebaIngresados=false;
void mostrarTitulo(int modo){
    cout << "\n========================================\n";
    cout << "         SISTEMA DE BIBLIOTECA\n\n";
    vector<std::string> modos = {
            "            INICIO DE SESION", //caso 0
            "              MODO  LECTOR", //caso 1
            "            MODO FUNCIONARIO", //caso 2
    };
    cout << modos[modo] << endl;
    cout << "========================================\n";
}
void pausa() {
    std::cout << "\n\nPresione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void desplegarOpciones(const vector<std::string>& opciones, int indice_min, int indice_max){
    if(indice_max > opciones.size()-1){
        cout << "\nEl indice maximo de la busqueda supera el tamaño de la coleccion de opciones.\n";
    }
    int contador=1;
    for(size_t i=indice_min; i < indice_max+1; i++){
        cout << contador << " - " << opciones[i] << endl;
        contador++;
    }
    cout << "0 - " << opciones[0] << endl;    
}
int manejarEntrada(){
    int opcion;
    cout << "\n\t>";
    while(!(cin >> opcion)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t>";
    }
    return opcion;
}
void mostrarDatosDePrueba(){
    cout << "========================================\n";

    cout << "\nLECTOR DE PRUEBA\n";
    cout << "  CI:       11111111\n";
    cout << "  Password: 1234\n";

    cout << "\nFUNCIONARIO DE PRUEBA\n";
    cout << "  CI:       22222222\n";
    cout << "  Password: 1234\n";

    cout << "\n========================================\n";
}
bool presentarInicioSesion(ISistema* sistema) {
    vector<std::string> opciones = {
            "Salir", //caso 0
            "Iniciar Sesion", //caso 1
            "Ingresar datos de prueba" //Caso 2

    };
    string identificador;
    string password;
    int entrada=-1;
    int reintentar=-1;
    do{
        opciones[2] = datosPruebaIngresados ? "Consultar datos de prueba" : "Ingresar datos de prueba";
        limpiarConsola();
        mostrarTitulo(0);
        desplegarOpciones(opciones, 1, 2);
        entrada = manejarEntrada();
        switch(entrada){
            case 0:{
                cout << "\nAdios!";
                pausa();
                return false;
                break;
            }
            case 1:{
                bool valido=false;
                bool cancelar=false;
                while(!valido && !cancelar){
                    limpiarConsola();
                    mostrarTitulo(0);
                    cout << "\nIngrese su identificacion: ";
                    cin >> identificador;
                    cout << "\nIngrese su contraseña: ";
                    cin >> password;
                    try{
                        valido = sistema->iniciarSesion(identificador, password);
                    }
                    catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                    }
                    if(valido){
                        cout << "\nSesion iniciada con exito!";
                        cout << "\nBienvenid@ " << sistema->obtenerNombreDeUsuario() << endl;
                        pausa();
                        return true;
                    }
                    do{
                        cout << "\nDatos invalidos, desea reintentar?" << endl << "1 - Si / 0 - No" << endl;
                        reintentar = manejarEntrada();
                    }while(reintentar!=0 && reintentar!=1);

                    if(reintentar==0){
                        cancelar=true;
                    }
                }
                break;
            }
            case 2:{
                limpiarConsola();
                if(datosPruebaIngresados){
                    cout << "\n========================================\n";
                    cout << "           DATOS DE PRUEBA\n";
                }else{
                    cout << "\n========================================\n";
                    cout << "            DATOS INGRESADOS            \n";
                    sistema->ingresarDatosDePrueba();
                    datosPruebaIngresados=true;
                }
                mostrarDatosDePrueba();
                entrada = -1;
                pausa();
                break;
            }
            default:{
                cout << "Opción inválida." << endl;
                entrada = -1;
                break;
            }
        }
    }while(entrada!=0 && !sistema->getSesionIniciada());
}

void presentarSesionLector(ISistema* sistema) {
    
    vector<std::string> opciones = {
            "Cerrar Sesion", //caso 0
            "Ver materiales", //caso 1
            "Ver informacion de material", //caso 2
            "Puntuar material" //caso 3
    };
    int entrada = -1;
    do {
        limpiarConsola();
        mostrarTitulo(1);
        desplegarOpciones(opciones, 1, 3);
        entrada = manejarEntrada();
        switch (entrada) {
            case 1:{
                limpiarConsola();
                mostrarTitulo(1);
                sistema->listarMateriales();
                pausa();
                break;  
            }
            case 2:{
                string codigoMaterial;
                cout << "Ingrese el codigo del material\n";
                cin >> codigoMaterial;
                try{
                    limpiarConsola();
                    mostrarTitulo(1);
                    sistema->verInfoMaterial(codigoMaterial);
                    pausa();
                }
                catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                        pausa();
                }
                break;
            }
            case 3:{
                cout << "NO IMPLEMENTADO.\n";
                pausa();
                break;
            }
            case 0:{
                cout << "Adios " << sistema->obtenerNombreDeUsuario() << "!" << endl;
                sistema->cerrarSesion();
                pausa(); 
                break;
            }
            default:{
                cout << "Opción inválida." << endl;
                entrada = -1;
                break;
            }

        }

    } while (entrada != 0);
}

void presentarSesionFuncionario(ISistema* sistema) {
    vector<std::string> opciones = {
            "Cerrar Sesion", //caso 0
            "Registrar Lector", //caso 1
            "Registrar Funcionario", //caso 2
            "Registrar Material", //caso 3
            "Registrar Prestamo", //caso 4
            "Ver Materiales", //caso 5
            "Consultar Prestamos de Lector", //caso 6
            "Consultar Puntajes de Material", //caso 7
            "Eliminar Lector", //caso 8
            "Eliminar Material", //caso 9
            "Cambiar fecha del sistema"//caso 10

    };
    int entrada = -1;
    do {
        limpiarConsola();
        mostrarTitulo(2);
        desplegarOpciones(opciones, 1, 10);
        entrada = manejarEntrada();
        switch (entrada) {
            case 1:{
                    string identificador="";
                    string nombre="";
                    string password="";
                    cout << "Ingrese la CI del lector\n";
                    cin >> identificador;
                    cout << "Ingrese el nombre del lector\n" << "\n\t> ";
                    cin >> nombre;
                    cout << "Ingrese la contrasenia del lector\n" << "\n\t> ";
                    cin >> password;
                    try{
                        sistema->registrarLector(identificador, nombre, password, sistema->obtenerFecha());
                        cout << "\nLector ingresado con exito!\n";
                        pausa();
                    }
                    catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                        pausa();
                    }
                break;
            }
            case 2:{
                    string identificador="";
                    string nombre="";
                    string password="";
                    int numEmp=0;
                    cout << "Ingrese la CI del funcionario\n" << "\n\t> ";
                    cin >> identificador;
                    cout << "Ingrese el nombre del funcionario\n" << "\n\t> ";
                    cin >> nombre;
                    cout << "Ingrese la contrasenia del funcionario\n" << "\n\t> ";
                    cin >> password;
                    cout << "Ingrese el numero de empleado del funcionario\n";
                    numEmp = manejarEntrada();
                    try{
                        sistema->registrarFuncionario(identificador, nombre, password, numEmp);
                        cout << "\Funcionario ingresado con exito!\n";
                        pausa();
                    }
                    catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                        pausa();
                    }
                break;
            }
            case 3:{
                //Atributos generales
                string codigo;
                string titulo;
                int anioPublicacion;
                int diasPermitidos;
                int tipo = 0;
                //Revista
                int numeroEdicion;
                bool esMensual;
                //Libro
                string autor;
                int cantPaginas;
                cout << "Ingrese el codigo del material\n" << "\n\t> ";
                cin >> codigo;
                cout << "Ingrese el titulo del material\n" << "\n\t> ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, titulo);
                cout << "Ingrese el anio de publicacion del material\n";
                anioPublicacion = manejarEntrada();
                cout << "Ingrese la cantidad de dias que puede prestarse el material\n";
                diasPermitidos = manejarEntrada();
                while(tipo!=1 && tipo!=2){
                cout << "El material que esta registrando es una revista o un libro?" << endl;
                cout << "1 - Revista\n2 - Libro\n";
                tipo = manejarEntrada();
                    if(tipo != 1 && tipo != 2){
                        cout << "Opcion invalida. Intente de nuevo." << endl;
                        pausa();
                    }
                }
                if(tipo == 1){ //Si es revista
                    cout << "Ingrese el numero de edicion de la revista\n";
                    numeroEdicion = manejarEntrada();
                    int aux = 0;
                    while(aux != 1 && aux != 2){
                        cout << "Es mensual?\n" << "1 - Si\n2 - No\n";
                        aux = manejarEntrada();
                        if(aux!= 1 && aux!=2){
                            cout << "Opcion invalida. Intente de nuevo." << endl;
                            pausa();
                        }
                    }
                    if(aux == 1){
                        esMensual=true;
                    }else{
                        esMensual=false;
                    }
                    try{
                        sistema->registrarRevista(codigo, titulo, anioPublicacion, diasPermitidos, numeroEdicion, esMensual);
                        cout << "\Revista ingresado con exito!\n";
                        pausa();
                    }
                    catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                        pausa();
                    }
                }else{ //Si es libro
                    autor;
                    cantPaginas;
                    cout << "Ingrese el nombre del autor del libro\n" << "\n\t> ";
                    cin >> autor;
                    cout << "Ingrese la cantidad de paginas del libro\n";
                    cantPaginas = manejarEntrada();
                    try{
                        sistema->registrarLibro(codigo, titulo, anioPublicacion, diasPermitidos, autor, cantPaginas);
                        cout << "\Libro ingresado con exito!\n";
                        pausa();
                    }
                    catch(const exception& e){
                        cout << "Error: " << e.what() << endl;
                        pausa();
                    }
                }
                break;
            }

            case 4:{
                string idUsuario;
                string codigo;
                int diasPermitidos;
                cout << "Ingrese el identificador del lector\n" << "\n\t> ";
                cin >> idUsuario;
                cout << "Ingrese el codigo del material\n" << "\n\t> ";
                cin >> codigo;
                cout << "Cuantos dias dura el prestamo?" << endl;
                diasPermitidos = manejarEntrada();
                try{
                    sistema->registrarPrestamo(idUsuario, codigo, sistema->obtenerFecha(), diasPermitidos);
                    cout << "Prestamo registrado con exito!\n";
                    pausa();
                }
                catch(const exception& e){
                    cout << "Error: " << e.what() << endl;
                    pausa();
                }
                break;
            }

            case 5:{
                limpiarConsola();
                mostrarTitulo(2);
                sistema->listarMateriales();
                pausa();
                break;
            }
            case 6:{
                string idUsuario;
                int diasPermitidos;
                cout << "Ingrese el identificador del lector\n" << "\n\t> ";
                cin >> idUsuario;
                try{
                    sistema->listarPrestamos(idUsuario);
                    pausa();
                }
                catch(const exception& e){
                    cout << "Error: " << e.what() << endl;
                    pausa();
                }
                break;
            }
            case 7:{
                cout << "NO IMPLEMENTADO.\n";
                pausa();
                break;
            }
            case 8:{
                cout << "NO IMPLEMENTADO.\n";
                pausa();
                break;
            }
            case 9:{
                cout << "NO IMPLEMENTADO.\n";
                pausa();
                break;
            }
            case 10:{
                int dia, mes, anio;
                int hora, minuto;
                bool valido;
                do{
                    valido = true;
                    cout << "Ingrese el dia de la fecha" << endl;
                    dia = manejarEntrada();
                    cout << "Ingrese el mes de la fecha" << endl;
                    mes = manejarEntrada();
                    cout << "Ingrese el anio de la fecha" << endl;
                    anio = manejarEntrada();
                    cout << "Ingrese la hora" << endl;
                    hora = manejarEntrada();
                    cout << "Ingrese los minutos" << endl;
                    minuto = manejarEntrada();
                    if((dia<1 || dia >31) || (mes < 1 || mes > 12) || (hora < 0 || hora > 23) || (minuto< 0 || minuto > 59)){
                        valido = false;
                        cout << "Fecha invalida, intente de nuevo." << endl;
                    }
                }while(!valido);
                sistema->cambiarFecha(dia, mes, anio, hora, minuto);
                cout << "Fecha cambiada con éxito." << endl << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto<< endl;
                pausa();
                break;
            }
            case 0:{
                cout << "Adios " << sistema->obtenerNombreDeUsuario() << "!" << endl;
                sistema->cerrarSesion();
                pausa(); 
                break;
            }
            default:{
                cout << "Opción inválida." << endl;
                entrada = -1;
                break;
            }

        }

    } while (entrada != 0);
}
