#include "EmployeesArrayMeth.h"
#include <iostream>
#include <string>


EmployeesList createEmployeesList() {
    EmployeesList L;
    L.size = 0;
    return L;
}

bool EmployeesListisEmpty(const EmployeesList& L) {
    return L.size == 0;
}

bool EmployeesListisFull(const EmployeesList& L) {
    return L.size == Max;
}

int EmployeesListSize(const EmployeesList& L) {
    return L.size;
}

int insertEmployee(EmployeesList* L, StructEmployee e, int pos) {
    if (EmployeesListisFull(*L)) {
        cout << "No memory space";
        return 0;
    }
    if (pos < 0 || pos> L->size) {
        cout << "Invalid position";
        return 0;
    }

    for (int i = L->size; i > pos; i--) {
        L->elements[i] = L->elements[i - 1];
    }
    L->elements[pos] = e;
    L->size++;
    return 1;
}

int removeEmployeeAt(EmployeesList* L, int pos) {
    if (EmployeesListisEmpty(*L)) {
        cout << "Empty EmployeesList";
        return 0;
    }
    if (pos<0 || pos>L->size) {
        cout << " invalid position";
        return 0;
    }
    for (int i = pos; i < L->size - 1; i++)
        L->elements[i] = L->elements[i + 1];
    L->size--;
    return 1;
}

StructEmployee getEmployee(const EmployeesList& L, int pos) {
    StructEmployee e = {};
    if (EmployeesListisEmpty(L)) {
        cout <<"EmployeesList is empty";
        return e;
    }
    if (pos<0 || pos>= L.size) { //0 -> size-1
        cout << "invalid position";
        return e;
    }
    return L.elements[pos];
}

string displayEmployeesList(const EmployeesList& L) {
    string ch="";
    if (EmployeesListisEmpty(L)) return "EmployeesList is empty! ";
    if (!EmployeesListisEmpty(L)) {
            for (int i = 0; i < L.size; i++){
                ch=ch+L.elements[i].ID+"\n";}
        }return ch;
}

EmployeesList CopyEmployeesList(const EmployeesList& L) {
    EmployeesList L2 = createEmployeesList();
    for (int i = 0; i < L.size; i++)
        insertEmployee(&L2, L.elements[i], i);
    return L2;
}
bool CompareEmployeesLists(const EmployeesList& L1, const EmployeesList& L2) {
    if (EmployeesListSize(L1) != EmployeesListSize(L2))
        return false;
    for (int i = 0; i < L1.size; i++)
    {
        if (L1.elements[i].ID != L2.elements[i].ID)
            return false;
    }
    return true;
}
