#include <stdio.h>
#include <iostream>
#include <string>

typedef struct _node
{
	int value;
	_node *next;
}node;

class node_list
{
public:
	node_list()
	{
		std::cout << "construct node list class" << std::endl;
	}
	node *create_node(int node_number)
	{
		node *header = NULL;
		header = new node;
		header->value = 0;
		header->next = NULL;
		node *pointer = NULL;
		for (int i = 0; i < node_number; i++)
		{
			pointer = new node;
			pointer->value = i + 1;
			pointer->next = header->next;
			header->next = pointer;
		}
		return header;
	}
	void display(node *header)
	{
		while (header->next != NULL)
		{
			std::cout << "node value:" << header->value << std::endl;
			header = header->next;
		}
	}
	node *reverse()
	{
		node *header = this->create_node(10);
		display(header);
		node *front = header;
		node *current = header->next;
		node *next = current->next;
		current->next = front;
		header->next = NULL;
		while (next->next != NULL)
		{
			front = current;
			current = next;
			next = next->next;
			current->next = front;
		}
		header = next;
		next->next = current;
		display(next);
	}
};
class test
{
public:
	test()
	{
		std::cout << "construct test class" << std::endl;
	}
	void show(std::string msg)
	{
		std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
	}
};
int main(int argc, char *argv[])
{
	test _test;
	_test.show("thank you test");
	node_list list;
	node *header = list.create_node(10);
	list.display(header);
	std::cout << "reverse " << std::endl;
	list.reverse();
	return 0;
}
