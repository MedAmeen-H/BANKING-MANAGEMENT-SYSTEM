//Qt related
#include "mainwindow.h"
#include <QVariant>
#include "qlistwidget.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "QFlags"
#include "QFocusFrame"
#include <QPixmap>
#include <QtWidgets/QMainWindow>

//Methods Call
#include "Statistics.h"
#include "FindBy.h"
#include <iostream>
#include <string>
#include <random>
#include "autogenerator.h"
using namespace std;

string AccN;
string Loanid;
string TransId;
string InitialStatus;

Date TodaysDate={7,12,2025};
StructCustomer s=StructCustomer{};

StructTransaction Trans;
StructTransaction LastTrans;
StructTransaction NewTrans;
StructLoan FrontLoan;
NodeAllTransactions* ATrans;

StructLoan LoanReq;
StructLoan NewLoan;

NodeLoan* Loan;
NodeCompletedLoan* CompLoan;

NodeCustomer* Cust;
NodeCustomer* UserCust;

StructCustomer Arc;

StructEmployee Emp;
StructEmployee Emp2;


string EmpLN;
string EmpBb;

string Newname;
string Newlastname;
string Newaddress;
float Newsalary;



StructEmployee UserEmp;
StructEmployee NewEmp;
//For an easier way to log out you can use 1234 as ID and Bouslama as a Last Name for the employee
//1234 as an AccNum and Rihab Bouslama as a Name for the Customer



//Initial  values for loan and transactions ids,incremented with each addition
//LN216
int ID=216;
//LN320
int Id=320;
int i=0;

//The initial values of the branch codes for each bank branch,incremented with each addition
//Sf10
int bb1=10;
//Kr10
int bb2=10;
//Ss10
int bb3=10;

float AvSalary=1000;

//The List of customers and employees and archived accounts
ListCustomers L = createListCustomers();
EmployeesList El=createEmployeesList();
ArchivedAccsList AccL=createArchivedAccsList();



//Ken taayet lel Customers mataayatch lel loans khater deja included feha!!!!
//Declaration of the functions


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/Images/skb.png");
    QIcon icon(pix);

    this->setWindowTitle("SKB: Sfaxian Kairouanian Bank");
    this->setWindowIcon(icon);
    QPixmap myImage(":/images/Images/Design.png");
    ui->Design->setPixmap(myImage);
    ui->Design->setMask(myImage.mask());
    ui->Design->show();
    ui->CreateNewCustBut->hide();
    ui->DoneModifyingBut->hide();
    ui->AddEmpToListBut->hide();
    ui->DepositLab->hide();


    ui->EmpNameLe->setReadOnly(true);
    ui->EmpLastNamele->setReadOnly(true);
    ui->EmpSalaryle->setReadOnly(true);
    ui->EmpAddressle->setReadOnly(true);


    populateListCustomers();
    populateListEmployees();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::populateListCustomers()
{
    //1st Customer's initial values
    string AccNum1="AbCDEfGhJkLm";
    string IBAN1="TN3411Kr08AbCDEfGhJkLm57";
    string BrC1="Kr08";
    ListLoan ListLoansC1=createListLoan();
    cout<<"Loans"<<ListLoansC1.size;
    insertLoan(&ListLoansC1, {"LN208","Student",8000.0,3.5,1000.0,7000.0,{15, 9, 2023},{15, 9, 2027},"Overdue"},1);

    cout<<"Loans"<<ListLoansC1.size;
    insertLoan(&ListLoansC1,{"LN209","Business",1700.0,3.5,1000.0,7000.0,{15, 9, 2024},{15, 9, 2025},"Active"},2);


    Queue* ReqLoansC1=CreateQueue();
    EnqueueLoan(ReqLoansC1,{"LN210","Business",1600.0,0,0,71600.0,{0,0,0},{0, 0,0},"Pending"});
    EnqueueLoan(ReqLoansC1,{"LN211","Car",1000.0,0,0,1000,{0,0,0},{0, 0,0},"Pending"});

    ListCompletedLoans CompLoansC1=createListCompletedLoans();
    InsertCompletedLoan(&CompLoansC1,{"LN206","Business",7000.0,3.5,1000.0,7000.0,{15, 9, 2024},{15, 9, 2025},"Completed"},1);
    InsertCompletedLoan(&CompLoansC1,{"LN207","Home",5000.0,3.5,1000.0,7000.0,{15, 9, 2024},{15, 9, 2025},"Completed"},2);

    AccTransactionsStack* DailyTransC1=createAccTransactionsStack();
    PushAccTransactionsStack(DailyTransC1,{"TRX314", AccNum1, "Deposit", 1200.0, {12, 3, 2025}});
    PushAccTransactionsStack(DailyTransC1,{"TRX315", AccNum1, "Withdrawal", 300.0, {28, 1, 2025}});

    ListAllTransactions AllTransC1=createListAllTransactions();
    InsertAllTransaction(&AllTransC1,{"TRX312", AccNum1, "Withdrawal", 200.0, {12, 3, 2026}},1);
    InsertAllTransaction(&AllTransC1,{"TRX313", AccNum1, "Deposit", 1200.0, {12, 3, 2027}},2);

    InsertCustomer(&L,{AccNum1, "Savings", IBAN1, BrC1, "Sboii", {12, 3, 2024},"Active", 5400.75,ListLoansC1,ReqLoansC1,CompLoansC1,DailyTransC1,AllTransC1},L.size+1);

    //2nd Customer's Initial values
    string AccNum2="1234";
    string IBAN2="TN9111Kr09CcGhL9NQMkPz62";
    string BrC2="Kr09";

    ListLoan ListLoansC2=createListLoan();
    insertLoan(&ListLoansC2, {"LN214","Student",8000.0,3.5,1000.0,7000.0,{15, 9, 2023},{15, 9, 2027},"Overdue"},1);
    insertLoan(&ListLoansC2,{"LN215","Business",8000.0,3.5,1000.0,7000.0,{15, 9, 2024},{15, 9, 2025},"Active"},2);
    cout<<ListLoansC1.head->next->data.LoanStatus;

    Queue* ReqLoansC2=CreateQueue();
    EnqueueLoan(ReqLoansC2,{"LN216","Business",7600,0,0,71600,{0,0,0},{0, 0,0},"Pending"});
    ListCompletedLoans CompLoansC2=createListCompletedLoans();
    InsertCompletedLoan(&CompLoansC2,{"LN212","Business",8000.0,3.5,1000.0,7000.0,{15, 9, 2024},{15, 9, 2025},"Completed"},1);


    AccTransactionsStack* DailyTransC2=createAccTransactionsStack();
    PushAccTransactionsStack(DailyTransC2,{"TRX318", AccNum2, "Deposit", 1200, {12, 3, 2025}});
    PushAccTransactionsStack(DailyTransC2,{"TRX319", AccNum2, "Withdrawal", 300.0, {28, 1, 2025}});

    ListAllTransactions AllTransC2=createListAllTransactions();
    InsertAllTransaction(&AllTransC2,{"TRX316", AccNum2, "Withdrawal", 1800, {12, 3, 2026}},1);
    InsertAllTransaction(&AllTransC2,{"TRX317", AccNum2, "Deposit", 1200, {12, 3, 2027}},2);

    InsertCustomer(&L,{AccNum2, "Savings", IBAN2, BrC2, "Rihab Bouslama", {12, 3, 2024},"Active", 10000,ListLoansC2,ReqLoansC2,CompLoansC2,DailyTransC2,AllTransC2},L.size+1);

    NodeCustomer* curr=L.head;
    while(curr){
        QString CustAcc = QString::fromStdString(curr->data.AccNum);
        QListWidgetItem* item = new QListWidgetItem(CustAcc, ui->ListCustWidg);
        item->setData(Qt::UserRole, QVariant(CustAcc));
        curr=curr->next;
    }

}

