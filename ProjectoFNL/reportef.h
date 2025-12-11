#ifndef REPORTEF_H
#define REPORTEF_H

#include <QString>

class reportef
{
public:
    reportef() = default;

    bool exportarCSV(const QString &ruta);
};

#endif // REPORTEF_H
