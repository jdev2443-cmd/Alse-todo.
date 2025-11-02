#ifndef CARRITOCOMPRAS_H
#define CARRITOCOMPRAS_H

#include <vector>
#include <string>
#include "itemcarrito.h"
using namespace std;

class CarritoCompras {
private:
    vector<ItemCarrito> items;

public:
    void agregarProducto(Producto p, int cantidad);
    void eliminarProducto(string nombre);
    double calcularTotal();
    void mostrarCarrito();
};

#endif