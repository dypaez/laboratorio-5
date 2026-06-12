#ifndef FABRICA_H
#define FABRICA_H
#include "ISistema.h"

class Fabrica {
    private:
    static Fabrica* instancia;
    Fabrica();
    ~Fabrica();

    public:
    static Fabrica* getInstancia();
    static ISistema* getSistema();
};

#endif
