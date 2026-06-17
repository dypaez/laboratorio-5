#include "presentacion.h"
#include "../Sistema/isistema.h"

#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
#include <limits>

using namespace std;

static void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void pausar() {
    cout << endl << "Presione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

static void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static int leerOpcion() {
    int opcion;
    cin >> opcion;

    if (cin.fail()) {
        limpiarEntrada();
        return -1;
    }

    return opcion;
}

static void mostrarMaterial(const DtMaterial& material) {
    cout << "Codigo: " << material.codigo << endl;
    cout << "Titulo: " << material.titulo << endl;
    cout << "Anio: " << material.anioPublicacion << endl;
    cout << "Puntaje promedio: " << material.puntajePromedio << endl;
    cout << "Cantidad puntajes: " << material.cantPuntajes << endl;
}

static void cargarDatosPrueba(ISistema* sistema) {
    DtFuncionario funcionario1 = sistema->ingresarDatosFuncionario("11111111", "Funcionario Prueba", "1234", 1);
    sistema->registrarFuncionario(funcionario1, "1234");

    DtFuncionario funcionario2 = sistema->ingresarDatosFuncionario("11111112", "Funcionario Dos", "1234", 2);
    sistema->registrarFuncionario(funcionario2, "1234");

    DtLector lector1 = sistema->ingresarDatosLector("22222222", "Lector Prueba", "1234", DtFecha(1, 1, 2026));
    sistema->registrarLector(lector1, "1234");

    DtLector lector2 = sistema->ingresarDatosLector("22222223", "Lector Dos", "1234", DtFecha(2, 1, 2026));
    sistema->registrarLector(lector2, "1234");

    DtLector lector3 = sistema->ingresarDatosLector("22222224", "Lector Tres", "1234", DtFecha(3, 1, 2026));
    sistema->registrarLector(lector3, "1234");

    DtLibro libro1 = sistema->ingresarDatosLibro("L001", "Libro Prueba", 2020, 7, "Autor Prueba", 100);
    sistema->registrarMaterial(libro1);

    DtLibro libro2 = sistema->ingresarDatosLibro("L002", "Libro Dos", 2021, 10, "Autor Dos", 200);
    sistema->registrarMaterial(libro2);

    DtLibro libro3 = sistema->ingresarDatosLibro("L003", "Libro Tres", 2022, 15, "Autor Tres", 300);
    sistema->registrarMaterial(libro3);

    DtRevista revista1 = sistema->ingresarDatosRevista("R001", "Revista Prueba", 2021, 5, 1, true);
    sistema->registrarMaterial(revista1);

    DtRevista revista2 = sistema->ingresarDatosRevista("R002", "Revista Dos", 2022, 5, 2, false);
    sistema->registrarMaterial(revista2);

    sistema->ingresarLector("22222222");
    sistema->registrarPrestamo(DtFecha(10, 6, 2026), "L001");
    sistema->confirmar();

    sistema->iniciarSesion("22222222", "1234");
    sistema->puntuarMaterial("L001", 5);
    sistema->cerrarSesion();
}

static void mostrarCredencialesPrueba() {
    cout << "Sistema de Biblioteca" << endl;
    cout << "=====================" << endl << endl;
    cout << "Datos de prueba cargados automaticamente." << endl << endl;
    cout << "Funcionario de prueba" << endl;
    cout << "CI: 11111111" << endl;
    cout << "Contrasenia: 1234" << endl << endl;
    cout << "Lector de prueba" << endl;
    cout << "CI: 22222222" << endl;
    cout << "Contrasenia: 1234" << endl;
    pausar();
}

void presentarSesionLector(ISistema* sistema);
void presentarSesionFuncionario(ISistema* sistema);

void presentarInicioSesion(ISistema* sistema) {
    cargarDatosPrueba(sistema);
    mostrarCredencialesPrueba();

    int opcion = -1;

    do {
        limpiarPantalla();
        cout << "Sistema de Biblioteca" << endl;
        cout << "=====================" << endl << endl;
        cout << "1 - Iniciar sesion como lector" << endl;
        cout << "2 - Iniciar sesion como funcionario" << endl;
        cout << "0 - Salir" << endl << endl;
        cout << "Opcion: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: {
                string ci;
                string contrasenia;

                cout << "CI: ";
                cin >> ci;
                cout << "Contrasenia: ";
                cin >> contrasenia;

                if (sistema->iniciarSesion(ci, contrasenia)) {
                    presentarSesionLector(sistema);
                } else {
                    cout << "CI o contrasenia incorrectos." << endl;
                    pausar();
                }
                break;
            }

            case 2: {
                string ci;
                string contrasenia;

                cout << "CI: ";
                cin >> ci;
                cout << "Contrasenia: ";
                cin >> contrasenia;

                if (sistema->iniciarSesion(ci, contrasenia)) {
                    presentarSesionFuncionario(sistema);
                } else {
                    cout << "CI o contrasenia incorrectos." << endl;
                    pausar();
                }
                break;
            }

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }
    } while (opcion != 0);
}

