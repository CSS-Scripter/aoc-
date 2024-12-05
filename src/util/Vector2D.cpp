#include "Vector2D.h"

#include "Matrix2D.h"

template<typename T>
Vector2D<T> operator-(Vector2D<T> v) {
    return Vector2D{ m_x - v.m_x, m_y - v.m_y };
}

template<typename T>
Vector2D<T> operator+(Vector2D<T> v) {
    return Vector2D{ m_x + v.m_x, m_y + v.m_y };
}

template<typename T>
Vector2D<T> operator*(Vector2D<T> v) {
    return Vector2D{ m_x * v.m_x, m_y * v.m_y };
}

template<typename T>
Vector2D<T> operator*(Matrix2D m) {
    int x { (m_x * m.x1) + (m_y * m.x2) };
    int y { (m_x * m.y1) + (m_y * m.y2) };
    return Vector2D{ x, y };
}
