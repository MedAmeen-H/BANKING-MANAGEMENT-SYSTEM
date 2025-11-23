#pragma once
#ifndef SINGLYLINKEDLISTCUSTOMERSMETH_H
#define SINGLYLINKEDLISTCUSTOMERSMETH_H

#include "SinglyLinkedListCustomers.h"

NodeCustomer* createNode(StructCustomer value);
void destroyNode(NodeCustomer* node);

ListCustomers createListCustomers();
void destroyListCustomers(ListCustomers* L);
bool isEmpty(const ListCustomers& L);
bool isFull(const ListCustomers& L);
int ListCustomersSize(const ListCustomers& L);

int insert(ListCustomers* L, StructCustomer e, int pos);
int removeAt(ListCustomers* L, int pos);
StructCustomer getElement(const ListCustomers& L, int pos);
void displayListCustomers(const ListCustomers& L);

ListCustomers CopyListCustomers(const ListCustomers& L);
bool CompareListCustomers(const ListCustomers& L1, const ListCustomers& L2);

#endif // SINGLYLINKEDListCustomersMETH_H