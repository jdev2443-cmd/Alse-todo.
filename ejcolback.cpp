#include <iostream>
#include <string>
#include <cstdlib> // Para exit()
using namespace std;

// Funciones para las operaciones
float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        cerr << "Error: División por cero no permitida." << endl;
        exit(1);
    }
    return a / b;
}

int main(int argc, char* argv[]) {
    // Presentación personalizada
    cout << "==========================================" << endl;
    cout << "   CALCULADORA HECHA POR:" << endl;
    cout << "   Santiago Alejandro Maldonado" << endl;
    cout << "   Juan Esteban Bolívar" << endl;
    cout << "==========================================" << endl;

    // Validación de cantidad de argumentos
    if (argc != 4) {
        cerr << "Uso incorrecto." << endl;
        cerr << "Debe ingresar: <operando1> <operador> <operando2>" << endl;
        cerr << "Ejemplo: ./calculadora 10 + 5" << endl;
        cerr << "   -- Atte: Santiago y Juan --" << endl;
        return 1;
    }

    try {
        // Conversión de los operandos a float (decimales)
        float operando1 = stof(argv[1]);
        string operador = argv[2];
        float operando2 = stof(argv[3]);

        float resultado = 0.0;

        // Selección de la operación según el operador
        if (operador == "+") {
            resultado = suma(operando1, operando2);
        } 
        else if (operador == "-") {
            resultado = resta(operando1, operando2);
        } 
        else if (operador == "*" || operador == "x" || operador == "X") {
            resultado = multiplicacion(operando1, operando2);
        } 
        else if (operador == "/") {
            resultado = division(operando1, operando2);
        } 
        else {
            cerr << "Error: Operador no válido. Use +, -, *, x o /." << endl;
            cerr << "   -- Programa hecho por Santiago y Juan --" << endl;
            return 1;
        }

        cout << "Resultado de la operación (" << operando1 << " " 
             << operador << " " << operando2 << "): " 
             << resultado << endl;
    } 
    catch (invalid_argument& e) {
        cerr << "Error: Los operandos deben ser números válidos." << endl;
        cerr << "   -- Santiago y Juan reportan este error --" << endl;
        return 1;
    }
    catch (out_of_range& e) {
        cerr << "Error: Número fuera de rango." << endl;
        cerr << "   -- Santiago y Juan reportan este error --" << endl;
        return 1;
    }

    cout << "==========================================" << endl;
    cout << "   ¡Gracias por usar la calculadora!" << endl;
    cout << "   -- Santiago Alejandro Maldonado & Juan Esteban Bolívar --" << endl;
    cout << "==========================================" << endl;

    return 0;
}