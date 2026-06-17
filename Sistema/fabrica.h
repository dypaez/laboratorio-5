#ifndef FABRICA_H
#define FABRICA_H

#include "isistema.h"

using namespace std;

class Fabrica {
private:
    static Fabrica* instancia;

    Fabrica();

public:
    static Fabrica* getInstancia();
    ISistema* getISistema();
    ~Fabrica();
};

#endif
