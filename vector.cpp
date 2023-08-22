#include "vector.h"

// Constructor and Destructor
Vector::Vector ()
    : m_size {0}, m_capacity {0}, m_arr {nullptr} {
}
Vector::Vector (int size)
    : m_size {size}, m_capacity {size}, m_arr {new int[m_capacity]} {
}
Vector::Vector (int size, int value)
    : m_size {size}, m_capacity {size}, m_arr {new int[m_capacity]} {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = value;
        }
}
Vector::Vector (const Vector& other) : m_size {other.m_size}, m_capacity {other.m_capacity} {
    if (other.m_arr) {
        m_arr = new int[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }
}
Vector& Vector::operator= (const Vector& other) {
    if (this != &other) {
        delete[] m_arr;

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr = new int[m_capacity];

        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}
Vector::~Vector () {
    delete[] m_arr;
}

// Element Access
int& Vector::operator[] (int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[index];
}
int Vector::at (int pos) {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[pos];
}
int Vector::front () {
    if (m_size == 0) {
        throw std::out_of_range("The container is empty - cannot access front element");
    }
    return m_arr[0];
}
int Vector::back () {
    if (m_size == 0) {
        throw std::out_of_range("The container is empty - cannot access back element");
    }
    return m_arr[m_size - 1];
}

// Capacity
int Vector::size () const {
    return m_size;
}
int Vector::capacity () const {
    return m_capacity;
}
bool Vector::empty () const {
    return m_size == 0;
}
void Vector::reserve (int thisMuch) {
    if (thisMuch <= m_capacity) {
        return;
    }
    int* tmp = new int[thisMuch];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = tmp;
    m_capacity = thisMuch;
}

// Modifiers
void Vector::push_back (int elem) {
    if (m_size == m_capacity) {
        m_capacity = m_capacity ? m_capacity * 2 : 1;
        int* tmp = new int[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }
    m_arr[m_size] = elem;
    ++m_size;
}
void Vector::pop_back () {
    --m_size;
}
void Vector::push_front (int elem) {
    if (m_size == m_capacity) {
        m_capacity = m_capacity ? m_capacity * 2 : 1;
        int* tmp = new int[m_capacity];
        for(int i = 0; i < m_size; ++i) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    for (int i = m_size; i > 0; --i) {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[0] = elem;
    ++m_size;
}
void Vector::pop_front () {
    for (int i = 0; i < m_size - 1; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}
void Vector::insert (int pos, int elem) {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    if (m_size == m_capacity) {
        m_capacity = m_capacity ? m_capacity * 2 : 1;
        int* tmp = new int[m_capacity];
        for (int i = 0; i < pos; ++i) {
            tmp[i] = m_arr[i];
        }
        tmp[pos] = elem;
        for (int i = pos; i < m_size; ++i) {
            tmp[i + 1] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    } else {
        for (int i = m_size; i > pos; --i) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[pos] = elem;
    }
    ++m_size;
}
void Vector::erase (int pos) {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = pos; i < m_size - 1; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}
void Vector::clear () {
    delete[] m_arr;
    m_arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}
