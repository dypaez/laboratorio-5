#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "isistema.h"
#include "../manejadores/manejadormaterial.h"
#include "../manejadores/manejadorpersona.h"
using namespace std;

class Sistema : public ISistema {
    private:
        static Sistema* instancia;

        ManejadorPersona* manejadorPersona;
        ManejadorMaterial* manejadorMaterial;
        bool sesionIniciada;
        string idUsuarioSesion;
        string nombreSesion;
        string rol;
        DtFecha fechaActual;
        Sistema();

    public:

        static ISistema* getInstancia();
        ~Sistema() override;
        bool getSesionIniciada() const override;
        string obtenerRol() const override;
        DtFecha* obtenerFecha() const override;
        string obtenerNombreDeUsuario() const override;
        void ingresarDatosDePrueba() override;
        bool iniciarSesion(const string& identificador, const string& password) override;
        void cerrarSesion() override;
        void listarMateriales() override;
        void verInfoMaterial(const string& codigoMaterial) override;
        void puntuarMaterial(const string& codigoMaterial, int valor) override;
        void registrarRevista(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, int numeroEdicion, bool esMensual) override;
        void registrarLibro(const string& codigo, const string& titulo, int anioPublicacion, int diasPermitidos, const string& autor, int cantPaginas) override;
        void registrarPrestamo(const string& idUsuario, const string& codigoMaterial, DtFecha* fecha, int diasPermitidos) override;
        void listarPrestamos(const string& id);
        void registrarFuncionario(const string& id, const string& nombre, const string& password, int numeroEmpleado) override;
        void registrarLector(const string&id, const string& nombre, const string& password, DtFecha* fecha) override;
        void cambiarFecha(int dia, int mes, int anio, int hora, int minuto);
     
};

#endif
