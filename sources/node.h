#pragma once
#include <iostream>
#include <string>

template <typename T>
class Node;

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Node<T> &node);

template <typename T>
class Node
{
private:
	T value;
	Node<T> *next;

public:
	Node(T value) : value(value), next(nullptr) {}
	Node(const Node<T> &other) : value(other.value), next(other.next) {}
	Node<T> &operator=(const Node<T> &other);
	bool operator==(const Node<T> &other);
	~Node() {}

	T getValue() const;
	void setValue(T value);
	Node<T> *getNext() const;
	void setNext(Node<T> *node);

	friend std::ostream &operator<< <T>(std::ostream &stream, const Node<T> &node);
};

template <typename T>
Node<T> &Node<T>::operator=(const Node<T> &other)
{
	if (this == &other)
		return *this;
	this->value = other.value;
	this->next = other.next;

	return *this;
}

template <typename T>
bool Node<T>::operator==(const Node<T> &other)
{
	if (this == &other)
		return true;
	return (this->value == other.value) && (this->next == other.next);
}

template <typename T>
T Node<T>::getValue() const
{
	return this->value;
}

template <typename T>
void Node<T>::setValue(T value)
{
	this->value = value;
}

template <typename T>
Node<T> *Node<T>::getNext() const
{
	return this->next;
}

template <typename T>
void Node<T>::setNext(Node<T> *node)
{
	this->next = node;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Node<T> &node)
{
	return stream << node.value;
}
