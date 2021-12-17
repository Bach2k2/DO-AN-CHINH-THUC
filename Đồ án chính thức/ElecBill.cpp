#include "ElecBill.h"
#include <iomanip>
int ElecBill::increment = 1;
ElecBill::ElecBill()
{
	this->next = NULL;
	this->billId = increment++;
	this->price = 0;
	this->meterNumber = 0;
	this->cusID = "";
}

ElecBill::ElecBill(ElecMeter meter, Customer cus, Date beginDate, Date endDate, UnitPrice& uPrice)
{
	this->billId = increment++;
	this->meter = meter;
	this->customer = cus;
	this->cusID = "";
	this->beginDate = beginDate;
	this->endDate = endDate;
	this->next = NULL;
	this->price = 0;
}
ElecBill::ElecBill(const ElecBill& bill)
{
	this->customer = bill.customer;
	this->meterNumber = bill.meterNumber;
	this->billId = bill.billId;
	this->beginDate = bill.beginDate;
	this->endDate = bill.endDate;
	this->price = bill.price;
	this->next = bill.next;
}
ElecBill::~ElecBill()
{
}
void ElecBill::setBillId(int Billid)
{
	this->billId = Billid;
}
void ElecBill::calcBill()
{
	// Them unit vao
	int unit = meter.getUnit();
	unitPrice.setUnit(unit);
	unitPrice.calcPrice();
	this->price = this->unitPrice.getTotalPrice();
}
void ElecBill::showUnitPrice()
{
	calcBill();
	unitPrice.showUnitPrice();
}
// Nhap tu ban phim
void ElecBill::setBeginDate(Date& date)
{
	this->beginDate = date;
}
void ElecBill::setEndDate(Date& date)
{
	this->endDate = date;
}
Date& ElecBill::getBeginDate()
{
	return this->beginDate;
}
Date& ElecBill::getEndDate()
{
	return this->endDate;
}
double ElecBill::getPrice()
{
	return price;
}
void ElecBill::showBillOut()
{
	cout << "\n *****************************************************************************";
	cout << "\n\tId hoa don : " << setw(5) << this->getBillId();
	cout << "\n|" << "\tTen Khach Hang: " << setw(15) << this->customer.getCusName() << "\t || \t " << "Ma Khach Hang: " << setw(10) << this->customer.getCusId();
	cout << "\n|" << "\tSo dien thoai : " << setw(10) << this->customer.getPhoneNum();
	cout << "\n|" << "\tDia chi : " << setw(30) << this->customer.getAddress();
	cout << "\n|" << "\tSo cong to : " << setw(5) << this->meter.getMeterNumber();
	cout << "\n|" << "\tSo dien truoc: " << setw(4) << this->meter.getPrevMeter() << setw(20) << "So dien sau: " << this->meter.getNextMeter();
	cout << "\n\t";
	this->showUnitPrice();
	cout << "\n*****************************************************************************" << endl;
}
void ElecBill::fromStringId(string line)
{
	/*
	* string result[2];
	string cell;
	int count = 0;
	for (int i = 0; i <= line.length(); i++)
	{
		if (line[i] == ',' || i == line.length())
		{
			result[count++] = cell;
			cell = "";
		}
		else
		{
			cell += line[i];
		}
	}
	int value1 = stof(result[0]);
	cout << " Cai 1: " << value1<<endl;
	this->meter.setMeterNumber(value1);
	this->meterNumber = value1;
	string value2 = result[1];
	cout << " Cai 2: " << value2 << endl;
	this->customer.setCusId(value2);
	this->cusID = value2;
	*/

}
void ElecBill::fromStringMonth(string line)
{
	string result[4];
	string cell;
	int count = 0;
	for (int i = 0; i <= line.length(); i++)
	{
		if (line[i] == ',' || i == line.length())
		{
			result[count++] = cell;
			cell = "";
		}
		else {
			cell += line[i];
		}
	}

	this->meterNumber = stof(result[0]);

	int n_prevMeter = this->meter.getNextMeter();

	this->meter.setNextMeter(stof(result[1]));// Gán giá trị chỉ số sau từ file;
	this->meter.setPrevMeter(n_prevMeter);
	int unit = this->meter.getNextMeter() - this->meter.getPrevMeter();
	this->meter.setUnit(unit);
	this->beginDate.fromString(result[2]);
	Date d = this->beginDate += 30;
	this->endDate = d;
}

void ElecBill::setMeter(const ElecMeter& meter)
{
	this->meter = meter;
}
void ElecBill::setCustomer(const Customer& cus)
{
	this->customer = cus;
}
void ElecBill::setUnitPrice(UnitPrice& unitPrice1)
{
	this->unitPrice.setRank(unitPrice1);
}