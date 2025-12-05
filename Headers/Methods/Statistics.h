#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include "StructCustomer.h"
#include "StructEmployee.h"

using namespace std;
int TotalLoans(StructCustomer** Customers, int size);
void LoansByType(StructCustomer** Customers, int size,
int& carCount, int& homeCount,
int& studentCount, int& businessCount);
void LoansByStatus(StructCustomer** Customers, int size,
int& activeCount, int& completedCount, int& overdueCount);
int ActiveLoans(StructCustomer** Customers, int size, string start, string end);
StructCustomer* CustomerWithMostLoans(StructCustomer** Customers, int size);
StructCustomer* CustomerWithHighestBalance(StructCustomer** Customers, int size);
StructCustomer* CustomerWithLowestBalance(StructCustomer** Customers, int size);
int Totalployees(StructEmployee* Employees, int size);
void EmployeesPerBranch(StructEmployee* Employees, int size,int* branchCounts, int branchLimit);
StructEmployee EarliestHiredEmployee(StructEmployee* Employees, int size);
StructEmployee MostRecentHiredEmployee(StructEmployee* Employees, int size);
#endif

