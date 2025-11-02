#include <iostream>
#include "producto.h"
#include "carritocompras.h"
#include "usuario.h"

using namespace std;

int main() {
    Producto p1("Camisa", 50.0, 10);
    Producto p2("Pantalon", 80.0, 5);
    Producto p3("Zapatos", 120.0, 8);

    CarritoCompras carrito;
    Usuario usuario("Santiago Alejandro Maldonado");

    carrito.agregarProducto(p1, 2);
    carrito.agregarProducto(p2, 1);

    carrito.mostrarCarrito();

    carrito.eliminarProducto("Camisa");

    carrito.mostrarCarrito();

    usuario.finalizarCompra(carrito);

    return 0;
}
