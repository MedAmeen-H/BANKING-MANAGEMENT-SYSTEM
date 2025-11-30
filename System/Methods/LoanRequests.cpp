#include<iostream>
#include "LoanRequestsMeth.h"
using namespace std;

Queue* CreateQueue() {
	Queue* Q = new (nothrow) Queue;
	if (!Q) {
		cout << "\nError: unable to allocate memory";
	}
	else {
		Q->Front = 0;
		Q->Tail = 0;
	}
	return Q;
}

void DestroyQueue(Queue* Q) {delete Q;}

void DisplayQueue(const Queue& Q) {
	for (int i = Q.Front; i <= Q.Tail; i++) {
		cout << Q.elements[i].AccNum << "\n";
		cout << Q.elements[i].LoanType << "\n";
		cout << Q.elements[i].Status << "\n";
		cout << Q.elements[i].Amount << "\n";
		cout << Q.elements[i].EndDate << "\n";
	}
	cout << endl;
}

bool isEmptyQueue(const Queue& Q) {
	return (Q.Front == 0);
}

bool isFullQueue(const Queue& Q) {
	return (Q.Tail == Max - 1);
}

int QueueSize(const Queue& Q) {
	if (isEmptyQueue(Q)) return 0;
	return Q.Tail - Q.Front;
}

int QueueLoan(Queue* Q, Loan L) {
	if (isFullQueue(*Q)) {
		cout << "\nQueue is full";
		return 0;
	}
	if (isEmptyQueue(*Q)) {
		Q->Front = 1;
		Q->Tail = 1;
	}
	else {
		Q->Tail++;
	}
	Q->elements[Q->Tail] = L;
	return 1;
}

Loan DequeueLoan(Queue* Q) {
	if (isEmptyQueue(*Q)) {
		cout << "\nQueue is empty";
		return {};
	}
	Loan e = Q->elements[Q->Front];
	if (Q->Front == Q->Tail) {
		Q->Front = 0;
		Q->Tail = 0;
	}
	else {
		Q->Front++;
	}
	return e;
}

Loan FrontElement(const Queue& Q) {
	if (isEmptyQueue(Q)) {
		cout << "\nQueue is empty";
		return {};
	}
	return Q.elements[Q.Front];
}

Queue* CopyQueue(const Queue& Q) {
	Queue* newQ = CreateQueue();
	for (int i = Q.Front; i <= Q.Tail; i++) {
		QueueLoan(newQ, Q.elements[i]);
	}
	return newQ;
}

bool CompareQueues(const Queue& Q1, const Queue& Q2) {
	if (QueueSize(Q1) != QueueSize(Q2)) return false;
	int i1 = Q1.Front;
	int i2 = Q2.Front;
	while (i1 <= Q1.Tail) {
		if (Q1.elements[i1].AccNum != Q2.elements[i2].AccNum) return false;
		if (Q1.elements[i1].LoanType != Q2.elements[i2].LoanType) return false;
		if (Q1.elements[i1].Status != Q2.elements[i2].Status) return false;
		if (Q1.elements[i1].EndDate != Q2.elements[i2].EndDate) return false;
		if (Q1.elements[i1].Amount != Q2.elements[i2].Amount) return false;
		i1++;
		i2++;
	}
	return true;
}
