#pragma once
#include "Customer.h"
class CustomerService
{
public:
    Customer* cusHead;
    Customer* cusTail;
    static int cusAmount;
public:
    CustomerService();
    ~CustomerService();
    void enqueue();
    void enqueue(Customer* customer);//them sau
    bool isEmpty();
    void dequeue();//Xoa dau
    void update();
    void display();
    void searchByName();
    bool contain(string);
    Customer& getACus(string);
    //   void setData();
    void readDataInFile(string);//Doc file
    void showInfoByMkh(string);
    void writeDataInFile(string);
    void displayUpdateMenu();
    void sortByName();
};

