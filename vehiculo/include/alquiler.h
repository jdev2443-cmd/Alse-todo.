#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include "vehiculo.h"
#include <vector>

class SistemaAlquiler {
private:
    std::vector<Vehiculo*> vehiculos;

public:
    void registrarVehiculo(Vehiculo* v);
    void mostrarDisponibles() const;
    void alquilarVehiculo(const std::string& placa);
    void devolverVehiculo(const std::string& placa);
    ~SistemaAlquiler();
};

#endif