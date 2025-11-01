#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

/**
 * @class Estudiante
 * @brief Representa a un estudiante con su información académica básica.
 *
 * Proyecto desarrollado por:
 *  - Santiago Alejandro Maldonado
 *  - Juan Esteban Bolívar
 *
 * Simula la gestión de registros académicos y cálculo de promedios.
 */
class Estudiante {
private:
    string nombreCompleto;    ///< Nombre completo del estudiante
    float valorMatricula;     ///< Valor o costo de matrícula
    float promedioGeneral;    ///< Promedio ponderado acumulado
    int creditosAprobados;    ///< Créditos totales aprobados

public:
    Estudiante(const string& nombreCompleto, float valorMatricula, float promedioGeneral, int creditosAprobados);

    /// Registra una nueva nota y actualiza el promedio ponderado
    void registrarNota(float nota, int creditos);

    /// Devuelve un resumen con nombre, promedio y créditos
    string resumen() const;

    // Getters para cálculos y reportes
    string getNombre() const { return nombreCompleto; }
    float getPromedio() const { return promedioGeneral; }
    int getCreditos() const { return creditosAprobados; }
};

#endif