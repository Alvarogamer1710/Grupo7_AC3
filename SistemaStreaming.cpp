#include <iostream>
#include <string>
using namespace std;

// clase peli
class Multimedia {
private:
    string titulo;
    string tipo;
    string genero;
    string calidad;
    bool estandar;
    float precio;
    bool disponible;

public:
    Multimedia(string t, string tip, string g, string cal, bool est, float p = 0.0) {
        titulo = t;
        tipo = tip;
        genero = g;
        calidad = cal;
        estandar = est;
        precio = p;
        disponible = true;
    }

    string getTitulo() { return titulo; }
    string getGenero() { return genero; }
    string getCalidad() { return calidad; }
    bool getDisponible() { return disponible; }
    void setDisponible(bool d) { disponible = d; }

    void mostrar() {
        cout << titulo << " - " << genero << " - " << calidad;
        if (!estandar) cout << " (" << precio << " euros)";
        cout << " - " << (disponible ? "Disponible" : "Alquilado") << endl;
    }
};

// vector basico
template <typename T>
class Vector {
private:
    T* datos;
    int cap;
    int tam;

public:
    Vector() {
        cap = 10;
        tam = 0;
        datos = new T[cap];
    }

    ~Vector() {
        delete[] datos;
    }

    void push(T elem) {
        if (tam >= cap) {
            cap *= 2;
            T* nuevo = new T[cap];
            for (int i = 0; i < tam; i++) nuevo[i] = datos[i];
            delete[] datos;
            datos = nuevo;
        }
        datos[tam++] = elem;
    }

    T get(int i) {
        if (i >= 0 && i < tam) return datos[i];
        return nullptr;
    }

    int size() { return tam; }
};

// sistema
class SistemaStreaming {
private:
    Vector<Multimedia*> catalogo;

public:
    void agregar(Multimedia* m) {
        catalogo.push(m);
    }

    // buscar por titulo
    void buscarTitulo(string t) {
        bool found = false;
        for (int i = 0; i < catalogo.size(); i++) {
            if (catalogo.get(i)->getTitulo() == t) {
                catalogo.get(i)->mostrar();
                found = true;
            }
        }
        if (!found) cout << "nada" << endl;
    }

    // buscar por genero
    void buscarGenero(string g) {
        bool found = false;
        for (int i = 0; i < catalogo.size(); i++) {
            if (catalogo.get(i)->getGenero() == g) {
                catalogo.get(i)->mostrar();
                found = true;
            }
        }
        if (!found) cout << "nada" << endl;
    }

    // ivan aca meté buscarCalidad y alquilar, tmb metelo en el menu

    void verTodo() {
        for (int i = 0; i < catalogo.size(); i++) {
            catalogo.get(i)->mostrar();
        }
    }
};

// main
int main() {
    SistemaStreaming sistema;

    // meter pelis
    sistema.agregar(new Multimedia("Blade Runner", "Pelicula", "Sci-Fi", "UHD", false, 3.99));
    sistema.agregar(new Multimedia("Akira", "Pelicula", "Anime", "FHD", true));
    sistema.agregar(new Multimedia("Ghost in the Shell", "Pelicula", "Anime", "UHD", false, 4.49));
    sistema.agregar(new Multimedia("The Matrix", "Pelicula", "Accion", "FHD", true));
    sistema.agregar(new Multimedia("Cowboy Bebop", "Serie", "Anime", "FHD", true));
    sistema.agregar(new Multimedia("Breaking Bad", "Serie", "Drama", "UHD", true));

    int op;
    string busq;

    do {
        cout << "\n--- STREAMING ---\n";
        cout << "1. Buscar titulo\n2. Buscar genero\n3. Ver todo\n0. Salir\n";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            cout << "Titulo: ";
            getline(cin, busq);
            sistema.buscarTitulo(busq);
        } else if (op == 2) {
            cout << "Genero: ";
            getline(cin, busq);
            sistema.buscarGenero(busq);
        } else if (op == 3) {
            sistema.verTodo();
        }
    } while (op != 0);

    return 0;
}
