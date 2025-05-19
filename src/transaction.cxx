#include "../include/transaction.hxx"
#include <iostream>
#include <sstream>
#include <ctype.h>

void Transaction::addEntry(){
    std::string beneficiary,date,time,category,item;
    double amount;
    char choice;
    std::cout<<"Input S for expense and R for earning: ";
    std::cin>>choice;
    std::cout<<std::endl;
    while(choice!='S'||choice!='R'||choice!='s'||choice!='r'){
        std::cout<<"Invalid input, enter S or R: ";
        std::cin>>choice;
        std::cout<<std::endl;
    }
    std::cout<<"Input the fields: "<<std::endl;
    std::cout<<"Beneficiary: ";
    getline(std::cin,beneficiary);
    std::cout<<std::endl;
    std::cout<<"Date: ";
    getline(std::cin,date);
    std::cout<<std::endl;
    std::cout<<"Time: ";
    getline(std::cin,time);
    std::cout<<std::endl;
    std::cout<<"Category: ";
    getline(std::cin,category);
    std::cout<<std::endl;
    std::cout<<"Item/(s): ";
    getline(std::cin,item);
    std::cout<<std::endl;

    std::cout<<"Beneficiary: "<<beneficiary<<std::endl;
    std::cout<<"Date: "<<date<<std::endl;
    std::cout<<"Time: "<<time<<std::endl;
    std::cout<<"Category: "<<category<<std::endl;
    std::cout<<"Item/(s): "<<item<<std::endl;
}