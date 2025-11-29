#pragma once
#ifndef SINGLYLINKEDLISTCUSTOMERS_H
#define SINGLYLINKEDLISTCUSTOMERS_H
#include<iostream>
#include "StructCustomer.h"
using namespace std;
struct NodeCustomer {
	Customer data;
	NodeCustomer* next;
};

struct ListCustomers {
	NodeCustomer* head;
	int size;
};

#endif