void MainWindow::populateListEmployees(){
    string Emp1="FgHJKLMnpqrs";
    insertEmployee(&El,{Emp1, "Mohamed Amine", "Hammadi", "Bab Saadoun", 65000.50, {12,5,2010}, "Kairouan"},El.size);
    string Emp2="kMnpqrstuvWX";
    insertEmployee(&El,{Emp2, "Adam", "Haddaji", "Ras Tabia", 8850.50, {12,5,2012}, "Kairouan"},El.size);
    string Emp3="ZzYyXxWwVvUu";
    insertEmployee(&El,{Emp3, "Senda", "Ahmed", "Bardo 1", 1500.50, {22,9,2016}, "Sfax"},El.size);
    string Emp4="yzBC789DEFGH";
    insertEmployee(&El,{Emp4, "Lina", "Taktak", "Jardin dEl Manzah 2", 15001.50, {21,4,2006}, "Kairouan"},El.size);
    string Emp5="1234";
    insertEmployee(&El,{Emp5, "Rihab", "Bouslama", "Nasser 2", 1000.50, {21,4,2019}, "Sousse"},El.size);
    mergeSortByLastName(&El,0,El.size-1);
    for (int i=0;i<El.size;i++){
        QString EmpAcc = QString::fromStdString(El.elements[i].LastName);
        QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpLastNameWid);
        item->setData(Qt::UserRole, QVariant(EmpAcc));
    }
    for (int i=0;i<El.size;i++){
        if (El.elements[i].BankBranch=="Sfax"){
            QString EmpAcc = QString::fromStdString(El.elements[i].ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSfaxWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }
    }
    for (int i=0;i<El.size;i++){
        if (El.elements[i].BankBranch=="Kairouan"){
            QString EmpAcc = QString::fromStdString(El.elements[i].ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchKairWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }
    }
    for (int i=0;i<El.size;i++){
        if (El.elements[i].BankBranch=="Sousse"){
            QString EmpAcc = QString::fromStdString(El.elements[i].ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSousseWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }
    }
}
//Home Page Buttons
void MainWindow::on_HomePageBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}

void MainWindow::on_HomePage_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}



//Displaying the list widgets for the user who's an employee
void MainWindow::populateListWidgetLoans(){

    NodeLoan* curr=Cust->data.Loans.head;
    while(curr){
        QString LoanId = QString::fromStdString(curr->data.LoanID);
        QListWidgetItem* item = new QListWidgetItem(LoanId, ui->ListLoansWid);
        item->setData(Qt::UserRole, QVariant(LoanId));
        curr=curr->next;
    }
}

void MainWindow::populateListWidgetCompletesLoans(){

    NodeCompletedLoan* curr=Cust->data.CompletedLoans.head;
    while(curr){
        QString LoanId = QString::fromStdString(curr->data.LoanID);
        QListWidgetItem* item = new QListWidgetItem(LoanId, ui->ListCompLoansWid);
        item->setData(Qt::UserRole, QVariant(LoanId));
        curr=curr->next;
    }
}

void MainWindow::populateListWidgetTransactions(){
    int i=Cust->data.Transactions->Top;
    while(i>0){
        QString transid = QString::fromStdString(Cust->data.Transactions->elements[i].TransactionID);
        QListWidgetItem* item = new QListWidgetItem(transid, ui->ListTransWid);
        item->setData(Qt::UserRole, QVariant(transid));
        i--;
    }
}
void MainWindow::populateListWidgetPendingLoans(){
    int i = Cust->data.ReqLoans->Front;
    while(i <= Cust->data.ReqLoans->Tail){
        QString reqLoan = QString::fromStdString(Cust->data.ReqLoans->elements[i].LoanID);
        QListWidgetItem* item = new QListWidgetItem(reqLoan, ui->ListReqLoansWidg);
        item->setData(Qt::UserRole, QVariant(reqLoan));
        i++;
    }

}
void MainWindow::populateListWidgetAllTransactions(){
    NodeAllTransactions* curr=Cust->data.AllTransactions.head;
    while(curr){
        QString AllTransaction = QString::fromStdString(curr->data.TransactionID);
        QListWidgetItem* item = new QListWidgetItem(AllTransaction, ui->ListAllTransWid);
        item->setData(Qt::UserRole, QVariant(AllTransaction));
        curr=curr->next;
    }
}
void MainWindow::populateListWidgeArcAcc(){
    for(int i=0;i<AccL.size;i++){
        QString arc = QString::fromStdString(AccL.elements[i].AccNum);
        QListWidgetItem* item = new QListWidgetItem(arc, ui->ListArcAccWid);
        item->setData(Qt::UserRole, QVariant(arc));
    }
}




//Displaying the list widgets for the user who is a customer
void MainWindow::populateListWidgetLoansForCust(){

    NodeLoan* curr=UserCust->data.Loans.head;
    while(curr){
        QString LoanId = QString::fromStdString(curr->data.LoanID);
        QListWidgetItem* item = new QListWidgetItem(LoanId, ui->ListLoansCustWid);
        item->setData(Qt::UserRole, QVariant(LoanId));
        curr=curr->next;
    }
}

void MainWindow::populateListWidgetPendingLoansForCust(){
    int i = UserCust->data.ReqLoans->Front;
    while(i <= UserCust->data.ReqLoans->Tail){
        QString reqLoan = QString::fromStdString(UserCust->data.ReqLoans->elements[i].LoanID);
        QListWidgetItem* item = new QListWidgetItem(reqLoan, ui->ListReqLoansCustWid);
        item->setData(Qt::UserRole, QVariant(reqLoan));
        i++;
    }

}
void MainWindow::populateListWidgetTransactionsForCust(){
    int i=UserCust->data.Transactions->Top;
    while(i>0){
        QString transid = QString::fromStdString(UserCust->data.Transactions->elements[i].TransactionID);
        QListWidgetItem* item = new QListWidgetItem(transid, ui->ListDailyTransCustWid);
        item->setData(Qt::UserRole, QVariant(transid));
        i--;
    }
}




//Buttons Of the Home Page (1st step)

//If the user is an employee:
void MainWindow::on_EmpBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->LogInEmp);
    ui->IDEmpLoginCond->clear();
    ui->NameEmpLoginCond->clear();
}
//If the user is a customer:
void MainWindow::on_CustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->LogInCust);
    ui->AccNumLOGINCond->clear();
    ui->NameLoginCond->clear();
}
void MainWindow::on_ExitBut_clicked()
{
    close();

}

//Log In Buttons (2nd Step)
void MainWindow::on_CustLogInBut_clicked()
{
    ui->AccNumLOGINCond->clear();
    ui->NameLoginCond->clear();
    NodeCustomer* C=FindCustomerByAccNum(L,ui->AccNumLOGINtxt->text().toStdString());
    string I=ui->NameLogintxt->text().toStdString();
    if (C and C->data.name==I){
        ui->AccNumLOGINtxt->clear();
        ui->NameLogintxt->clear();
        UserCust=C;
        ui->stackedWidget->setCurrentWidget(ui->CustPage);
        ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
        ui->WelcomeCustLab->setText(QString::fromStdString("Welcome to SKB "+C->data.name+"\n how can we help you?"));
    }
    else if(C==nullptr){
        ui->AccNumLOGINCond->setText("This account number \n does not exist!");
    }
    else if(C->data.name!=I){
        ui->NameLoginCond->setText("Wrong Name.Try again.");
    }
}

void MainWindow::on_EmpLogInBut_clicked()
{
    ui->IDEmpLoginCond->clear();
    ui->NameEmpLoginCond->clear();
    StructEmployee I=FindEmpById(El,ui->IDEmpLogintxt->text().toStdString());
    string n=ui->NameEmpLogintxt->text().toStdString();
    if (I.ID!="" and n==I.LastName){
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
        ui->IDEmpLogintxt->clear();
        ui->NameEmpLogintxt->clear();
        UserEmp=I;
        ui->WelcomeEmp->setText(QString::fromStdString("Welcome "+UserEmp.name+" how would you \n like to start your day?"));
    }
    else if(I.ID==""){
        ui->IDEmpLoginCond->setText("This employee does not exist!");
    }
    else if(n!=I.LastName){
        ui->NameEmpLoginCond->setText("Wrong Name.Try again.");
    }
}

//Here The Employee is the user

void MainWindow::on_ListCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListCustomersPage);

}
void MainWindow::on_AddCustButt_clicked()
{
    ui->CreateNewCustBut->show();
    ui->AccNum->clear();
    ui->AccType->clear();
    ui->IBAN->clear();
    ui->BranchCode->clear();
    ui->AccNameLe->clear();
    ui->OpeningDate->clear();
    ui->BalanceLe->clear();
    ui->ListLoansWid->clear();
    ui->ListTransWid->clear();
    ui->ListAllTransWid->clear();
    ui->ListCompLoansWid->clear();
    ui->ListReqLoansWidg->clear();
    s.status="Inactive";
    s.AccNum=generateID();
    s.date=TodaysDate;
    s.Loans={};
    s.ReqLoans={};
    s.Transactions={};
    s.AllTransactions={};
    //Example of BranchCode if the employee is from Sfax
    //The new customer's branch code would be Sf10 or Sf11...
    if(UserEmp.BankBranch=="Sfax"){
        s.BrancheCode="Sf"+to_string(bb1+1);
    }else if(UserEmp.BankBranch=="Sousse"){
        s.BrancheCode="Ss"+to_string(bb2+1);
    }else{
        s.BrancheCode="Kr"+to_string(bb3+1);
    }
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustAttrPage);

    ui->AccNum->setText(QString::fromStdString(s.AccNum));
    ui->StatusOfCustforEmp->setCurrentText(QString::fromStdString(s.status));
    ui->BranchCode->setText(QString::fromStdString(s.BrancheCode));
    ui->BalanceLe->setText(QString::fromStdString(to_string(s.balance)));
    ui->AccNameLe->setReadOnly(false);
    ui->BalanceLe->setReadOnly(false);
    ui->AccType->setReadOnly(false);

}

