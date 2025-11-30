#ifndef DAILYLOGMETH_H
#define DAILYLOGMETH_H
#include "DailyLog.h"
aDailyTransaction* CreateADailyTransaction(Transaction value);
void DestroyATransaction(aDailyTransaction* node);
DailyLogStack CreateDailyLogStack();
void DestroyDailyLogStack(DailyLogStack* Stack);
bool DailyLogStackEmpty(const DailyLogStack& Stack);
bool bool DailyLogStackFull(const DailyLogStack& Stack);
int DailyLogSize(const DailyLogStack& Stack);
int PushTransaction(DailyLogStack* Stack, Transaction e);
Transaction PopTransaction(DailyLogStack* Stack;
Transaction TopTransaction(const DailyLogStack& Stack);
void DisplayDailyLog(const DailyLogStack& Stack);
DailyLogStack CopyDailyLog(const DailyLogStack& Stack);
bool CompareDailyLogs(const DailyLogStack& L1, const DailyLogStack& L2);
#endif
