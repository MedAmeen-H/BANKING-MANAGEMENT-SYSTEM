#include "SinglyLinkedListAllTransactionsMeth.h"
#include <iostream>
using namespace std;
#include <string>


NodeAllTransactions* createNodeAllTransactions(StructTransaction value) {
	NodeAllTransactions* node = new (nothrow) NodeAllTransactions{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}


void destroyNodeAllTransactions(NodeAllTransactions* node) {
	delete node;
}


bool ListAllTransactionsisEmpty(const ListAllTransactions& L) {
	return L.size == 0;
}

int ListAllTransactionsSize(const ListAllTransactions& L) {
	return L.size;
}

bool ListAllTransactionsisFull(const ListAllTransactions& L) {
	NodeAllTransactions* test = new (nothrow) NodeAllTransactions;
	if (!test) return true;
	delete test;
	return false;
}


int InsertAllTransaction(ListAllTransactions* L, StructTransaction e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeAllTransactions* n = createNodeAllTransactions(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		NodeAllTransactions* prev = nullptr;
		NodeAllTransactions* current = L->head;
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


int removeAllTransactionAt(ListAllTransactions* L, int pos) {
	if (!L || ListAllTransactionsisEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeAllTransactions* prev = nullptr;
	NodeAllTransactions* current = L->head;
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
	destroyNodeAllTransactions(current);
	L->size--;
	return 1;
}
StructTransaction getAllTransaction(const ListAllTransactions& L, int pos) {
	StructTransaction s = {};
	if (ListAllTransactionsisEmpty(L)) {
		cerr << "\nListAllTransactions is empty\n";
		return s;
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return s;
	}


	NodeAllTransactions* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}

	return current->data;
}


ListAllTransactions createListAllTransactions() {
	return ListAllTransactions{ nullptr, 0 };
}


void destroyListAllTransactions(ListAllTransactions* L) {
	if (!L) return;
	NodeAllTransactions* current = L->head;
	while (current) {
		NodeAllTransactions* temp = current;
		current = current->next;
		destroyNodeAllTransactions(temp);
	}
	L->head = nullptr;
	L->size = 0;
}


void displayListAllTransactions(const ListAllTransactions& L) {
	if (ListAllTransactionsisEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	NodeAllTransactions* current = L.head;
	while (current != nullptr) {
		cout << "Transaction ID: " + current->data.TransactionID << endl;
		cout << "Account Number: " + current->data.AccNum << endl;
		cout << "Transaction Type: " + current->data.Type << endl;
		cout << "Amount: " << current->data.amount << endl;
		cout << "Date: " + current->data.date << endl;
		current = current->next;
	}
	cout << "NULL\n";
}



ListAllTransactions CopyListAllTransactions(const ListAllTransactions& L) {
	ListAllTransactions newListAllTransactions = createListAllTransactions();
	NodeAllTransactions* current = L.head;
	NodeAllTransactions* tail = nullptr;

	while (current) {
		NodeAllTransactions* n = createNodeAllTransactions(current->data);
		if (!n) {

			cerr << "\nMemory allocation failed while copying\n";
			destroyListAllTransactions(&newListAllTransactions);
			return createListAllTransactions();
		}

		if (!newListAllTransactions.head) {
			newListAllTransactions.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newListAllTransactions.size = L.size;
	return newListAllTransactions;
}



bool CompareListAllTransactions(const ListAllTransactions& L1, const ListAllTransactions& L2) {
	if (L1.size != L2.size) return false;

	NodeAllTransactions* p1 = L1.head;
	NodeAllTransactions* p2 = L2.head;

	while (p1) {
		if (p1->data.TransactionID != p2->data.TransactionID)return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}
