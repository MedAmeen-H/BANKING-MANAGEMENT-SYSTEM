#ifndef LOANREQUESTS_H
#define LOANREQUESTS_H
#include "StructLoan.h"
constexpr int Max = 100;
struct Queue {
	Loan elements[Max];
	int Front; 
	int Tail; 
};
#endif
