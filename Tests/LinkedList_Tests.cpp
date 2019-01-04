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
    ILinkedList<long long int> *linkedListNum = nullptr;
    virtual void SetUp()
    {
        linkedListNum = new LinkedList<long long int>(1);
    }

    virtual void TearDown()
    {
        linkedListNum = nullptr;
        delete linkedListNum;
    }
};

TEST_F(LinkedList_Tests, Assert_Is_Initialized_With_One_Value)
{
    ASSERT_THAT(linkedListNum->get_size(), 1);
}

TEST_F(LinkedList_Tests, Assert_Throws_When_Empty_Calling_Print_All)
{
    linkedListNum->remove_first();
    ASSERT_THROW(linkedListNum->print_all(), std::out_of_range);

}

TEST_F(LinkedList_Tests, Assert_Is_Empty_When_Clear_All)
{
    linkedListNum->add_last(2.3);
    linkedListNum->add_first(88);
    linkedListNum->clear_all();

    ASSERT_THAT(linkedListNum->get_size(), 0);
}

TEST_F(LinkedList_Tests, Assert_Can_Add_First)
{
    linkedListNum->add_first(2);

    ASSERT_THAT(linkedListNum->get_head_value(), 2);
}

TEST_F(LinkedList_Tests, Assert_Can_Add_Last)
{
    linkedListNum->add_last(2);

    ASSERT_THAT(linkedListNum->get_tail_value(), 2);
}

TEST_F(LinkedList_Tests, Assert_Can_Remove_First)
{
    linkedListNum->add_first(2);
    linkedListNum->remove_first();

    ASSERT_THAT(linkedListNum->get_head_value(), 1);
}

TEST_F(LinkedList_Tests, Assert_Throws_When_Empty_Calling_Remove_First)
{
    linkedListNum->remove_first();
    ASSERT_THROW(linkedListNum->remove_first(), std::out_of_range);

}

TEST_F(LinkedList_Tests, Assert_Can_Remove_Last)
{
    linkedListNum->add_last(2);
    linkedListNum->remove_last();

    ASSERT_THAT(linkedListNum->get_tail_value(), 1);
}

TEST_F(LinkedList_Tests, Assert_Throws_When_Empty_Calling_Remove_Last)
{
    linkedListNum->remove_last();
    ASSERT_THROW(linkedListNum->remove_last(), std::out_of_range);
}

TEST_F(LinkedList_Tests, Assert_That_Contains_Number_1)
{
    ASSERT_THAT(linkedListNum->contains(1), true);
}

TEST_F(LinkedList_Tests, Assert_That_Does_Not_Contain_Number_2)
{
    ASSERT_THAT(linkedListNum->contains(2), false);
}

TEST_F(LinkedList_Tests, Assert_Can_Remove_By_Value_Number_1)
{
    linkedListNum->add_first(2);
    linkedListNum->add_last(4);
    linkedListNum->remove_by_value(1);

    ASSERT_THAT(linkedListNum->contains(1), false);
}

TEST_F(LinkedList_Tests, Assert_Can_Get_Head_Value_Number_1)
{
    ASSERT_THAT(linkedListNum->get_head_value(), 1);
}

TEST_F(LinkedList_Tests, Assert_Can_Get_Tail_Value_Number_3)
{
    linkedListNum->add_last(3);
    ASSERT_THAT(linkedListNum->get_tail_value(), 3);
}

TEST_F(LinkedList_Tests, Assert_Throws_When_Empty_Calling_Get_Tail_Value)
{
    linkedListNum->remove_by_value(1);
    ASSERT_THROW(linkedListNum->get_tail_value(), std::out_of_range);
}

TEST_F(LinkedList_Tests, Assert_Throws_When_Empty_Calling_Get_Head_Value)
{
    linkedListNum->remove_first();
    ASSERT_THROW(linkedListNum->get_head_value(), std::out_of_range);
}