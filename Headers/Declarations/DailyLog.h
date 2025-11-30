#pragma once
#ifndef STACKALLTRANSACTIONS_H
#define STACKALLTRANSACTIONS_H
#include<iostream>
#include "StructTransaction.h"
using namespace std;
struct NodeAllTransactions {
	Transaction data;
	NodeAllTransactions* next;
};

struct StackAllTransactions {
	NodeAllTransactions* Top;
};

#endif
