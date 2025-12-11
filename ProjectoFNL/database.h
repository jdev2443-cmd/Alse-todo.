#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>

class database
{
public:
    static database& instance();
    QSqlDatabase& getDatabase();

private:
    database();
    ~database() = default;

    QSqlDatabase db;

    void crearTablas();
};

#endif // DATABASE_H
