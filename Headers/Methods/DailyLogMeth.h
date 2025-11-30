#pragma once
#ifndef STACKALLTRANSACTIONSMETH_H
#define STACKALLTRANSACTIONSMETH_H
#include "StackAllTransactions.h"
NodeAllTransactions* createNodeAllTransactions(Transaction value);
void destroyNodeAllTransactions(NodeAllTransactions* node);
StackAllTransactions* createStackAllTransactions();
void destroyStackAllTransactions(StackAllTransactions* Stack);
bool StackAllTransactionsisEmpty(const StackAllTransactions& Stack);
bool StackAllTransactionsisFull(const StackAllTransactions& Stack);
int StackAllTransactionsSize(const StackAllTransactions& Stack);
int PushTransaction(StackAllTransactions* Stack, Transaction e, int pos);
int PopTransactionAt(StackAllTransactions* Stack, int pos);
int TopTransaction(const StackAllTransactions& Stack);
void displayStackAllTransactions(const StackAllTransactions& Stack);
StackAllTransactions* CopyStackAllTransactions(const StackAllTransactions& Stack);
bool CompareStackAllTransactions(const StackAllTransactions& L1, const StackAllTransactions& L2);
#endif

