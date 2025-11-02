#include "../include/usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string n) : nombre(n) {}

void Usuario::finalizarCompra(CarritoCompras carrito) {
    cout << "\nCompra finalizada por " << nombre << endl;
    carrito.mostrarCarrito();
    cout << "Gracias por su compra!" << endl;
}
