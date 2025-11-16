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
    bool getEstandar() { return estandar; }
    float getPrecio() { return precio; }
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

    // buscar por calidad
    void buscarCalidad(string c) {
        bool found = false;
        for ( int i = 0; i < catalogo.size(); i++) {
            if (catalogo.get(i)->getCalidad() == c) {
                catalogo.get(i)->mostrar();
                found = true;
            }
        }
        if (!found) cout << "nada" << endl;
    }

    // alquilar contenido
    void alquilarContenido(string a) {
        bool found = false;
        for (int i = 0; i < catalogo.size(); i++)
        {
            if (catalogo.get(i)->getTitulo() == a)
            {
                found = true;
                if (catalogo.get(i)->getDisponible())
                {
                    if (!catalogo.get(i)->getEstandar())
                    {
                        cout << "El precio es: " << catalogo.get(i)->getPrecio() << " euros" << endl;
                    }
                    catalogo.get(i)->setDisponible(false);
                    cout << "Alquilado con exito" << endl;
                } else
                {
                    cout << "Ya alquilado" << endl;
                }
                break;
            }
        }
        if (!found) cout << "nada" << endl;
    }

    void verTodo() {
        for (int i = 0; i < catalogo.size(); i++) {
            catalogo.get(i)->mostrar();
        }
    }
};

