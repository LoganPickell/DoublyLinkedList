# DoublyLinkedList
Below is the prompt for my Algorithms (CPSC 2380) project 1. 









CPSC 2380 - 01 and 9S1: Algorithms
 
Project 1: Doubly Linked List

Due at the beginning of the class, Tuesday, October 17, 2023

By
Dr. Chia-Chu Chiang

Department of Computer Science
University of Arkansas at Little Rock
2801 S. University Avenue
Little Rock, Arkansas 7204-1099, USA

Total Points: 100 points

Given the code of doubly linked list, 
// Node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
	friend class DoublyLinkedList;
	public:
		Node();
		Node(int v);
		~Node();
		

	private:
		Node *prev;
		int  value;
		Node *next;

};

#endif

// Node.cpp
#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
Node::Node()
{
	prev = NULL;
	value = 0;
	next = NULL;
}

Node::Node(int v)
{
	prev = NULL;
	value = v;
	next = NULL;
}

Node::~Node()
{
	
}

#endif

// doublylinkedlist.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Node.h"

class DoublyLinkedList{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addNewNodeToFront(Node* newNode);
	void addNewNodeToBack(Node* newnNde);
	Node* removeNodeFromFront();
	void removeNodeFromBack();
	void displayDoublyLinkedList();
	bool isPalindrome();
	void split(int n);
       void drawDoublyLinkedList();
private:
	Node* head;
	Node* tail;

};
#endif

// complete the following methods in the doubly linked list class.

// doublylinkedlist.cpp
#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList() 
{
	head = NULL;
	tail = NULL;
}




DoublyLinkedList::~DoublyLinkedList() 
{

}

void DoublyLinkedList::addNewNodeToFront(Node * newNode) {
	if(head == NULL && tail == NULL) {
		head = tail = newNode;
	} else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void DoublyLinkedList::addNewNodeToBack(Node * newNode) {
	if(head == NULL && tail == NULL) {
		head = tail = newNode;
	} else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}


Node* DoublyLinkedList::removeNodeFromFront()
{
	Node *tempNode;

	tempNode = head;
	head = head->next;
	return tempNode;
}


void DoublyLinkedList::displayDoublyLinkedList()
{
	Node *tempNode;

	tempNode = head;
	while (tempNode != NULL)
    {
        cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }
}

void DoublyLinkedList::drawDoublyLinkedList()
{
  // CODE TO BE ADDED for Project 1
  //	Might reuse displayDoublyLinkedList()
}


bool DoublyLinkedList::isPalindrome()
{
  // CODE TO BE ADDED for Project 1
  ... 
}

Void DoublyLinkedList::split(int n) // n is the number of even partitions
{
  // CODE TO BE ADDED for Project 1
  ...
}


1. (30 Points) Write a method void drawDoublyLinkedList() that draws a pictorial view of a doubly linked list. For example, if you run the following main.cpp, you should produce the output below.

2. (30 Points) Write a method bool isPalindrome() that returns true if a doubly linked list of integers is a palindrome or not. An empty doubly linked list of integers is a palindrome. You are NOT allowed to use any “reverse” method. Please use the following main.cpp to test the method for correctness.

3. (40 Points) Write a method, void split(n), that evenly splits a doubly linked list into n (n  1) doubly sub linked lists. If n is less than 1, exceeds the size of the doubly linked list, or the list cannot be evenly divided, print “cannot be processed.” to the output. Please use the following main.cpp to test the method for correctness.



int main() test case was given for each question, cut that out to save space. Most of the code is in my source code, with slight modifications that helped with memory, initializing and deallocating changes for example. 


Your project will be graded based on the correctness of the program. In addition, the readability of the program will also be taken into account. To make the program readable, you should have a program header placed on the top of the program describing your name, student ID, and a brief description of what the program is going to in one or two sentences. Your program should be modular and lots of comments in the program. 

// University of Arkansas at Little Rock
// Department of Computer Science
// CPSC 2380 - 01 and 9S1: Algorithms
// Fall 2023
// Project 1: Doubly Linked List
// Due Date: October 17, 2023, Tuesday
// Name:
// T-number (Last 4 Digits):
// Description of the Program (2-3 sentences):
// Date Written:
// Date Revised:
Figure 1: Program Header


Grading Scheme
1. No credits given if the program is not compiled.
2. Partial credits given if the program works partially correct.
3. Absolutely, no late project.

You should ONLY turn in the source code of project 1 to the Blackboard, with sufficient sample outputs. LATE PROJECTS WILL NOT BE ACCEPTED. FIRM!
