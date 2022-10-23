#include "Employer.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
Employee::Employee() : Information()
{
    this->_MHS = 0;
    this->_Education = " ";
    this->_Experience = " ";
}
Employee::Employee(string _Name, string _Year, string _Email, string _PhoneNumber, string _Address,int _MHS, string _Education, string _Experience)
 : Information(_Name, _Year, _Email, _PhoneNumber, _Address)
{
    this->_MHS = _MHS;
    this->_Education = _Education;
    this->_Experience = _Experience; 
}
Employee::Employee(const Employee& e) : Information(e)
{
    this->_MHS = e._MHS;
    this->_Education = e._Education;
    this->_Experience = e._Experience;  
}
Employee::~Employee()
{
}
void Employee::AddEmployer(Employer* e)
{
    this->employer.AddLast(e);
}
ostream& operator<<(ostream& o,Employee& e)
{
    if (e.employer.GetLength() == 0) cout<<"Chua apply cong viec nao!";
    else
    {
        e.Show();
        cout<<"  "<<e.GetName()<<" da apply cong viec: "<<endl;
        for(int i = 0; i<e.employer.GetLength(); i++)
        {
            cout<<i+1<<": ";e.employer[i]->Show(); cout<<endl;
        }
    }
    return o;
}
int Employee::GetMHS()
{
    return _MHS;
}
void Employee::SetMHS(int _MHS)
{
    this->_MHS = _MHS;
}
string Employee::GetEducation()
{
    return _Education;
}
void Employee::SetEducation(string _Education)
{
    this->_Education = _Education;
}
string Employee::GetExperience()
{
    return _Experience;
}
void Employee::SetExperience(string _Experience)
{
    this->_Experience = _Experience;
}
void Employee::Show()
{
    cout << left << setw(5) << GetMHS();
    Information::Show();
    cout << setw(15) << GetEducation();
    cout << setw(15) << GetExperience();
    cout << endl;
}
void Employee::Read_File(ifstream &filein)
{  
    fflush(stdin);
    Information::Read_File(filein);
    getline(filein, _Education,',');
    getline(filein, _Experience,',');
    filein >> _MHS;
    filein.ignore();
}
void Employee::Input()
{
    cout << "\nEnter MHS: ";
    cin >> _MHS;

    Information::Input();
    cout << "\nEnter the education: ";
    getline(cin, _Education); 
    cout << "\nEnter the experience: ";
    getline(cin, _Experience);
    cin.ignore();
}
bool Employee::operator==(const Employee& e)
{
    return(this->_Name == e._Name && this->_Year == e._Year && this->_Email == e._Email 
    && this->_PhoneNumber == e._PhoneNumber && this->_Address == e._Address && this->_MHS == e._MHS 
    && this->_Education == e._Education && this->_Experience == e._Experience);
}
// void Employee::AddEmployer(Employer* e)
// {
//     this->employer.push_back(e);
// }
// ostream& operator<<(ostream& o, Employee& e)
// {
//     if (e.employer.size() == 0) cout<<"Chua apply cong viec nao!";
//     else
//     {
//         e.Show();
//         cout<<"  "<<e.GetName()<<" da apply cong viec: "<<endl;
//         for(int i = 0; i<e.employer.size(); i++)
//         {
//             cout<<i+1<<": ";e.employer[i]->Show();cout<<endl;
//         }
//     }
//     return o;
// }
// void Employee::AddEmployer(Employer* e)
// {
//     this->employer.push_back(e);
// }
// void Employee::Show()
// {
//     cout << setw(5)<< "MHS = "<<this->_MHS << ", Education = " << _Education <<", Experience = " <<_Education<<endl;
//     if (this->employer.size() == 0) cout <<setw(5)<< " "<<"Chua apply cong viec nao!";
//     else
//     {
//         cout << setw(5)<<" "<<"Cac cong viec da apply: "<< endl;
//         for(int i = 0; i<this->employer.size(); i++)
//         {
//             cout<<setw(5)<<" "<<this->employer[i]->
//         }
//     }
// }
