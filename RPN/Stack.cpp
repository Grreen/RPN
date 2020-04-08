#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack() :top(nullptr)
{

}

template <class T>
Stack<T>::~Stack()
{
	while (top)
	{
		Node* prev = top;
		top = top->prev;
		delete prev;
	}
}

template <class T>
int Stack<T>::Count()
{
	if (IsEmpty())
		return 0;

	int count = 1;
	Node *temp = top;
	while (temp->prev)
	{
		count++;
		temp = temp->prev;
	}
	return count;
}

template <class T>
void Stack<T>::Push(T element)
{
	Node* newNode = new Node;
	newNode->element = element;
	newNode->prev = top;
	top = newNode;
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return top ? false : true;
}

template <class T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		return -1;

	T temp = top->element;
	Node* del = top;
	top = top->prev;
	delete del;
	return temp;
}

template <class T>
T Stack<T>::Peek()
{
	if (IsEmpty())
		return -1;
	return top->element;
}

template <class T>
void Stack<T>::PrintStack()
{
	while (top)
	{
		cout << Pop() << ' ';
	}

	cout << endl;
}