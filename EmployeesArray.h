#pragma once
#ifndef EMPLOYEESARRAY_H
#define EMPLOYEESARRAY_H
#include "StructEmployee.h"
#include <iostream>
using namespace std;
constexpr int Max=100;
struct EmployeesList {
    StructEmployee elements[Max];
    int size;
};

#endif // EMPLOYEESARRAY_H