void MainWindow::on_CreateNewCustBut_clicked()
{
    s.name=ui->AccNameLe->text().toStdString();
    s.balance=ui->BalanceLe->text().toFloat();
    s.AccType=ui->AccType->text().toStdString();
    s.IBAN=generateIBAN(s.AccNum,s.BrancheCode);
    if(!ValidName(s.name) or !ValidName(s.AccType) or s.balance<50){
        QMessageBox::warning(this, "Not Valid", "A Customer's attributes must satisfy these criteria: \n -The name must start with a capital letter and not contain any numbers. \n -The Account type must start with a capital letter and not contain any numbers. \n -The initial balance has to be above 50TND.");
    }else{
        //Creating the lists for the new customer
        s.Loans=createListLoan();
        s.ReqLoans=CreateQueue();
        s.CompletedLoans=createListCompletedLoans();
        s.Transactions=createAccTransactionsStack();
        s.AllTransactions=createListAllTransactions();

        ui->BalanceLe->setText(QString::fromStdString(to_string(s.balance)));
        ui->IBAN->setText(QString::fromStdString(s.IBAN));
        ui->OpeningDate->setText(QString::fromStdString(DisplayDate(s.date)));
        //The New Customer is added to the list
        InsertCustomer(&L,s,L.size+1);

        //The New Customer is added to the list widget
        QListWidgetItem* item=new QListWidgetItem(QString::fromStdString(s.AccNum),ui->ListCustWidg);
        ui->ListCustWidg->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable);


        QMessageBox::information(this, "Success", "New Customer has been added successfully.");
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->ListCustomersPage);
        ui->CreateNewCustBut->hide();
    }


}

//Pressing on the AccNum will display the Attributes of the customers.
void MainWindow::on_ListCustWidg_itemPressed(QListWidgetItem *item)
{

    ui->ViewListLoansBut->show();
    ui->ListLoansWid->clear();
    ui->ListReqLoansWidg->clear();
    ui->ListCompLoansWid->clear();
    ui->ListTransWid->clear();
    ui->ListAllTransWid->clear();

    AccN=item->text().toStdString();
    Cust=FindCustomerByAccNum(L,AccN);
    //Clearing The previous customer's attributes.
    ui->AccNum->clear();
    ui->AccType->clear();
    ui->IBAN->clear();
    ui->BranchCode->clear();
    ui->AccNameLe->clear();
    ui->OpeningDate->clear();
    ui->BalanceLe->clear();

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustAttrPage);

    //Showing each attribute
    ui->StatusOfCustforEmp->setCurrentText(QString::fromStdString(Cust->data.status));
    ui->AccNum->setText(QString::fromStdString(Cust->data.AccNum));
    ui->AccType->setText(QString::fromStdString(Cust->data.AccType));
    ui->IBAN->setText(QString::fromStdString(Cust->data.IBAN));
    ui->BranchCode->setText(QString::fromStdString(Cust->data.BrancheCode));
    ui->AccNameLe->setText(QString::fromStdString(Cust->data.name));
    ui->OpeningDate->setText(QString::fromStdString(DisplayDate(Cust->data.date)));
    ui->BalanceLe->setText(QString::fromStdString(to_string(Cust->data.balance)));
    ui->AccNameLe->setReadOnly(true);
    ui->BalanceLe->setReadOnly(true);
    ui->AccType->setReadOnly(true);
    ui->BranchCode->setReadOnly(true);

    //Displaying each list
    populateListWidgetLoans();
    populateListWidgetPendingLoans();
    populateListWidgetTransactions();
    populateListWidgetCompletesLoans();
    populateListWidgetAllTransactions();

    InitialStatus=Cust->data.status;

}


void MainWindow::on_BackToCustAttrBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustAttrPage);
}

//Here The combo box is the status of the customer this function deletes the customer when the employee
//changes status to closed
void MainWindow::on_StatusOfCustforEmp_textActivated(const QString &arg1)
{
    Cust->data.status=arg1.toStdString();
    if ((Cust->data.status)=="Closed"){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "Confirmation", "Are you sure you want to delete this customer?",QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            //We add the closed account to the archived list
            insertArchivedAcc(&AccL,Cust->data,AccL.size);
            //We destroy the node of that customer from the list(we destroyed the dynamically allocated lists individually in the function)
            destroyNodeCustomer(&L,Cust);
            //Deleting the customer's account number from the list widget
            QListWidgetItem* item=ui->ListCustWidg->takeItem(ui->ListCustWidg->currentRow());
            delete item;
            //Back to list of customers page
            ui->stackedWidget->setCurrentWidget(ui->EmpPage);
            ui->EmpStackedWidget->setCurrentWidget(ui->ListCustomersPage);

        }
        else{
            Cust->data.status=InitialStatus;
            ui->StatusOfCustforEmp->setCurrentText(QString::fromStdString(InitialStatus));
            ui->stackedWidget->setCurrentWidget(ui->EmpPage);
            ui->EmpStackedWidget->setCurrentWidget(ui->ListCustomersPage);
        }
    }
    else if(Cust->data.status!=InitialStatus){
        //The usage of else if instead of else is a way of optimizing the code
        //Since if the initial status hasn't been changed there is no need to itterate
        ChangeAccStatus(&L,Cust->data.AccNum,Cust->data.status);
        QMessageBox::information(this, "Changed", QString::fromStdString("AccNumber "+Cust->data.AccNum+" is now "+Cust->data.status));
    }
}
//When the customer presses the button "View Lists" and clicks on an ID it displays the Attributes
void MainWindow::on_ListLoansWid_itemClicked(QListWidgetItem *item)
{
    //We used the same page for Pending Loans Attributes And Loans Attributes
    //That's why we had to hide these buttons when displaying loans attr
    ui->DeclineRequestBut->hide();
    ui->AcceptRequestBut->hide();

    Loanid=item->text().toStdString();
    Loan=FindLoanByID(Cust->data.Loans,Loanid);

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListLoansPage);

    //Showing each attribute
    ui->LoanIDEmp->setText(QString::fromStdString(Loan->data.LoanID));
    ui->LoanTypeEmp->setText(QString::fromStdString(Loan->data.LoanType));
    ui->PrincAmountEmp->setText(QString::fromStdString(to_string(Loan->data.principalAmount)));
    ui->AmountPaidEmp->setText(QString::fromStdString(to_string(Loan->data.AmountPaid)));
    ui->IntRateEmp->setText(QString::fromStdString(to_string(Loan->data.interestRate)));
    ui->RemBalanceEmp->setText(QString::fromStdString(to_string(Loan->data.remainingBalance)));
    ui->StartDateEmp->setText(QString::fromStdString(DisplayDate(Loan->data.startDate)));
    ui->EndDateEmp->setText(QString::fromStdString(DisplayDate(Loan->data.endDate)));
    ui->LoanStatusEmp->setCurrentText(QString::fromStdString(Loan->data.LoanStatus));
    //For tracking purposes
    InitialStatus=Loan->data.LoanStatus;

}

//Here if the employee changes the status of a loan to Completed
//This loan would be deleted from the list of loans of the customer
//And then added to the completed loans list for that customer
void MainWindow::on_LoanStatusEmp_textActivated(const QString &arg1)
{
    Loan->data.LoanStatus=arg1.toStdString();
    if (Loan->data.LoanStatus=="Completed"){
        //Showing a "Loan...has been completed" message
        QMessageBox::information(this, "Success", QString::fromStdString("Loan "+Loan->data.LoanID+" has been completed."));
        //Adding the loan to the completed loans list
        InsertCompletedLoan(&Cust->data.CompletedLoans,Loan->data,Cust->data.CompletedLoans.size+1);

        //Deleting the loan from the loans list
        destroyNodeLoanFromList(&Cust->data.Loans,Loan);
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
        //Deleting the loan from the loans list widget
        QListWidgetItem* item=ui->ListLoansWid->takeItem(ui->ListLoansWid->currentRow());
        delete item;
        QString LoanId = QString::fromStdString(Loan->data.LoanID);
        //Adding the loan to the completed loans list widget
        QListWidgetItem* item2 = new QListWidgetItem(LoanId, ui->ListCompLoansWid);
        item2->setData(Qt::UserRole, QVariant(LoanId));
    }else if(Loan->data.LoanStatus!=InitialStatus){
        //The Status of the loan is Changed
        ChangeLoanStatus(&Cust->data.Loans,Loan->data.LoanID,Loan->data.LoanStatus);
        QMessageBox::information(this, "Changed", QString::fromStdString("Loan "+Loan->data.LoanID+" is now "+Loan->data.LoanStatus));
    }
}

