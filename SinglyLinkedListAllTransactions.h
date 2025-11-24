#pragma once
#ifndef SINGLYLINKEDLISTALLTRANSACTIONS_H
#define SINGLYLINKEDLISTALLTRANSACTIONS_H
#include<iostream>
#include "structures.h"
using namespace std;
struct NodeAllTransactions {
	StructTransaction data;
	NodeAllTransactions* next;
};

struct ListAllTransactions {
	NodeAllTransactions* head;
	int size;
};

#endif