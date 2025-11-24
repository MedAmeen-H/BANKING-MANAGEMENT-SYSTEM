#pragma once
#ifndef DOUBLYLINKEDLISTMETH_H
#define DOUBLYLINKEDLISTMETH_H
#include "DoublyLinkedListLoans.h"
NodeLoan* createNodeLoan(StructLoan data);
void destroyNodeLoan(NodeLoan* node);
ListLoan createListLoan();
void destroyListLoan(ListLoan* L);
bool ListLoanIsEmpty(const ListLoan& L);
bool ListLoanIsFull(const ListLoan& L);
int ListLoanSize(const ListLoan& L);
int insertLoan(ListLoan* L, StructLoan e, int pos);
int removeAtLoan(ListLoan* L, int pos);
StructLoan getLoan(const ListLoan& L, int pos);
void displayListLoan(const ListLoan& L);
ListLoan CopyListLoan(const ListLoan& L);
bool CompareLoanLists(const ListLoan& L1, const ListLoan& L2);
#endif
