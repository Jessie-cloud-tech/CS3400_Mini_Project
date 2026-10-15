#include<iostream>
#include<stdexcept>
#include<gtest/gtest.h>
#include "../include/queue.h"

//-----------Test cases for the Queue class------------

// Test that a new queue is empty
TEST(QueueTest, NewQueueIsEmpty) {
    Queue<int> q;

    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

// Test that enqueueing an element makes the queue non-empty
TEST(QueueTest, EnqueueMakesTheQueueNonEmpty) {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);

    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.size(), 2);
}

// Test that dequeueing returns and removes the first inserted element
TEST(QueueTest, DequeueReturnsAndRemovesThefirstInsertedElement) {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    EXPECT_EQ(q.dequeue(),10);
    EXPECT_EQ(q.dequeue(),20);
    EXPECT_EQ(q.dequeue(),30);
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

// Test that peek returns the front element without removing it
TEST(QueueTest, PeekREturnsFrontWithoutRemovitIt) {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    EXPECT_EQ(q.peek(),10);
    EXPECT_EQ(q.peek(),10);

    q.dequeue();

    EXPECT_EQ(q.peek(),20);
    EXPECT_FALSE(q.isEmpty());
    EXPECT_EQ(q.size(), 2);
}

// Test that dequeueing from an empty queue throws an exception
TEST(QueueTest, DequeueFromEmptyQueueThrowsException) {
    Queue<int> q;

    EXPECT_THROW(q.dequeue(),std::underflow_error);
}

// Test that peeking into an empty queue throws an exception
TEST(QueueTest, PeekFromEmptyQueueThrowsException) {
    Queue<int> q;

    EXPECT_THROW(q.peek(),std::underflow_error);
}

// Test that clear removes all elements from the queue
TEST(QueueTest, ClearRemovesAllElements) {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.clear();

    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

// Test that the queue works with different data types (e.g., strings)
TEST(QueueTest, WorksWithStrings) {
    Queue<std::string> q;

    q.enqueue("Hello");
    q.enqueue("World");

    EXPECT_EQ(q.dequeue(), "Hello");
    EXPECT_EQ(q.dequeue(), "World");
}