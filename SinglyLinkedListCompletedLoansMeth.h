#pragma once
#ifndef SINGLYLINKEDLISTCOMPLETEDLOANS_METH_H
#define SINGLYLINKEDLISTCOMPLETEDLOANS_METH_H
#include "SinglyLinkedListCompletedLoans.h"
NodeCompletedLoan* createNodeCompletedLoan(StructLoan value);
void destroyNodeCompletedLoan(NodeCompletedLoan* node);

ListCompletedLoans createListCompletedLoans();
void destroyListCompletedLoans(ListCompletedLoans* L);
bool ListCompletedLoansisEmpty(const ListCompletedLoans& L);
bool ListCompletedLoansisFull(const ListCompletedLoans& L);
int ListCompletedLoansSize(const ListCompletedLoans& L);

int InsertCompletedLoan(ListCompletedLoans* L, StructLoan e, int pos);
int removeCompletedLoanAt(ListCompletedLoans* L, int pos);
StructLoan getCompletedLoan(const ListCompletedLoans& L, int pos);
void displayListCompletedLoans(const ListCompletedLoans& L);

ListCompletedLoans CopyListCompletedLoans(const ListCompletedLoans& L);
bool CompareListCompletedLoans(const ListCompletedLoans& L1, const ListCompletedLoans& L2);


#endif