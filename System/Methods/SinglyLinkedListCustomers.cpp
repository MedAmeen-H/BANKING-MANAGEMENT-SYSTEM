#include "SinglyLinkedListCustomersMeth.h"
#include <iostream>
using namespace std;
#include <string>


NodeCustomer* createNodeCustomer(Customer value) {
	NodeCustomer* node = new (nothrow) NodeCustomer{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}


void destroyNodeCustomer(NodeCustomer* node) {
	delete node;
}


bool ListCustomersisEmpty(const ListCustomers& L) {
	return L.size == 0;
}

int ListCustomersSize(const ListCustomers& L) {
	return L.size;
}

bool ListCustomersisFull(const ListCustomers& L) {
	NodeCustomer* test = new (nothrow) NodeCustomer;
	if (!test) return true;
	delete test;
	return false;
}


int InsertCustomer(ListCustomers* L, Customer e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeCustomer* n = createNodeCustomer(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		NodeCustomer* prev = nullptr;
		NodeCustomer* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->next = current;
	}

	L->size++;
	return 1;
}


int removeCustomerAt(ListCustomers* L, int pos) {
	if (!L || ListCustomersisEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeCustomer* prev = nullptr;
	NodeCustomer* current = L->head;



	if (pos == 1) {
		L->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroyNodeCustomer(current);
	L->size--;
	return 1;
}



Customer getCustomer(const ListCustomers& L, int pos) {
	Customer s = {};
	if (ListCustomersisEmpty(L)) {
		cerr << "\nListCustomers is empty\n";
		return s;
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return s;
	}


	NodeCustomer* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}

	return current->data;
}


ListCustomers createListCustomers() {
	return ListCustomers{ nullptr, 0 };
}


void destroyListCustomers(ListCustomers* L) {
	if (!L) return;
	NodeCustomer* current = L->head;
	while (current) {
		NodeCustomer* temp = current;
		current = current->next;
		destroyNodeCustomer(temp);
	}
	L->head = nullptr;
	L->size = 0;
}


void displayListCustomers(const ListCustomers& L) {
	if (ListCustomersisEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	NodeCustomer* current = L.head;
	while (current != nullptr) {
		cout << "AccNumber: " << current->data.AccNum<< ", Name: " << current->data.name << endl;
		current = current->next;
	}
	cout << "NULL\n";
}



ListCustomers CopyListCustomers(const ListCustomers& L) {
	ListCustomers newListCustomers = createListCustomers();
	NodeCustomer* current = L.head;
	NodeCustomer* tail = nullptr;

	while (current) {
		NodeCustomer* n = createNodeCustomer(current->data);
		if (!n) {

			cerr << "\nMemory allocation failed while copying\n";
			destroyListCustomers(&newListCustomers);
			return createListCustomers();
		}

		if (!newListCustomers.head) {
			newListCustomers.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newListCustomers.size = L.size;
	return newListCustomers;
}



bool CompareListCustomers(const ListCustomers& L1, const ListCustomers& L2) {
	if (L1.size != L2.size) return false;

	NodeCustomer* p1 = L1.head;
	NodeCustomer* p2 = L2.head;

	while (p1) {
		if (p1->data.AccNum!= p2->data.AccNum)return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}


