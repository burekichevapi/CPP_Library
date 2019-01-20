//
// Created by amer on 1/18/19.
//

#include <BinaryNode.h>
#include "IBinaryTree.h"

template <class T>
class BinaryTree : IBinaryTree<T>
{
private:
    BinaryNode<T>* Find(BinaryNode<T>* currentNode, T value)
    {
        if(currentNode == nullptr)
            return nullptr;

        if(currentNode->GetValue() == value)
            return currentNode;

        if(currentNode->GetValue() > value)
            return Find(currentNode->GetLeftChild(), value);

        return Find(currentNode->GetRightChild(), value);
    }
public:
    BinaryTree(BinaryNode<T>* rootNode)
    {
        this->_rootNode = rootNode;
    }

    void Insert(BinaryNode<T>* node, T value) override
    {
        auto* current = node;

        if(current->GetValue() > value)
        {
            if(current->GetLeftChild() == nullptr)
            {
                current->SetLeftChild(new BinaryNode<T>(value));
                current->GetLeftChild()->SetParent(current);

            }
            else
                Insert(current->GetLeftChild(), value);
        }
        else
        {
            if(current->GetRightChild() == nullptr)
            {
                current->SetRightChild(new BinaryNode<T>(value));
                current->GetRightChild()->SetParent(current);
            }
            else
                Insert(current->GetRightChild(), value);
        }
    }

    BinaryNode<T>* Find(T value) override
    {
        return Find(this->_rootNode, value);
    }
};