#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "producto.h"

class ItemCarrito {
private:
    Producto producto;
    int cantidad;

public:
    ItemCarrito(Producto p, int c);
    double subtotal();
    string getNombreProducto();
    int getCantidad();
    double getPrecioUnitario();
};

#endif
