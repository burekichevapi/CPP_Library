//
// Created by amer on 12/31/18.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IStack.h"
#include "../src/Stack.cpp"
#include "../src/LinkedList.cpp"

class Stack_Tests : public testing::Test
{
protected:
    void push2and3(IStack<long long int> *stackNum )
    {
        stackNum->push(2);
        stackNum->push(3);
    }

public:
    IStack<long long int> *stackNum = nullptr;
    virtual void SetUp()
    {
        auto *ll = new LinkedList<long long int>(1);
        stackNum = new Stack<long long int>(ll);
    }

    virtual void TearDown()
    {
        stackNum = nullptr;
        delete stackNum;
    }
};

TEST_F(Stack_Tests , Assert_Is_Not_Empty)
{
    ASSERT_THAT(stackNum->is_empty(), false);
}

TEST_F(Stack_Tests , Assert_That_Stack_Has_One_Value)
{
    ASSERT_THAT(stackNum->get_depth(), 1);
}

TEST_F(Stack_Tests , Assert_Is_Empty_After_Pop)
{
    stackNum->pop();
    ASSERT_THAT(stackNum->is_empty(), true);
}

TEST_F(Stack_Tests , Assert_Can_Push_Value_Top_Of_Stack)
{
    push2and3(stackNum);

    ASSERT_THAT(stackNum->get_depth(), 3);
}

TEST_F(Stack_Tests , Assert_Can_Pekk_Value_Top_Of_Stack)
{
    push2and3(stackNum);

    ASSERT_THAT(stackNum->peek(), 3);
}

TEST_F(Stack_Tests , Assert_Can_Pop_Top_Value)
{
    push2and3(stackNum);
    stackNum->pop();
    ASSERT_THAT(stackNum->peek(), 2);
    ASSERT_THAT(stackNum->get_depth(), 2);
}

TEST_F(Stack_Tests , Assert_Is_Empty_After_Clear)
{
    push2and3(stackNum);
    stackNum->clear();
    ASSERT_THAT(stackNum->is_empty(), true);
}