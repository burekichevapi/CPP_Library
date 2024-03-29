#ifndef AMER_DELIC_ILINKEDLIST_H
#define AMER_DELIC_ILINKEDLIST_H

#include "LinkedNode.h"


template <class T>
class ILinkedList
{
protected:
    LinkedNode<T> *_head = nullptr,
            *_tail = nullptr,
            *_previous = nullptr;

    T *_items = nullptr;

    unsigned int _size = 0;

    bool isNull(LinkedNode<T> *temp)
    { return temp == nullptr; }

    bool nextIsNull(LinkedNode<T> *temp)
    { return temp->GetNextNode() == nullptr; }

public:
    bool IsEmpty()
    { return _size == 0; }

    LinkedNode<T> *GetHeadPointer()
    {return this->_head; }

    void IncreaseSize()
    { _size++; }

    virtual unsigned int GetSize() = 0;

    virtual void PrintAll() = 0;

    virtual void Clear() = 0;

    virtual void AddFirst(LinkedNode<T> *newNode) = 0;

    virtual void AddFirst(T item) = 0;

    virtual void AddLast(LinkedNode<T> *newNode) = 0;

    virtual void AddLast(T item) = 0;

    virtual void RemoveFirst() = 0;

    virtual void RemoveLast() = 0;

    virtual bool Contains(T value) = 0;

    virtual void RemoveByValue(T value) = 0;

    virtual T GetHeadValue() = 0;

    virtual T GetTailValue() = 0;

    virtual void InsertAt(unsigned int index, T item) = 0;
};

#endif //AMER_DELIC_ILINKEDLIST_H
