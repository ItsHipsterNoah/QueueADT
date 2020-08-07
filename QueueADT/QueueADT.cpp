
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class Queue
{
public:
	void makeEmpty();
	bool isEmpty();
	void print();
	void enqueue(int data);
	void dequeue();
	Queue();
	~Queue();

private:
	Node* front;
	Node* rear;
};

Queue::Queue() : front{nullptr}, rear{nullptr}
{
}


void Queue::print()
{
	if (!front) {
		std::cout << "ERROR! List is empty" << std::endl;
	}
	else {
		Node* temp = front;
		while (temp != rear) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		std::cout << temp->data << std::endl;
	}
}

void Queue::enqueue(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	if (!front) {
		front = newNode;
		rear = front;
	}
	else {
		Node* temp = front;
		while (temp != rear) {
			temp = temp->next;
		}
		temp->next = newNode;
		rear = temp->next;
	}
}

void Queue::dequeue() {
	if (!front) {
		std::cout << "ERROR! Queue is empty." << std::endl;
	}
	else {
		Node* temp = front->next;
		std::cout << "Dequeuing " << front->data << std::endl;
		delete front;
		front = temp;
	}
}

void Queue::makeEmpty()
{
	Node* temp = front;
	while (temp) {
		temp = temp->next;
		delete front;
		front = temp;
	}
}

bool Queue::isEmpty()
{
	return front;
}


Queue::~Queue()
{
	makeEmpty();
}

int main()
{
	Queue q;
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(1);
	q.print();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.print();
	_CrtDumpMemoryLeaks();
	return 0;
}