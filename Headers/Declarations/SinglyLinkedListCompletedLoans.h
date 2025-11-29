#pragma once
#ifndef SINGLYLINKEDLISTCOMPLETEDLOANS_H
#define SINGLYLINKEDLISTCOMPLETEDLOANS_H
#include<iostream>
#include "StructLoan.h"
using namespace std;
struct NodeCompletedLoan {
	Loan data;
	NodeCompletedLoan* next;
};

struct ListCompletedLoans {
	NodeCompletedLoan* head;
	int size;
};

#endif

