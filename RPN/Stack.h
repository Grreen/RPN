#pragma once
#include <iostream>

template <class T>
class Stack
{
	struct Node
	{
		T element;
		Node* prev;
	}*top;

	//Node* top;

public:
	Stack() :top(nullptr)
	{

	}

	~Stack()
	{
		while (top)
		{
			Node* prev = top;
			top = top->prev;
			delete prev;
		}
	}

	int Count()
	{
		if (IsEmpty())
			return 0;

		int count = 1;
		Node* temp = top;
		while (temp->prev)
		{
			count++;
			temp = temp->prev;
		}
		return count;
	}

	void Push(T element)
	{
		Node* newNode = new Node;
		newNode->element = element;
		newNode->prev = top;
		top = newNode;
	}

	T Pop()
	{
		//if (IsEmpty())
		//	return nullptr;

		T temp = top->element;
		Node* del = top;
		top = top->prev;
		delete del;
		return temp;
	}

	T Peek()
	{
		if (IsEmpty())
			return -1;
		return top->element;
	}

	bool IsEmpty()
	{
		return top ? false : true;
	}

	void PrintStack()
	{
		while (top)
		{
			cout << Pop() << ' ';
		}

		cout << endl;
	}

};

