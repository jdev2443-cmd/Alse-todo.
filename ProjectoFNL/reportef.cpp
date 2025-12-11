#include "reportef.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFile>
#include <QTextStream>
#include <QDebug>

bool reportef::exportarCSV(const QString &ruta)
{
    QFile file(ruta);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo";
        return false;
    }

    QTextStream out(&file);

    out << "id,nombre,tipo,cantidad,ubicacion,dia_compra,min_almacen,notas\n";

    QSqlQuery query("SELECT * FROM components");
    while (query.next()) {
        out << query.value("id").toString() << ",";
        out << query.value("nombre").toString() << ",";
        out << query.value("tipo").toString() << ",";
        out << query.value("cantidad").toString() << ",";
        out << query.value("ubicacion").toString() << ",";
        out << query.value("dia_compra").toString() << ",";
        out << query.value("min_almacen").toString() << ",";
        out << query.value("notas").toString() << "\n";
    }

    file.close();
    return true;
}
