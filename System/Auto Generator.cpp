#include <iostream>
#include <random>
#include <string>
using namespace std;
string generateID(); 
string generateIBAN(string , string );
string generateNC(string);
string generateCN(string, string, string);


int main() { // You can safely ignore the main function. it was used for testing purposes;
    string random=generateID();
    cout << random<<" ///iban:"<<generateIBAN(random,"A00")<<endl;
    return 1;
}

string generateID() { //returns employee Id or customer AccNum
    string Base = "23456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    random_device rd;                
    mt19937 gen(rd());               
    uniform_int_distribution<> dist(0, Base.size()-1);  
    string Id="";

    for (int i = 0; i < 12; i++) {
        int r = dist(gen);               
        Id += Base[r];
    }

    return Id;
}


string generateIBAN(string AccNum,string BrCode) { //requires a branch code and an account number 
                                                    //returns an IBAN of the format TN CN 11 Branchcode AccNum NC
    string NC = generateNC(AccNum),CN=generateCN(AccNum,BrCode,NC);
    string IBAN = "TN" + CN + "11" + BrCode + AccNum + NC;
    return IBAN;
}

string generateNC(string AccNum) { //returns NC for IBAN generation
    int NC =0 ;
    string weights = "451";
    for (int i = 0; i < AccNum.size(); i++) {
        int ascii = AccNum[i];
        int order = weights[i % 3]-48;
        if (ascii <= 57) NC += (ascii - 48) * order;
        else if (ascii <= 132) NC += (ascii - 55) * order;
        else NC += (ascii - 61) * order;
    }
    string res = to_string(97 - (NC % 97));
    return((res.size() == 1) ? "0" + res : res);
}

string generateCN(string AccNum, string BrCode,string  NC) { //returns CN for IBAN generation
    int CN = 0;
    string format = "11" + BrCode + AccNum + NC + "TN";
    for (int i = 0; i < format.size(); i++) {
        int ascii = format[i];
        if (ascii <= 57) CN += (ascii - 48);
        else if (ascii <= 132) CN += (ascii - 55);
        else CN += (ascii - 61);
    }
    string res = to_string(98 - (CN % 97));
    return((res.size() == 1) ? "0" + res : res);
}
