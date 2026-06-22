#ifndef MANEJADOR_PERSONA_H
#define MANEJADOR_PERSONA_H
#include "../dominio/usuario.h"
#include "../dominio/funcionario.h"
#include "../dominio/lector.h"
#include <map>
#include <set>
#include <string>
using namespace std;

class ManejadorPersona {
private:
    static ManejadorPersona* instancia;
    map<string, Usuario*> personas;
    ManejadorPersona() = default;

public:
    ~ManejadorPersona();

    static ManejadorPersona* getInstancia();
    Lector* crearLector(const string&id, const string& nombre, const string& password, DtFecha* fechaRegistro);
    Funcionario* crearFuncionario(const string& id, const string& nombre, const string& password, int numeroEmpleado);
    DtUsuario* getDatosPersona(const string& id) const;
    set<DtUsuario*> getDatosPersonas() const;
    Usuario* getPersona(const string& id) const;
    string getNombreUsuario(const string& id) const;
    string getRolUsuario(const string &id) const;
    void crearPrestamo(Lector* l, Material* m, DtFecha* fecha, int diasPermitidos);
    Lector* buscarLector(const string& id);
    void agregarPersona(Usuario* persona);
    bool existePersona(const string& id) const;
    bool validarSesion(const Usuario* u, const string &password) const;
};

#endif
