#include "DailyLogMeth.h"
#include <iostream>
using namespace std;


aDailyTransaction* CreateADailyTransaction(Transaction value) {
	aDailyTransaction* node = new (nothrow) aDailyTransaction{ value, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}


void DestroyATransaction(aDailyTransaction* node) {
	delete node;
}


bool DailyLogStackEmpty(const DailyLogStack& Stack) {
	return Stack.Top == nullptr;
}

int DailyLogSize(const DailyLogStack& Stack) {
	int size = 0;
	aDailyTransaction* n = Stack.Top;
	while (n != nullptr) {
		size++;
		n = n->next;
	}
	return size;
}

bool DailyLogStackFull(const DailyLogStack& Stack) {
	aDailyTransaction* test = new (nothrow) aDailyTransaction;
	if (!test) return true;
	delete test;
	return false;
}


int PushTransaction(DailyLogStack* Stack, Transaction e) {
	if (!Stack) return 0;
	if (DailyLogStackFull(*Stack)) return 0;
	aDailyTransaction* n = CreateADailyTransaction(e);
	n->next = Stack->Top;
	Stack->Top = n;
	return 1;
}


Transaction PopTransaction(DailyLogStack* Stack) {
	if (!Stack || DailyLogStackEmpty(*Stack)) {
		cerr << "\nStack is empty";
		return {};
	}
	aDailyTransaction* TOP = Stack->Top;
	Transaction e = TOP->data;
	Stack->Top = Stack->Top->next;
	DestroyATransaction(TOP);
	return (e);
}

DailyLogStack CreateDailyLogStack() {
	DailyLogStack* S = new (nothrow) DailyLogStack;
	if (!S) {
		cout << "\nError: unable to allocate memory";
	}
	else {
		S->Top = nullptr;
	}
	return *S;
}


void DestroyDailyLogStack(DailyLogStack* Stack) {
	aDailyTransaction* n = Stack->Top;
	while (n != nullptr) {
		Stack->Top = n->next; 
		DestroyATransaction(n); 
		n = Stack->Top; 
	}
	delete Stack;
}


void DisplayDailyLog(const DailyLogStack& Stack) {
	if (DailyLogStackEmpty(Stack)) {
		cout << "List is empty\n";
		return;
	}
	aDailyTransaction* current = Stack.Top;
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



DailyLogStack CopyDailyLog(const DailyLogStack& Stack) {
	DailyLogStack newStackAllTransactions = CreateDailyLogStack();
	aDailyTransaction* current = Stack.Top;
	aDailyTransaction* tail = nullptr;

	while (current) {
		aDailyTransaction* n = CreateADailyTransaction(current->data);
		if (!n) {

			cerr << "\nMemory allocation failed while copying\n";
			DestroyDailyLogStack(&newStackAllTransactions);
			return CreateDailyLogStack();
		}

		if (!newStackAllTransactions.Top) {
			newStackAllTransactions.Top = n;
			tail = n;
		}
		else {
			tail->next = n;
			tail = n;
		}
		current = current->next;
	}
	return newStackAllTransactions;
}



bool CompareDailyLogs(const DailyLogStack& L1, const DailyLogStack& L2) {
	if (DailyLogSize(L1) != DailyLogSize(L2)) return false;
	aDailyTransaction* p1 = L1.Top;
	aDailyTransaction* p2 = L2.Top;

	while (p1!=nullptr) {
		if (p1->data.TransactionID != p2->data.TransactionID)return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}
