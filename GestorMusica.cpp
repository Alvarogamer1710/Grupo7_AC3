//
// Created by Álvaro on 15/11/2025.
//

#include <iostream>
#include <string>
#include "Cancion.cpp"
#include "biblioteca_musica.cpp"

class GestorMusica {
private:
    biblioteca_musica<Cancion> canciones;

public:
    // Agregar una canción
    void agregarCancion(const Cancion& c) {
        canciones.push_back(c);
    }

    // Buscar por título de canción
    void buscarPorTitulo(const std::string& titulo) const {
        bool encontrado = false;
        for (size_t i = 0; i < canciones.size(); ++i) {
            if (canciones[i].getTituloCancion() == titulo) {
                canciones[i].mostrar();
                encontrado = true;
            }
        }
        if (not encontrado)
            std::cout << "No se encontro la cancion con ese titulo.\n";
    }

    // Buscar por álbum
    void buscarPorAlbum(const std::string& album) const {
        bool encontrado = false;
        for (size_t i = 0; i < canciones.size(); ++i) {
            if (canciones[i].getTituloAlbum() == album) {
                canciones[i].mostrar();
                encontrado = true;
            }
        }
        if (not encontrado)
            std::cout << "No se encontro el album.\n";
    }

    // Buscar por grupo
    void buscarPorGrupo(const std::string& grupo) const {
        bool encontrado = false;
        for (size_t i = 0; i < canciones.size(); ++i) {
            if (canciones[i].getGrupo() == grupo) {
                canciones[i].mostrar();
                encontrado = true;
            }
        }
        if (not encontrado)
            std::cout << "No se encontro el grupo.\n";
    }

    // Buscar por género
    void buscarPorGenero(const std::string& genero) const {
        bool encontrado = false;
        for (size_t i = 0; i < canciones.size(); ++i) {
            if (canciones[i].getGenero() == genero) {
                canciones[i].mostrar();
                encontrado = true;
            }
        }
        if (not encontrado)
            std::cout << "No se encontro el genero.\n";
    }
};