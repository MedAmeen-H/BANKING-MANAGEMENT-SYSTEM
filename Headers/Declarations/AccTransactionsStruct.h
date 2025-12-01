#ifndef ACCTRANSACTIONSSTACK_H
#define ACCTRANSACTIONSSTACK_H
#include "StructTransaction.h"
constexpr int Max = 100;
struct AccTransactionsStack {
	StructTransaction elements[Max];
	int Top;
};
#endif
