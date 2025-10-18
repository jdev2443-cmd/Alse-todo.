/*
    Proyecto: Cálculo de la máxima ganancia de una acción 📈
    Autores: 
        - Santiago Alejandro Maldonado Barrera
        - Juan Esteban Bolívar
    Programa de Ingeniería Electrónica
    Escuela Colombiana de Ingeniería Julio Garavito
    Año: 2025

    Descripción:
    Este programa determina la máxima ganancia posible al comprar y vender una acción
    en diferentes días, asegurando que la compra se haga antes de la venta.
*/

#include <iostream>
#include <vector>
using namespace std;

// Función que calcula la ganancia máxima posible
int calcularMaxGanancia(vector<int>& precios) {
    if (precios.empty()) return 0; // Si no hay precios, no se puede calcular

    int minimo = precios[0];   // Precio mínimo encontrado hasta el momento
    int maxGanancia = 0;       // La mejor ganancia posible encontrada

    // Recorremos los precios día a día
    for (int i = 1; i < precios.size(); i++) {
        // Actualizamos el mínimo si encontramos un precio más bajo
        if (precios[i] < minimo) {
            minimo = precios[i];
        } else {
            // Calculamos la ganancia si vendemos en este día
            int gananciaActual = precios[i] - minimo;
            // Si esta ganancia es mejor que la anterior, la guardamos
            if (gananciaActual > maxGanancia) {
                maxGanancia = gananciaActual;
            }
        }
    }

    return maxGanancia;
}

int main() {
    // Mensaje de presentación
    cout << "==============================================" << endl;
    cout << "  ESCUELA COLOMBIANA DE INGENIERÍA JULIO GARAVITO" << endl;
    cout << "  INGENIERÍA ELECTRÓNICA" << endl;
    cout << "  AUTORES: Santiago Alejandro Maldonado Barrera y Juan Esteban Bolívar" << endl;
    cout << "  PROGRAMA: Cálculo de máxima ganancia en acciones 📊" << endl;
    cout << "==============================================" << endl;

    // Primera prueba: caso con ganancia
    vector<int> precios1 = {7, 1, 5, 3, 6, 4};
    int resultado1 = calcularMaxGanancia(precios1);
    cout << "\nCaso 1: Precios = [7, 1, 5, 3, 6, 4]" << endl;
    cout << "La ganancia máxima posible es: " << resultado1 << endl;

    // Segunda prueba: caso sin ganancia
    vector<int> precios2 = {7, 6, 4, 3, 1};
    int resultado2 = calcularMaxGanancia(precios2);
    cout << "\nCaso 2: Precios = [7, 6, 4, 3, 1]" << endl;
    cout << "La ganancia máxima posible es: " << resultado2 << endl;

    cout << "\nGracias por usar nuestro programa. 💡" << endl;

    return 0;
}