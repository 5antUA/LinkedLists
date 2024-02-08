#pragma once
#include <iostream>

class NodeDouble {
public:
	double data;
	NodeDouble* prev, * next;

	NodeDouble(double data) : data(data), prev(NULL), next(NULL) {}
};

class LinkedList {
public:
	NodeDouble* head, * tail;

	LinkedList() { head = tail = NULL; }
	LinkedList(double data) { push_front(data); }
	~LinkedList() { while (head != NULL) pop_front(); }

	// ADDING AN ELEMENT TO THE BEGINNING OF THE LIST
	void push_front(double data) {
		NodeDouble* node = new NodeDouble(data);
		if (head == NULL) head = tail = node;
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	// ADDING AN ELEMENT TO THE END OF A LIST
	void push_back(double data) {
		NodeDouble* node = new NodeDouble(data);
		if (head == NULL) head = tail = node;
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}

	// DELETING THE FIRST ELEMENT OF THE LIST
	void pop_front() {
		if (head == NULL) return;
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			NodeDouble* node = head->next;
			node->prev = NULL;
			delete head;
			head = node;
		}
	}

	// DELETING THE LAST ELEMENT OF THE LIST
	void pop_back() {
		if (head == NULL) return;
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			NodeDouble* node = tail->prev;
			node->next = NULL;
			delete tail;
			tail = node;
		}
	}

	// RETURN OF THE STRUCTURE AT THE SPECIFIED INDEX
	NodeDouble* getIt(int k) {
		NodeDouble* node = head;
		int n = 0;

		if (k < 0) return NULL;
		else if (k == 0) return head;
		else {
			for (; n != k && node->next; n++)
				node = node->next;

			return node;
		}
	}

	// RETURN OF THE ELEMENT AT THE SPECIFIED INDEX
	double getElem(int k) {
		NodeDouble* node = getIt(k);
		return node->data;
	}

	// CLEARING THE LIST
	void deleteList() {
		while (head != NULL) pop_front();
	}

	// DISPLAY THE LIST ON THE SCREEN
	void printList() {
		for (NodeDouble* node = head; node != NULL; node = node->next) {
			std::cout << node->data << " ";
		}
		std::cout << std::endl;
	}
};
