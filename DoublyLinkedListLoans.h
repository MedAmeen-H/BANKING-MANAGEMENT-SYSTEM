#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Structures.h"
struct NodeLoan {
	StructLoan data;
	NodeLoan* next;
	NodeLoan* prev;
};
struct ListLoan {
	NodeLoan* head;
	NodeLoan* tail;
	int size;
};
#endif