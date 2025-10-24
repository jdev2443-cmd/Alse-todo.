#ifndef AUTO_H
#define AUTO_H

#include "vehiculo.h"

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(std::string m, std::string mo, std::string p, int cap);
    void mostrarInformacion() const override;
};

#endif