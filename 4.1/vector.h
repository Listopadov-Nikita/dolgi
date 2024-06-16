#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <ctime>

class Vector {
private:
    int* elements;
    int size;

public:
    Vector();
    Vector(int size);
    ~Vector();

    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    Vector(Vector&& other) noexcept;

    Vector& operator=(Vector&& other) noexcept;

    void resize(int new_size);
    int get_size() const;
    void fill_random(int v_size, int max_el);

    int& operator[](int index);
    const int& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

#endif
