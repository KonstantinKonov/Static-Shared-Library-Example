#pragma once
#include <iostream>
#include <cassert>

#include "node.h"

// forward class declaration
template <typename T>
class LL;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const LL<T> &ll);

template <typename T>
class LL
{
private:
	Node<T> *head;

public:
	LL() : head(nullptr) {}
	LL(const Node<T> &node) : head(new Node(node)) {}
	LL(Node<T> *const node) : head(node) {}
	LL(const LL<T> &ll);
	~LL();

	void push_back(Node<T> *const node);
	void push_front(Node<T> *const node);
	Node<T> &pop_back();
	Node<T> &pop_front();
	Node<T> peek_back() const;
	Node<T> peek_front() const;

	friend std::ostream &operator<< <T>(std::ostream &stream, const LL<T> &ll);
};

template <typename T>
LL<T>::LL(const LL<T> &ll)
{
	head = ll.head;
}

template <typename T>
LL<T>::~LL()
{
	Node<T> *currNode = head;
	while (currNode != nullptr)
	{
		Node<T> *temp = currNode->getNext();
		delete currNode;
		currNode = temp;
	}
}

template <typename T>
void LL<T>::push_back(Node<T> *const node)
{
	if (head == nullptr)
	{
		head = node;
		return;
	}

	Node<T> *currNode = head;
	while (currNode->getNext() != nullptr)
	{
		currNode = currNode->getNext();
	}
	currNode->setNext(node);
}

template <typename T>
void LL<T>::push_front(Node<T> *const node)
{
	Node<T> *temp = head;
	head = node;
	head->setNext(temp);
}

template <typename T>
Node<T> &LL<T>::pop_back()
{
	assert(head != nullptr);

	if (head->getNext() == nullptr)
	{
		Node<T> *temp = head;
		head = nullptr;
		return *temp;
	}

	Node<T> *currNode = head;
	while (currNode->getNext()->getNext() != nullptr)
	{
		currNode = currNode->getNext();
	}

	Node<T> *temp = currNode->getNext();
	currNode->setNext(nullptr);
	return *temp;
}

template <typename T>
Node<T> &LL<T>::pop_front()
{
	assert(head != nullptr);

	if (head->getNext() == nullptr)
	{
		Node<T> *temp = head;
		head = nullptr;
		return *temp;
	}

	Node<T> *temp = head;
	head = head->getNext();
	return *temp;
}

template <typename T>
Node<T> LL<T>::peek_back() const
{
	assert(head != nullptr);

	Node<T> *currNode = head;
	while (currNode->getNext() != nullptr)
	{
		currNode = currNode->getNext();
	}
	return *currNode;
}

template <typename T>
Node<T> LL<T>::peek_front() const
{
	assert(head != nullptr);

	return *head;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const LL<T> &ll)
{
	Node<T> *currNode = ll.head;
	while (currNode != nullptr)
	{
		stream << currNode->getValue() << " ";
		currNode = currNode->getNext();
	}
	return stream;
}