#include "Manage_Ee.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

Manage_Ee::Manage_Ee()
{

}
Manage_Ee::~Manage_Ee()
{
//chua luu kia :v
}
void Manage_Ee::Add(Employee k)
{
    this->listee.AddLast(k); 
}
void Manage_Ee::Show()
{
    if(listee.GetLength() == 0) cout <<" ";
    else 
    {
        for(int i =0; i<listee.GetLength(); i++)
        {
            listee[i].Show();
            //cout<< endl;
        }
    }
}
int Manage_Ee::IndexOf(int m)
{
    int index = -1;
    for(int i = 0; i<listee.GetLength(); i++)
    {
        if(listee[i].GetMHS() == m)
        {
            index = i;
            break;
        }
    }
    return index;
}
void Manage_Ee::Update(int m)
{
    int index = IndexOf(m);
    if(index>=0)
    {
        int select;
        do
        {
            do
            {
            cout <<setw(35)<<"1. Update Name "<<endl;
            cout <<setw(35)<<"2. Update Year "<<endl;
            cout <<setw(35)<<"3. Update Email "<<endl;
            cout <<setw(35)<<"4. Update PhoneNumber "<<endl;
            cout <<setw(35)<<"5. Update Address "<<endl;
            cout <<setw(35)<<"6. Update Education "<<endl;
            cout <<setw(35)<<"7. Update Experiece "<<endl;
            cout <<setw(35)<<"8. Exit "<<endl;
            cout <<"Select your choice: ";
            cin>>select;
            }while(select<=0 && select>8);
            switch(select)
            {
                {
                case 1:
                string n;
                cout <<"New Name = ";cin>>n;
                listee[index].SetName(n);
                system("pause");
                break;
                }
                {
                case 2:
                string year;
                cout <<"New Year = ";cin>>year;
                listee[index].SetYear(year);
                system("pause");
                break;
                }
                {
                case 3:
                string email;
                cout <<"New Email = ";cin>>email;
                listee[index].SetEmail(email);
                system("pause");
                break;
                }
                {
                case 4:
                string p;
                cout <<"New PhoneNumber = ";cin>>p;
                listee[index].SetPhoneNumber(p);
                system("pause");
                break;
                }
                {
                case 5:
                string a;
                cout <<"New Address = ";cin>>a;
                listee[index].SetAddress(a);
                system("pause");
                break;
                }
                {
                case 6:
                string e;
                cout <<"New Education = ";cin>>e;
                listee[index].SetEducation(e);
                system("pause");
                break;
                }
                {
                case 7:
                string a;
                cout <<"New Experience = ";cin>>a;
                listee[index].SetExperience(a);
                system("pause");
                break;
                }
            }
        } while(select != 8);
    }
}
void Manage_Ee::Delete(int m)
{
    int index = IndexOf(m);
    listee.Remove(listee[index]);
}
void Manage_Ee::Read_File(ifstream &filein)
{
    while(!filein.eof())
    {
        Employee *p = new Employee ;
        p->Read_File(filein);
        this->Add(*p);
    }
}
Employee& Manage_Ee::MHS(int index)
{
    int m = IndexOf(index);
    return this->listee[m];
}
