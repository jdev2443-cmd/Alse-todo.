#include "../include/biblio.h"
#include "../include/libros.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Sistema de Biblioteca - Escuela Colombiana de Ingeniería Julio Garavito\n";
    cout << "Autores: Santiago Alejandro Maldonado y Juan Esteban Bolívar\n\n";

    Biblioteca b;
    int opcion = -1;

    while (opcion != 0) {
        cout << "\n---- MENU DE LA BIBLIOTECA ----\n";
        cout << "1. Agregar libro\n";
        cout << "2. Eliminar libro\n";
        cout << "3. Buscar libro por título\n";
        cout << "4. Mostrar libros disponibles\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); 

        if (opcion == 1) {
            string titulo, autor, isbn;
            cout << "Título: "; getline(cin, titulo);
            cout << "Autor: "; getline(cin, autor);
            cout << "ISBN: "; getline(cin, isbn);
            b.agregarLibro(Libro(titulo, autor, isbn));
        }
        else if (opcion == 2) {
            string isbn;
            cout << "Digite el ISBN del libro a eliminar: ";
            getline(cin, isbn);
            b.eliminarLibro(isbn);
        }
        else if (opcion == 3) {
            string titulo;
            cout << "Ingrese parte o todo el título a buscar: ";
            getline(cin, titulo);
            b.buscarPorTitulo(titulo);
        }
        else if (opcion == 4) {
            b.mostrarLibrosDisponibles();
        }
        else if (opcion == 5) {
            cout << "Terminando el sistema...\n";
        }
        else {
            cout << "Opción inválida, intente nuevamente.\n";
        }
    }

    return 0;
}