//By clicking on the TransId in the List Widget the employee will get to the page with the transaction's attributes
void MainWindow::on_ListTransWid_itemClicked(QListWidgetItem *item)
{
    TransId=item->text().toStdString();
    Trans=FindTransById(*Cust->data.Transactions,TransId);

    //Showing the Attributes of the Transaction the employee clicked on
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustomersTransactions);
    ui->TransIdEmp->setText(QString::fromStdString(Trans.TransactionID));
    ui->AccNumTransEmp->setText(QString::fromStdString(Trans.AccNum));
    ui->TransDateEmp->setText(QString::fromStdString(DisplayDate(Trans.date)));
    ui->TransTypeEmp->setText(QString::fromStdString(Trans.Type));
    ui->AmountTransEmp->setText(QString::fromStdString(to_string(Trans.amount)));
}


//This Button will take the employee to the requested loans attribute by clicking
//on one of the corresponding requested loans IDs.
void MainWindow::on_ListReqLoansWidg_itemClicked(QListWidgetItem *item)
{
    Loanid=item->text().toStdString();
    LoanReq=FindReqLoanById(*Cust->data.ReqLoans,Loanid);

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListLoansPage);

    //The employee has the option of either accepting or declining the request
    ui->AcceptRequestBut->show();
    ui->DeclineRequestBut->show();


    ui->LoanIDEmp->setText(QString::fromStdString(LoanReq.LoanID));
    ui->LoanTypeEmp->setText(QString::fromStdString(LoanReq.LoanType));

    //Showing each attribute of the pending loans
    ui->PrincAmountEmp->setText(QString::fromStdString(to_string(LoanReq.principalAmount)));
    ui->AmountPaidEmp->setText(QString::fromStdString(to_string(LoanReq.AmountPaid)));
    ui->IntRateEmp->setText(QString::fromStdString(to_string(LoanReq.interestRate)));
    ui->RemBalanceEmp->setText(QString::fromStdString(to_string(LoanReq.remainingBalance)));
    ui->StartDateEmp->setText(QString::fromStdString(DisplayDate(LoanReq.startDate)));
    ui->EndDateEmp->setText(QString::fromStdString(DisplayDate(LoanReq.endDate)));
    ui->LoanStatusEmp->setCurrentText(QString::fromStdString(LoanReq.LoanStatus));
}

//This is the case where the employee Accepts the Request for the loan of a specific customer
void MainWindow::on_AcceptRequestBut_clicked()
{
    ui->LoanStatusCust->setEnabled(true);
    FrontLoan=Cust->data.ReqLoans->elements[Cust->data.ReqLoans->Front];
    //Since we're dealing with a queue for the requested loans, the employee can only dequeue the front request (the oldest request)
    if(LoanReq.LoanID==FrontLoan.LoanID){
        if(ListCompletedLoansisEmpty(Cust->data.CompletedLoans)){
            //The Customer never paid a loan before in that case he will have the common interest rate
            LoanReq.interestRate=10.0;
        }else{
            //The Employee knows that this customer has completed loans (pays his loans)so he will help him by lowering the interest rate
            LoanReq.interestRate=6.0;
        }
        LoanReq.startDate=TodaysDate;
        LoanReq.endDate=TodaysDate;
        if (LoanReq.LoanType=="Car"){
            //The loan will last 6 years
            LoanReq.endDate.year=TodaysDate.year+6;
        }else if(LoanReq.LoanType=="Home"){
            //The loan will last 15 years
            LoanReq.endDate.year=TodaysDate.year+15;
        }else if(LoanReq.LoanType=="Student"){
            //The loan will last 5 years
            LoanReq.endDate.year=TodaysDate.year+5;
        }else{
            //The loan will last 10 years
            LoanReq.endDate.year=TodaysDate.year+10;
        }
        //Adding the accepted loan request to the loans list
        insertLoan(&Cust->data.Loans,LoanReq,Cust->data.Loans.size+1);
        //Deleting the accepted loan from the queue
        DequeueLoan(Cust->data.ReqLoans);
        //Message showing "You have accepted the request for the Loan ..."
        QMessageBox::information(this, "Success", QString::fromStdString("You have accepted the request for the Loan "+LoanReq.LoanID));
        //Taking the employee back to all the customers' lists page
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
        //Deleting the accepted loan from the pending list loans widget.
        QListWidgetItem* item=ui->ListReqLoansWidg->takeItem(ui->ListReqLoansWidg->currentRow());
        delete item;
        //Adding the accepted loan to the list loans widget.
        QString LoanId = QString::fromStdString(LoanReq.LoanID);
        QListWidgetItem* item2 = new QListWidgetItem(LoanId, ui->ListLoansWid);
        item2->setData(Qt::UserRole, QVariant(LoanId));
    }else{
        QMessageBox::critical(this, "Error", "You cannot accept this loan while older ones are still pending.");
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
    }
}
//This is the case where the employee Declines the Request for the loan of a specific customer
void MainWindow::on_DeclineRequestBut_clicked()
{
    ui->LoanStatusCust->setEnabled(true);
    FrontLoan=Cust->data.ReqLoans->elements[Cust->data.ReqLoans->Front];
    //Since we're dealing with a queue for the requested loans, the employee can only dequeue the front request (the oldest request)
    if(LoanReq.LoanID==FrontLoan.LoanID){
        //Deleting the declined loan request from the queue
        DequeueLoan(Cust->data.ReqLoans);
        //Message showing "You have declined the request for the Loan... "
        QMessageBox::information(this, "Success", QString::fromStdString("You have declined the request for the Loan "+LoanReq.LoanID));
        //Taking the employee back to all the customers' lists page
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
        //Deleting the declined loan request from the pending list loans widget.
        QListWidgetItem* item=ui->ListReqLoansWidg->takeItem(ui->ListReqLoansWidg->currentRow());
        delete item;
    }else{
        QMessageBox::critical(this, "Error", "You cannot decline this loan while older ones are still pending.");
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
    }
}

//The employee clicks on a Transaction Id from the All Transactions list widget of a customer
void MainWindow::on_ListAllTransWid_itemClicked(QListWidgetItem *item)
{
    //Taking the customer to the transactions' attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustomersTransactions);

    TransId=item->text().toStdString();
    ATrans=FindAllTransById(Cust->data.AllTransactions,TransId);

    //Showing the Attributes of the  selected Transaction
    ui->TransIdEmp->setText(QString::fromStdString(ATrans->data.TransactionID));
    ui->AccNumTransEmp->setText(QString::fromStdString(ATrans->data.AccNum));
    ui->TransDateEmp->setText(QString::fromStdString(DisplayDate(ATrans->data.date)));
    ui->TransTypeEmp->setText(QString::fromStdString(ATrans->data.Type));
    ui->AmountTransEmp->setText(QString::fromStdString(to_string(ATrans->data.amount)));
}


void MainWindow::on_ListCompLoansWid_itemClicked(QListWidgetItem *item)
{
    //We used the same page for Pending Loans Attributes And Loans Attributes and Completed Loans Attributes
    //That's why we had to hide these buttons when displaying completed loans attr
    ui->DeclineRequestBut->hide();
    ui->AcceptRequestBut->hide();

    //Taking the employee to the completed loans' attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListLoansPage);

    Loanid=item->text().toStdString();
    CompLoan=FindCompLoanByID(Cust->data.CompletedLoans,Loanid);

    //Showing the completed loans' attributes
    ui->LoanIDEmp->setText(QString::fromStdString(CompLoan->data.LoanID));
    ui->LoanTypeEmp->setText(QString::fromStdString(CompLoan->data.LoanType));
    ui->PrincAmountEmp->setText(QString::fromStdString(to_string(CompLoan->data.principalAmount)));
    ui->AmountPaidEmp->setText(QString::fromStdString(to_string(CompLoan->data.AmountPaid)));
    ui->IntRateEmp->setText(QString::fromStdString(to_string(CompLoan->data.interestRate)));
    ui->RemBalanceEmp->setText(QString::fromStdString(to_string(CompLoan->data.remainingBalance)));
    ui->StartDateEmp->setText(QString::fromStdString(DisplayDate(CompLoan->data.startDate)));
    ui->EndDateEmp->setText(QString::fromStdString(DisplayDate(CompLoan->data.endDate)));
    ui->LoanStatusEmp->setCurrentText(QString::fromStdString(CompLoan->data.LoanStatus));

}



void MainWindow::on_BackListCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListCustomersPage);
}

//The employee decides to view the list of employees
void MainWindow::on_ListEmployeesBut_clicked()
{
    ui->AddEmpToListBut->show();
    ui->BackToEmpListsBut->show();
    ui->ModifyEmpBut->show();
    ui->DeleteEmpBut->show();
    //Taken to employee's attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
}

