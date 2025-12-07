#pragma once
#ifndef STATISTICSMETH_H
#define STATISTICSMETH_H
#include "StructTransaction.h"
#include "LoansDoublyLinkedListMeth.h"
#include "EmployeesArrayMeth.h"
#include "CustomersSinglyLinkedListMeth.h"
bool isEarlier(const Date& d1, const Date& d2);

StructEmployee MostRecentlyHiredEmployee(const EmployeesList& L);
StructEmployee EarliestHiredEmployee(const EmployeesList& L);

int compareDates(Date d1, Date d2);
bool range(string date, string start, string end);

ListLoan ActiveLoans(ListCustomers c, Date start, Date end);

int TotalLoansByCust(const ListLoan& L);
int TotalLoans(const ListCustomers& L);
int NumberOfCompletedLoans(const ListCustomers& L);
int EmployeesPerBranch(const EmployeesList& L,string b);
int NumberOfLoansByTypeByCust(const ListLoan& L, string T);
int NumberOfLoansByType(const ListCustomers& L, string T);

int NumberOfLoansByStatusByCust(const ListLoan& L, string T);
int NumberOfLoansByStatus(const ListCustomers& L, string T);

StructCustomer CustomerWithHighestLoanNumber(const ListCustomers& C);
StructCustomer CustomerWithHighestAccountBalance(const ListCustomers& C);
StructCustomer CustomerWithLowestAccountBalance(const ListCustomers& C);

#endif
