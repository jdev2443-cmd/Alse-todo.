#include "../include/producto.h"
#include <iostream>
using namespace std;

Producto::Producto(string n, double p, int s) : nombre(n), precio(p), stock(s) {}

string Producto::getNombre() { return nombre; }
double Producto::getPrecio() { return precio; }
int Producto::getStock() { return stock; }

void Producto::reducirStock(int cantidad) {
    if (cantidad <= stock) {
        stock -= cantidad;
    } else {
        cout << "No hay suficiente stock de " << nombre << endl;
    }
}
