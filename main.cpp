#include <iostream>
#include <string>

#include "GestorMusica.cpp"
#include "SistemaStreaming.cpp"

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

    // Streaming
    SistemaStreaming sistema;

    // añadir contenidos al sistema de streaming
    sistema.agregar(new Multimedia("Blade Runner", "Pelicula", "Sci-Fi", "UHD", false, 3.99));
    sistema.agregar(new Multimedia("Akira", "Pelicula", "Anime", "FHD", true));
    sistema.agregar(new Multimedia("Ghost in the Shell", "Pelicula", "Anime", "UHD", false, 4.49));
    sistema.agregar(new Multimedia("The Matrix", "Pelicula", "Accion", "FHD", true));
    sistema.agregar(new Multimedia("Cowboy Bebop", "Serie", "Anime", "FHD", true));
    sistema.agregar(new Multimedia("Breaking Bad", "Serie", "Drama", "UHD", true));

    int op;
    std::string busq;

    do {
        std::cout << "\n--- STREAMING ---\n";
        std::cout << "1. Buscar titulo\n2. Buscar genero\n3. Buscar calidad\n4. Alquilar contenido\n5. Ver todo\n0. Salir\n";
        std::cin >> op;
        std::cin.ignore();

        if (op == 1) {
            std::cout << "Titulo: ";
            std::getline(std::cin, busq);
            sistema.buscarTitulo(busq);
        } else if (op == 2) {
            std::cout << "Genero: ";
            std::getline(std::cin, busq);
            sistema.buscarGenero(busq);
        } else if (op == 3) {
            std::cout << "Calidad: ";
            std::getline(std::cin, busq);
            sistema.buscarCalidad(busq);
        } else if (op == 4) {
            std::cout << "Titulo del contenido por alquilar: ";
            std::getline(std::cin, busq);
            sistema.alquilarContenido(busq);
        } else if (op == 5) {
            sistema.verTodo();
        }
    } while (op != 0);

    return 0;
}