//The employee selects an employee from Sfax
void MainWindow::on_ListEmpBranchSfaxWid_itemClicked(QListWidgetItem *item)
{
    EmpBb=item->text().toStdString();
    Emp=FindEmpById(El,EmpBb);
    ui->AddEmpToListBut->hide();

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);

    ui->EmpIDle->setText(QString::fromStdString(Emp.ID));
    ui->EmpNameLe->setText(QString::fromStdString(Emp.name));
    ui->EmpLastNamele->setText(QString::fromStdString(Emp.LastName));
    ui->EmpAddressle->setText(QString::fromStdString(Emp.adress));
    ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp.salary)));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp.HireDate)));
    ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp.BankBranch));
}

//The employee selects an employee from Kairouan
void MainWindow::on_ListEmpBranchKairWid_itemPressed(QListWidgetItem *item)
{
    EmpBb=item->text().toStdString();
    Emp=FindEmpById(El,EmpBb);
    ui->AddEmpToListBut->hide();

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);

    ui->EmpIDle->setText(QString::fromStdString(Emp.ID));
    ui->EmpNameLe->setText(QString::fromStdString(Emp.name));
    ui->EmpLastNamele->setText(QString::fromStdString(Emp.LastName));
    ui->EmpAddressle->setText(QString::fromStdString(Emp.adress));
    ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp.salary)));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp.HireDate)));
    ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp.BankBranch));
}


//The employee selects an employee from Sousse
void MainWindow::on_ListEmpBranchSousseWid_itemClicked(QListWidgetItem *item)
{
    EmpBb=item->text().toStdString();
    Emp=FindEmpById(El,EmpBb);
    ui->AddEmpToListBut->hide();

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);

    ui->EmpIDle->setText(QString::fromStdString(Emp.ID));
    ui->EmpNameLe->setText(QString::fromStdString(Emp.name));
    ui->EmpLastNamele->setText(QString::fromStdString(Emp.LastName));
    ui->EmpAddressle->setText(QString::fromStdString(Emp.adress));
    ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp.salary)));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp.HireDate)));
    ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp.BankBranch));
}

//The Employee attempts to delete a selected employee.
void MainWindow::on_DeleteEmpBut_clicked()
{
    if(Emp.ID==UserEmp.ID){
        QMessageBox::critical(this, "Impossible", "You cannot delete yourself.");
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
    }
    else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "Confirmation", "Are you sure you want to delete this employee?",QMessageBox::Yes | QMessageBox::No);
        //Deleting
        if (reply == QMessageBox::Yes) {
            QList<QListWidgetItem*> matches = ui->ListEmpLastNameWid->findItems(QString::fromStdString(Emp.LastName), Qt::MatchExactly);
            QListWidgetItem* item1 = nullptr;
            if (!matches.isEmpty()) {
                item1 = matches.first();
                int row2 = ui->ListEmpLastNameWid->row(item1);
                ui->ListEmpLastNameWid->takeItem(row2);
            }
            removeThisEmployee(&El,Emp);
            QListWidgetItem* item;
            if(Emp.BankBranch=="Sfax"){
                item=ui->ListEmpBranchSfaxWid->takeItem(ui->ListEmpBranchSfaxWid->currentRow());
            }
            else if(Emp.BankBranch=="Kairouan"){
                item=ui->ListEmpBranchKairWid->takeItem(ui->ListEmpBranchKairWid->currentRow());
            }
            else{
                item=ui->ListEmpBranchSousseWid->takeItem(ui->ListEmpBranchSousseWid->currentRow());
            }
            delete item;//The Deleted Employee's Id is deleted from its' bank branch list widget
            delete item1;//The Deleted Employee's Last Name is deleted from the last names list widget
            ui->stackedWidget->setCurrentWidget(ui->EmpPage);
            ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
        }
        //Not deleting
        else{
            //Back to the list of employees page
            ui->stackedWidget->setCurrentWidget(ui->EmpPage);
            ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
        }
    }
}

//The Employee Attempts to add an employee
void MainWindow::on_AddEmployeeBut_clicked()
{
    //Taken to the employee's attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);
    //The button to add an employee is shown in the page
    ui->AddEmpToListBut->show();

    //Clearing the previously selected employee's attributes
    ui->EmpIDle->clear();
    ui->EmpNameLe->clear();
    ui->EmpLastNamele->clear();
    ui->EmpAddressle->clear();
    ui->EmpSalaryle->clear();
    ui->EmpHireDatele->clear();

    NewEmp.ID=generateID();//The Id of the new employee is auto generated(unique)
    NewEmp.HireDate=TodaysDate;//The hire date is today's date

    //Showing the Id and the Hire date
    ui->EmpIDle->setText(QString::fromStdString(NewEmp.ID));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(NewEmp.HireDate)));


    //The employee has the option of typing the attributes
    ui->EmpBankBranchle->setEnabled(true);
    ui->EmpNameLe->setReadOnly(false);
    ui->EmpLastNamele->setReadOnly(false);
    ui->EmpSalaryle->setReadOnly(false);
    ui->EmpAddressle->setReadOnly(false);

}


void MainWindow::on_AddEmpToListBut_clicked()
{
    //The New Employee has the attributes typed by the user
    Newlastname=ui->EmpLastNamele->text().toStdString();
    Newname=ui->EmpNameLe->text().toStdString();
    Newaddress=ui->EmpAddressle->text().toStdString();
    Newsalary=ui->EmpSalaryle->text().toFloat();
    if (!ValidName(Newlastname) or !ValidName(Newname) or !ValidAddress(Newaddress) or Newsalary<AvSalary){
        QMessageBox::warning(this, "Not Valid", "The New Employee's attributes must satisfy these criteria: \n -Names must start with capital letters without numbers. \n -The Address must be determined \n -The salary has to be higher than the Average Salary.");
    }
    else{
        ui->EmpBankBranchle->setEnabled(false);
        NewEmp.LastName=ui->EmpLastNamele->text().toStdString();
        NewEmp.name=ui->EmpNameLe->text().toStdString();
        NewEmp.BankBranch=ui->EmpBankBranchle->currentText().toStdString();
        NewEmp.adress=ui->EmpAddressle->text().toStdString();
        NewEmp.salary=ui->EmpSalaryle->text().toFloat();

        insertEmployee(&El,NewEmp,El.size);
        mergeSortByLastName(&El,0,El.size-1);
        ui->ListEmpLastNameWid->clear();
        for (int i=0;i<El.size;i++){
            QString EmpAcc = QString::fromStdString(El.elements[i].LastName);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpLastNameWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }
        if(NewEmp.BankBranch=="Sfax"){
            QString EmpAcc = QString::fromStdString(NewEmp.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSfaxWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }else if(NewEmp.BankBranch=="Kairouan"){
            QString EmpAcc = QString::fromStdString(NewEmp.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchKairWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }else{
            QString EmpAcc = QString::fromStdString(NewEmp.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSousseWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }
        QMessageBox::information(this, "Success", "New Employee has been added successfully.");
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
    }
}

void MainWindow::on_ModifyEmpBut_clicked()
{
    if (Emp.ID==UserEmp.ID){
        QMessageBox::critical(this, "Impossible", "You cannot modify your attributes.");
    }
    else{
        //The employee can type in the new attributes
        ui->EmpBankBranchle->setEnabled(true);

        ui->EmpNameLe->setReadOnly(false);
        ui->EmpLastNamele->setReadOnly(false);
        ui->EmpSalaryle->setReadOnly(false);
        ui->EmpAddressle->setReadOnly(false);

        ui->DoneModifyingBut->show();
    }

}
void MainWindow::on_DoneModifyingBut_clicked()
{
    Emp2.ID=Emp.ID;
    Emp2.HireDate=Emp.HireDate;

    Emp2.LastName=ui->EmpLastNamele->text().toStdString();
    Emp2.name=ui->EmpNameLe->text().toStdString();
    Emp2.BankBranch=ui->EmpBankBranchle->currentText().toStdString();
    Emp2.adress=ui->EmpAddressle->text().toStdString();
    Emp2.salary=ui->EmpSalaryle->text().toFloat();
    //Case where the modified attributes don't satisfy the criteria
    if (!ValidName(Emp2.LastName) or !ValidName(Emp2.name) or !ValidAddress(Emp2.adress) or Emp2.salary<AvSalary){
        QMessageBox::warning(this, "Not Valid", "The Modified Employee's attributes must satisfy these criteria: \n -Names must start with capital letters without numbers. \n -The Address must be determined \n -The salary has to be higher than the Average Salary.");
    }
    else{//Case Where All the modified attributes are valid

        //Deleling the old name from the last names list
        QList<QListWidgetItem*> matches = ui->ListEmpLastNameWid->findItems(QString::fromStdString(Emp.LastName), Qt::MatchExactly);
        QListWidgetItem* item1 = nullptr;
        if (!matches.isEmpty()) {
            item1 = matches.first();
            int row2 = ui->ListEmpLastNameWid->row(item1);
            ui->ListEmpLastNameWid->takeItem(row2);
        }

        //Deleting the employees id from his old bank branch list widget
        if(Emp.BankBranch=="Sfax"){
            QListWidgetItem* item=ui->ListEmpBranchSfaxWid->takeItem(ui->ListEmpBranchSfaxWid->currentRow());
            delete item;
        }else if(Emp.BankBranch=="Kairouan"){
            QListWidgetItem* item=ui->ListEmpBranchKairWid->takeItem(ui->ListEmpBranchKairWid->currentRow());
            delete item;
        }else{
            QListWidgetItem* item=ui->ListEmpBranchSousseWid->takeItem(ui->ListEmpBranchSousseWid->currentRow());
            delete item;
        }

        QString EmpAcc = QString::fromStdString(Emp2.LastName);

        // find correct sorted place
        int insertRow = 0;
        while (insertRow < ui->ListEmpLastNameWid->count() &&ui->ListEmpLastNameWid->item(insertRow)->text().compare(EmpAcc, Qt::CaseInsensitive) < 0)
        {
            insertRow++;
        }

        // insert item alphabetically
        QListWidgetItem* item = new QListWidgetItem(EmpAcc);
        ui->ListEmpLastNameWid->insertItem(insertRow, item);
        item->setData(Qt::UserRole, QVariant(EmpAcc));

        //The Employee's attributes will be modified in the list
        ModifyEmp(&El,Emp,Emp2.LastName,Emp2.name,Emp2.adress,Emp2.BankBranch,Emp2.salary);

        if(Emp2.BankBranch=="Sfax"){
            QString EmpAcc = QString::fromStdString(Emp2.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSfaxWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }else if(Emp2.BankBranch=="Kairouan"){
            QString EmpAcc = QString::fromStdString(Emp2.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchKairWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }else{
            QString EmpAcc = QString::fromStdString(Emp2.ID);
            QListWidgetItem* item = new QListWidgetItem(EmpAcc, ui->ListEmpBranchSousseWid);
            item->setData(Qt::UserRole, QVariant(EmpAcc));
        }

        //Showing the Modified version's attributes
        ui->EmpIDle->setText(QString::fromStdString(Emp2.ID));
        ui->EmpNameLe->setText(QString::fromStdString(Emp2.name));
        ui->EmpLastNamele->setText(QString::fromStdString(Emp2.LastName));
        ui->EmpAddressle->setText(QString::fromStdString(Emp2.adress));
        ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp2.salary)));
        ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp2.HireDate)));
        ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp2.BankBranch));

        //Now the employee can no longer change the values unless he clicks on modify button another time
        ui->EmpBankBranchle->setEnabled(false);
        ui->EmpNameLe->setReadOnly(true);
        ui->EmpLastNamele->setReadOnly(true);
        ui->EmpSalaryle->setReadOnly(true);
        ui->EmpAddressle->setReadOnly(true);

        //Hiding the Done modifying button
        ui->DoneModifyingBut->hide();

        //Taken back to the employees page
        ui->stackedWidget->setCurrentWidget(ui->EmpPage);
        ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
    }
}

