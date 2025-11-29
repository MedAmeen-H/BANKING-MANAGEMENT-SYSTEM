#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "StructLoan.h"
struct NodeLoan {
	Loan data;
	NodeLoan* next;
	NodeLoan* prev;
};
struct ListLoan {
	NodeLoan* head;
	NodeLoan* tail;
	int size;
};
#endif

