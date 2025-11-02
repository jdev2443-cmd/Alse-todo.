#include "../include/itemcarrito.h"

ItemCarrito::ItemCarrito(Producto p, int c) : producto(p), cantidad(c) {}

double ItemCarrito::subtotal() {
    return producto.getPrecio() * cantidad;
}

string ItemCarrito::getNombreProducto() {
    return producto.getNombre();
}

int ItemCarrito::getCantidad() {
    return cantidad;
}

double ItemCarrito::getPrecioUnitario() {
    return producto.getPrecio();
}
