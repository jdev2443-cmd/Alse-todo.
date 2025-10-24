#ifndef BICICLETA_H
#define BICICLETA_H

#include "vehiculo.h"
#include <string>
#include <iostream>

class Bicicleta : public Vehiculo {
private:
    std::string tipo;  // montaña, ruta, etc.

public:
    Bicicleta(std::string m, std::string mo, std::string p, std::string t)
        : Vehiculo(m, mo, p), tipo(t) {}

    void mostrarInformacion() const override {
        std::cout << "Bicicleta: " << marca << " " << modelo
                  << " (" << tipo << ") - Placa: " << placa
                  << (disponible ? " [Disponible]" : " [Alquilada]") << "\n";
    }
};

#endif
