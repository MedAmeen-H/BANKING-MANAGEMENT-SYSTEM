#include "SinglyLinkedListCompletedLoansMeth.h"
#include <iostream>
using namespace std;
#include <string>


NodeCompletedLoan* createNodeCompletedLoan(StructLoan value) {
	NodeCompletedLoan* node = new (nothrow) NodeCompletedLoan{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}


void destroyNodeCompletedLoan(NodeCompletedLoan* node) {
	delete node;
}


bool ListCompletedLoansisEmpty(const ListCompletedLoans& L) {
	return L.size == 0;
}

int ListCompletedLoansSize(const ListCompletedLoans& L) {
	return L.size;
}

bool ListCompletedLoansisFull(const ListCompletedLoans& L) {
	NodeCompletedLoan* test = new (nothrow) NodeCompletedLoan;
	if (!test) return true;
	delete test;
	return false;
}


int InsertCompletedLoan(ListCompletedLoans* L, StructLoan e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeCompletedLoan* n = createNodeCompletedLoan(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next = L->head;
		L->head = n;
	}
	else {
		NodeCompletedLoan* prev = nullptr;
		NodeCompletedLoan* current = L->head;
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


int removeCompletedLoanAt(ListCompletedLoans* L, int pos) {
	if (!L || ListCompletedLoansisEmpty(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size) {
		cerr << "\nInvalid position";
		return 0;
	}
	NodeCompletedLoan* prev = nullptr;
	NodeCompletedLoan* current = L->head;
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
	destroyNodeCompletedLoan(current);
	L->size--;
	return 1;
}
StructLoan getCompletedLoan(const ListCompletedLoans& L, int pos) {
	StructLoan s = {};
	if (ListCompletedLoansisEmpty(L)) {
		cerr << "\nListCompletedLoans is empty\n";
		return s;
	}
	if (pos < 1 || pos > L.size) {
		cerr << "\nInvalid position\n";
		return s;
	}


	NodeCompletedLoan* current = L.head;
	for (int i = 1; i < pos; i++) {
		current = current->next;
	}

	return current->data;
}


ListCompletedLoans createListCompletedLoans() {
	return ListCompletedLoans{ nullptr, 0 };
}


void destroyListCompletedLoans(ListCompletedLoans* L) {
	if (!L) return;
	NodeCompletedLoan* current = L->head;
	while (current) {
		NodeCompletedLoan* temp = current;
		current = current->next;
		destroyNodeCompletedLoan(temp);
	}
	L->head = nullptr;
	L->size = 0;
}


void displayListCompletedLoans(const ListCompletedLoans& L) {
	if (ListCompletedLoansisEmpty(L)) {
		cout << "List is empty\n";
		return;
	}
	NodeCompletedLoan* current = L.head;
	while (current != nullptr) {
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



ListCompletedLoans CopyListCompletedLoans(const ListCompletedLoans& L) {
	ListCompletedLoans newListCompletedLoans = createListCompletedLoans();
	NodeCompletedLoan* current = L.head;
	NodeCompletedLoan* tail = nullptr;

	while (current) {
		NodeCompletedLoan* n = createNodeCompletedLoan(current->data);
		if (!n) {

			cerr << "\nMemory allocation failed while copying\n";
			destroyListCompletedLoans(&newListCompletedLoans);
			return createListCompletedLoans();
		}

		if (!newListCompletedLoans.head) {
			newListCompletedLoans.head = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	newListCompletedLoans.size = L.size;
	return newListCompletedLoans;
}



bool CompareListCompletedLoans(const ListCompletedLoans& L1, const ListCompletedLoans& L2) {
	if (L1.size != L2.size) return false;

	NodeCompletedLoan* p1 = L1.head;
	NodeCompletedLoan* p2 = L2.head;

	while (p1) {
		if (p1->data.LoanID != p2->data.LoanID)return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}
