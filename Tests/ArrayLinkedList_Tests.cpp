//
// Created by amer on 1/3/19.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"
#include "../src/ArrayLinkedList.cpp"

class ArrayLinkedList_Tests : public testing::Test
{
public:
    ILinkedList<long long int> *arrayLinkedList = nullptr;
    virtual void SetUp()
    {
        arrayLinkedList = new ArrayLinkedList<long long int>();
        arrayLinkedList->add_first(new Node<long long int>(1));
    }

    virtual void TearDown()
    {
        arrayLinkedList = nullptr;
        delete arrayLinkedList;
    }
};

TEST_F(ArrayLinkedList_Tests, ClearAll_AssertLinkedListSizeIs0)
{
    arrayLinkedList->clear_all();

    ASSERT_THAT(arrayLinkedList->get_size(), 0);
}

TEST_F(ArrayLinkedList_Tests, GetSize_AssertLinkedListHas1Value)
{
    ASSERT_THAT(arrayLinkedList->get_size(), 1);
}

TEST_F(ArrayLinkedList_Tests, AddFirst_AssertHeadIs2)
{
    arrayLinkedList->add_first(2);

    ASSERT_THAT(arrayLinkedList->get_head_value(), 2);
}

TEST_F(ArrayLinkedList_Tests, AddLast_AssertTailIs3)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->add_last(3);

    ASSERT_THAT(arrayLinkedList->get_tail_value(), 3);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_AssertHeadIs1)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->remove_first();

    ASSERT_THAT(arrayLinkedList->get_head_value(), 1);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_RemoveFromEmptyList_AssertIsEmpty)
{
    arrayLinkedList->remove_last();
    arrayLinkedList->remove_first();

    ASSERT_THAT(arrayLinkedList->get_size(), 0);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_AssertTailIs2)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->remove_last();

    ASSERT_THAT(arrayLinkedList->get_tail_value(), 2);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_RemoveFromEmptyList_AssertIsEmpty)
{
    arrayLinkedList->remove_first();
    arrayLinkedList->remove_last();

    ASSERT_THAT(arrayLinkedList->get_size(), 0);
}

TEST_F(ArrayLinkedList_Tests, Contains_AssertListContains1)
{
    ASSERT_THAT(arrayLinkedList->contains(1), true);
}

TEST_F(ArrayLinkedList_Tests, Contains_AssertListDoesNotContain2)
{
    ASSERT_THAT(arrayLinkedList->contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, Contains_WhenEmpty_AssertListDoesNotContain1)
{
    arrayLinkedList->clear_all();

    ASSERT_THAT(arrayLinkedList->contains(1), false);

}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_FirstValue_AssertListDoesNotContain1)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->add_first(3);
    arrayLinkedList->remove_by_value(1);

    ASSERT_THAT(arrayLinkedList->contains(1), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_MiddelValue_AssertListDoesNotContain2)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->add_first(3);
    arrayLinkedList->remove_by_value(2);

    ASSERT_THAT(arrayLinkedList->contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_LastValue_AssertListDoesNotContain3)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->add_first(3);
    arrayLinkedList->remove_by_value(3);

    ASSERT_THAT(arrayLinkedList->contains(3), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_WhenListDoesNotContainValue_AssertListIsSameSize)
{
    arrayLinkedList->add_first(2);
    arrayLinkedList->add_first(3);
    arrayLinkedList->remove_by_value(4);

    ASSERT_THAT(arrayLinkedList->get_size(), 3);
}

TEST_F(ArrayLinkedList_Tests, GetHeadValue_WhenListEmpty_AssertThrowsOutOfRange)
{
    arrayLinkedList->clear_all();

    ASSERT_THROW(arrayLinkedList->get_head_value(), std::out_of_range);
}

TEST_F(ArrayLinkedList_Tests, GetTailValue_WhenListEmpty_AssertThrowsOutOfRange)
{
    arrayLinkedList->clear_all();

    ASSERT_THROW(arrayLinkedList->get_tail_value(), std::out_of_range);
}