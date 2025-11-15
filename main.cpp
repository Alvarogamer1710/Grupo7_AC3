#include <iostream>

#include "GestorMusica.cpp";


int main() {
    GestorMusica gestor;
    Cancion c1("Imagine", "Imagine", "John Lennon", "Rock");
    Cancion c2("Billie Jean", "Thriller", "Michael Jackson", "Pop");
    Cancion c3("Smells Like Teen Spirit", "Nevermind", "Nirvana", "Grunge");
    gestor.agregarCancion(c1);
    gestor.agregarCancion(c2);
    gestor.agregarCancion(c3);
    std::cout << "Buscando por titulo 'Imagine':\n";
    gestor.buscarPorTitulo("Imagine");
    std::cout << "\nBuscando por album 'Thriller':\n";
    gestor.buscarPorAlbum("Thriller");
    std::cout << "\nBuscando por grupo 'Nirvana':\n";
    gestor.buscarPorGrupo("Nirvana");
    std::cout << "\nBuscando por genero 'Pop':\n";
    gestor.buscarPorGenero("Pop");

    std::cout << "\nSin busquedas:\n";
    gestor.buscarPorGenero("Unknown Genre");
    gestor.buscarPorTitulo("Unknown Song");
    gestor.buscarPorAlbum("Unknown Song");
    gestor.buscarPorGrupo("Unknown Group");



}