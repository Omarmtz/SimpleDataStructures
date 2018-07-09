#include "pch.h"

#include "../DataStructures/src/DataStructures/Stack/Stack.h"
#include "../DataStructures/src/DataStructures/Stack/Stack.cpp"

TEST(StackTests, PushItem_StackEmpty_ItemPushed) {
	Stack<int> stack;

	stack.Push(1);

	EXPECT_EQ(stack.Peek(), 1);
}

TEST(StackTests, PushItem_StackMultipleValues_ItemPushed) {
	Stack<int> stack;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	EXPECT_EQ(stack.Peek(), 4);
}

TEST(StackTests, PopItem_StackMultipleValues_ItemRemoved) {
	Stack<int> stack;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);

	stack.Pop();

	EXPECT_EQ(stack.Peek(), 3);
}

TEST(StackTests, PopItem_StackSingleValue_ItemRemoved) {
	Stack<int> stack;

	stack.Push(1);
	stack.Pop();

	EXPECT_EQ(stack.Size(), 0);
	EXPECT_ANY_THROW({
		auto a = stack.Peek();
		});
}