void presentarSesionLector(ISistema* sistema) {
    int opcion = -1;

    do {
        limpiarPantalla();
        cout << "Sesion lector" << endl;
        cout << "============" << endl << endl;
        cout << "1 - Ver materiales" << endl;
        cout << "2 - Ver informacion de material" << endl;
        cout << "3 - Puntuar material" << endl;
        cout << "0 - Cerrar sesion" << endl << endl;
        cout << "Opcion: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: {
                
                break;
            }

            case 2: {
                
                break;
            }

            case 3: {
                string codigo;
                int valor;

                cout << "Codigo de material: ";
                cin >> codigo;
                cout << "Puntaje 1 a 5: ";
                valor = leerOpcion();

                break;
            }

            case 0:
                sistema->cerrarSesion();
                break;

            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }

    } while (opcion != 0);
}

void presentarSesionFuncionario(ISistema* sistema) {
    int opcion = -1;

    do {
        limpiarPantalla();
        cout << "Sesion funcionario" << endl;
        cout << "==================" << endl << endl;
        cout << "1 - Registrar lector" << endl;
        cout << "2 - Registrar funcionario" << endl;
        cout << "3 - Registrar material" << endl;
        cout << "4 - Registrar prestamo" << endl;
        cout << "5 - Ver materiales" << endl;
        cout << "6 - Consultar prestamos de lector" << endl;
        cout << "7 - Consultar puntajes de material" << endl;
        cout << "8 - Eliminar lector" << endl;
        cout << "9 - Eliminar material" << endl;
        cout << "0 - Cerrar sesion" << endl << endl;
        cout << "Opcion: ";
        opcion = leerOpcion();

        switch (opcion) {
            case 1: {
                string ci;
                string nombre;
                string contrasenia;
                int dia;
                int mes;
                int anio;

                cout << "CI: ";
                cin >> ci;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Contrasenia: ";
                cin >> contrasenia;
                cout << "Fecha registro dia mes anio: ";
                cin >> dia >> mes >> anio;

                
                break;
            }

            case 2: {
                string ci;
                string nombre;
                string contrasenia;
                int numeroEmpleado;

                cout << "CI: ";
                cin >> ci;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Contrasenia: ";
                cin >> contrasenia;
                cout << "Numero empleado: ";
                cin >> numeroEmpleado;

                break;
            }

            case 3: {
                int tipo;
                string codigo;
                string titulo;
                int anioPublicacion;
                int diasPermitidos;

                cout << "1 - Libro" << endl;
                cout << "2 - Revista" << endl;
                cout << "Tipo: ";
                tipo = leerOpcion();

                cout << "Codigo: ";
                cin >> codigo;
                cout << "Titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Anio publicacion: ";
                cin >> anioPublicacion;
                cout << "Dias permitidos: ";
                cin >> diasPermitidos;

                if (tipo == 1) {
                    string autor;
                    int cantPaginas;

                    cout << "Autor: ";
                    cin.ignore();
                    getline(cin, autor);
                    cout << "Cantidad paginas: ";
                    cin >> cantPaginas;

                    
                } else if (tipo == 2) {
                    int numeroEdicion;
                    int mensual;

                    cout << "Numero edicion: ";
                    cin >> numeroEdicion;
                    cout << "Es mensual? 1 si, 0 no: ";
                    cin >> mensual;

                } else {
                    cout << "Tipo invalido." << endl;
                }

                pausar();
                break;
            }

            case 4: {
                string ci;
                string codigo;
                int dia;
                int mes;
                int anio;

                cout << "CI lector: ";
                cin >> ci;
                cout << "Codigo material: ";
                cin >> codigo;
                cout << "Fecha prestamo dia mes anio: ";
                cin >> dia >> mes >> anio;

                
                break;
            }

            case 5: {
                
                break;
            }

            case 6: {
                string ci;
                cout << "CI lector: ";
                cin >> ci;

                break;
            }

            case 7: {
                string codigo;
                cout << "Codigo material: ";
                cin >> codigo;

                
                break;
            }

            case 8: {
                string ci;
                cout << "CI lector a eliminar: ";
                cin >> ci
                break;
            }

            case 9: {
                string codigo;
                cout << "Codigo material a eliminar: ";
                cin >> codigo;
                
                break;
            }

            case 0:
                sistema->cerrarSesion();
                break;

            default:
                cout << "Opcion invalida." << endl;
                pausar();
                break;
        }

    } while (opcion != 0);
}
