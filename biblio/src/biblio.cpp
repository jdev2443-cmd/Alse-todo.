#include "../include/biblio.h"
#include <iostream>

void Biblioteca::agregarLibro(const Libro &libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado: " << libro.getTitulo() << std::endl;
}

void Biblioteca::eliminarLibro(const std::string &isbn) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getISBN() == isbn) {
            std::cout << "Eliminando libro: " << it->getTitulo() << std::endl;
            libros.erase(it);
            return;
        }
    }
    std::cout << "No se encontró un libro con ISBN: " << isbn << std::endl;
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "\nLibros disponibles:\n";
    for (const auto &libro : libros)
        if (libro.estaDisponible())
            libro.mostrarInfo();
}

void Biblioteca::buscarPorTitulo(const std::string &titulo) const {
    std::cout << "\nResultados de búsqueda para: " << titulo << "\n";
    for (const auto &libro : libros)
        if (libro.getTitulo().find(titulo) != std::string::npos)
            libro.mostrarInfo();
}