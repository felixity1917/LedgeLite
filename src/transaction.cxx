#include "include/transaction.hxx"
#include <iostream>
#include <sstream>
#include <ctype.h>
using namespace std;

void Transaction::addEntry(){
    string beneficiary,date,time,category,item;
    double amount;
    char choice;
    cout<<"Input S for expense and R for earning: ";
    cin>>choice;
    cout<<endl;
    while(choice!='S'||choice!='R'||choice!='s'||choice!='r'){
        cout<<"Invalid input, enter S or R: ";
        cin>>choice;
        cout<<endl;
    }
    cout<<"Input the fields: "<<endl;
    cout<<"Beneficiary: ";
    getline(cin,beneficiary);
    cout<<endl;
    cout<<"Date: ";
    getline(cin,date);
    cout<<endl;
    cout<<"Time: ";
    getline(cin,time);
    cout<<endl;
    cout<<"Category: ";
    getline(cin,category);
    cout<<endl;
    cout<<"Item/(s): ";
    getline(cin,item);
    cout<<endl;

    cout<<"Beneficiary: "<<beneficiary<<endl;
    cout<<"Date: "<<date<<endl;
    cout<<"Time: "<<time<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Item/(s): "<<item<<endl;
}