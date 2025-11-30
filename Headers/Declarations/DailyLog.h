#ifndef DAILYLOG_H
#define DAILYLOG_H
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


