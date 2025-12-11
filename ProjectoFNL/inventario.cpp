#include "inventario.h"
#include "database.h"
#include <QtSql>

bool inventario::insertarComponente(const Componentes &c) {
    QSqlQuery q(database::instance().getDatabase());

    q.prepare("INSERT INTO components "
              "(nombre, tipo, cantidad, ubicacion, dia_compra, min_almacen, notas) "
              "VALUES (:nombre, :tipo, :cantidad, :ubicacion, :dia_compra, :min_almacen, :notas)");

    q.bindValue(":nombre", c.nombre);
    q.bindValue(":tipo", c.tipo);
    q.bindValue(":cantidad", c.cantidad);
    q.bindValue(":ubicacion", c.ubicacion);
    q.bindValue(":dia_compra", c.dia_compra);
    q.bindValue(":min_almacen", c.min_almacen);
    q.bindValue(":notas", c.notas);

    return q.exec();
}
