#include "ArchivedAccountsArrayMeth.h"
#include <iostream>
#include <string>
using namespace std;


ArchivedAccsList createArchivedAccsList() {
    ArchivedAccsList L;
    L.size = 0;
    return L;
}

bool ArchivedAccsListisEmpty(const ArchivedAccsList& L) {
    return L.size == 0;
}

bool ArchivedAccsListisFull(const ArchivedAccsList& L) {
    return L.size == Max;
}

int ArchivedAccsListSize(const ArchivedAccsList& L) {
    return L.size;
}

int insertArchivedAcc(ArchivedAccsList* L, StructCustomer e, int pos) {
    if (ArchivedAccsListisFull(*L)) {
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

int removeArchivedAccAt(ArchivedAccsList* L, int pos) {
    if (ArchivedAccsListisEmpty(*L)) {
        cout << "Empty ArchivedAccsList";
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

StructCustomer getArchivedAcc(const ArchivedAccsList& L, int pos) {
    StructCustomer e = {};
    if (ArchivedAccsListisEmpty(L)) {
        cout <<"ArchivedAccsList is empty";
        return e;
    }
    if (pos<0 || pos>= L.size) {
        cout << "invalid position";
        return e;
    }
    return L.elements[pos];
}

string displayArchivedAccsList(const ArchivedAccsList& L) {
    string ch="";
    if (ArchivedAccsListisEmpty(L)) return "ArchivedAccsList is empty! ";
    if (!ArchivedAccsListisEmpty(L)) {
        for (int i = 0; i < L.size; i++){
            ch=ch+L.elements[i].AccNum+"\n";}
    }return ch;
}

ArchivedAccsList CopyArchivedAccsList(const ArchivedAccsList& L) {
    ArchivedAccsList L2 = createArchivedAccsList();
    for (int i = 0; i < L.size; i++)
        insertArchivedAcc(&L2, L.elements[i], i);
    return L2;
}
bool CompareArchivedAccsLists(const ArchivedAccsList& L1, const ArchivedAccsList& L2) {
    if (ArchivedAccsListSize(L1) != ArchivedAccsListSize(L2))
        return false;
    for (int i = 0; i < L1.size; i++)
    {
        if (L1.elements[i].AccNum != L2.elements[i].AccNum)
            return false;
    }
    return true;
}


