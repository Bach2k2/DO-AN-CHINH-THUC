#include "ElecMeter.h"
#include <iostream>
#include<string>
using namespace std;
ElecMeter::ElecMeter() {
    this->meterNumber = 0;
    this->prevMeter = 0;
    this->nextMeter = 0;
    this->unit = 0;
    this->next = NULL;
}
ElecMeter::ElecMeter(int meterNumber, int prevMeter, int afterMeter)
{
    this->meterNumber = meterNumber;
    this->prevMeter = prevMeter;
    this->nextMeter = afterMeter;
    this->unit = afterMeter - prevMeter;
    this->next = NULL;
}
ElecMeter::ElecMeter(const ElecMeter& meter)
{
    this->meterNumber = meter.meterNumber;
    this->prevMeter = meter.prevMeter;
    this->nextMeter = meter.nextMeter;
    this->unit = this->nextMeter - this->prevMeter;
    this->next = NULL;
}
ElecMeter::~ElecMeter()
{
}
ostream& operator<<(ostream& os,const ElecMeter& meter)
{
    os << meter.meterNumber <<"\t\t" << meter.prevMeter << " " << meter.nextMeter << " " << meter.unit << endl;
    return os;
}
void ElecMeter::setUnit(int unit)
{
    this->unit = unit;
}
void  ElecMeter::setMeterNumber(int number)
{
    this->meterNumber = number;
}
void ElecMeter::setPrevMeter(int meter)
{
    this->prevMeter = meter;
}
void ElecMeter::setNextMeter(int meter)
{
    this->nextMeter = meter;
}
void ElecMeter::writeFile(string path)
{
    fstream file(path);
    if (file.is_open())
    {
        file << "So cong to " << "\t\t" << "so dien truoc" << "\t\t" << "so dien sau" << "\t\t" << "so dien tieu thu" << endl;
        file << this->meterNumber << "\t\t" << this->prevMeter << "\t\t" << this->nextMeter<< "\t\t" << this->unit << endl;     
    }
    else
    {
        cout << "Khong thay file can tim" << endl;
    }
}
void ElecMeter::fromString(string line)
{
    string result[10];
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
   
    this->meterNumber = stof(result[0]);
    this->prevMeter = stof(result[1]);
    this->nextMeter = stof(result[2]);
    this->unit = this->nextMeter - this->prevMeter;
}
