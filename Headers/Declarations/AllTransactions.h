#pragma once
#ifndef ALLTRANSACTIONS_H
#define ALLTRANSACTIONS_H
#include<iostream>
#include "StructTransaction.h"
using namespace std;
struct NodeAllTransactions {
	StructTransaction data;
	NodeAllTransactions* next;
};

struct ListAllTransactions {
	NodeAllTransactions* head;
	int size;
};

#endif
