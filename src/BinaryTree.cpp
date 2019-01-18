//
// Created by amer on 1/18/19.
//

#include "IBinaryTree.h"

template <class T>
class BinaryTree : IBinaryTree<T>
{
public:
    BinaryTree(T rootValue)
    {
        this->_rootNode = new Node<T>(rootValue);
    }

    void Add(T value) override
    {


    }

    Node<T>* Find(Node<T>* node, T value) override
    {
        auto* current = node;

        if(current->GetValue() == nullptr)
            return nullptr;

        if(current->GetValue() == value)
            return current;

        if(current->GetValue() > value)
            return Find(current->GetLeftNode(), value);

        return Find(current->GetRightNode(), value);

    }
};