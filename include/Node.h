#ifndef AMER_DELIC_NODE_H
#define AMER_DELIC_NODE_H


template <class T> class Node
{
private:
    T _value = 0;
    Node *_previousNode = nullptr;
    Node *_nextNode = nullptr;

public:
    Node(T value);
    Node(Node<T> *previous, T value, Node<T> *next);

    T GetValue();
    void SetValue(T value);

    Node *GetNextNode();
    void SetNextNode(Node *node);

    Node *GetPreviousNode();
    void SerPreviousNode(Node *node);
};


#endif //AMER_DELIC_NODE_H
