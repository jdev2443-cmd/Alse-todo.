#include <iostream>
#include<vector>
#include <cmath>
#include<cctype>

// Definir la estructura de una nota(grade)
struct Grade{
    int studentId; 
    float grade;
};

// Función para leer las coordenadas de varias notas
void leerNotas(Grade notas[], int n){
    char respuesta;
    std::cout << "¿Desea ingresar las notas manualmente? (s/n): ";
    std::cin>>respuesta;
    // Leer la respuesta del usuario
    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's'){
        // Completar: Leer las coordenadas de cada nota
        for (int i=0; i<n; i++){
            std::cout << "Ingrese las notas del estudiante" << i + 1 << " (id, nota): ";
            std::cin >> notas[i].studentId>> notas[i].grade;
        }
    }
    else{
        // Usar valores predeterminados
        std::cout << "Usando valores predeterminados...\n";
        for (int i =0; i<n; i++){
        notas[i] ={1000 + i, 1.0};
        }
    }
}

// Función para calcular la mayor magnitud
double calcularPromedio(Grade notas[], int n, int &indiceNotaMasAlta) {
    double sum = 0.0;
    indiceNotaMasAlta =0;
    for (int i =0; i < n; i++){
        sum += notas[i].grade;
        if (notas[i].grade > notas[indiceNotaMasAlta].grade){
            indiceNotaMasAlta = i;
        }
    } 
    return sum / n;
}

// Función para mostrar el promedio y estdudiante con mayor nota
void mostrarResultado(Grade notas[], int indiceNotaMasAlta, double promedio){
    std::cout << "\n========= RESULTADOS =========\n";
    std::cout << "Promedio general de notas: " << promedio << "\n";
    std::cout << "Estudiante con mayor calificación:\n";
    std::cout << "   ID: " << notas[indiceNotaMasAlta].studentId;
              << "  -> Nota: " << notas[indiceNotaMasAlta].grade << "\n";
    std::cout << "==============================\n"
}

int main(){
    int n;
    std::cout << "Ingrese el número de estudiantes (mínimo 2): ";
    // Leer el número de notas
    std::cin>>n;

    if(n<2){
        std::cout << "Se necesitan al menos 2 estudiantes para determinar el promedio.\n";
        return 1;
    }
    // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer las notas (manual o predeterminado)
    std::vector<Grade> notas(n);
    leerNotas(notas.data(), n);
    // Calcular promedio
    int indiceNotaMasAlta;
    // llamar funcion
    double promedio = calcularPromedio(notas.data(),n,indiceNotaMasAlta);
    //  Mostrar el resultado
    mostrarResultado(notas.data(), indiceNotaMasAlta, promedio);

    return 0;
}
