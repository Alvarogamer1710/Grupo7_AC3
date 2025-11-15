//
// Created by juanl on 11/15/2025.
//

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <cstddef>

class Cancion
{
public:
    std::string title;
    std::string album;
    std::string artist;
    std::string genre;

    Cancion() = default;
    Cancion(std::string t, std::string a, std::string ar, std::string g)
        : title(std::move(t)), album(std::move(a)), artist(std::move(ar)), genre(std::move(g)) {}

    void print() const
    {
        std::cout << "Song: " << title
                  << " | Album: " << album
                  << " | Artist: " << artist
                  << " | Genre: " << genre << '\n';
    }

    bool operator==(const Cancion& other) const
    {
        return title == other.title && album == other.album && artist == other.artist && genre == other.genre;
    }
};

class biblioteca_musica {
private:
    Cancion* data_;
    size_t size_;
    size_t capacity_;

    void ampliacionSiNecesario() {
        if (size_ >= capacity_) {
            size_t nuevaCapacidad = (capacity_ == 0) ? 1 : capacity_ * 2;
            Cancion* nuevasCanciones = new Cancion[nuevaCapacidad];
            for (size_t i = 0; i < size_; ++i) {
                nuevasCanciones[i] = data_[i];
            }
            delete[] data_;
            data_ = nuevasCanciones;
            capacity_ = nuevaCapacidad;
        }
    }
public:
    biblioteca_musica() : data_(nullptr), size_(0), capacity_(0) {}
    ~biblioteca_musica() { delete[] data_; }

    void push_back(const Cancion& cancion) {
        ampliacionSiNecesario();
        data_[size_++] = cancion;
    }
    bool quitarPrimero(const Cancion& cancion) {
        for (size_t i = 0; i < size_; ++i) {
            if (data_[i] == cancion) {
                for (size_t j = i; j + 1 < size_; ++j) data_[j] = data_[j + 1];
                --size_;
                return true;
            }
        }
        return false;
    }
    size_t size() const { return size_; }

    Cancion& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("index out of range");
        return data_[index];
    }
    const Cancion& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("index out of range");
        return data_[index];
    }

};