//
// Created by amer on 12/31/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IStack.h"
#include "../src/ArrayStack.cpp"

class ArrayStack_Tests : public testing::Test
{
protected:
    void push2and3(IStack<long long int> *stackNum)
    {
        stackNum->Push(2);
        stackNum->Push(3);
    }

public:
    IStack<long long int> *stackNum = nullptr;
    virtual void SetUp()
    {
        stackNum = new ArrayStack<long long int>();
        stackNum->Push(1);
    }

    virtual void TearDown()
    {
        stackNum = nullptr;
        delete stackNum;
    }
};

TEST_F(ArrayStack_Tests, Assert_Is_Not_Empty)
{
    ASSERT_THAT(stackNum->IsEmpty(), false);
}

TEST_F(ArrayStack_Tests, Assert_That_Stack_Has_One_Value)
{
    ASSERT_THAT(stackNum->GetDepth(), 1);
}

TEST_F(ArrayStack_Tests, Assert_Is_Empty_After_Pop)
{
    stackNum->Pop();
    ASSERT_THAT(stackNum->IsEmpty(), true);
}

TEST_F(ArrayStack_Tests, Assert_Can_Push_Value_Top_Of_Stack)
{
    push2and3(stackNum);

    ASSERT_THAT(stackNum->GetDepth(), 3);
}

TEST_F(ArrayStack_Tests, Assert_Can_Peek_Value_Top_Of_Stack)
{
    push2and3(stackNum);

    ASSERT_THAT(stackNum->Peek(), 3);
}

TEST_F(ArrayStack_Tests, Assert_Can_Pop_Top_Value)
{
    push2and3(stackNum);
    stackNum->Pop();
    ASSERT_THAT(stackNum->Peek(), 2);
    ASSERT_THAT(stackNum->GetDepth(), 2);
}

TEST_F(ArrayStack_Tests, Assert_Is_Empty_After_Clear)
{
    push2and3(stackNum);
    stackNum->Clear();
    ASSERT_THAT(stackNum->IsEmpty(), true);
}