// Project 1: Doubly Linked List
// Due Date: October 17, 2023, Tuesday
// Name: Logan Pickell
//prompt for project in readme
// 
// Description of the Program (2-3 sentences):
//  -Doubly Linked List familiarity.
//  -Being able to work with pointers, and pointers within linked lists. 
//  -Understanding function calls and while/for loops.

// Date Written: 9/29/2023
// Date Revised:10/6/2023   10/8/2023

//Credit Dr.Chia - Chu Chiang for base code
//Department of Computer Science

//This is my source code for a project in my Algorithms course

#include <iostream>
#include "doublylinkedlist.h"

int main()
{
	{																							 //#1 (drawDoublyLinkedList)
	// Create a doubly linked list
		DoublyLinkedList* Dll_1{ new DoublyLinkedList };

		// Each node contains one integer
		Node n1{ 10 };
		Node n2{ 20 };
		Node n3{ 30 };
		Node n4{ 40 };
		Node n5{ 50 };

		// a doubly linked list of integers by inserting nodes
		Dll_1->addNewNodeToFront(&n1);
		Dll_1->addNewNodeToFront(&n2);
		Dll_1->addNewNodeToFront(&n3);
		Dll_1->addNewNodeToFront(&n4);
		Dll_1->addNewNodeToFront(&n5);


		Dll_1->drawDoublyLinkedList();
		

		cout << endl;
		system("PAUSE");
		system("CLS");






		//#2 (Palindrome)


//test case 1


		Dll_1->displayDoublyLinkedList();
		cout << Dll_1->isPalindrome() << endl;


		if (Dll_1->isPalindrome())
		{
			cout << "Dll_1 is a Palindrome.\n";
		}
		else
		{
			cout << "Dll_1 is NOT a Palindrome.\n";
		}
		cout << endl;

		delete Dll_1;
		system("PAUSE");
		system("CLS");


		//test case 2


		// Create a doubly linked list
		DoublyLinkedList* Dll_2{ new DoublyLinkedList };

		// Each node contains one integer
		Node n6{ 10 };
		Node n7{ 20 };
		Node n8{ 20 };
		Node n9{ 10 };

		// a doubly linked list of integers by inserting nodes
		Dll_2->addNewNodeToFront(&n6);
		Dll_2->addNewNodeToFront(&n7);
		Dll_2->addNewNodeToFront(&n8);
		Dll_2->addNewNodeToFront(&n9);

		Dll_2->displayDoublyLinkedList();
		cout << Dll_2->isPalindrome() << endl;

		if (Dll_2->isPalindrome())
		{
			cout << "Dll_2 is a Palindrome.\n";
		}
		else
		{
			cout << "Dll_2 is NOT a Palindrome.\n";
		}

		cout << endl;
		delete Dll_2;
		system("PAUSE");
		system("CLS");


	} //enclosing this to let variables go out of scope
																										//#3(Split)


	// test case 1


	{
		// Create a doubly linked list
		DoublyLinkedList* Dll_3;
		Dll_3 = new DoublyLinkedList;

		// Each node contains one integer
		Node n10{ 1 };
		Node n11{ 2 };
		Node n12{ 3 };
		Node n13{ 4 };
		Node n14{ 5 };
		Node n15{ 6 };
		Node n16{ 7 };
		Node n17{ 8 };


		// a doubly linked list of integers by inserting nodes
		Dll_3->addNewNodeToBack(&n10);
		Dll_3->addNewNodeToBack(&n11);
		Dll_3->addNewNodeToBack(&n12);
		Dll_3->addNewNodeToBack(&n13);
		Dll_3->addNewNodeToBack(&n14);
		Dll_3->addNewNodeToBack(&n15);
		Dll_3->addNewNodeToBack(&n16);
		Dll_3->addNewNodeToBack(&n17);


		
		
		vector<DoublyLinkedList*> lists{ Dll_3->split(Dll_3->askPartitions()) }; //initializing our new vector of lists to the return value of split(). asking the user for n.
		delete Dll_3;// delete list we no longer need.
		
		
		int listCount{ 1 };
		for (const auto& list : lists) //ranged based for loop to draw each list, if it could not process the split lists will be empty. (const auto&) should result in cheap variable for printing
		{
			cout << "[List " << listCount << "]" << endl;
			listCount++;
			list->drawDoublyLinkedList();
			cout << endl;
			delete list; //allocated each list as a new DoublyLinkedList, so we should delete each list after use
		}
		
		system("PAUSE");
		system("CLS");
	}



	// test case 2


	// Create a doubly linked list
	DoublyLinkedList* Dll_4{ new DoublyLinkedList };

	// Each node contains one character of a string
	Node n18{ 1 };
	Node n19{ 2 };
	Node n20{ 3 };
	Node n21{ 4 };
	Node n22{ 5 };
	Node n23{ 6 };
	Node n24{ 7 };

	// a doubly linked list of characters by inserting nodes
	Dll_4->addNewNodeToBack(&n18);
	Dll_4->addNewNodeToBack(&n19);
	Dll_4->addNewNodeToBack(&n20);
	Dll_4->addNewNodeToBack(&n21);
	Dll_4->addNewNodeToBack(&n22);
	Dll_4->addNewNodeToBack(&n23);
	Dll_4->addNewNodeToBack(&n24);

	Dll_4->split(Dll_4->askPartitions()); // 7 is a prime number, using this test case to show a case that can not be processed.

	delete Dll_4;
	system("PAUSE");

	return 0;
}
	