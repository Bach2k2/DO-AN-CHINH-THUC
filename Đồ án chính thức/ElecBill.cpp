#include "ElecBill.h"
int ElecBill::increment = 1;
ElecBill::ElecBill()
{
	this->next = NULL;
	this->billId = increment++;
	this->price = 0;
	this->meterNumber = 0;
	this->cusID = "";
}

ElecBill::ElecBill(ElecMeter meter,Customer cus,Date beginDate,Date endDate, UnitPrice& uPrice)
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
void ElecBill::setBeginDate()
{
	Date date;
	date.setDate();
	beginDate = date;
}
void ElecBill::setEndDate()
{
	Date date;
	date.setDate();
	endDate = date;
}
Date& ElecBill::getBeginDate()
{
	return this->beginDate;
}
Date& ElecBill::getEndDate()
{
	return this->endDate;
}
void ElecBill::showBillOut()
{
	/*
	* cout << "So cong to: " << meter.getMeterNumber()
		<< "\n Ten Khach hang" << customer.getCusName()
		<< "\n so dien thoai" << customer.getPhoneNum()
		<< "\n Dia chi: " << customer.getAddress()
		<< "\n Gia dien\n"; unitPrice.showUnitPrice();
	cout << "Tong tien: " << unitPrice.getTotalPrice();
	*/
	cout << "\n*****************************************************************************" << endl;
	cout << "|\nId hoa don: " << this->getBillId();
	cout << "|\nTen Khach Hang: " << this->customer.getCusName() << "\t " << "Ma Khach Hang: " << "\t\t" << this->customer.getCusId();
	cout << "|\nSo dien thoai: " << this->customer.getPhoneNum();
	cout << "|\nDia chi: " << this->customer.getAddress();
	cout << "|\n so cong to: " << this->meter.getMeterNumber();
	cout << "|\n so dien truoc " << this->meter.getPrevMeter() << "\t\t" << "so dien sau" << this->meter.getNextMeter();
	cout << "|\n ";
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
	this->meter.setNextMeter(stof(result[1]));
	int unit = this->meter.getNextMeter() - this->meter.getPrevMeter();
	this->meter.setUnit(unit);
	this->beginDate.fromString(result[2]);
	Date d= this->beginDate += 30;
	this->endDate = d;
	}	

void ElecBill::setMeter(const ElecMeter& meter)
{
	this->meter = meter;
}
void ElecBill::setCustomer(const Customer& cus)
{
	this->customer=cus;
}
void ElecBill::setUnitPrice(UnitPrice& unitPrice1)
{
	this->unitPrice.setRank(unitPrice1);
}