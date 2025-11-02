#include "../include/carritocompras.h"
#include <iostream>
using namespace std;

void CarritoCompras::agregarProducto(Producto p, int cantidad) {
    p.reducirStock(cantidad);
    items.push_back(ItemCarrito(p, cantidad));
    cout << "Producto agregado al carrito: " << p.getNombre() << endl;
}

void CarritoCompras::eliminarProducto(string nombre) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].getNombreProducto() == nombre) {
            items.erase(items.begin() + i);
            cout << "Producto eliminado del carrito: " << nombre << endl;
            return;
        }
    }
    cout << "El producto no se encuentra en el carrito." << endl;
}

double CarritoCompras::calcularTotal() {
    double total = 0;
    for (auto &item : items) {
        total += item.subtotal();
    }
    return total;
}

void CarritoCompras::mostrarCarrito() {
    cout << "\n--- Productos en el carrito ---" << endl;
    for (auto &item : items) {
        cout << "Producto: " << item.getNombreProducto()
             << " | Cantidad: " << item.getCantidad()
             << " | Precio unitario: $" << item.getPrecioUnitario()
             << " | Subtotal: $" << item.subtotal() << endl;
    }
    cout << "Total a pagar: $" << calcularTotal() << endl;
}
