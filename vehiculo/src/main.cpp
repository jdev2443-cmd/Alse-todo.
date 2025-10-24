#include "../include/alquiler.h"
#include "../include/auto.h"
#include "../include/vehiculo.h"
#include "../include/bici.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Sistema de Alquiler de Vehículos - Escuela Colombiana de Ingeniería Julio Garavito\n";
    cout << "Autores: Santiago Alejandro Maldonado y Juan Esteban Bolívar\n\n";

    SistemaAlquiler sistema;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n--- MENU DE ALQUILER ---\n";
        cout << "1. Registrar vehículo\n";
        cout << "2. Mostrar vehículos disponibles\n";
        cout << "3. Alquilar vehículo\n";
        cout << "4. Devolver vehículo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            int tipo;
            cout << "\nSeleccione tipo de vehículo:\n";
            cout << "1. Auto\n";
            cout << "2. Bicicleta\n";
            cout << "Opción: ";
            cin >> tipo;
            cin.ignore();

            string marca, modelo, placa;
            cout << "Marca: "; getline(cin, marca);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Placa: "; getline(cin, placa);

            if (tipo == 1) {
                int capacidad;
                cout << "Capacidad de pasajeros: ";
                cin >> capacidad;
                cin.ignore();
                sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
            } else if (tipo == 2) {
                string tipoBici;
                cout << "Tipo de bicicleta (montaña, ruta, etc.): ";
                getline(cin, tipoBici);
                sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipoBici));
            } else {
                cout << "Opción inválida.\n";
            }
        }
        else if (opcion == 2) {
            sistema.mostrarDisponibles();
        }
        else if (opcion == 3) {
            string placa;
            cout << "Ingrese la placa del vehículo a alquilar: ";
            getline(cin, placa);
            sistema.alquilarVehiculo(placa);
        }
        else if (opcion == 4) {
            string placa;
            cout << "Ingrese la placa del vehículo a devolver: ";
            getline(cin, placa);
            sistema.devolverVehiculo(placa);
        }
        else if (opcion == 5) {
            cout << "Saliendo del sistema...\n";
        }
        else {
            cout << "Opción inválida, intente de nuevo.\n";
        }
    }

    return 0;
}