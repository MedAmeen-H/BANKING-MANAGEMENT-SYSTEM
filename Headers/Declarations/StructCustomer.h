#pragma once
#ifndef STRUCTCUSTOMER_H
#define STRUCTCUSTOMER_H
#include "DoublyLinkedListLoansMeth.h"
#include "AccTransactionsStackMeth.h"
#include <string>
using namespace std;
struct Customer {
    string AccNum;
    string AccType;
    string IBAN;
    int BrancheCode;
    string name;
    string date;
    string status;
    float balance;
    ListLoan Loans;
    AccTransactionsStack Transactions;
};

#endif
