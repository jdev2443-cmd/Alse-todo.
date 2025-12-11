#ifndef COMPONENTES_H
#define COMPONENTES_H

#include <QString>

struct Componentes
{

    QString nombre;
    QString tipo;
    int cantidad;
    QString ubicacion;
    QString dia_compra;
    int min_almacen;
    QString notas;

    Componentes()
        : cantidad(0),
          min_almacen(0)
    {}
};

#endif
