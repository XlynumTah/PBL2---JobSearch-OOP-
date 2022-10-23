#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Information 
{
protected:
    string _Name;
    string _Year;
    string _Email;
    string _PhoneNumber;
    string _Address;
public:
    Information();
    Information(string, string, string, string, string);
    Information(const Information&);
    ~Information();
    string GetName();
    void SetName(string);
    string GetYear();
    void SetYear(string);
    string GetEmail();
    void SetEmail(string);
    string GetPhoneNumber();
    void SetPhoneNumber(string);
    string GetAddress();
    void SetAddress(string);
    void Show();
    void Read_File(ifstream &);
    void Input();

};