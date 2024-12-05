#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include "Matrix2D.h"

#include <type_traits>

template<typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>
class Vector2D
{
private:
    T m_x { };
    T m_y { };

public:
    Vector2D(T x, T y)
    : m_x { x }
    , m_y { y } {};

    friend Vector2D<T> operator-(Vector2D<T> v);
    friend Vector2D<T> operator+(Vector2D<T> v);
    friend Vector2D<T> operator*(Vector2D<T> v);

    Vector2D<T> operator*(Matrix2D m);
};

#endif
