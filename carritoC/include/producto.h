#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string n, double p, int s);
    string getNombre();
    double getPrecio();
    int getStock();
    void reducirStock(int cantidad);
};

#endif
