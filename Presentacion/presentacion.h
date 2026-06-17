#ifndef PRESENTACION_H
#define PRESENTACION_H

class ISistema;

void cargarDatos(ISistema* sistema);
void presentarInicioSesion(ISistema* sistema);
void presentarSesionLector(ISistema* sistema);
void presentarSesionFuncionario(ISistema* sistema);

#endif
