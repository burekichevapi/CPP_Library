#include "Node.h"

template <class T>
Node<T>::Node(T value)
{
    _value = value;
    _previousNode = nullptr;
    _nextNode = nullptr;
}

template <class T>
Node<T>::Node(Node<T> *previous, T value, Node<T> *next)
{
    _previousNode = previous;
    _value = value;
    _nextNode = next;
}

template <class T>
T Node<T>::get_value(){return _value;}
template <class T>
void Node<T>::set_value(T value){_value = value;}

template <class T>
Node<T>* Node<T>::get_next_node() {return _nextNode;}
template <class T>
void Node<T>::set_next_node(Node *node){_nextNode = node;}

template <class T>
Node<T>* Node<T>::get_previous_node() {return _previousNode;}
template <class T>
void Node<T>::set_previous_node(Node *node){_previousNode = node;}