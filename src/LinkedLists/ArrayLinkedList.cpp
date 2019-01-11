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

    unsigned int GetSize() override
    { return this->_size; }

    void PrintAll() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty.");

        for(int i = 0; i < this->_size; i++)
            std::cout << this->_items[i] << "\n";
    }

    void Clear() override
    {
        this->_size = 0;
        this->_items = nullptr;
        delete (this->_items);

        this->_items = new T[0];
    }

    void AddFirst(T item) override
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

    void AddFirst(Node<T> *newNode) override
    { AddFirst(newNode->GetValue()); }

    void AddLast(T item) override
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

    void AddLast(Node<T> *newNode) override
    { AddLast(newNode->GetValue()); }

    void RemoveFirst() override
    {
        if (this->IsEmpty())
            throw std::out_of_range("List is Empty");

        this->_size--;

        T *newArray = new T[this->_size];

        for(int i = 0; i < this->_size; i++)
            newArray[i] = this->_items[i+1];

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    void RemoveLast() override
    {
        if (this->IsEmpty())
            return;

        this->_size--;

        T *newArray = new T[this->_size];

        for(int i = 0; i < this->_size; i++)
            newArray[i] = this->_items[i];

        this->_items = newArray;

        newArray = nullptr;
        delete (newArray);
    }

    bool Contains(T value) override
    {
        if(this->IsEmpty())
            return false;

        for(int i = 0; i < this->_size; i++)
            if(this->_items[i] == value)
                return true;

        return false;
    }

    void RemoveByValue(T value) override
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

    T GetHeadValue() override
    {
        if(this->IsEmpty())
            throw std::out_of_range("List is Empty");

        return this->_items[0];
    }

    T GetTailValue() override
    {
        if(this->IsEmpty())
            throw std::out_of_range("List is Empty");

        return this->_items[this->_size-1];
    }

    void InsertAt(unsigned int index, T item) override
    {
        if(index > this->_size || index < 0)
            throw std::out_of_range("Index is out of range.");

        T *newArray = new T[++this->_size];
        int i = 0;

        for(i; i < index; i++)
            newArray[i] = this->_items[i];

        newArray[i++] = item;

        for(i; i < this->_size; i++)
            newArray[i] = this->_items[i-1];

        this->_items = newArray;
    }
};