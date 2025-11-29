#pragma once
#ifndef STACKALLTRANSACTIONS_METH_H
#define STACKALLTRANSACTIONS_METH_H
#include "StackAllTransactions.h"
NodeAllTransactions* createNodeAllTransactions(Transaction value);
void destroyNodeAllTransactions(NodeAllTransactions* node);
StackAllTransactions createStackAllTransactions();
void destroyStackAllTransactions(StackAllTransactions* L);
bool StackAllTransactionsisEmpty(const StackAllTransactions& L);
bool StackAllTransactionsisFull(const StackAllTransactions& L);
int StackAllTransactionsSize(const StackAllTransactions& L);
int InsertAllTransaction(StackAllTransactions* L, Transaction e, int pos);
int removeAllTransactionAt(StackAllTransactions* L, int pos);
Transaction getAllTransaction(const StackAllTransactions& L, int pos);
void displayStackAllTransactions(const StackAllTransactions& L);
StackAllTransactions CopyStackAllTransactions(const StackAllTransactions& L);
bool CompareStackAllTransactions(const StackAllTransactions& L1, const StackAllTransactions& L2);
#endif
