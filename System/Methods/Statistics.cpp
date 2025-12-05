#include "../Declarations/Statistics.h"
#include "../Declarations/StructEmployee.h"
#include <iostream>

bool range(string date, string start, string end)
{
    return (date >= start && date <= end);
}
int TotalLoans(StructCustomer** Customer, int size)
{
    int total = 0;

    for (int i = 0; i < size; i++) {
        if (Customer[i])
            total += Customer[i]->Loans.size;
    }
    return total;
}

void LoansByType(StructCustomer** Customer, int size,int& carCount, int& homeCount,int& studentCount, int& businessCount)
{
    carCount = homeCount = studentCount = businessCount = 0;

    for (int i = 0; i < size; i++) {
        if (Customer[i]) {
            NodeLoan* node = Customer[i]->Loans.head;

        while (node) {
            if (node->data.LoanType == "car") carCount++;
            else if (node->data.LoanType == "home") homeCount++;
            else if (node->data.LoanType == "student") studentCount++;
            else if (node->data.LoanType == "business") businessCount++;
            node = node->next;
        }
        }
    }
}
void LoansByStatus(StructCustomer** Customer, int size,
    int& activeCount, int& completedCount, int& overdueCount)
{
    activeCount = completedCount = overdueCount = 0;

    for (int i = 0; i < size; i++) {
        NodeLoan* node = Customer[i]->Loans.head;

        while (node) {
            if (node->data.LoanStatus == "active") activeCount++;
            else if (node->data.LoanStatus == "completed") completedCount++;
            else if (node->data.LoanStatus == "overdue") overdueCount++;

            node = node->next;
        }
    }
}
int ActiveLoans(StructCustomer** Customer, int size, string start, string end)
{
    int total = 0;

    for (int i = 0; i < size; i++) {
        NodeLoan* node = Customer[i]->Loans.head;

        while (node) {
            if (node->data.LoanStatus == "active" && range(node->data.StartDate, start, end))
            {
                total++;
            }
            node = node->next;
        }
    }
    return total;
}
StructCustomer* CustomerWithMostLoans(StructCustomer** Customer, int size)
{
    if (size == 0) return nullptr;

    StructCustomer* best = Customer[0];
    int maxLoans = Customer[0]->Loans.size;

    for (int i = 1; i < size; i++) {
        if (Customer[i]->Loans.size > maxLoans) {
            maxLoans = Customer[i]->Loans.size;
            best = Customer[i];
        }
    }
    return best;
}


StructCustomer* CustomerWithHighestBalance(StructCustomer** Customer, int size)
{
    if (size == 0) return nullptr;

    StructCustomer* best = Customer[0];

    for (int i = 1; i < size; i++) {
        if (Customer[i]->balance > best->balance)
            best = Customer[i];
    }
    return best;
}

StructCustomer* CustomerWithLowestBalance(StructCustomer** Customer, int size)
{
    if (size == 0) return nullptr;

    StructCustomer* worst = Customer[0];

    for (int i = 1; i < size; i++) {
        if (Customer[i]->balance < worst->balance)
            worst = Customer[i];
    }
    return worst;
}
int TotalEmployees(StructEmployee* employees, int size)
{
    return size;
}

void EmployeesPerBranch(StructEmployee* employees, int size,
    int* branchCounts, int maxBranch)
{
    for (int i = 0; i < maxBranch; i++)
        branchCounts[i] = 0;

    for (int i = 0; i < size; i++) {
        int b = employees[i].BankBranch;
        if (b >= 0 && b < maxBranch)
            branchCounts[b]++;
    }
}
