//
// Created by amerd on 7/16/2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ILinkedList.h"
#include "../src/PriorityQueue.cpp"
#include "../src/LinkedLists/LinkedList.cpp"


class PriorityQueue_Tests : public testing::Test
{
public:
    PriorityQueue<long long int> *PQ = nullptr;

    virtual void SetUp()
    {
        auto *ll = new LinkedList<long long int>(1);
        PQ = new PriorityQueue<long long int>(ll);
    }

    virtual void TearDown()
    {
        PQ = nullptr;
        delete PQ;
    }
};

// TODO: Need to add Enqueue Tests when Enqueue method is fixed.

TEST_F(PriorityQueue_Tests, Enqueue_Assert_Does_NOT_Throw_When_Empty)
{
    PQ->Clear();
    EXPECT_NO_THROW(PQ->GetNextItem());
}

TEST_F(PriorityQueue_Tests, Enqueue_Assert_IsEmpty_When_Clear)
{
    PQ->Enqueue(2);
    PQ->Clear();
    ASSERT_THAT(PQ->Empty(), true);
}