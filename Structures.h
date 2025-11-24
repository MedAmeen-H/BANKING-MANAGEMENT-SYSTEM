#pragma once
#ifndef STRUCTURES_H
#define STRUCTURES_H 
#include <string>
using namespace std;
struct StructEmployee {
    string ID;
    string name;
    string LastName;
    string adress;
    float salary;
    string HireDate;
    int BankBranch;
};
struct StructTransaction {
    string TransactionID;
    string AccNum;
    string Type;
    float amount;
    string date;
};
struct StructLoan {
    string LoanID;
    string LoanType;
    float principalAmount;
    float interestRate;
    float AmountPaid;
    float remainingBalance;
    string startDate;
    string endDate;
    string LoanStatus;
};
struct StructCustomer {
    string AccNum;
    string AccType;
    string IBAN;
    int BrancheCode;
    string name;
    string date;
    string status;
    float balance;
};

#endif
