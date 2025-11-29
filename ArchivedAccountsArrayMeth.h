#ifndef ARCHIVEDACCOUNTSARRAYMETH_H
#define ARCHIVEDACCOUNTSARRAYMETH_H
#include "ArchivedAccountsArray.h"
#include <string>
using namespace std;

ArchivedAccsList createArchivedAccsList();
bool ArchivedAccsListisEmpty(const ArchivedAccsList& L);
bool ArchivedAccsListisFull(const ArchivedAccsList& L);
int ArchivedAccsListSize(const ArchivedAccsList& L);

int insertArchivedAcc(ArchivedAccsList* L,StructCustomer e, int pos);
int removeArchivedAccAt(ArchivedAccsList* L, int pos);
StructCustomer getArchivedAcc(const ArchivedAccsList& L, int pos);
string displayArchivedAccsList(const ArchivedAccsList& L);

ArchivedAccsList CopyArchivedAccsList(const ArchivedAccsList& L);
bool CompareArchivedAccsLists(const ArchivedAccsList& L1, const ArchivedAccsList& L2);


#endif // ARCHIVEDACCOUNTSARRAYMETH_H
