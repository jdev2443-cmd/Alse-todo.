// Proyecto Biblioteca
// Autores: Santiago Alejandro Maldonado y Juan Esteban Bolívar

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "libros.h"
#include <vector>

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro &libro);
    void eliminarLibro(const std::string &isbn);
    void mostrarLibrosDisponibles() const;
    void buscarPorTitulo(const std::string &titulo) const;
};

#endif