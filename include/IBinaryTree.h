//
// Created by amer on 1/18/19.
//

#ifndef AMER_DELIC_IBINARYTREE_H
#define AMER_DELIC_IBINARYTREE_H

#include "Node.h"

template <class T>
class IBinaryTree
{
protected:
    Node<T> *_rootNode = nullptr;

public:
    virtual void Add(T value) = 0;

    virtual Node<T>* Find(Node<T> currentNode, T value) = 0;

};

#endif //AMER_DELIC_IBINARYTREE_H
