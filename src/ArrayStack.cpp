
#include <iostream>
#include <IStack.h>


template <class T>
class ArrayStack : public IStack<T>{
private:
    unsigned int _capacity;
    T *_items = new T[0];

public:

    unsigned int GetDepth() override
    { return _capacity; }

    bool IsEmpty() override
    { return _capacity == 0; }

    void PrintAll() override
    {
        unsigned int i = 0;

        while (i < _capacity) {
            std::cout << _items[i] << "\n";
            i++;
        }
    }

    void Push(T item) override
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

    void Push(Node<T> *node) override
    { Push(node->get_value()); }

    void Pop() override
    {
        if (IsEmpty())
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

    void Clear() override
    {
        _capacity = 0;
        _items = nullptr;
        delete (_items);

        _items = new T[0];
    }

    T Peek() override
    { return _items[0]; }
};