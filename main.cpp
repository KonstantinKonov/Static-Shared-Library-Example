#include <iostream>

#include "include/node.h"
#include "include/ll.h"

int main()
{
	LL<int> ll;

	ll.push_back(new Node<int>(1));
	ll.push_back(new Node<int>(2));
	ll.push_back(new Node<int>(3));
	ll.push_back(new Node<int>(4));
	ll.push_back(new Node<int>(5));

	std::cout << ll << std::endl;
}