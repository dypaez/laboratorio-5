#ifndef PRESENTACION_H
#define PRESENTACION_H
#include <vector>
#include <string>
#include "../sistema/isistema.h"

void limpiarConsola();
void desplegarOpciones(const vector<std::string>& opciones, int indice_min, int indice_max);
int manejarEntrada();
bool presentarInicioSesion(ISistema* sistema);
void presentarSesionLector(ISistema* sistema);
void presentarSesionFuncionario(ISistema* sistema);



#endif
