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
	//Node* tempNode{};                  This was giving me an error, allowing the system to deconstruct,
	//Node* nextTempNode{};                    but deleting the lists we allocated with new.

	//tempNode = head;
	//while (tempNode != nullptr)
	//{
	//	nextTempNode = tempNode->next;
	//	delete tempNode;
	//	tempNode = nextTempNode;
	//}     
}

void DoublyLinkedList::addNewNodeToFront(Node* newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	count++;
}

void DoublyLinkedList::addNewNodeToBack(Node* newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	count++;
}


Node* DoublyLinkedList::removeNodeFromFront()
{
	Node* tempNode;

	tempNode = head;
	head = head->next;
	head->prev = NULL; //added this line
	return tempNode;
	count--;
}

void DoublyLinkedList::removeNodeFromBack()//added
{
	tail = tail->prev;
	tail->next = NULL;
	count--;
}


void DoublyLinkedList::displayDoublyLinkedList()
{
	Node* tempNode{ head };

	while (tempNode != NULL)
	{
		cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
	cout << endl;
}

void DoublyLinkedList::drawDoublyLinkedList()
{
	
	Node* tempNode{ head };
	
	while (tempNode != NULL)
	{
		cout << "[Address: " << tempNode << ", Prev: " << tempNode->prev <<
			", Value: " << tempNode->value << ", Next: " << tempNode->next << "]\n";
		tempNode = tempNode->next;
	}


	//printf version

	/*
	
	Node* tempNode2;
	tempNode2 = head;
	while (tempNode2 != NULL)
	{
		printf("[Address: %p, Prev: %p, Value: %d, Next: %p]\n", tempNode2, tempNode2->prev, tempNode2->value, tempNode2->next);
		tempNode2 = tempNode2->next;
	}
	
	*/
}


bool DoublyLinkedList::isPalindrome()
{
	Node* tempHead{ head };
	Node* tempTail{ tail };

	while (tempHead != NULL && tempTail!= NULL)
	{
		if (tempHead->value != tempTail->value)
		{
			return false;
		}
		tempHead = tempHead->next;
		tempTail = tempTail->prev;
	}
	return true;
}


//I added a return value, for the new lists
vector<DoublyLinkedList*> DoublyLinkedList::split(int n) // n is the number of even partitions
{
	vector<DoublyLinkedList*> lists;
	if (n <= 1 || count%n!=0)
	{
		cout << "Cannot be processed. \n";
		return lists;
	}

	cout << n << " evenly split subdoubly linked lists.\n";
	

	std::vector<Node*> heads{};
	std::vector<Node*> tails{};


	Node* tempNode = head;
	while (tempNode != NULL)
	{
		heads.push_back(tempNode);

		for (int i{ 1 }; i <= count / n; i++)
		{
			cout << tempNode->value << " ";
			tempNode = tempNode->next;
		}


		if (tempNode != NULL)
		{
			tails.push_back(tempNode->prev);//we stop our previous for loop at the head, so our tail is ->prev
		}
		else
		{
			tails.push_back(tail);//null does not have a ->prev pointer, if NULL -> the end of the old list = the end of our new list.
		}
		cout << endl;
				
	}
	cout << endl;
	
	
	for (int i{ 0 }; i < n; i++)
	{
		DoublyLinkedList* Dll = new DoublyLinkedList;
		lists.push_back(Dll);//vector containing n # of list
	}
	
	for (int i{ 0 }; i < n; i++) //detatch the head and tail, add node to its list, attach head and tail to new list.
	{
		heads[i]->prev = NULL;
		tails[i]->next = NULL;

		Node* tempNode = heads[i];
		Node* tempTail = tails[i];
		
	
	
		       
		while (tempNode->next != tempTail && tempNode != tempTail && tempNode->next != NULL) //can't forget about the middle nodes
		{
			tempNode = tempNode->next;
			lists[i]->addNewNodeToBack(tempNode);
		}
 		tempNode = heads[i];
		if (tempNode == tempTail) // if you split n by (# of nodes)  its only 1 node per list.
		{
			lists[i]->addNewNodeToBack(tails[i]);
		}
		else
		{
			lists[i]->addNewNodeToFront(heads[i]);
			lists[i]->addNewNodeToBack(tails[i]);
		}
		lists[i]->head = heads[i];
		lists[i]->tail = tails[i];
		cout << "[Head" << i + 1 << "]   [Address:" << heads[i] << "]    [Value:" << heads[i]->value << "]" << endl;
		cout << "[Tail" << i + 1 << "]   [Address:" << tails[i] << "]    [Value:" << tails[i]->value << "]" << endl << endl;
		
	}
	return lists;
}
int DoublyLinkedList::askPartitions()
{
	int n{ 0 };
	displayDoublyLinkedList();
	cout << endl << "Split this list how many times?" << endl;
	cin >> n;
	cout << endl;
	return n;
}
#endif