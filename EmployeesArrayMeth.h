#pragma once
#ifndef EMPLOYEESARRAYMETH_H
#define EMPLOYEESARRAYMETH_H
#include <string>
#include "EmployeesArray.h"
using namespace std;
EmployeesList createEmployeesList();
bool EmployeesListisEmpty(const EmployeesList& L);
bool EmployeesListisFull(const EmployeesList& L);
int EmployeesListSize(const EmployeesList& L);

int insertEmployee(EmployeesList* L,StructEmployee e, int pos);
int removeEmployeeAt(EmployeesList* L, int pos);
StructEmployee getEmployee(const EmployeesList& L, int pos);
string displayEmployeesList(const EmployeesList& L);

EmployeesList CopyEmployeesList(const EmployeesList& L);
bool CompareEmployeesLists(const EmployeesList& L1, const EmployeesList& L2);


#endif // EMPLOYEESARRAYMETH_H
