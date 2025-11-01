#include "../include/estud.h"
#include <sstream>
#include <iomanip>

Estudiante::Estudiante(const string& nombreCompleto, float valorMatricula, float promedioGeneral, int creditosAprobados)
    : nombreCompleto(nombreCompleto),
      valorMatricula(valorMatricula),
      promedioGeneral(promedioGeneral),
      creditosAprobados(creditosAprobados)
{
    if (promedioGeneral < 0.0f) this->promedioGeneral = 0.0f;
    if (promedioGeneral > 5.0f) this->promedioGeneral = 5.0f;
    if (creditosAprobados < 0) this->creditosAprobados = 0;
}

void Estudiante::registrarNota(float nota, int creditos) {
    if (nota < 0.0f || nota > 5.0f || creditos <= 0) return;

    float totalAnterior = promedioGeneral * creditosAprobados;
    promedioGeneral = (totalAnterior + nota * creditos) / (creditosAprobados + creditos);
    creditosAprobados += creditos;
}

string Estudiante::resumen() const {
    ostringstream ss;
    ss << fixed << setprecision(2);
    ss << "👤 " << nombreCompleto
       << " | Promedio: " << promedioGeneral
       << " | Créditos aprobados: " << creditosAprobados;
    return ss.str();
}