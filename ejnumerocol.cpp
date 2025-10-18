/*
    Proyecto: Conversión de título de columna de Excel a número 🔠➡️🔢
    Autores: 
        - Santiago Alejandro Maldonado Barrera
        - Juan Esteban Bolívar
    Programa de Ingeniería Electrónica
    Escuela Colombiana de Ingeniería Julio Garavito
    Año: 2025

    Descripción:
    Este programa convierte un título de columna de Excel (por ejemplo "A", "AB", "ZY")
    en su número correspondiente. Por ejemplo:
        A -> 1
        Z -> 26
        AA -> 27
        AB -> 28
        ZY -> 701
*/

#include <iostream>
#include <string>
using namespace std;

// Función que convierte el título de columna en número
int convertirColumnaExcel(string titulo) {
    long resultado = 0;

    // Recorremos cada letra del título
    for (char letra : titulo) {
        // Convertimos la letra en un valor (A = 1, B = 2, ..., Z = 26)
        int valor = letra - 'A' + 1;

        // Aplicamos el sistema posicional de base 26
        resultado = resultado * 26 + valor;
    }

    return resultado;
}

int main() {
    // Mensaje de presentación
    cout << "==============================================" << endl;
    cout << "  ESCUELA COLOMBIANA DE INGENIERÍA JULIO GARAVITO" << endl;
    cout << "  INGENIERÍA ELECTRÓNICA" << endl;
    cout << "  AUTORES: Santiago Alejandro Maldonado Barrera y Juan Esteban Bolívar" << endl;
    cout << "  PROGRAMA: Conversión de título de columna de Excel a número 🔠➡️🔢" << endl;
    cout << "==============================================" << endl;

    // Casos de prueba predefinidos
    string columna1 = "AB";
    int resultado1 = convertirColumnaExcel(columna1);
    cout << "\nCaso 1: Título de columna = \"" << columna1 << "\"" << endl;
    cout << "Número correspondiente: " << resultado1 << endl;

    string columna2 = "ZY";
    int resultado2 = convertirColumnaExcel(columna2);
    cout << "\nCaso 2: Título de columna = \"" << columna2 << "\"" << endl;
    cout << "Número correspondiente: " << resultado2 << endl;

    // Entrada del usuario
    string entradaUsuario;
    cout << "\n==============================================" << endl;
    cout << "Ahora ingresa un título de columna personalizado (por ejemplo: A, AA, FX, etc.): ";
    cin >> entradaUsuario;

    int resultadoUsuario = convertirColumnaExcel(entradaUsuario);
    cout << "El número correspondiente al título \"" << entradaUsuario << "\" es: " << resultadoUsuario << endl;

    cout << "\nGracias por usar nuestro programa. 💡" << endl;

    return 0;
}