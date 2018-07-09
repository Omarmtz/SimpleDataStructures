#include "pch.h"

#include "../DataStructures/src/DataStructures/Queue/Queue.h"
#include "../DataStructures/src/DataStructures/Queue/Queue.cpp"

TEST(QueueTests, EnqueueItem_QueueEmpty_ItemEnqueued) {
	Queue<int> queue;

	queue.Enqueue(1);

	EXPECT_EQ(queue.Front(), 1);
}

TEST(QueueTests, EnqueueItem_QueueMultipleValues_ItemEnqueued) {
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);

	EXPECT_EQ(queue.Front(), 1);
}

TEST(QueueTests, DequeueItem_QueueMultipleValues_ItemDequeued) {
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);
	queue.Enqueue(4);

	queue.Dequeue();

	EXPECT_EQ(queue.Front(), 2);
}

TEST(QueueTests, DequeueItem_QueueSingleValue_ItemDequeued) {
	Queue<int> queue;

	queue.Enqueue(1);
	queue.Dequeue();

	EXPECT_EQ(queue.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = queue.Front();
		});
}