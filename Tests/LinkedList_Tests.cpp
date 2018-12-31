//
// Created by amer on 12/31/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"
#include "../src/LinkedList.cpp"
#include "../src/Node.cpp"

class LinkedList_Tests : public testing::Test
{
public:
    ILinkedList<int> *int_linkedList = nullptr;
    virtual void SetUp()
    {
        int_linkedList = new LinkedList<int>(1);
    }

    virtual void TearDown()
    {
        int_linkedList = nullptr;
        delete int_linkedList;
    }
};


TEST_F(LinkedList_Tests, Assert_Is_Initialized_With_One_Value)
{
    ASSERT_FALSE(int_linkedList->get_number_of_nodes() == 0);
}

TEST_F(LinkedList_Tests, Assert_Can_Add_First)
{
    int_linkedList->add_first(2);

    ASSERT_THAT(int_linkedList->get_head_value(), 2);
}

TEST_F(LinkedList_Tests, Assert_Can_Remove_First)
{
    int_linkedList->remove_first();

    ASSERT_TRUE(int_linkedList->get_number_of_nodes() == 0);
}

TEST_F(LinkedList_Tests, Assert_Can_Add_Last)
{
    int_linkedList->add_last(2);

    ASSERT_THAT(int_linkedList->get_tail_value(), 2);
}