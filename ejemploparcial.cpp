/*
    ---------------------------------------------------------------
       UNIVERSIDAD : Escuela colobiana de ingenieria julio garavito- PROGRAMACIÓN ESTRUCTURADA
       Ejercicio de evaluación: Cálculo del promedio y mayor nota
       Entrega de:
           - Santiago Alejandro Maldonado Barrera
           - Juan Esteban Bolívar Muñoz
    ---------------------------------------------------------------
*/

#include <iostream>
#include <cctype> // tolower() mover de manera independiente

// Estructura que guarda la info de cada estudiante
struct Grade {
    int id;
    float nota;
};

// Función que permite llenar el arreglo de notas
void leerNotas(Grade lista[], int cantidad) {
    char opcion;
    std::cout << "\n¿Desea ingresar las notas manualmente? (s/n): ";
    std::cin >> opcion;
    opcion = std::tolower(opcion);

    if (opcion == 's') {
        std::cout << "\n--- Registro manual de notas ---\n";
        for (int i = 0; i < cantidad; i++) {
            std::cout << "Estudiante " << (i + 1) << " -> Ingrese (id nota): ";
            std::cin >> lista[i].id >> lista[i].nota;

            // Validación del rango
            while (lista[i].nota < 0.0 || lista[i].nota > 5.0) {
                std::cout << "  >> Nota inválida. Debe estar entre 0.0 y 5.0, vuelva a ingresar: ";
                std::cin >> lista[i].nota;
            }
        }
    } else {
        std::cout << "\nCargando valores predeterminados...\n";
        // Valores ejemplo
        Grade base[] = {
            {111, 3.2},
            {222, 4.7},
            {333, 2.9},
            {444, 5.0}
        };

        for (int i = 0; i < cantidad; i++) {
            if (i < 4) lista[i] = base[i];
            else lista[i] = {1000 + i, 0.0}; // relleno extra
        }
    }
}

// Función que calcula promedio y devuelve índice de mejor nota
double calcularPromedio(Grade lista[], int cantidad, int &posMejor) {
    double suma = 0.0;
    posMejor = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += lista[i].nota;

        if (lista[i].nota > lista[posMejor].nota) {
            posMejor = i; // se actualiza si se encuentra una nota mayor
        }
    }

    return suma / cantidad;
}

// Función que muestra resultados finales
void mostrarResultados(Grade lista[], int posMejor, double promedio) {
    std::cout << "\n========= RESULTADOS =========\n";
    std::cout << "Promedio general de notas: " << promedio << "\n";
    std::cout << "Estudiante con mayor calificación:\n";
    std::cout << "   ID: " << lista[posMejor].id
              << "  -> Nota: " << lista[posMejor].nota << "\n";
    std::cout << "==============================\n";
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de estudiantes (mínimo 2): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << ">> Error: deben ser al menos 2 estudiantes.\n";
        return 1;
    }

    Grade *grupo = new Grade[n];

    leerNotas(grupo, n);

    int posMayor;
    double prom = calcularPromedio(grupo, n, posMayor);

    mostrarResultados(grupo, posMayor, prom);

    delete[] grupo;
    return 0;
}