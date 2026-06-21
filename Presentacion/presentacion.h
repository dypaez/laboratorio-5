#ifndef PRESENTACION_H
#define PRESENTACION_H
#include <vector>
#include <string>
#include "../sistema/isistema.h"

void limpiarConsola();
int desplegarOpciones(const vector<std::string>& opciones, int indice_min, int indice_max);
int manejarEntrada();
void presentarInicioSesion(ISistema* sistema);
void presentarSesionLector(ISistema* sistema);
void presentarSesionFuncionario(ISistema* sistema);



#endif
