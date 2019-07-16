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
        arrayLinkedList->AddFirst(new LinkedNode<long long int>(1));
    }

    virtual void TearDown()
    {
        arrayLinkedList = nullptr;
        delete arrayLinkedList;
    }
};

TEST_F(ArrayLinkedList_Tests, ClearAll_Assert_Linked_List_Size_Is_0)
{
    arrayLinkedList->Clear();

    ASSERT_THAT(arrayLinkedList->GetSize(), 0);
}

TEST_F(ArrayLinkedList_Tests, GetSize_Assert_Linked_List_Has_One_Value)
{
    ASSERT_THAT(arrayLinkedList->GetSize(), 1);
}

TEST_F(ArrayLinkedList_Tests, AddFirst_Assert_Head_Is_2)
{
    arrayLinkedList->AddFirst(2);

    ASSERT_THAT(arrayLinkedList->GetHeadValue(), 2);
}

TEST_F(ArrayLinkedList_Tests, AddLast_Assert_Tail_Is_3)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddLast(3);

    ASSERT_THAT(arrayLinkedList->GetTailValue(), 3);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_Assert_Head_Is_1)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->RemoveFirst();

    ASSERT_THAT(arrayLinkedList->GetHeadValue(), 1);
}

TEST_F(ArrayLinkedList_Tests, RemoveFirst_Remove_From_Empty_List_Assert_Throws_Out_Of_Range)
{
    arrayLinkedList->RemoveLast();
    ASSERT_THROW(arrayLinkedList->RemoveFirst(), std::out_of_range);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_Assert_Tail_Is_2)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->RemoveLast();

    ASSERT_THAT(arrayLinkedList->GetTailValue(), 2);
}

TEST_F(ArrayLinkedList_Tests, RemoveLast_Remove_From_Empty_List_Assert_Is_Empty)
{
    arrayLinkedList->RemoveFirst();
    arrayLinkedList->RemoveLast();

    ASSERT_THAT(arrayLinkedList->GetSize(), 0);
}

TEST_F(ArrayLinkedList_Tests, Contains_Assert_List_Contains_One)
{
    ASSERT_THAT(arrayLinkedList->Contains(1), true);
}

TEST_F(ArrayLinkedList_Tests, Contains_Assert_List_Does_Not_Contain_2)
{
    ASSERT_THAT(arrayLinkedList->Contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, Contains_When_Empty_Assert_List_Does_Not_Contain_1)
{
    arrayLinkedList->Clear();

    ASSERT_THAT(arrayLinkedList->Contains(1), false);

}

TEST_F(ArrayLinkedList_Tests, Remove_By_Value_First_Value_Assert_List_Does_Not_Contain_1)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(1);

    ASSERT_THAT(arrayLinkedList->Contains(1), false);
}

TEST_F(ArrayLinkedList_Tests, Remove_By_Value_Middel_Value_Assert_List_Does_Not_Contain_2)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(2);

    ASSERT_THAT(arrayLinkedList->Contains(2), false);
}

TEST_F(ArrayLinkedList_Tests, RemoveByValue_Last_Value_Assert_List_Does_Not_Contain_3)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(3);

    ASSERT_THAT(arrayLinkedList->Contains(3), false);
}

TEST_F(ArrayLinkedList_Tests, Remove_By_Value_When_List_Does_Not_Contain_Value_Assert_List_Is_Same_Size)
{
    arrayLinkedList->AddFirst(2);
    arrayLinkedList->AddFirst(3);
    arrayLinkedList->RemoveByValue(4);

    ASSERT_THAT(arrayLinkedList->GetSize(), 3);
}

TEST_F(ArrayLinkedList_Tests, Get_Head_Value_When_List_Empty_Assert_Throws_OutOfRange)
{
    arrayLinkedList->Clear();

    ASSERT_THROW(arrayLinkedList->GetHeadValue(), std::out_of_range);
}

TEST_F(ArrayLinkedList_Tests, GetTailValue_When_List_Empty_Assert_Throws_OutOfRange)
{
    arrayLinkedList->Clear();

    ASSERT_THROW(arrayLinkedList->GetTailValue(), std::out_of_range);
}