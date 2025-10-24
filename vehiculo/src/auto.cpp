#include "../include/auto.h"
#include <iostream>

Auto::Auto(std::string m, std::string mo, std::string p, int cap)
    : Vehiculo(m, mo, p), capacidadPasajeros(cap) {}

void Auto::mostrarInformacion() const {
    std::cout << "[AUTO] ";
    Vehiculo::mostrarInformacion();
    std::cout << "  Capacidad de pasajeros: " << capacidadPasajeros << std::endl;
}
