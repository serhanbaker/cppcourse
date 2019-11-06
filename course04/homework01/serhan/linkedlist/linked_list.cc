#include "linked_list.h"
#include <ostream>

void linked_list::push_front(int data)
{
	auto temp{std::make_unique<Node>(data)};
	if (mHead)
	{
		temp->mNext = std::move(mHead);
		mHead = std::move(temp);
	}
	else
	{
		mHead = std::move(temp);
	}
	mSize++;
}

void linked_list::pop_front()
{
	if (mHead == nullptr)
	{
		return;
	}

	std::unique_ptr<Node> temp = std::move(mHead);
	mHead = std::move(temp->mNext);
	mSize--;
}

void linked_list::reset()
{
	while (mHead)
	{
		mHead = std::move(mHead->mNext);
	}
	mSize = 0;
}

void linked_list::reverse()
{
	linked_list tmp;
	Node *root = mHead.get();
	while (root)
	{
		tmp.push_front(root->mData);
		root = root->mNext.get();
	}
	reset();
	mHead = std::move(tmp.mHead);
}

std::ostream &operator<<(std::ostream &os, const linked_list &list)
{
	Node *head = list.mHead.get();
	while (head)
	{
		os << head->mData << ' ';
		head = head->mNext.get();
	}
	return os;
}

int linked_list::getHead()
{
	if (mSize == 0)
		throw std::out_of_range("Empty list");

	return mHead->mData;
}