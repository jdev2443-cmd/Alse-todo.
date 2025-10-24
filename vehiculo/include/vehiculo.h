// Proyecto Sistema de Alquiler de Vehículos
// Autores: Santiago Alejandro Maldonado y Juan Esteban Bolívar

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
protected:
    std::string marca, modelo, placa;
    bool disponible;

public:
    Vehiculo(std::string m, std::string mo, std::string p, bool d = true);
    virtual ~Vehiculo() = default;
    virtual void mostrarInformacion() const;
    bool estaDisponible() const;
    void setDisponible(bool d);
    std::string getPlaca() const;
};

#endif