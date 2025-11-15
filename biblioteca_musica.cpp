//
// Created by juanl on 11/15/2025.
//

#include <iostream>

template <typename T>
class biblioteca_musica {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void ampliacionSiNecesario() {
        if (size_ >= capacity_) {
            size_t nuevaCapacidad = (capacity_ == 0) ? 1 : capacity_ * 2;
            T* nuevas = new T[nuevaCapacidad];
            for (size_t i = 0; i < size_; ++i) {
                nuevas[i] = data_[i];
            }
            delete[] data_;
            data_ = nuevas;
            capacity_ = nuevaCapacidad;
        }
    }
public:
    biblioteca_musica() : data_(nullptr), size_(0), capacity_(0) {}
    ~biblioteca_musica() { delete[] data_; }

    void push_back(const T& valor) {
        ampliacionSiNecesario();
        data_[size_] = valor;
        ++size_;
    }
    bool quitarPrimero(const T& valor) {
        for (size_t i = 0; i < size_; ++i) {
            if (data_[i] == valor) {
                for (size_t j = i; j + 1 < size_; ++j) data_[j] = data_[j + 1];
                --size_;
                return true;
            }
        }
        return false;
    }
    size_t size() const { return size_; }

    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("index out of range");
        return data_[index];
    }
    const T& operator[](size_t index) const {
        if (index >= size_) throw std::out_of_range("index out of range");
        return data_[index];
    }

};