//The user wants to see the archived accounts
void MainWindow::on_ViewArchAccBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListArcAccPage);
    populateListWidgeArcAcc();
}

void MainWindow::on_ListArcAccWid_itemClicked(QListWidgetItem *item)
{
    AccN=item->text().toStdString();
    Arc=FindArcAccByAccNum(AccL,AccN);

    //Cleariing the previously selected archived account's attributes.
    ui->AccNum->clear();
    ui->AccType->clear();
    ui->IBAN->clear();
    ui->BranchCode->clear();
    ui->AccNameLe->clear();
    ui->OpeningDate->clear();
    ui->BalanceLe->clear();
    ui->ViewCustomersListsBut->hide();

    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->CustAttrPage);

    //The archived account's status is always closed.
    //Showing the archived account's attributes
    ui->StatusOfCustforEmp->setCurrentText(QString::fromStdString("Closed"));
    ui->AccNum->setText(QString::fromStdString(Arc.AccNum));
    ui->AccType->setText(QString::fromStdString(Arc.AccType));
    ui->IBAN->setText(QString::fromStdString(Arc.IBAN));
    ui->BranchCode->setText(QString::fromStdString(Arc.BrancheCode));
    ui->AccNameLe->setText(QString::fromStdString(Arc.name));
    ui->OpeningDate->setText(QString::fromStdString(DisplayDate(Arc.date)));
    ui->BalanceLe->setText(QString::fromStdString(to_string(Arc.balance)));

    //The employee can never change these attributes.
    ui->AccNameLe->setReadOnly(true);
    ui->BalanceLe->setReadOnly(true);
    ui->AccType->setReadOnly(true);
    ui->BranchCode->setReadOnly(true);

}

//These buttons take the user to the employee's home page
void MainWindow::on_BackToHomePEmpBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}


void MainWindow::on_BackToCustAttr_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}


void MainWindow::on_BackToCustAttr_7_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}


void MainWindow::on_BackToEmpHomePage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}

void MainWindow::on_BackToEmpHomePageBut_clicked()
{
    ui->LoanStatusCust->setEnabled(true);
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}
void MainWindow::on_BackToEmpHomePage_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}

void MainWindow::on_BackToHomeEmpBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}

void MainWindow::on_BackToHomePEmpBut_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpHomePage);
}

//These buttons take the user to all the selected customer's lists page
void MainWindow::on_BackToAllLists_clicked()
{
    ui->LoanStatusCust->setEnabled(true);
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
}

void MainWindow::on_ViewCustomersListsBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
}
void MainWindow::on_BackToAllListsBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->AllCustomersListsPage);
}



void MainWindow::on_BackToEmpListsBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->ListEmployeesPage);
}


//Log Out
//Since the employee's log out declares the beginning of a new day
//All daily transactions from each customers will be deleted and copied into different "all transactions singly linked lists" for each customer
void MainWindow::on_LogOutEmp_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
    CreateAllTheTransFinalDay(&L);
    //Today's date becomes tomorrow's
    TodaysDate.day=TodaysDate.day+1;
    ui->CancelLastTransCustBut->hide();
    NodeCustomer* curr=L.head;
    while(curr){
        cout<<"Customer "+curr->data.name<<endl;;
        displayAccTransactionsStack(*curr->data.Transactions);
        curr=curr->next;
    }
}

//The user is the customer
void MainWindow::on_ViewListLoansBut_clicked()
{
    ui->ListLoansCustWid->clear();
    ui->ListReqLoansCustWid->clear();
    //User taken to his list of loans page.
    ui->stackedWidget->setCurrentWidget(ui->CustHomePage);
    ui->CustStackedWidget->setCurrentWidget(ui->ListOfLoansCust);
    //Displaying the list of loans for the customer.
    populateListWidgetLoansForCust();
    populateListWidgetPendingLoansForCust();
}



//The customer checks his attributes.
void MainWindow::on_CustDetailsBut_clicked()
{
    //Take to the customer's details page.
    ui->stackedWidget->setCurrentWidget(ui->CustHomePage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustDetailsPage);

    //Showing each attribute.
    ui->StatusOfCustforCust->setCurrentText(QString::fromStdString(UserCust->data.status));
    ui->AccNumCust->setText(QString::fromStdString(UserCust->data.AccNum));
    ui->AccTypeCust->setText(QString::fromStdString(UserCust->data.AccType));
    ui->IBANCust->setText(QString::fromStdString(UserCust->data.IBAN));
    ui->BranchCustCode->setText(QString::fromStdString(UserCust->data.BrancheCode));
    ui->AccNameCust->setText(QString::fromStdString(UserCust->data.name));
    ui->OpeningCustDate->setText(QString::fromStdString(DisplayDate(UserCust->data.date)));
    ui->BalanceCustLe->setText(QString::fromStdString(to_string(UserCust->data.balance)));
}

