#include "vector.h"
#include <iostream>
Vector::Vector() : elements(nullptr), size(0) {}

Vector::Vector(int size) : size(size) {
    elements = new int[size];
}

Vector::~Vector() {
    delete[] elements;
}

Vector::Vector(const Vector& other) : size(other.size) {
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        elements[i] = other.elements[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

Vector::Vector(Vector&& other) noexcept : elements(other.elements), size(other.size) {
    other.elements = nullptr;
    other.size = 0;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] elements;
        elements = other.elements;
        size = other.size;
        other.elements = nullptr;
        other.size = 0;
    }
    return *this;
}

void Vector::resize(int new_size) {
    delete[] elements;
    size = new_size;
    elements = new int[size];
}

int Vector::get_size() const {
    return size;
}
/*
void Vector::fillRandom(int Min, int Max) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        elements[i] = rand() % (Max - Min) + Min;
    }
}
*/
void Vector::fill_random(int v_size, int max_el) {
    srand(time(nullptr));
    for (int i = 1; i <= v_size; i++) {
        int x = rand() % max_el + 1;
        std::cout << x << ' ';
        elements[x] = elements[x] + 1;
    }
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

const int& Vector::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// Перегрузка операторов ввода/вывода
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.size; ++i) {
        os << vec.elements[i];
        if (i < vec.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.elements[i];
    }
    return is;
}
