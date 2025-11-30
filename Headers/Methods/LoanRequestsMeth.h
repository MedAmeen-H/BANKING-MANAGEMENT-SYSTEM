#ifndef LOANREQUESTSMETH_H
#define LOANREQUESTSMETH_H
#include "LoanRequests.h"
Queue* CreateQueue();
void DestroyQueue(Queue* Q);
void DisplayQueue(const Queue& Q);
bool isEmptyQueue(const Queue& Q);
bool isFullQueue(const Queue& Q);
int QueueSize(const Queue& Q);
int QueueLoan(Queue* Q, Loan L);
Loan DequeueLoan(Queue* Q);
Loan FrontElement(const Queue& Q);
Queue* CopyQueue(const Queue& Q);
bool CompareQueues(const Queue& Q1, const Queue& Q2);
#endif
