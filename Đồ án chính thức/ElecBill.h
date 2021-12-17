#pragma once
#include "ElecMeter.h"
#include "Customer.h"
#include "UnitPrice.h"
#include "Date.h"
class ElecBill
{
private:
    int billId;
    static int increment; // id tu tang
    Date beginDate;
    Date endDate;
    double price;
    UnitPrice unitPrice;
public:
    int meterNumber;
    string cusID;
    ElecMeter meter; // cong to
    Customer customer;// khach hang
    ElecBill* next;
    ElecBill();
  //  ElecBill(int billId, int, int, int, string, string, string ,string,Date,Date,UnitPrice&);
    ElecBill(ElecMeter,Customer,Date,Date,UnitPrice&);
    ElecBill(const ElecBill&);
    ~ElecBill();
    void setBillId(int);
    int getBillId() { return this->billId; };
   // void setAllData();
    void setBeginDate();
    Date& getBeginDate();
    Date& getEndDate();
    void setMeter(const ElecMeter &);
    void setCustomer(const Customer&);
    void setEndDate();
    void calcBill();
    void showUnitPrice();
    void showBillOut();
    void fromStringId(string);
    void fromStringMonth(string);
    void setUnitPrice(UnitPrice&);
};