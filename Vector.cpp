#include "Vector.h"

Vector::Vector(int n)
{
    if (n < 2)
    {
        n = 2;
    }

    _size = 0;
    _capacity = n;
    _resizeFactor = n;
    _elements = new int[_capacity];
}

Vector::~Vector()
{
    delete[] _elements;
}

int Vector::size() const
{
    return _size;
}

int Vector::capacity() const
{
    return _capacity;
}

int Vector::resizeFactor() const
{
    return _resizeFactor;
}

bool Vector::empty() const
{
    return _size == 0;
}

void Vector::push_back(const int& val)
{
    // Make more space when the vector is full.
    if (_size == _capacity)
    {
        reserve(_capacity + _resizeFactor);
    }

    _elements[_size] = val;
    _size++;
}

int Vector::pop_back()
{
    if (empty())
    {
        std::cerr << "error: pop from empty vector" << std::endl;
        return -9999;
    }

    _size--;
    return _elements[_size];
}

void Vector::reserve(const int n)
{
    if (n <= _capacity)
    {
        return;
    }

    // Increase the capacity by the resize factor.
    int newCapacity = _capacity;
    while (newCapacity < n)
    {
        newCapacity += _resizeFactor;
    }

    // Copy the elements to a bigger array.
    int* newElements = new int[newCapacity];
    for (int i = 0; i < _size; i++)
    {
        newElements[i] = _elements[i];
    }

    delete[] _elements;
    _elements = newElements;
    _capacity = newCapacity;
}

void Vector::resize(const int n)
{
    if (n < 0)
    {
        return;
    }

    reserve(n);
    _size = n;
}

void Vector::assign(const int val)
{
    for (int i = 0; i < _size; i++)
    {
        _elements[i] = val;
    }
}

void Vector::resize(const int n, const int& val)
{
    if (n < 0)
    {
        return;
    }

    int oldSize = _size;
    resize(n);

    // Set the value only for new elements.
    for (int i = oldSize; i < _size; i++)
    {
        _elements[i] = val;
    }
}

Vector::Vector(const Vector& other)
{
    _size = other._size;
    _capacity = other._capacity;
    _resizeFactor = other._resizeFactor;
    _elements = new int[_capacity];

    // Copy values to a different array.
    for (int i = 0; i < _size; i++)
    {
        _elements[i] = other._elements[i];
    }
}

Vector& Vector::operator=(const Vector& other)
{
    // Do nothing if we assign the vector to itself.
    if (this != &other)
    {
        int* newElements = new int[other._capacity];
        for (int i = 0; i < other._size; i++)
        {
            newElements[i] = other._elements[i];
        }

        delete[] _elements;
        _elements = newElements;
        _size = other._size;
        _capacity = other._capacity;
        _resizeFactor = other._resizeFactor;
    }

    return *this;
}

int& Vector::operator[](int n) const
{
    if (n < 0 || n >= _size)
    {
        std::cerr << "error: index out of range" << std::endl;
        return _elements[0];
    }

    return _elements[n];
}
