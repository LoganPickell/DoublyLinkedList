#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <stdio.h>
#include "Node.h"

class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addNewNodeToFront(Node* newNode);
	void addNewNodeToBack(Node* newNode);
	Node* removeNodeFromFront();
	void removeNodeFromBack();
	void displayDoublyLinkedList();
	bool isPalindrome();
	vector<DoublyLinkedList*>split(int n);
	int askPartitions();
	void drawDoublyLinkedList();
	int count{0};
private:
	Node* head;
	Node* tail;
};
#endif
