#include "Manage_Er.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Manage_Er::Manage_Er()
{

}
Manage_Er::~Manage_Er()
{

}
void Manage_Er::Add(Employer k)
{
    lister.AddLast(k);
}
void Manage_Er::Show()
{
    if(lister.GetLength() == 0) cout <<" ";
    else 
    {
        for(int i =0; i<lister.GetLength(); i++)
        {
            lister[i].Show();
            cout<< endl;
        }
    }
}
int Manage_Er::IndexOf(int m)
{
    int index = -1;
    for(int i = 0; i<lister.GetLength(); i++)
    {
        if(lister[i].GetMS() == m)
        {
            index = i;
            break;
        }
    }
    return index;
}
void Manage_Er::Update(int m)
{
    int index = IndexOf(m);
    if(index>=0)
    {
        int select;
        do
        {

            cout <<left<<setw(35)<<"1. Update Name "<<endl;
            cout <<left<<setw(35)<<"2. Update Year "<<endl;
            cout <<left<<setw(35)<<"3. Update Email "<<endl;
            cout <<left<<setw(35)<<"4. Update PhoneNumber "<<endl;
            cout <<left<<setw(35)<<"5. Update Address "<<endl;
            cout <<left<<setw(35)<<"6. Update Requirement "<<endl;
            cout <<left<<setw(35)<<"7. Update Salary "<<endl;
            cout <<left<<setw(35)<<"8. Update Time "<<endl;
            cout <<left<<setw(35)<<"9. Update NumberApply "<<endl;
            cout <<left<<setw(35)<<"10. Exit "<<endl;
            cout <<"Select your choice: ";
            do{cin>>select;}while(select<=0 && select>10);
            switch(select)
            {
                {
                case 1:
                string n;
                cout <<"New Name = ";cin>>n;
                lister[index].SetName(n);
                system("pause");
                break;
                }
                {
                case 2:
                string year;
                cout <<"New Year = ";cin>>year;
                lister[index].SetYear(year);
                system("pause");
                break;
                }
                {
                case 3:
                string email;
                cout <<"New Email = ";cin>>email;
                lister[index].SetEmail(email);
                system("pause");
                break;
                }
                {
                case 4:
                string p;
                cout <<"New PhoneNumber = ";cin>>p;
                lister[index].SetPhoneNumber(p);
                system("pause");
                break;
                }
                {
                case 5:
                string a;
                cout <<"New Address = ";cin>>a;
                lister[index].SetAddress(a);
                system("pause");
                break;
                }
                {
                case 6:
                string e;
                cout <<"New Requirement = ";cin>>e;
                lister[index].SetRequirement(e);
                system("pause");
                break;
                }
                {
                case 7:
                string a;
                cout <<"New Salary = ";cin>>a;
                lister[index].SetSalary(a);
                system("pause");
                break;
                }
                {
                case 8:
                string a;
                cout <<"New Time = ";cin>>a;
                lister[index].SetTime(a);
                system("pause");
                break;
                }
                {
                case 9:
                int a;
                cout <<"New NumberApply = ";cin>>a;
                lister[index].SetNumberApply(a);
                system("pause");
                break;
                }
            }
        } while(select != 10);
    }
}
void Manage_Er::Delete(int m)
{
    int index = IndexOf(m);
    lister.Remove(lister[index]);
}
void Manage_Er::Read_File(ifstream &filein)
{
    while(!filein.eof())
    {
        Employer *p = new Employer ;
        p->Read_File(filein);
        this->Add(*p);
    }
}
Employer& Manage_Er::MS(int index)
{
    int m = IndexOf(index);
    return this->lister[m];
}