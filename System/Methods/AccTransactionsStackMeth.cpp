#include <iostream>
using namespace std;
#include "AccTransactionsStackMeth.h"
AccTransactionsStack* createAccTransactionsStack() {
	AccTransactionsStack* S = new (nothrow) AccTransactionsStack;
	if (!S) {
		cerr << "\nMEMORY ALLOCATION FAILED FOR STACK\n";
	}
	S->Top = {};
	return S;
}
void destroyAccTransactionsStack(AccTransactionsStack* P) {
	delete P;
}
bool AccTransactionsStackisEmpty(const AccTransactionsStack& S) {
	return S.Top == -1;
}
bool AccTransactionsStackisFull(const AccTransactionsStack& S) {
	return S.Top == Max - 1;
}
int AccTransactionsStackSize(const AccTransactionsStack& S) {
	return S.Top;
}
void PushAccTransactionsStack(AccTransactionsStack* S, StructTransaction e) {
	if (AccTransactionsStackisFull(*S)) {
		cout << "Stack is full!! Cannot push this transaction!! "<< endl;
		return;
	}
	S->elements[(S->Top) + 1] = e;
}
StructTransaction PopAccTransactionsStack(AccTransactionsStack* S) {
	if (AccTransactionsStackisEmpty(*S)) {
		cout << "Stack is empty!! Cannot pop" << endl;
		return {};
	}
	return S->elements[(S->Top)--];
}
StructTransaction TopAccTransactionsStack(const AccTransactionsStack& S) {
	if (AccTransactionsStackisEmpty(S)) {
		cout << "Stack is empty!! Cannot retrieve top element" << endl;
		return {};
	}
	return S.elements[S.Top];
}
void displayAccTransactionsStack(const AccTransactionsStack& S) {
	if (AccTransactionsStackisEmpty(S)) {
		cout << "Stack is empty!! Nothing to display" << endl;
		return;
	}
	cout << "Stack elements: ";
	for (int i = S.Top; i >= 0; i--) {
		cout << "Transaction "<< (S.Top)-i+1<<":"<< endl;
		cout << "Transaction ID: "<< S.elements[i].TransactionID << endl;
		cout << "Account Number: " << S.elements[i].AccNum << endl;
		cout << "Type: " << S.elements[i].Type << endl;
		cout << "Amount: " << S.elements[i].amount << endl;
		cout << "Date: " << S.elements[i].date << endl;
	}
}
AccTransactionsStack* CopyAccTransactionsStack(const AccTransactionsStack& S) {
	if (AccTransactionsStackisEmpty(S)) {
		cout << "Stack is empty!! Nothing to copy" << endl;
		return nullptr;
	}
	AccTransactionsStack* newStack = createAccTransactionsStack();
	if (!newStack) {
		cout << "Memory allocation failed!!" << endl;
		return nullptr;
	}
	for (int i = 0; i <= S.Top; i++) {
		PushAccTransactionsStack(newStack, S.elements[i]);
	}
	return newStack;
}
bool CompareAccTransactionsStacks(const AccTransactionsStack& S1, const AccTransactionsStack& S2) {
	if (S1.Top != S2.Top) return false;
	for (int i = 0; i <= S1.Top; i++) {
		if (S1.elements[i].TransactionID != S2.elements[i].TransactionID) return false;
	}
	return true;
}
