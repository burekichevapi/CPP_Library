#include "ArrayStack.h"

#include <iostream>

template <class T>
bool ArrayStack<T>::is_empty()
{ return _capacity == 0; }

template <class T>
void ArrayStack<T>::print_all()
{
    unsigned int i = 0;

    while (i < _capacity) {
        std::cout << _items[i] << "\n";
        i++;
    }
}

template <class T>
void ArrayStack<T>::push(T item)
{
    unsigned int newCapacity = ++_capacity;

    T *newArray = new T[newCapacity];

    newArray[0] = item;

    while (newCapacity >= 1) {
        newArray[newCapacity] = _items[newCapacity - 1];
        newCapacity--;
    }

    _items = newArray;

    newArray = nullptr;
    delete (newArray);
}

template <class T>
void ArrayStack<T>::pop()
{
    if (is_empty())
        return;

    unsigned int newCapacity = --_capacity;

    T *newArray = new T[newCapacity];
    unsigned int i = 0;

    while (i < newCapacity) {
        newArray[i] = _items[i + 1];
        i++;
    }

    _items = newArray;

    newArray = nullptr;
    delete (newArray);
}

template <class T>
void ArrayStack<T>::clear()
{
    _capacity = 0;
    _items = nullptr;
    delete (_items);

    _items = new T[0];
}

template <class T>
T ArrayStack<T>::get_top_value()
{
    return _items[0];
}

template <class T>
T ArrayStack<T>::get_bottom_value()
{
    return _items[_capacity-1];

}
