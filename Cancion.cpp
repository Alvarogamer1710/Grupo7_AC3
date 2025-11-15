#include <iostream>
#include <string>

class Cancion {
private:
    std::string tituloCancion;
    std::string tituloAlbum;
    std::string grupo;
    std::string genero;

public:
    Cancion() {}

    // Constructor
    Cancion(const std::string& tCancion,
            const std::string& tAlbum,
            const std::string& g,
            const std::string& gen)
        : tituloCancion(tCancion),
          tituloAlbum(tAlbum),
          grupo(g),
          genero(gen) {}

    // Getters
    std::string getTituloCancion() const { return tituloCancion; }
    std::string getTituloAlbum()  const { return tituloAlbum; }
    std::string getGrupo()        const { return grupo; }
    std::string getGenero()       const { return genero; }

    // Mostrar información
    void mostrar() const {
        std::cout << "Cancion:" << tituloCancion << "\nAlbum:" << tituloAlbum << "\nGrupo:" << grupo << "\nGenero:" << genero << std::endl;
    }
};

