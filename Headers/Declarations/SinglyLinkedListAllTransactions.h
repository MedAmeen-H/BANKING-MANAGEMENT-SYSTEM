#pragma once
#ifndef SINGLYLINKEDLISTALLTRANSACTIONS_H
#define SINGLYLINKEDLISTALLTRANSACTIONS_H
#include<iostream>
#include "StructTransaction.h"
using namespace std;
struct NodeAllTransactions {
	Transaction data;
	NodeAllTransactions* next;
};

struct ListAllTransactions {
	NodeAllTransactions* head;
	int size;
};

#endif

