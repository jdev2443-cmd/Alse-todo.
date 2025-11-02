#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "carritocompras.h"
using namespace std;

class Usuario {
private:
    string nombre;
    vector<vector<ItemCarrito>> historialCompras;

public:
    Usuario(string n);
    void finalizarCompra(CarritoCompras carrito);
};

#endif
