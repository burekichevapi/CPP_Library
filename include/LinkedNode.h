#ifndef AMER_DELIC_NODE_H
#define AMER_DELIC_NODE_H

template <class T> class LinkedNode
{
private:
    T _value = 0;
    LinkedNode *_previousNode = nullptr;
    LinkedNode *_nextNode = nullptr;

public:
    LinkedNode(T value);
    LinkedNode(LinkedNode<T> *previous, T value, LinkedNode<T> *next);

    T GetValue();
    void SetValue(T value);

    LinkedNode *GetNextNode();
    void SetNextNode(LinkedNode *node);

    LinkedNode *GetPreviousNode();
    void SetPreviousNode(LinkedNode *node);
};

#endif //AMER_DELIC_NODE_H
