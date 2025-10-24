#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string placa;
    bool disponible;

public:
    Vehiculo(std::string m, std::string mo, std::string p)
        : marca(m), modelo(mo), placa(p), disponible(true) {}

    virtual ~Vehiculo() = default;

    virtual void mostrarInformacion() const {
        std::cout << "Vehículo: " << marca << " " << modelo
                  << " - Placa: " << placa
                  << (disponible ? " [Disponible]" : " [Alquilado]") << "\n";
    }

    bool estaDisponible() const { return disponible; }
    void setDisponible(bool d) { disponible = d; }
    std::string getPlaca() const { return placa; }
};

#endif
