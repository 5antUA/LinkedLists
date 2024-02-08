#pragma once
#include <iostream>

struct NodeUnary {
	double data;
	NodeUnary* next;

	NodeUnary(double data) : data(data), next(NULL) {}
};

class OneLinkedList {
public:
	NodeUnary* head, * tail;

	OneLinkedList() { this->head = this->tail = NULL; }
	OneLinkedList(double data) { push_front(data); }
	~OneLinkedList() { while (head != NULL) pop_front(); }

	// ADDING AN ELEMENT TO THE BEGINNING OF THE LIST
	void push_front(double data) {
		NodeUnary* node = new NodeUnary(data);
		node->next = head;
		head = node;
		if (tail == NULL) tail = head;
	}

	// ÄÎÄÀÂÀÍÍß ÅËÅÌÅÍÒÓ ÍÀ Ê²ÍÅÖÜ ÑÏÈÑÊÓ
	void push_back(double data) {
		NodeUnary* node = new NodeUnary(data);
		if (head == NULL) {
			head = tail = node;
		}
		else {
			tail->next = node;
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
			NodeUnary* node = head;
			head = node->next;
			delete node;
		}
	}

	// DELETING THE LAST ELEMENT OF THE LIST
	void pop_back() {
		if (head == NULL) {
			return;
		}
		else if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			NodeUnary* node = head;
			while (node->next != tail) node = node->next;
			delete tail;
			node->next = NULL;
			tail = node;
		}
	}

	// RETURN OF THE STRUCTURE AT THE SPECIFIED INDEX
	NodeUnary* getIt(int k) {
		NodeUnary* node = head;
		int n = 0;

		if (k < 0) return NULL;
		else if (k == 0) return node;
		else {
			while (n != k) {
				node = node->next;
				n++;
			}
			return node;
		}
	}

	// RETURN OF THE ELEMENT AT THE SPECIFIED INDEX
	double getElem(int k) {
		NodeUnary* node = getIt(k);
		return node->data;
	}

	// INSERT YOUR ELEMENT IN THE SPECIFIED POSITION
	void insert(int k, double data) {
		NodeUnary* left = getIt(k);
		if (left == NULL) return;

		NodeUnary* right = left->next;
		if (right == NULL) {
			push_back(data);
			return;
		}

		NodeUnary* node = new NodeUnary(data);
		left->next = node;
		node->next = right;
	}

	// DELETING ELEMENT AT THE SPECIFIED POSITION
	void erase(int k) {
		if (k < 0) return;
		else if (k == 0) {
			pop_front();
			return;
		}

		NodeUnary* left = getIt(k - 1);
		NodeUnary* node = left->next;
		if (node == NULL) return;
		NodeUnary* right = node->next;

		left->next = right;
		if (node == tail) tail = left;
		delete node;
	}

	// CLEARING THE LIST
	void deleteList() {
		while (head != NULL) pop_front();
	}

	// COPYING THE FIRST ELEMENT TO THE END OF THE LIST
	void copyHead() {
		push_back(head->data);
	}

	// COPYING THE LAST ELEMENT TO THE END OF THE LIST
	void copyTail() {
		if (head == NULL) {
			return;
		}
		push_front(tail->data);
	}

	// DISPLAY THE LIST ON THE SCREEN
	void printList() {
		for (NodeUnary* node = head; node != NULL; node = node->next) {
			std::cout << node->data << " ";
		}
		std::cout << std::endl;
	}
};