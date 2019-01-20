//
// Created by amer on 1/18/19.
//

#ifndef AMER_DELIC_IBINARYTREE_H
#define AMER_DELIC_IBINARYTREE_H

#include "LinkedNode.h"

template <class T>
class IBinaryTree
{
protected:
    LinkedNode<T> *_rootNode = nullptr;

public:
    virtual void Add(T value) = 0;

    virtual LinkedNode<T>* Find(LinkedNode<T> currentNode, T value) = 0;

};

#endif //AMER_DELIC_IBINARYTREE_H
