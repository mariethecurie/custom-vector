#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

class Vector {
public:
    // Constructor and Destructor
    Vector ();
    Vector (int size);
    Vector (int size, int value);
    Vector (const Vector& other);
    Vector& operator= (const Vector& other);
    ~Vector ();

    // Element Access
    int& operator[] (int index);
    int at (int pos);
    int front ();
    int back ();

    // Capacity
    int size () const;
    int capacity () const;
    bool empty () const;
    void reserve (int thisMuch);

    // Modifiers
    void push_back (int elem);
    void pop_back ();
    void push_front (int elem);
    void pop_front ();
    void insert (int pos, int elem);
    void erase (int pos);
    void clear ();

private:
    int m_size;
    int m_capacity;
    int* m_arr;
};

#endif