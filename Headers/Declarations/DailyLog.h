#ifndef STACKALLTRANSACTIONS_H
#define STACKALLTRANSACTIONS_H
#include<iostream>
#include "StructTransaction.h"
using namespace std;
struct aDailyTransaction {
	Transaction data;
	aDailyTransaction* next;
};

struct DailyLogStack {
	aDailyTransaction* Top;
};

#endif

