#include "LinkedNode.h"

template <class T>
LinkedNode<T>::LinkedNode(T value)
{
    _value = value;
    _previousNode = nullptr;
    _nextNode = nullptr;
}

template <class T>
LinkedNode<T>::LinkedNode(LinkedNode<T> *previous, T value, LinkedNode<T> *next)
{
    _previousNode = previous;
    _value = value;
    _nextNode = next;
}

template <class T>
T LinkedNode<T>::GetValue(){return _value;}
template <class T>
void LinkedNode<T>::SetValue(T value){_value = value;}

template <class T>
LinkedNode<T>* LinkedNode<T>::GetNextNode() {return _nextNode;}
template <class T>
void LinkedNode<T>::SetNextNode(LinkedNode *node){_nextNode = node;}

template <class T>
LinkedNode<T>* LinkedNode<T>::GetPreviousNode() {return _previousNode;}
template <class T>
void LinkedNode<T>::SetPreviousNode(LinkedNode *node){_previousNode = node;}