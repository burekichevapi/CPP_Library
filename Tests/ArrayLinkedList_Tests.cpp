//
// Created by amer on 1/3/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"
#include "../src/LinkedLists/ArrayLinkedList.cpp"

class ArrayLinkedList_Tests : public testing::Test
{
public:
    ILinkedList<long long int> *arrayLinkedList = nullptr;
    virtual void SetUp()
    {
        arrayLinkedList = new ArrayLinkedList<long long int>();
        arrayLinkedList->AddFirst(new Node<long long int>(1));
    }

    virtual void TearDown()
    {
        arrayLinkedList = nullptr;
        delete arrayLinkedList;
    }
};

TEST_F(ArrayLinkedList_Tests, ClearAll_AssertLinkedListSizeIs0)
{
    arrayLinkedList->Clear();

    ASSERT_THAT(arrayLinkedList->GetSize(), 0);
}

TEST_F(ArrayLinkedList_Tests, GetSize_AssertLinkedListHas1Value)
{
    ASSERT_THAT(arrayLinkedList->GetSize(), 1);
}

TEST_F(ArrayLinkedList_Tests, AddFirst_AssertHeadIs2)
{
    arrayLinkedList->AddFirst(2);

    ASSERT_THAT(arrayLinkedList->GetHeadValue(), 2);
}

TEST_F(ArrayLinkedList_Tests, AddLast_AssertTailIs3)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddLast(3);

    ASSERT_THAT(arrayLinkedList->GetTailValue(), 3);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_AssertHeadIs1)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->RemoveFirst();

    ASSERT_THAT(arrayLinkedList->GetHeadValue(), 1);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_RemoveFromEmptyList_AssertIsEmpty)
{
    arrayLinkedList->RemoveLast();
    arrayLinkedList->RemoveFirst();

    ASSERT_THAT(arrayLinkedList->GetSize(), 0);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_AssertTailIs2)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->RemoveLast();

    ASSERT_THAT(arrayLinkedList->GetTailValue(), 2);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_RemoveFromEmptyList_AssertIsEmpty)
{
    arrayLinkedList->RemoveFirst();
    arrayLinkedList->RemoveLast();

    ASSERT_THAT(arrayLinkedList->GetSize(), 0);
}

TEST_F(ArrayLinkedList_Tests, Contains_AssertListContains1)
{
    ASSERT_THAT(arrayLinkedList->Contains(1), true);
}

TEST_F(ArrayLinkedList_Tests, Contains_AssertListDoesNotContain2)
{
    ASSERT_THAT(arrayLinkedList->Contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, Contains_WhenEmpty_AssertListDoesNotContain1)
{
    arrayLinkedList->Clear();

    ASSERT_THAT(arrayLinkedList->Contains(1), false);

}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_FirstValue_AssertListDoesNotContain1)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(1);

    ASSERT_THAT(arrayLinkedList->Contains(1), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_MiddelValue_AssertListDoesNotContain2)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(2);

    ASSERT_THAT(arrayLinkedList->Contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_LastValue_AssertListDoesNotContain3)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(3);

    ASSERT_THAT(arrayLinkedList->Contains(3), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_WhenListDoesNotContainValue_AssertListIsSameSize)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(4);

    ASSERT_THAT(arrayLinkedList->GetSize(), 3);
}

TEST_F(ArrayLinkedList_Tests, GetHeadValue_WhenListEmpty_AssertThrowsOutOfRange)
{
    arrayLinkedList->Clear();

    ASSERT_THROW(arrayLinkedList->GetHeadValue(), std::out_of_range);
}

TEST_F(ArrayLinkedList_Tests, GetTailValue_WhenListEmpty_AssertThrowsOutOfRange)
{
    arrayLinkedList->Clear();

    ASSERT_THROW(arrayLinkedList->GetTailValue(), std::out_of_range);
}