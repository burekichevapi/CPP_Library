//
// Created by amer on 1/2/19.
//

#include <ILinkedList.h>
#include <iostream>

template<class T>
class ArrayLinkedList : public ILinkedList<T>
{
public:
    ArrayLinkedList()
    { this->_items = new T[0]; }

    unsigned int get_size() override
    { return this->_size; }

    void print_all() override
    {
        for(int i = 0; i < this->_size; i++)
            std::cout << this->_items[i] << "\n";
    }

    void clear_all() override
    {
        this->_size = 0;
        this->_items = nullptr;
        delete (this->_items);

        this->_items = new T[0];
    }

    void add_first(T item) override
    {
        this->_size++;

        T *newArray = new T[this->_size];
        newArray[0] = item;

        for(int i = 1; i < this->_size; i++)
            newArray[i] = this->_items[i - 1];

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    void add_first(Node<T> *newNode) override
    { add_last(newNode->get_value()); }

    void add_last(T item) override
    {
        unsigned int newSize = ++this->_size;
        T *newArray = new T[newSize];

        for(int i = 0; i < newSize-1; i++)
            newArray[i] = this->_items[i];

        newArray[newSize-1] = item;

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    void add_last(Node<T> *newNode) override
    { add_last(newNode->get_value()); }

    void remove_first() override
    {
        if (this->empty())
            return;

        this->_size--;

        T *newArray = new T[this->_size];

        for(int i = 0; i < this->_size; i++)
            newArray[i] = this->_items[i+1];

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    void remove_last() override
    {
        if (this->empty())
            return;

        this->_size--;

        T *newArray = new T[this->_size];

        for(int i = 0; i < this->_size; i++)
            newArray[i] = this->_items[i];

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    bool contains(T value) override
    {
        if(this->empty())
            return false;

        for(int i = 0; i < this->_size; i++)
            if(this->_items[i] == value)
                return true;

        return false;
    }

    void remove_by_value(T value) override
    {
        T *newArray = new T[this->_size - 1];

        for (int i = 0; i < this->_size; i++)
        {
            if (this->_items[i] == value)
            {
                for (i; i < this->_size; i++)
                    newArray[i] = this->_items[i + 1];

                this->_size--;
                break;
            }

            newArray[i] = this->_items[i];
        }

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);

    }

    T get_head_value() override
    {
        if(this->empty())
            throw std::out_of_range("List is Empty");

        return this->_items[0];
    }

    T get_tail_value() override
    {
        if(this->empty())
            throw std::out_of_range("List is Empty");

        return this->_items[this->_size-1];
    }
};