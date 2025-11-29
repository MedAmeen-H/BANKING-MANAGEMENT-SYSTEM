#pragma once
#ifndef SINGLYLINKEDLISTCUSTOMERSMETH_H
#define SINGLYLINKEDLISTCUSTOMERSMETH_H

#include "SinglyLinkedListCustomers.h"

NodeCustomer* createNodeCustomer(Customer value);
void destroyNodeCustomer(NodeCustomer* node);

ListCustomers createListCustomers();
void destroyListCustomers(ListCustomers* L);
bool ListCustomersisEmpty(const ListCustomers& L);
bool ListCustomersisFull(const ListCustomers& L);
int ListCustomersSize(const ListCustomers& L);

int InsertCustomer(ListCustomers* L, Customer e, int pos);
int removeCustomerAt(ListCustomers* L, int pos);
Customer getCustomer(const ListCustomers& L, int pos);
void displayListCustomers(const ListCustomers& L);

ListCustomers CopyListCustomers(const ListCustomers& L);
bool CompareListCustomers(const ListCustomers& L1, const ListCustomers& L2);


#endif 


