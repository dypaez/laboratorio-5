#ifndef FABRICA_H
#define FABRICA_H
#include "isistema.h"

class Fabrica {
    private:
    static Fabrica* instancia;
    Fabrica();
    

    public:
    static Fabrica* getInstancia();
    static ISistema* getISistema();
    ~Fabrica();
};

#endif
