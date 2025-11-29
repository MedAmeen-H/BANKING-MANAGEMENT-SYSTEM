#pragma once
#ifndef ACCTRANSACTIONSSTACKMETH_H
#define ACCTRANSACTIONSSTACKMETH_H
#include "AccTransactionsStack.h"
AccTransactionsStack* createAccTransactionsStack();
void destroyAccTransactionsStack(AccTransactionsStack* P);
bool AccTransactionsStackisEmpty(const AccTransactionsStack& S);
bool AccTransactionsStackisFull(const AccTransactionsStack& S);
int AccTransactionsStackSize(const AccTransactionsStack& S);
void PushAccTransactionsStack(AccTransactionsStack* S, int e);
StructTransaction PopAccTransactionsStack(AccTransactionsStack* S);
StructTransaction TopAccTransactionsStack(const AccTransactionsStack& S);
void displayAccTransactionsStack(const AccTransactionsStack& S);
AccTransactionsStack* CopyAccTransactionsStack(const AccTransactionsStack& S);
bool CompareAccTransactionsStacks(const AccTransactionsStack& S1, const AccTransactionsStack& S2);
#endif 
