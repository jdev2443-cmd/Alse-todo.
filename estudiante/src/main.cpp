#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
#include "../include/estud.h"
using namespace std;

/**
 * @brief Aplicación principal de gestión de estudiantes.
 *
 * Desarrollado por:
 *   Santiago Alejandro Maldonado y Juan Esteban Bolívar
 *
 * Simula el registro académico de varios estudiantes,
 * el cálculo de promedios y la generación de reportes.
 */

int main() {
    vector<Estudiante> estudiantes;

    cout << "==============================\n";
    cout << "  SISTEMA ACADÉMICO UNIVERSITARIO\n";
    cout << "  Desarrollado por: Santiago Alejandro Maldonado y Juan Esteban Bolívar\n";
    cout << "==============================\n\n";

    // Registro inicial de estudiantes
    estudiantes.emplace_back("Santiago Alejandro Maldonado", 1500000, 4.3, 36);
    estudiantes.emplace_back("Juan Esteban Bolívar", 1400000, 3.9, 28);
    estudiantes.emplace_back("Laura Ramírez", 1300000, 4.7, 42);
    estudiantes.emplace_back("Daniel Torres", 1250000, 3.5, 20);

    cout << "📋 ESTUDIANTES REGISTRADOS INICIALMENTE:\n";
    for (const auto& e : estudiantes)
        cout << " - " << e.resumen() << endl;
    cout << endl;

    cout << "🏫 REGISTRANDO NUEVAS NOTAS...\n";
    estudiantes[0].registrarNota(4.8, 3);  // Santiago
    estudiantes[1].registrarNota(4.2, 4);  // Juan
    estudiantes[2].registrarNota(4.6, 2);  // Laura
    estudiantes[3].registrarNota(3.8, 3);  // Daniel

    cout << "\n✅ PROMEDIOS ACTUALIZADOS:\n";
    for (const auto& e : estudiantes)
        cout << " - " << e.resumen() << endl;
    cout << endl;

    // Cálculo del promedio general ponderado
    float suma = 0.0f;
    int totalCreditos = 0;
    for (const auto& e : estudiantes) {
        suma += e.getPromedio() * e.getCreditos();
        totalCreditos += e.getCreditos();
    }
    float promedioGeneral = (totalCreditos > 0) ? suma / totalCreditos : 0.0f;

    cout << "📈 Promedio general del grupo: " << fixed << setprecision(2) << promedioGeneral << "\n\n";

    // Generar reporte .txt
    ofstream reporte("reportes/reporte_estudiantes.txt");
    if (reporte.is_open()) {
        reporte << "REPORTE DE ESTUDIANTES - UNIVERSIDAD VIRTUAL\n";
        reporte << "Autores: Santiago Alejandro Maldonado, Juan Esteban Bolívar\n\n";
        reporte << "Nombre,Promedio,Creditos\n";
        for (const auto& e : estudiantes) {
            reporte << e.getNombre() << ","
                    << fixed << setprecision(2) << e.getPromedio() << ","
                    << e.getCreditos() << "\n";
        }
        reporte << "\nPromedio general del grupo: " << fixed << setprecision(2) << promedioGeneral << "\n";
        reporte.close();
        cout << "📝 Reporte generado exitosamente en 'reportes/reporte_estudiantes.txt'\n";
    } else {
        cerr << "❌ Error: no se pudo crear el archivo de reporte.\n";
    }

    cout << "\nFin de la simulación académica.\n";
    return 0;
}