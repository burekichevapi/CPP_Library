//
// Created by amer on 12/31/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"
#include "../src/LinkedLists/DoublyLinkedList.cpp"
#include "../src/Nodes/LinkedNode.cpp"

class DoublyLinkedList_Tests : public testing::Test
{
public:
    ILinkedList<long long int> *linkedListNum = nullptr;
    virtual void SetUp()
    {
        linkedListNum = new DoublyLinkedList<long long int>(1, 2);
    }

    virtual void TearDown()
    {
        linkedListNum = nullptr;
        delete linkedListNum;
    }
};


TEST_F(DoublyLinkedList_Tests, Assert_Is_Initialized_With_Two_Values)
{
    ASSERT_THAT(linkedListNum->GetSize(), 2);
}

TEST_F(DoublyLinkedList_Tests, Assert_Throws_When_Empty_Calling_Print_All)
{
    linkedListNum->RemoveFirst();
    linkedListNum->RemoveFirst();
    ASSERT_THROW(linkedListNum->PrintAll(), std::out_of_range);

}

TEST_F(DoublyLinkedList_Tests, Assert_Is_Empty_When_Clear_All)
{
    linkedListNum->AddLast(2.3);
    linkedListNum->AddFirst(88);
    linkedListNum->Clear();

    ASSERT_THAT(linkedListNum->GetSize(), 0);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Add_First)
{
    linkedListNum->AddFirst(3);

    ASSERT_THAT(linkedListNum->GetHeadValue(), 3);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Add_Last)
{
    linkedListNum->AddLast(3);

    ASSERT_THAT(linkedListNum->GetTailValue(), 3);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Remove_First)
{
    linkedListNum->AddFirst(3);
    linkedListNum->RemoveFirst();

    ASSERT_THAT(linkedListNum->GetHeadValue(), 1);
}

TEST_F(DoublyLinkedList_Tests, Assert_Throws_When_Empty_Calling_Remove_First)
{
    linkedListNum->RemoveFirst();
    linkedListNum->RemoveFirst();
    ASSERT_THROW(linkedListNum->RemoveFirst(), std::out_of_range);

}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Remove_Last)
{
    linkedListNum->AddLast(3);
    linkedListNum->RemoveLast();

    ASSERT_THAT(linkedListNum->GetTailValue(), 2);
}

TEST_F(DoublyLinkedList_Tests, Assert_Throws_When_Empty_Calling_Remove_Last)
{
    linkedListNum->RemoveLast();
    linkedListNum->RemoveLast();
    ASSERT_THROW(linkedListNum->RemoveLast(), std::out_of_range);
}

TEST_F(DoublyLinkedList_Tests, Assert_That_Contains_Number_1)
{
    ASSERT_THAT(linkedListNum->Contains(1), true);
}

TEST_F(DoublyLinkedList_Tests, Assert_That_Does_Not_Contain_Number_3)
{
    ASSERT_THAT(linkedListNum->Contains(3), false);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Remove_By_Value_Number_1)
{
    linkedListNum->AddFirst(2);
    linkedListNum->AddLast(4);
    linkedListNum->RemoveByValue(1);

    ASSERT_THAT(linkedListNum->Contains(1), false);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Get_Head_Value_Number_1)
{
    ASSERT_THAT(linkedListNum->GetHeadValue(), 1);
}

TEST_F(DoublyLinkedList_Tests, Assert_Can_Get_Tail_Value_Number_3)
{
    linkedListNum->AddLast(3);
    ASSERT_THAT(linkedListNum->GetTailValue(), 3);
}

TEST_F(DoublyLinkedList_Tests, Assert_Throws_When_Empty_Calling_Get_Tail_Value)
{
    linkedListNum->RemoveByValue(1);
    linkedListNum->RemoveLast();

    ASSERT_THROW(linkedListNum->GetTailValue(), std::out_of_range);
}

TEST_F(DoublyLinkedList_Tests, Assert_Throws_When_Empty_Calling_Get_Head_Value)
{
    linkedListNum->RemoveLast();
    linkedListNum->RemoveFirst();
    ASSERT_THROW(linkedListNum->GetHeadValue(), std::out_of_range);
}