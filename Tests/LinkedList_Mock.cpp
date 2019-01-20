#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"

template <class T>
class LinkedList_Mock : public ILinkedList<T>
{
public:
    MOCK_METHOD1_T(isNull, bool(LinkedNode<T> node));
    MOCK_METHOD1_T(nextIsNull, bool(LinkedNode<T> node));
    MOCK_METHOD0(IsEmpty, bool());
    MOCK_METHOD0(GetSize, unsigned int());
    MOCK_METHOD1_T(AddFirst, void(T item));
    MOCK_METHOD1_T(AddFirst, void(LinkedNode<T> newNode));
    MOCK_METHOD1_T(AddLast, void(T item));
    MOCK_METHOD1_T(AddLast, void(LinkedNode<T> newNode));
    MOCK_METHOD0(RemoveFirst, void());
    MOCK_METHOD0(RemoveLast, void());
    MOCK_METHOD1_T(Contains, bool(T value));
    MOCK_METHOD1_T(RemoveByValue, void(T value));
    MOCK_METHOD0_T(GetHeadValue, T());
    MOCK_METHOD0_T(GetTailValue, T());


};