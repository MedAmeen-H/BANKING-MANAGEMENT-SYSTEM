#pragma once
#ifndef SINGLYLINKEDLISTCUSTOMER_H
#define SINGLYLINKEDLISTCUSTOMER_H
#include <list>
#include "StructCustomer.h"
using namespace std;
Struct NodeCustomer{
  Customer data;
  NodeCustomer* next;
}
Struct ListCustomers{
  NodeCustomer* head;
  int Size;
}
#endif