//The customer checks one of his loans by selecting its' ID.
void MainWindow::on_ListLoansCustWid_itemClicked(QListWidgetItem *item)
{
    Loanid=item->text().toStdString();
    Loan=FindLoanByID(UserCust->data.Loans,Loanid);
    //Taken to the loan attributes page
    ui->stackedWidget->setCurrentWidget(ui->CustHomePage);
    ui->CustStackedWidget->setCurrentWidget(ui->LoanAttrCust);

    //Showing each attribute of the selected loan
    ui->LoanIDCust->setText(QString::fromStdString(Loan->data.LoanID));
    ui->LoanTypeCustComboBox->setCurrentText(QString::fromStdString(Loan->data.LoanType));
    ui->PrincAmountLoanCust->setText(QString::fromStdString(to_string(Loan->data.principalAmount)));
    ui->AmountPaidLoanCust->setText(QString::fromStdString(to_string(Loan->data.AmountPaid)));
    ui->IntRateLoanCust->setText(QString::fromStdString(to_string(Loan->data.interestRate)));
    ui->RemBalanceLoanCust->setText(QString::fromStdString(to_string(Loan->data.remainingBalance)));
    ui->StartDateLoanCust->setText(QString::fromStdString(DisplayDate(Loan->data.startDate)));
    ui->EndDateLoanCust->setText(QString::fromStdString(DisplayDate(Loan->data.endDate)));
    ui->LoanStatusCust->setCurrentText(QString::fromStdString(Loan->data.LoanStatus));

    ui->LoanTypeCustComboBox->setEnabled(false);
    ui->LoanStatusCust->setEnabled(false);
}

//The Customer checks his selected requested loan
void MainWindow::on_ListReqLoansCustWid_itemClicked(QListWidgetItem *item)
{
    Loanid=item->text().toStdString();
    LoanReq=FindReqLoanById(*UserCust->data.ReqLoans,Loanid);

    //Taken to Loan Attributes Page
    ui->stackedWidget->setCurrentWidget(ui->CustHomePage);
    ui->CustStackedWidget->setCurrentWidget(ui->LoanAttrCust);

    //Showing each attribute of the selected requested loan
    ui->LoanIDCust->setText(QString::fromStdString(LoanReq.LoanID));
    ui->LoanTypeCustComboBox->setCurrentText(QString::fromStdString(LoanReq.LoanType));
    ui->PrincAmountLoanCust->setText(QString::fromStdString(to_string(LoanReq.principalAmount)));
    ui->AmountPaidLoanCust->setText(QString::fromStdString(to_string(LoanReq.AmountPaid)));
    ui->IntRateLoanCust->setText(QString::fromStdString(to_string(LoanReq.interestRate)));
    ui->RemBalanceLoanCust->setText(QString::fromStdString(to_string(LoanReq.remainingBalance)));
    ui->StartDateLoanCust->setText(QString::fromStdString(DisplayDate(LoanReq.startDate)));
    ui->EndDateLoanCust->setText(QString::fromStdString(DisplayDate(LoanReq.endDate)));
    ui->LoanStatusCust->setCurrentText(QString::fromStdString(LoanReq.LoanStatus));
    ui->LoanStatusCust->setEnabled(false);
}

void MainWindow::on_ViewListTransactionsBut_clicked()
{
    ui->ListDailyTransCustWid->clear();
    //Taken to the page with the list of daily transactions.
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->ListTransactionsCustPage);
    //Displaying all the daily transactions by ID in the transaction list widget.
    populateListWidgetTransactionsForCust();
}



//The Customer checks his selected daily transaction
void MainWindow::on_ListDailyTransCustWid_itemClicked(QListWidgetItem *item)
{
    TransId=item->text().toStdString();
    Trans=FindTransById(*UserCust->data.Transactions,TransId);

    //Taken to Transaction Attributes Page
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->TransAttrCustPage);

    //Showing each attribute of the selected daily transaction
    ui->TransIdCust->setText(QString::fromStdString(Trans.TransactionID));
    ui->AccNumTransCust->setText(QString::fromStdString(Trans.AccNum));
    ui->TransDateCust->setText(QString::fromStdString(DisplayDate(Trans.date)));
    ui->TransTypeCust->setText(QString::fromStdString(Trans.Type));
    ui->AmountTransCust->setText(QString::fromStdString(to_string(Trans.amount)));
}


//The Customer attempts to cancel his last transaction
void MainWindow::on_CancelLastTransCustBut_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation", "Are you sure you want to cancel your last transaction?",QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        //The Customer confirms canceling the last transaction and can no longer cancel another unless he makes another transaction
        ui->CancelLastTransCustBut->hide();
        LastTrans=UserCust->data.Transactions->elements[UserCust->data.Transactions->Top];
        QList<QListWidgetItem*> matches = ui->ListDailyTransCustWid->findItems(QString::fromStdString(LastTrans.TransactionID), Qt::MatchExactly);
        QListWidgetItem* item1 = nullptr;
        if (!matches.isEmpty()) {
            item1 = matches.first();
            int row2 = ui->ListDailyTransCustWid->row(item1);
            ui->ListDailyTransCustWid->takeItem(row2);
        }
        delete item1;
        if(LastTrans.Type=="Withdrawal"){
            //The money the customer withdrew will be given back to him.
            UserCust->data.balance=UserCust->data.balance+LastTrans.amount;
        }
        else{
            //The money the customer added will be taken from him.
            UserCust->data.balance=UserCust->data.balance-LastTrans.amount;
        }
        //Popping the last transaction from the daily transactions stack
        PopAccTransactionsStack(UserCust->data.Transactions);
        //Taken to the list of transactions page
        ui->stackedWidget->setCurrentWidget(ui->CustPage);
        ui->CustStackedWidget->setCurrentWidget(ui->ListTransactionsCustPage);
    }
    else{
        //No longer canceling it
        //Taken back to the list of transactions page
        ui->stackedWidget->setCurrentWidget(ui->CustPage);
        ui->CustStackedWidget->setCurrentWidget(ui->ListTransactionsCustPage);
    }
}
//The customer attempts to request a new loan.
void MainWindow::on_RequestNewLoanBut_clicked()
{
    NewLoan.LoanID="LN"+to_string(ID+1);
    ID++;

    ui->LoanIDCust_2->setText(QString::fromStdString(NewLoan.LoanID));

    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->NewLoanRequest);


    NewLoan.LoanStatus="Pending";
    NewLoan.AmountPaid=0;
    //Waiting to be determined by the employee
    NewLoan.interestRate=0;
    NewLoan.startDate={0,0,0};
    NewLoan.endDate={0,0,0};

}


//Submitting the request.
void MainWindow::on_SubmitReqBut_clicked()
{
    //The customer sets the principal amount and the remaing balance is the principal amount.
    NewLoan.principalAmount=ui->ReqLoanPrincAmountCustLe->text().toFloat();
    NewLoan.remainingBalance=NewLoan.principalAmount;
    NewLoan.LoanType=ui->ReqLoanTypeCust->currentText().toStdString();
    //Request added to the queue.
    EnqueueLoan(UserCust->data.ReqLoans,NewLoan);
    QMessageBox::information(this, "Success", "Request has been submitted.");
    //Taken to the customer's home page.
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
    QString reqLoan = QString::fromStdString(NewLoan.LoanID);
    QListWidgetItem* item = new QListWidgetItem(reqLoan, ui->ListReqLoansCustWid);
    item->setData(Qt::UserRole, QVariant(reqLoan));
}
//Customer attempts to make a new transaction.
void MainWindow::on_NewTransCustBut_clicked()
{
    ui->NewTransAmountCustLe->clear();
    //Taken to the New Transactions Page.
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->NewTransactionPage);
    //The TransactionID is auto generated and unique.
    ui->NewTransIdCust->setText(QString::fromStdString("TRX"+to_string(Id+1)));
    //By default the type of new transaction is "Deposit"
    ui->TypeOfNewTransCust->setCurrentText("Deposit");
    NewTrans.Type= "Deposit";
    //By showing the deposit label we hide any button related to the withdrawal
    ui->DepositLab->show();
}


void MainWindow::on_TypeOfNewTransCust_textActivated(const QString &arg1)
{
    NewTrans.Type = arg1.toStdString();
    if (NewTrans.Type  == "Deposit") {
        //The Customer can type in the amout he wants to deposit
        ui->NewTransAmountCustLe->setReadOnly(false);
        ui->DepositLab->show();
    }
    else if (NewTrans.Type == "Withdrawal") {
        ui->NewTransAmountCustLe->setReadOnly(true);
        ui->DepositLab->hide();
    }
}

void MainWindow::on_AddNewTrans_clicked()
{
    NewTrans.TransactionID="TRX"+to_string(Id+1);
    Id++;
    NewTrans.date=TodaysDate;
    NewTrans.AccNum=UserCust->data.AccNum;
    NewTrans.amount=ui->NewTransAmountCustLe->text().toFloat();
    if(NewTrans.Type=="Withdrawal" and NewTrans.amount>UserCust->data.balance){
        //The amount the customer withdraws has to be less than his balance
        QMessageBox::information(this, "Impossible", "The amount you withdraw has to be less than your balance "+QString::number(UserCust->data.balance)+".");
    }
    else{
        if(NewTrans.Type=="Withdrawal" and NewTrans.amount<=UserCust->data.balance){
            //The amount the customer withdrew is taking from his balance
            UserCust->data.balance=UserCust->data.balance-NewTrans.amount;}
        else if(NewTrans.Type=="Deposit"){
            //The deposit amount is added to his balance
            UserCust->data.balance=UserCust->data.balance+NewTrans.amount;
        }
        //Added Transaction to the daily transactions stack
        PushAccTransactionsStack(UserCust->data.Transactions,NewTrans);

        QMessageBox::information(this, "Success", "Transaction has been made.");

        //Taken to Customer's Home page.
        ui->stackedWidget->setCurrentWidget(ui->CustPage);
        ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);

        //The daily transaction is added to the DailyTransaction List Widget.
        QString newt = QString::fromStdString(NewTrans.TransactionID);
        QListWidgetItem* item = new QListWidgetItem(newt, ui->ListDailyTransCustWid);
        item->setData(Qt::UserRole, QVariant(newt));
        ui->CancelLastTransCustBut->show();
    }
}

