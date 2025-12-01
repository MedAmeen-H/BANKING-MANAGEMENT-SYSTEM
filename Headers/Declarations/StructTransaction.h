#pragma once
#ifndef STRUCTTRANSACTION_H
#define STRUCTTRANSACTION_H 
#include <string>
using namespace std;
struct Transaction {
    string TransactionID;
    string AccNum;
    string Type;
    float amount;
    string date;
};
#endif
