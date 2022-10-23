#include "Information.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
Information::Information()
{
    this->_Name = " ";
    this->_Year = " ";
    this->_Email = " ";
    this->_PhoneNumber = " ";
    this->_Address = " ";
}
Information::Information(string _Name, string _Year, string _Email, string _PhoneNumber, string _Address)
{  
    this->_Name = _Name;
    this->_Year = _Year;
    this->_Email = _Email;
    this->_PhoneNumber = _PhoneNumber;
    this->_Address = _Address;
}
Information::Information(const Information& i)
{
    this->_Name = i._Name;
    this->_Year = i._Year;
    this->_Email = i._Email;
    this->_PhoneNumber = i._PhoneNumber;
    this->_Address = i._Address;
}
Information::~Information()
{
}
string Information::GetName()
{
    return _Name;
}
void Information::SetName(string _Name)
{
    this->_Name = _Name;
}
string Information::GetYear()
{
    return _Year;
}
void Information::SetYear(string _Year)
{
    this->_Year = _Year;
}
string Information::GetEmail()
{
    return _Email;
}
void Information::SetEmail(string _Email )
{
    this->_Email = _Email;
}
string Information::GetPhoneNumber()
{
    return _PhoneNumber;
}
void Information::SetPhoneNumber(string _PhoneNumber)
{
    this->_PhoneNumber = _PhoneNumber;
}
string Information::GetAddress()
{
    return _Address;
}
void Information::SetAddress(string _Address)
{
    this->_Address = _Address;
}
void Information::Show()
{
    cout << setw(25) << GetName();
    cout << setw(5) << GetYear();
    cout << setw(25) << GetEmail();
    cout << setw(12) << GetPhoneNumber();
    cout << setw(10) << GetAddress(); 

}
void Information::Read_File(ifstream &filein)
{  
    fflush(stdin);
    getline(filein, _Name,',');
    getline(filein, _Year,',');
    getline(filein,_Email,',');
    getline(filein, _PhoneNumber,',');
    getline(filein, _Address,',');
}

void Information::Input()
{
    cin.ignore(); 
    cout << "\nEnter the name: ";
    getline(cin, _Name);
    cout << "\nEnter the year: ";
    getline(cin, _Year);
    cout << "\nEnter the email: ";
    getline(cin, _Email);
    cout << "\nEnter the phone: ";
    getline(cin, _PhoneNumber);
    cout << "\nEnter the address: ";
    getline(cin, _Address);
}