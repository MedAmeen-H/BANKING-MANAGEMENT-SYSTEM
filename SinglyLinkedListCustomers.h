#pragma once
#ifndef SINGLYLINKEDListCustomers_H
#define SINGLYLINKEDListCustomers_H
#include<iostream>
#include "structures.h"
using namespace std;
struct NodeCustomer {
	StructCustomer data;
	NodeCustomer* next;
};

struct ListCustomers {
	NodeCustomer* head;
	int size;
};

#endif