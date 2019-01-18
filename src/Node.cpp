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
T Node<T>::GetValue(){return _value;}
template <class T>
void Node<T>::SetValue(T value){_value = value;}

template <class T>
Node<T>* Node<T>::GetNextNode() {return _nextNode;}
template <class T>
void Node<T>::SetNextNode(Node *node){_nextNode = node;}

template <class T>
Node<T>* Node<T>::GetPreviousNode() {return _previousNode;}
template <class T>
void Node<T>::SerPreviousNode(Node *node){_previousNode = node;}

template <class T>
Node<T>* Node<T>::GetLeftNode() {return _previousNode;}
template <class T>
void Node<T>::SetLeftNode(Node *node){_previousNode = node;}

template <class T>
Node<T>* Node<T>::GetRightNode() {return _nextNode;}
template <class T>
void Node<T>::SetRightNode(Node *node){_nextNode = node;}