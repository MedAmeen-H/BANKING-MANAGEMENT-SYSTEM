#pragma once
#ifndef SINGLYLINKEDLISTALLTRANSACTIONS_METH_H
#define SINGLYLINKEDLISTALLTRANSACTIONS_METH_H
#include "SinglyLinkedListAllTransactions.h"
NodeAllTransactions* createNodeAllTransactions(StructTransaction value);
void destroyNodeAllTransactions(NodeAllTransactions* node);
ListAllTransactions createListAllTransactions();
void destroyListAllTransactions(ListAllTransactions* L);
bool ListAllTransactionsisEmpty(const ListAllTransactions& L);
bool ListAllTransactionsisFull(const ListAllTransactions& L);
int ListAllTransactionsSize(const ListAllTransactions& L);
int InsertAllTransaction(ListAllTransactions* L, StructTransaction e, int pos);
int removeAllTransactionAt(ListAllTransactions* L, int pos);
StructTransaction getAllTransaction(const ListAllTransactions& L, int pos);
void displayListAllTransactions(const ListAllTransactions& L);
ListAllTransactions CopyListAllTransactions(const ListAllTransactions& L);
bool CompareListAllTransactions(const ListAllTransactions& L1, const ListAllTransactions& L2);


#endif