//IF the transaction's type is withdrawal the customer can withdraw money using these denominations
void MainWindow::on_plus50_clicked()
{
    i=ui->NewTransAmountCustLe->text().toInt();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i+50)));
}


void MainWindow::on_min50_clicked()
{
    i=ui->NewTransAmountCustLe->text().toFloat();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i-50)));
}


void MainWindow::on_plus20_clicked()
{
    i=ui->NewTransAmountCustLe->text().toFloat();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i+20)));
}


void MainWindow::on_min20_clicked()
{
    i=ui->NewTransAmountCustLe->text().toFloat();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i-20)));
}


void MainWindow::on_plus10_clicked()
{
    i=ui->NewTransAmountCustLe->text().toFloat();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i+10)));
}


void MainWindow::on_min10_clicked()
{
    i=ui->NewTransAmountCustLe->text().toFloat();
    ui->NewTransAmountCustLe->setText(QString::fromStdString(to_string(i-10)));
}


//Back to list of transactions page
void MainWindow::on_BackToTransListCust_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->ListTransactionsCustPage);
}
//Back to list of loans page
void MainWindow::on_BackToListLoansCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->ListOfLoansCust);
}



//Back to customer's home page
void MainWindow::on_BackToTransPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}


void MainWindow::on_BackToHomeCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}


void MainWindow::on_BackToLoansPage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}

void MainWindow::on_BackToCustHomeBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}
void MainWindow::on_BackToHoCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}
void MainWindow::on_BackToCustHoPageBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}
void MainWindow::on_BackListCustBut_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->CustPage);
    ui->CustStackedWidget->setCurrentWidget(ui->CustHomePage);
}


//The customer logs out
void MainWindow::on_LogOutCustBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->HomePage);
}




//The statistics button will take the employee to the statistics page
void MainWindow::on_StatisticsBut_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->StatisticsPage);

    ui->TotOfEmp->setText(QString::fromStdString(to_string(El.size)));
    ui->TotOfLoans->setText(QString::fromStdString(to_string(TotalLoans(L))));

    ui->TableLoansByType->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(to_string(NumberOfLoansByType(L,"Car")))));
    ui->TableLoansByType->setItem(0, 1, new QTableWidgetItem(QString::number(NumberOfLoansByType(L,"Home"))));
    ui->TableLoansByType->setItem(0, 2, new QTableWidgetItem(QString::number(NumberOfLoansByType(L,"Student"))));
    ui->TableLoansByType->setItem(0, 3, new QTableWidgetItem(QString::number(NumberOfLoansByType(L,"Business"))));

    //When we click on display

    ui->TableLoansByStatus->setItem(0, 0,  new QTableWidgetItem(QString::number(NumberOfLoansByStatus(L,"Active"))));
    ui->TableLoansByStatus->setItem(0, 1, new QTableWidgetItem(QString::number(NumberOfCompletedLoans(L))));
    ui->TableLoansByStatus->setItem(0, 2, new QTableWidgetItem(QString::number(NumberOfLoansByStatus(L,"Active"))));

    ui->TableEmpByBranch->setItem(0, 0, new QTableWidgetItem(QString::number(EmployeesPerBranch(El,"Kairouan"))));
    ui->TableEmpByBranch->setItem(0, 1, new QTableWidgetItem(QString::number(EmployeesPerBranch(El,"Sfax"))));
    ui->TableEmpByBranch->setItem(0, 2, new QTableWidgetItem(QString::number(EmployeesPerBranch(El,"Sousse"))));

    ui->TableCustWith->setColumnWidth(0, 180);  // AccNum
    ui->TableCustWith->setColumnWidth(1, 100);  // Loans
    ui->TableCustWith->setColumnWidth(2, 150);  // Balance

    // Row 0 — Highest Loans Customer
    ui->TableCustWith->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(CustomerWithHighestLoanNumber(L).AccNum)));
    ui->TableCustWith->setItem(0, 1, new QTableWidgetItem( QString::number(CustomerWithHighestLoanNumber(L).Loans.size)));
    ui->TableCustWith->setItem(0, 2, new QTableWidgetItem(QString::number(CustomerWithHighestLoanNumber(L).balance)));

    // Row 1 — Highest Balance Customer
    ui->TableCustWith->setItem(1, 0, new QTableWidgetItem(QString::fromStdString(CustomerWithHighestAccountBalance(L).AccNum)));
    ui->TableCustWith->setItem(1, 1, new QTableWidgetItem(QString::number(CustomerWithHighestAccountBalance(L).Loans.size)));
    ui->TableCustWith->setItem(1, 2, new QTableWidgetItem(QString::number(CustomerWithHighestAccountBalance(L).balance)));

    // Row 2 — Lowest Balance Customer
    ui->TableCustWith->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(CustomerWithLowestAccountBalance(L).AccNum)));
    ui->TableCustWith->setItem(2, 1, new QTableWidgetItem(QString::number(CustomerWithLowestAccountBalance(L).Loans.size)));
    ui->TableCustWith->setItem(2, 2, new QTableWidgetItem(QString::number(CustomerWithLowestAccountBalance(L).balance)));
}

//Displaying the active loans for a chosen date
void MainWindow::on_DisplayActiveLoansBut_clicked()
{
    QDate qStart = ui->ActiveStartDate->date();
    QDate qEnd   = ui->ActiveEndDate->date();
    Date dStart = { qStart.day(), qStart.month(), qStart.year() };
    Date dEnd   = { qEnd.day(),   qEnd.month(),   qEnd.year() };
    ui->ListOfActiveLoansWid->clear();

    ListLoan activeLoans = ActiveLoans(L,dStart,dEnd);
    NodeLoan* curr=activeLoans.head;
    while(curr){
        QString LoanId = QString::fromStdString(curr->data.LoanID);
        QListWidgetItem* item = new QListWidgetItem(LoanId, ui->ListOfActiveLoansWid);
        item->setData(Qt::UserRole, QVariant(LoanId));
        curr=curr->next;
    }
}
//The Most Recently Recruited Employee Button will take the employee to the employee's attributes page
void MainWindow::on_RecentlyRecEmpBut_clicked()
{
    Emp=MostRecentlyHiredEmployee(El);
    //These buttons are useless here
    ui->AddEmpToListBut->hide();
    ui->BackToEmpListsBut->hide();
    ui->ModifyEmpBut->hide();
    ui->DeleteEmpBut->hide();
    //Taken to the employee's attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);
    //Showing the employee's attributes
    ui->EmpIDle->setText(QString::fromStdString(Emp.ID));
    ui->EmpNameLe->setText(QString::fromStdString(Emp.name));
    ui->EmpLastNamele->setText(QString::fromStdString(Emp.LastName));
    ui->EmpAddressle->setText(QString::fromStdString(Emp.adress));
    ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp.salary)));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp.HireDate)));
    ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp.BankBranch));
}
//The Earliest Recruited Employee Button will take the employee to the employee's attributes page
void MainWindow::on_EarliestRecBut_clicked()
{
    Emp=EarliestHiredEmployee(El);
    //These buttons are useless here
    ui->AddEmpToListBut->hide();
    ui->BackToEmpListsBut->hide();
    ui->ModifyEmpBut->hide();
    ui->DeleteEmpBut->hide();
    //Taken to the employee's attributes page
    ui->stackedWidget->setCurrentWidget(ui->EmpPage);
    ui->EmpStackedWidget->setCurrentWidget(ui->EmpAttrPage);
    //Showing the employee's attributes
    ui->EmpIDle->setText(QString::fromStdString(Emp.ID));
    ui->EmpNameLe->setText(QString::fromStdString(Emp.name));
    ui->EmpLastNamele->setText(QString::fromStdString(Emp.LastName));
    ui->EmpAddressle->setText(QString::fromStdString(Emp.adress));
    ui->EmpSalaryle->setText(QString::fromStdString(to_string(Emp.salary)));
    ui->EmpHireDatele->setText(QString::fromStdString(DisplayDate(Emp.HireDate)));
    ui->EmpBankBranchle->setCurrentText(QString::fromStdString(Emp.BankBranch));
}


































































































