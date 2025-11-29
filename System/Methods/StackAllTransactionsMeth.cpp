#include "StackAllTransactionsMeth.h"
#include <iostream>
using namespace std;
#include <string>


NodeAllTransactions* createNodeAllTransactions(Transaction value) {
	NodeAllTransactions* node = new (nothrow) NodeAllTransactions{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}


void destroyNodeAllTransactions(NodeAllTransactions* node) {
	delete node;
}


bool StackAllTransactionsisEmpty(const StackAllTransactions& Stack) {
	return Stack.size == 0;
}

int StackAllTransactionsSize(const StackAllTransactions& Stack) {
	return Stack.size;
}

bool StackAllTransactionsisFull(const StackAllTransactions& Stack) {
	NodeAllTransactions* test = new (nothrow) NodeAllTransactions;
	if (!test) return true;
	delete test;
	return false;
}


int PushTransaction(StackAllTransactions* Stack, Transaction e, int pos) {
	if (!Stack) return 0;
	if (pos < 1 || pos > Stack->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeAllTransactions* n = createNodeAllTransactions(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = Stack->head;
		Stack->head = n;
	}
	else {
		NodeAllTransactions* prev = nullptr;
		NodeAllTransactions* current = Stack->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->next = current;
	}

	Stack->size++;
	return 1;
}


int PopTransactionAt(StackAllTransactions* Stack, int pos) {
	if (!Stack || StackAllTransactionsIsEmpty(*Stack)) {
		cerr << "\nStack is empty";
		return 0;
	}
	if (pos < 1 || pos > Stack->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeAllTransactions* prev = nullptr;
	NodeAllTransactions* current = Stack->head;
	if (pos == 1) {
		Stack->head = current->next;
	}
	else {
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
	}
	destroyNodeAllTransactions(current);
	Stack->size--;
	return 1;
}
Transaction getAllTransaction(const StackAllTransactions& Stack, int pos) {
	Transaction s = {};
	if (StackAllTransactionsIsEmpty(Stack)) {
		cerr << "\nStackAllTransactions is empty\n";
		return s;
	}
	if (pos < 1 || pos > Stack.size) {
		cerr << "\nInvalid position\n";
		return s;
	}


	NodeAllTransactions* current = Stack.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}

	return current->data;
}


StackAllTransactions createStackAllTransactions() {
	return StackAllTransactions{ nullptr, 0 };
}


void destroyStackAllTransactions(StackAllTransactions* Stack) {
	if (!Stack) return;
	NodeAllTransactions* current = Stack->head;
	while (current) {
		NodeAllTransactions* temp = current;
		current = current->next;
		destroyNodeAllTransactions(temp);
	}
	Stack->head = nullptr;
	Stack->size = 0;
}


void displayStackAllTransactions(const StackAllTransactions& Stack) {
	if (StackAllTransactionsIsEmpty(Stack)) {
		cout << "List is empty\n";
		return;
	}
	NodeAllTransactions* current = Stack.head;
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



StackAllTransactions CopyStackAllTransactions(const StackAllTransactions& Stack) {
	StackAllTransactions newStackAllTransactions = createStackAllTransactions();
	NodeAllTransactions* current = Stack.head;
	NodeAllTransactions* tail = nullptr;

	while (current) {
		NodeAllTransactions* n = createNodeAllTransactions(current->data);
		if (!n) {

			cerr << "\nMemory allocation failed while copying\n";
			destroysStackAllTransactions(&newStackAllTransactions);
			return createStackAllTransactions();
		}

		if (!newStackAllTransactions.head) {
			newStackAllTransactions.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newStackAllTransactions.size = Stack.size;
	return newStackAllTransactions;
}



bool CompareStackAllTransactions(const StackAllTransactions& L1, const StackAllTransactions& L2) {
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
