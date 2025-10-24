#include "../include/vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(std::string m, std::string mo, std::string p, bool d)
    : marca(m), modelo(mo), placa(p), disponible(d) {}

void Vehiculo::mostrarInformacion() const {
    std::cout << "Marca: " << marca
              << " | Modelo: " << modelo
              << " | Placa: " << placa
              << " | Disponible: " << (disponible ? "Sí" : "No")
              << std::endl;
}

bool Vehiculo::estaDisponible() const {
    return disponible;
}

void Vehiculo::setDisponible(bool d) {
    disponible = d;
}

std::string Vehiculo::getPlaca() const {
    return placa;
}
