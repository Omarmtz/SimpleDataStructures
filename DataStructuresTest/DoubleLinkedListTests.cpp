#include "pch.h"

#include "../DataStructures/src/DataStructures/DoubleLinkedList/DoubleLinkedList.h"
#include "../DataStructures/src/DataStructures/DoubleLinkedList/DoubleLinkedList.cpp"

TEST(DoubleLinkedListTests, PushBackFirstItem_EmptyList_ElementPushed) {
	DoubleLinkedList<int> list;

	list.PushBack(1);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(DoubleLinkedListTests, PushBackFirstItemLValue_EmptyList_ElementPushed) {
	DoubleLinkedList<int> list;
	int x = 1;
	list.PushBack(x);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(DoubleLinkedListTests, PushBackMultipleItems_EmptyList_ElementsPushed) {
	DoubleLinkedList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
	EXPECT_EQ(list[2], 3);
	EXPECT_EQ(list[3], 4);
	EXPECT_EQ(list.Size(), 4);
}

TEST(DoubleLinkedListTests, PushFrontFirstItem_EmptyList_ElementPushed) {
	DoubleLinkedList<int> list;

	list.PushFront(1);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(DoubleLinkedListTests, PushFrontFirstItemLValue_EmptyList_ElementPushed) {
	DoubleLinkedList<int> list;
	int x = 1;
	list.PushFront(x);

	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list.Size(), 1);
}

TEST(DoubleLinkedListTests, PushFrontMultipleItems_EmptyList_ElementsPushed) {
	DoubleLinkedList<int> list;

	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushFront(4);

	EXPECT_EQ(list[3], 1);
	EXPECT_EQ(list[2], 2);
	EXPECT_EQ(list[1], 3);
	EXPECT_EQ(list[0], 4);
	EXPECT_EQ(list.Size(), 4);
}

TEST(DoubleLinkedListTests, SearchNumberInList_ContainsNumber_ReturnsTrue) {
	DoubleLinkedList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	EXPECT_TRUE(list.Contains(3));
}


TEST(DoubleLinkedListTests, SearchNumberInList_DoesNotContainsNumber_ReturnsFalse) {
	DoubleLinkedList<int> list;

	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);

	EXPECT_FALSE(list.Contains(100));
}

TEST(DoubleLinkedListTests, RemoveElement_ContainsOneElement_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.PushBack(1);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 0);
}

TEST(DoubleLinkedListTests, RemoveElement_ContainsMultipleElements_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	list.Remove(2);

	EXPECT_FALSE(list.Contains(2));
	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 3);
}

TEST(DoubleLinkedListTests, RemoveHeadElement_ContainsElement_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

	list.Remove(1);

	EXPECT_EQ(list.Size(), 2);
	EXPECT_EQ(list[0], 2);
	EXPECT_EQ(list[1], 3);
}

TEST(DoubleLinkedListTests, RemoveTailElement_ContainsElement_ListRemovedItem) {
	DoubleLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

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
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);

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


TEST(DoubleLinkedListTests, PopBackFirstItem_EmptyList_ExceptionThrow) {
	DoubleLinkedList<int> list;
	ASSERT_ANY_THROW({ list.PopBack(); });
}

TEST(DoubleLinkedListTests, PopFrontFirstItem_EmptyList_ExceptionThrow) {
	DoubleLinkedList<int> list;
	ASSERT_ANY_THROW({ list.PopFront(); });
}

TEST(DoubleLinkedListTests, PushFrontItem_ListContainItems_HeadContainsPushedElement) {
	DoubleLinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushFront(4);

	ASSERT_EQ(list.GetHead(), 4);
	ASSERT_EQ(list[0], 4);
}

TEST(DoubleLinkedListTests, PushBackItem_ListContainItems_TailContainsPushedElement) {
	DoubleLinkedList<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushBack(4);

	ASSERT_EQ(list.GetTail(), 4);	
}