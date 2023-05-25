#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the namr of the student: ";
	cin >> nm;
	Node* newNode = new Node(); //Step 1
	newNode->noMhs = nim; //Step 2
	newNode->nama = nm;

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //Step3
		if (START != NULL)
			START->prev = newNode; //Step 4
		newNode->prev = NULL; //Step 5
		START = newNode; //Step 6
		return;
	}

	/*Intersting a Node Between Two Nodes in the list*/
	Node* current = START; // Step 1.a
	Node* previous = NULL; // Step 1.b
	while (current->next != NULL && current->next->noMhs < nim) // Stop c.1
	{
		previous = current; // 1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers mot allowed" << endl;
		return;
	}

	newNode->next = current->next; // Step 4
	newNode->prev = current; // Step 5
	if (current->next != NULL)
		current->next->prev = newNode; // Step 6
	current->next = newNode; // Step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START; // Step 1.a
	*current = START; // Step 1.b
	while (current != NULL && rollNo != (*current)->noMhs) { // Step 1.c
		*previous = *current; // Step1.d
		*previous = (*current)->next; // Step 1.e
	}
	return (*current != NULL);
}

bool  DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; // Step 2
	if (previous != NULL)
		previous->next = current->next; // Step 3
	else
		START = current->next;

	delete current; // Step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecord in traverse order of roll number are: " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->next;
		}
	}
}
	