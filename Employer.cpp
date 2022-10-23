#include "Employer.h"
#include <iomanip>
#include <iostream>
using namespace std;
Employer::Employer() : Information()
{
    this->_MS = 0;
    this->_Field = " ";
    this->_Salary = " ";
    this->_Requirement = " ";
    this->_Time = " ";
    this->_NumberApply= 0;

}
Employer::Employer(string _Name, string _Year, string _Email, string _PhoneNumber, string _Address, int _MS, string _Field, string _Salary,string _Requirement, string _Time, int _NumberApply)
 : Information(_Name, _Year, _Email, _PhoneNumber, _Address)
{
    this->_MS = _MS;
    this->_Field = _Field;
    this->_Salary = _Salary;
    this->_Requirement = _Requirement;
    this->_Time = _Time;
    this->_NumberApply= _NumberApply;
}
Employer::Employer(const Employer& r) : Information(r)
{
    this->_MS = r._MS;
    this->_Field = r._Field;
    this->_Salary = r._Salary;
    this->_Requirement = r._Requirement;
    this->_Time = r._Time;
    this->_NumberApply= r._NumberApply;
}
Employer::~Employer()
{
}
int Employer::GetMS()
{
    return _MS;
}
void Employer::SetMS(int _MS)
{
    this->_MS = _MS;
}
string Employer::GetField()
{
    return _Field;
}
void Employer::SetField(string _Field)
{
    this->_Field = _Field;
}
string Employer::GetRequirement()
{
    return _Requirement;
}
void Employer::SetRequirement(string _Requirement)
{
    this->_Requirement = _Requirement;
}
string Employer::GetSalary()
{
    return _Salary;
}
void Employer::SetSalary(string _Salary)
{
    this->_Salary = _Salary;
} 
string Employer::GetTime()
{
    return _Time;
}
void Employer::SetTime(string _Time)
{
    this->_Time = _Time;
}  
int Employer::GetNumberApply()
{
    return _NumberApply;
}
void Employer::SetNumberApply(int _NumberApply)
{
    this->_NumberApply = _NumberApply;
}
void Employer::Show()
{
    cout << left << setw(5) << GetMS();
    Information::Show();
    cout << setw(25) << GetField();
    cout << setw(15) << GetRequirement();
    cout << setw(10) << GetSalary();
    cout << setw(11) << GetTime();
    cout <<right<< setw(11) << GetNumberApply() << endl;
}
void Employer::AddEmployee(Employee* e)
{
    this->employee.AddLast(e);
    e->AddEmployer(this);
}
ostream& operator<<(ostream& o,Employer& e)
{
    if (e.employee.GetLength() == 0) cout<<"Chua co ai apply cong viec nay!"<<endl;
    else
    {
        cout<<endl;
        for(int i = 0; i<e.employee.GetLength(); i++)
        {
            cout<<i+1<<": ";e.employee[i]->Show(); cout<<endl;
        }
    }
    return o;
}
void Employer::Read_File(ifstream &filein)
{
    Information::Read_File(filein);
    getline(filein, _Field, ',');
    getline(filein, _Requirement, ',');
    getline(filein, _Salary, ',');
    getline(filein, _Time, ',');
    filein >> _MS; 
    filein.ignore();
} 
void Employer::Input()
{
    cout << "\nEnter the MS: ";
    cin >> _MS;
    cin.ignore(); 
    Information::Input();
    cout << "\nEnter the field: ";
    getline(cin, _Field);
    cout << "\nEnter the requirement: ";
    getline(cin, _Requirement);
    cout << "\nEnter the salary: ";
    getline(cin, _Salary);
    cout << "\nEnter the Time: ";
    getline(cin, _Time);
    cout << "\nEnter the NumberApply: ";
    cin >> _NumberApply;
    cin.ignore();
}
bool Employer::operator==(const Employer& r)
{
    return(this->_Name == r._Name && this->_Year == r._Year && this->_Email == r._Email 
    && this->_PhoneNumber == r._PhoneNumber && this->_Address == r._Address && this->_MS == r._MS 
    && this->_Field == r._Field && this->_Salary == r._Salary && this->_Time == r._Time && this->_NumberApply == r._NumberApply );
}
// void Employer::AddEmployee(Employee* e)
// {
//     this->employee.push_back(e);
//     e->AddEmployer(this);
// }
// ostream& operator<<(ostream& o,Employer& e)
// {
//     if (e.employee.size() == 0) cout<<"Chua co ai apply cong viec nay!";
//     else
//     {
//         e.Show();
//         cout <<": "<<endl;
//         for(int i = 0; i<e.employee.size(); i++)
//         {
//             cout<<i+1<<": ";e.employee[i]->Show(); cout<<endl;
//         }
//     }
//     return o;
// }