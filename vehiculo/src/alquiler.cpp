#include "../include/alquiler.h"
#include <iostream>
#include <algorithm> 

using namespace std;

void SistemaAlquiler::registrarVehiculo(Vehiculo* v) {
    vehiculos.push_back(v);
    cout << "Vehículo con placa " << v->getPlaca() << " registrado correctamente.\n";
}

void SistemaAlquiler::mostrarDisponibles() const {
    cout << "\n--- Vehículos Disponibles ---\n";
    bool hayDisponibles = false;
    for (const auto& v : vehiculos) {
        if (v->estaDisponible()) {
            v->mostrarInformacion();
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles) {
        cout << "No hay vehículos disponibles en este momento.\n";
    }
}

void SistemaAlquiler::alquilarVehiculo(const string& placa) {
    auto it = find_if(vehiculos.begin(), vehiculos.end(),
                      [&placa](Vehiculo* v) { return v->getPlaca() == placa; });

    if (it != vehiculos.end()) {
        if ((*it)->estaDisponible()) {
            (*it)->setDisponible(false);
            cout << "Vehículo con placa " << placa << " alquilado exitosamente.\n";
        } else {
            cout << "El vehículo con placa " << placa << " ya está alquilado.\n";
        }
    } else {
        cout << "No se encontró un vehículo con la placa " << placa << ".\n";
    }
}

void SistemaAlquiler::devolverVehiculo(const string& placa) {
    auto it = find_if(vehiculos.begin(), vehiculos.end(),
                      [&placa](Vehiculo* v) { return v->getPlaca() == placa; });

    if (it != vehiculos.end()) {
        if (!(*it)->estaDisponible()) {
            (*it)->setDisponible(true);
            cout << "Vehículo con placa " << placa << " devuelto exitosamente.\n";
        } else {
            cout << "El vehículo con placa " << placa << " ya estaba disponible.\n";
        }
    } else {
        cout << "No se encontró un vehículo con la placa " << placa << ".\n";
    }
}

SistemaAlquiler::~SistemaAlquiler() {
    for (auto v : vehiculos) {
        delete v; // Liberar memoria de los punteros
    }
}
