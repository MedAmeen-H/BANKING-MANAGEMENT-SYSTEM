#pragma once
#ifndef SINGLYLINKEDLISTCOMPLETEDLOANS_H
#define SINGLYLINKEDLISTCOMPLETEDLOANS_H
#include<iostream>
#include "structures.h"
using namespace std;
struct NodeCompletedLoan {
	StructLoan data;
	NodeCompletedLoan* next;
};

struct ListCompletedLoans {
	NodeCompletedLoan* head;
	int size;
};

#endif