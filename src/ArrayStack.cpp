
#include <iostream>
#include <IStack.h>


template <class T>
class ArrayStack : public IStack<T>{
private:
    unsigned int _capacity;
    T *_items = new T[0];

public:

    unsigned int get_depth() override
    { return _capacity; }

    bool is_empty() override
    { return _capacity == 0; }

    void print_all() override
    {
        unsigned int i = 0;

        while (i < _capacity) {
            std::cout << _items[i] << "\n";
            i++;
        }
    }

    void push(T item) override
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

    void push(Node<T> *node) override
    { push(node->get_value()); }

    void pop() override
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

    void clear() override
    {
        _capacity = 0;
        _items = nullptr;
        delete (_items);

        _items = new T[0];
    }

    T peek() override
    { return _items[0]; }
};