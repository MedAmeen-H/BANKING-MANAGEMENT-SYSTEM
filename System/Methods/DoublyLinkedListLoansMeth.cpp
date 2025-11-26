#include<iostream>
#include<string>
#include "DoublyLinkedListLoansMeth.h"
using namespace std;
NodeLoan* createNodeLoan(StructLoan data) {
	NodeLoan* node = new (nothrow) NodeLoan;
	if (!node) {
		cout << "\nMemory allocation failed for node\n";
		return nullptr;
	}
	node->data = data;
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}
int insertLoan(ListLoan* L, StructLoan e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cout << "\nInvalid position";
		return 0;
	}
	NodeLoan* n = createNodeLoan(e);
	if (!n) return 0;
	if (ListLoanIsEmpty(*L)) {
		L->head = n;
		L->tail = n;
	}
	else if (pos == 1) {
		n->next = L->head;
		L->head->prev = n;
		L->head = n;
	}
	else if (pos == L->size + 1) {
		n->prev = L->tail;
		L->tail->next = n;
		L->tail = n;
	}
	else {
		NodeLoan* prev = nullptr;
		NodeLoan* current = L->head;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = n;
		n->prev = prev;
		n->next = current;
		current->prev = n;
	}
	L->size++;
	return 1;
}
int removeAtLoan(ListLoan* L, int pos) {
	if (!L || ListLoanIsEmpty(*L)) {
		cout << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cout << "\nInvalid position";
		return 0;
	}
	NodeLoan* current;
	if (L->size == 1) {
		current = L->head;
		L->head = nullptr;
		L->tail = nullptr;
	}
	else if (pos == 1) {
		current = L->head;
		L->head = L->head->next;
		L->head->prev = nullptr;

	}
	else if (pos == L->size) {
		current = L->tail;
		L->tail = L->tail->prev;
		L->tail->next = nullptr;
	}
	else {
		NodeLoan* prevNode = nullptr;
		current = L->head;
		for (int i = 1; i < pos; i++) {
			prevNode = current;

			current = current->next;
		}
		current->next->prev = prevNode;
		prevNode->next = current->next;
	}
	destroyNodeLoan(current);
	L->size--;
	return 1;
}
ListLoan createListLoan() {
	return ListLoan{ nullptr, nullptr, 0 };
}
void destroyListLoan(ListLoan* L) {
	if (!L) return;
	NodeLoan* current = L->head;
	while (current) {
		NodeLoan* temp = current;
		current = current->next;
		destroyNodeLoan(temp);
	}
	L->head = nullptr;
	L->tail = nullptr;
	L->size = 0;
}
ListLoan CopyListLoan(const ListLoan& L) {
	ListLoan newList = createListLoan();
	NodeLoan* current = L.head;
	NodeLoan* tail = nullptr;
	while (current) {
		NodeLoan* n = createNodeLoan(current->data);
		if (!n) {
			cerr << "\nMemory allocation failed while copying\n";
			destroyListLoan(&newList);
			return createListLoan();
		}
		n->prev = tail;
		if (!newList.head) {
			newList.head = n;
		}
		else {
			tail->next = n;
		}
		tail = n;
		current = current->next;
	}
	newList.tail = tail;
	newList.size = L.size;
	return newList;
}
bool ListLoanIsEmpty(const ListLoan& L) {
	return L.size == 0;
}
bool ListLoanIsFull(const ListLoan& L) {
	NodeLoan* test = new (nothrow) NodeLoan;
	if (!test) return true;
	delete test;
	return false;
}
int ListLoanSize(const ListLoan& L) {
	return L.size;
}
int getLoan(const ListLoan& L, int pos) {
	if (ListLoanIsEmpty(L)) {
		cerr << "\nList is empty\n";
		return -1;
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return -1;
	}
	NodeLoan* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
		cout << "Loan ID: " + current->data.LoanID << endl;
		cout << "Loan type: " + current->data.LoanType << endl;
		cout << "Principal Amount: " << current->data.principalAmount << endl;
		cout << "Interest Rate: " << current->data.interestRate << endl;
		cout << "Amount Paid : " << current->data.AmountPaid << endl;
		cout << "Remaining Balance: " << current->data.remainingBalance << endl;
		cout << "Start Date: " + current->data.startDate << endl;
		cout << "End Date: " + current->data.endDate << endl;
		cout << "Loan Status: " + current->data.LoanStatus << endl;
	}
	return (1);
}
void displayListLoan(const ListLoan& L) {
	if (ListLoanIsEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	NodeLoan* current = L.head;
	while (current) {
		cout << "Loan ID: " + current->data.LoanID << endl;
		cout << "Loan type: " + current->data.LoanType << endl;
		cout << "Principal Amout: " << current->data.principalAmount << endl;
		cout << "Interest Rate: " << current->data.interestRate << endl;
		cout << "Amount Paid : " << current->data.AmountPaid << endl;
		cout << "Remaining Balance: " << current->data.remainingBalance << endl;
		cout << "Start Date: " + current->data.startDate << endl;
		cout << "End Date: " + current->data.endDate << endl;
		cout << "Loan Status: " + current->data.LoanStatus << endl;
		current = current->next;
	}
	cout << "NULL\n";
}
bool CompareLoanLists(const ListLoan& L1, const ListLoan& L2) {
	if (L1.size != L2.size) return false;

	NodeLoan* p1 = L1.head;
	NodeLoan* p2 = L2.head;

	while (p1) {
		if (p1->data.LoanID != p2->data.LoanID) return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}
void destroyNodeLoan(NodeLoan* node) {
	delete node;

}

