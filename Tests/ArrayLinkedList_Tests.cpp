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
        arrayLinkedList->add_first(1);
    }

    virtual void TearDown()
    {
        arrayLinkedList = nullptr;
        delete arrayLinkedList;
    }
};

TEST_F(ArrayLinkedList_Tests, Assert_Head_Is_1)
{
    ASSERT_THAT(arrayLinkedList->get_head_value(), 1);
}