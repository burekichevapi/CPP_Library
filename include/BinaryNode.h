#ifndef AMER_DELIC_BINARYNODE_H
#define AMER_DELIC_BINARYNODE_H

template <class T> class BinaryNode
{
private:
    T _value = 0;
    BinaryNode *_leftChild = nullptr;
    BinaryNode *_rightChild = nullptr;
    BinaryNode *_parentNode = nullptr;

public:
    BinaryNode(T value);
    BinaryNode(BinaryNode<T> *parent,
               BinaryNode<T> *leftChild,
               BinaryNode<T> *rightChild,
               T value);

    T GetValue();
    void SetValue(T value);

    BinaryNode *GetParent();
    void SetParent(BinaryNode *node);

    BinaryNode *GetLeftChild();
    void SetLeftChild(BinaryNode *node);

    BinaryNode *GetRightChild();
    void SetRightChild(BinaryNode *node);
};

#endif //AMER_DELIC_BINARYNODE_H