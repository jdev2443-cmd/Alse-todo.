#include "database.h"

database& database::instance()
{
    static database instance;
    return instance;
}

database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("inventario.db");

    if (!db.open()) {
        qDebug() << "Error abriendo la base de datos:" << db.lastError().text();
    } else {
        qDebug() << "Base de datos abierta correctamente.";
        crearTablas();
    }
}

QSqlDatabase& database::getDatabase()
{
    return db;
}

void database::crearTablas()
{
    QSqlQuery query(db);

    QString sql =
        "CREATE TABLE IF NOT EXISTS components ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "nombre TEXT NOT NULL, "
        "tipo TEXT, "
        "cantidad INTEGER, "
        "ubicacion TEXT, "
        "dia_compra TEXT, "
        "min_almacen INTEGER, "
        "notas TEXT"
        ");";

    if (!query.exec(sql)) {
        qDebug() << "Error creando tabla components:"
                 << query.lastError().text();
    } else {
        qDebug() << "Tabla components lista.";
    }
}
