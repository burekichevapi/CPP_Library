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

    T get_value();
    void set_value(T value);

    Node *get_next_node();
    void set_next_node(Node *node);

    Node *get_previous_node();
    void set_previous_node(Node *node);
};


#endif //AMER_DELIC_NODE_H
