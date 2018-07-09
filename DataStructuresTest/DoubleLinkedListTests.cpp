#include "pch.h"

#include "../DataStructures/src/DataStructures/DoubleLinkedList/DoubleLinkedList.h"
#include "../DataStructures/src/DataStructures/DoubleLinkedList/DoubleLinkedList.cpp"

TEST(DoubleLinkedListTests, InsertFirstItem_DoubleLinkedList) {
	DoubleLinkedList<int> list;

	list.Add(1);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(DoubleLinkedListTests, InsertMultipleItems_DoubleLinkedList) {
	DoubleLinkedList<int> list;

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

TEST(DoubleLinkedListTests, SearchNumberInList_ContainsNumber_ReturnsTrue) {
	DoubleLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);

	EXPECT_TRUE(list.Contains(3));
}


TEST(DoubleLinkedListTests, SearchNumberInList_DoesNotContainsNumber_ReturnsFalse) {
	DoubleLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);

	EXPECT_FALSE(list.Contains(100));
}

TEST(DoubleLinkedListTests, RemoveElement_ContainsOneElement_ListRemovedItem) {
	DoubleLinkedList<int> list;	
	list.Add(1);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 0);	
}

TEST(DoubleLinkedListTests, RemoveElement_ContainsMultipleElements_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(2);

	EXPECT_FALSE(list.Contains(2));
	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 3);
}

TEST(DoubleLinkedListTests, RemoveHeadElement_ContainsElement_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 2);
	EXPECT_EQ(list[1], 3);
}

TEST(DoubleLinkedListTests, RemoveTailElement_ContainsElement_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Remove(3);

	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
}

TEST(DoubleLinkedListTests, GetFirstItem_ListIsEmpty_ThrowsException) {
	DoubleLinkedList<int> list;
	
	EXPECT_EQ(list.Size(), 0);

	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}

TEST(DoubleLinkedListTests, Clear_ListContainsElements_ListCleared) {
	DoubleLinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);

	list.Clear();

	EXPECT_EQ(list.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}

TEST(DoubleLinkedListTests, Clear_ListEmpty_ListCleared) {
	DoubleLinkedList<int> list;

	list.Clear();

	EXPECT_EQ(list.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = list[0];
		});
}