#ifndef ARCHIVEDACCOUNTSARRAY_H
#define ARCHIVEDACCOUNTSARRAY_H
#include "StructCustomer.h"
#include <iostream>
using namespace std;
constexpr int Max=100;
struct ArchivedAccsList {
    StructCustomer elements[Max];
    int size;
};
#endif // ARCHIVEDACCOUNTSARRAY_H
