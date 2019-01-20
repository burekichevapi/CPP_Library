#include "BinaryNode.h"

template <class T>
BinaryNode<T>::BinaryNode(T value)
{
    _value = value;
    _leftChild = nullptr;
    _rightChild = nullptr;
    _parentNode = nullptr;
}

template <class T>
BinaryNode<T>::BinaryNode(BinaryNode<T> *parent,
                          BinaryNode<T> *leftChild,
                          BinaryNode<T> *rightChild,
                          T value)
{
    _parentNode = parent;
    _leftChild = leftChild;
    _value = value;
    _rightChild = rightChild;
}

template <class T>
BinaryNode<T>* BinaryNode<T>::GetParent()
{return _parentNode;}

template <class T>
void BinaryNode<T>::SetParent(BinaryNode<T> *node)
{_parentNode = node;}

template <class T>
T BinaryNode<T>::GetValue()
{return _value;}

template <class T>
void BinaryNode<T>::SetValue(T value)
{_value = value;}

template <class T>
BinaryNode<T>* BinaryNode<T>::GetLeftChild()
{return _leftChild;}

template <class T>
void BinaryNode<T>::SetLeftChild(BinaryNode *node)
{_leftChild = node;}

template <class T>
BinaryNode<T>* BinaryNode<T>::GetRightChild()
{return _rightChild;}

template <class T>
void BinaryNode<T>::SetRightChild(BinaryNode *node)
{_rightChild = node;}