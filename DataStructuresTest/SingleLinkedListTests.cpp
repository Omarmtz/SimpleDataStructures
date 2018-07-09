#include "pch.h"

#include "../DataStructures/src/DataStructures/LinkedList/LinkedList.h"
#include "../DataStructures/src/DataStructures/LinkedList/LinkedList.cpp"


TEST(LinkedListTests, InsertFirstItem_LinkedList) {
	LinkedList<int> list;

	list.Add(1);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(LinkedListTests, InsertMultipleItems_LinkedList) {
	LinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
	EXPECT_EQ(list[2], 3);
	EXPECT_EQ(list[3], 4);
	EXPECT_EQ(list.Size(), 4);
}

TEST(LinkedListTests, SearchNumberInList_ContainsNumber_ReturnsTrue) {
	LinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);

	EXPECT_TRUE(list.Contains(3));
}


TEST(LinkedListTests, SearchNumberInList_DoesNotContainsNumber_ReturnsFalse) {
	LinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);

	EXPECT_FALSE(list.Contains(100));
}

TEST(LinkedListTests, RemoveElement_ContainsOneElement_ListRemovedItem) {
	LinkedList<int> list;
	list.Add(1);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 0);
}

TEST(LinkedListTests, RemoveElement_ContainsMultipleElements_ListRemovedItem) {
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(2);

	EXPECT_FALSE(list.Contains(2));
	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 3);
}

TEST(LinkedListTests, RemoveHeadElement_ContainsElement_ListRemovedItem) {
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 2);
	EXPECT_EQ(list[1], 3);
}

TEST(LinkedListTests, RemoveTailElement_ContainsElement_ListRemovedItem) {
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(3);

	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
}

TEST(LinkedListTests, GetFirstItem_ListIsEmpty_ThrowsException) {
	LinkedList<int> list;

	EXPECT_EQ(list.Size(), 0);

	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}

TEST(LinkedListTests, Clear_ListContainsElements_ListCleared) {
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Clear();

	EXPECT_EQ(list.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}

TEST(LinkedListTests, Clear_ListEmpty_ListCleared) {
	LinkedList<int> list;

	list.Clear();

	EXPECT_EQ(list.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}