#include "List.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Manage_Ee.h"
#include "Manage_Er.h"
//#include "menu.h"
using namespace std;
void Read_File(Manage_Ee&,Manage_Er&);
void Menu(Manage_Ee& ,Manage_Er& );
void MEmployee(Manage_Ee&,Manage_Er&);
void MEmployer(Manage_Ee&,Manage_Er&);
Manage_Ee dbee;
Manage_Er dber;
int main()
{
    cout << "\n||==================================PBL2==============================||";
    cout << "\n||                        DO AN CO SO LAP TRINH                       ||";
    cout << "\n||                XAY DUNG HE THONG TIM KIEM VIEC LAM                 ||";
    cout << "\n||  Giang vien huong dan: Mai Van Ha                                  ||";
    cout << "\n||  Sinh vien thuc hien : Tran Thi My Linh                            ||";
    cout << "\n||                        Ho Thi Nhu Quynh                            ||";
    cout << "\n||  Nhom: 20.11                                                       ||";
    cout << "\n||  Lop : 20TCLC_KHDL                                                 ||";
    cout << "\n||====================================================================||\n";
    Menu(dbee,dber);
    return 0;
}
void Read_File(Manage_Ee& dbee,Manage_Er& dber)
{
    ifstream file1;     
    file1.open("Employee.txt", ios_base::in);
    if (file1.fail())
	    cout << "Failed to open this file!" << endl;
    else    
        cout << "Open this file successfully!" << endl;
    dbee.Read_File(file1);
    file1.close();
    ifstream file2;     
    file2.open("Employer.txt", ios_base::in);
    if (file2.fail())
	    cout << "Failed to open this file!" << endl;
    else    
        cout << "Open this file successfully!" << endl;   
    dber.Read_File(file2);
    file2.close();
}
void Menu(Manage_Ee& dbee,Manage_Er& dber)
{
    Read_File(dbee,dber);
    int Choice;
    do
    {
        cout << "\n||====================================================================||";
        cout << "\n||                         -------   MENU   -------                   ||";
        cout << "\n||                               1. Employee                          ||";
        cout << "\n||                               2. Employer                          ||";
        cout << "\n||                               3. Exit                              ||";
        cout << "\n||====================================================================||\n";
        cout << "\n Enter your choice: ";
        do
        {
            cin >> Choice;
        } while (Choice < 1 && Choice > 3);
        switch (Choice)
        {
            {
            case 1:
                MEmployee(dbee,dber);
                system("pause");
                break;
            }
            {
            case 2:
                MEmployer(dbee,dber);
                system("pause");
                break;
            }
        }
    } while (Choice != 3);
}
void MEmployee(Manage_Ee& dbee,Manage_Er& dber)
{
    int Choice;
    do
    {
        do
        {
        cout << "\n\t====================EMPLOYEE MANAGER====================";
        cout << "\n\t  1. Information of employee ";
        cout << "\n\t  2. Add information of employee";
        cout << "\n\t  3. Update information of employee";
        cout << "\n\t  4. Apply to employer";
        cout << "\n\t  5. List of employer applied";
        cout << "\n\t  6. Delete information of employee";
        cout << "\n\t  7. Exit";
        cout << "\n\t==========================END===========================\n";
        cout << "Enter Your Choice: ";
            cin >> Choice;
        } while (Choice < 1 || Choice > 7);
        switch (Choice)
        {
            case 1:
            {
                cout << "\n            ================================Information of Employee==================================    \n";
                cout << left << setw(5) << "MHS" << setw(25) << "Name" << setw(5) << "Year" << setw(25) << "Email"
                     << setw(12) << "PhoneNumber" << setw(10) << "Address"
                     << setw(15) << "Education" << setw(15) << "Experience" << endl;
                dbee.Show();
                system("pause");
                break;
            }
            case 2:
            {
                Employee p;
                p.Input();
                dbee.Add(p); 
                system("pause");
                break;
            }
            case 3:
            {
                int m;
                cout << "Nhap MHS can Update: ";
                cin >> m;
                dbee.Update(m);
                system("pause");
                break;
            }
            case 4:
            {
                int m;
                cout<<"Nhap MHS can thuc hien thao tac: ";
                cin >> m;
                cout<<"- Doi tuong dang thuc hien thao tac: ";
                dbee.MHS(m).Show();
                cout <<"- Danh sach cac cong viec hien co: "<<endl;
                cout << left << setw(5) << "MS" << setw(25) << "Name" << setw(5) << "Year" << setw(25) << "Email"
                     << setw(12) << "PhoneNumber" << setw(10) << "Address"
                     << setw(25) << "Field" << setw(15) << "Requirement" << setw(10) << "Salary" << setw(11) << "Time"
                     << setw(11) << "NumberApply" << endl;
                dber.Show();
                char a;
                do
                {
                    int n;
                    cout <<"Nhap MS cong viec muon apply: ";cin>>n;
                    int count = dber.MS(n).GetNumberApply();
                    // Employee *t = new Employee(dbee.MHS(m));
                    // Employer *k = new Employer(dber.MS(n));
                    // (*t).Show();
                    // (*k).Show();
                    dber.MS(n).AddEmployee(&dbee.MHS(m));
                    //cout<<dbee.MHS(m);
                    count++;
                    dber.MS(n).SetNumberApply(count);
                    cout<<"Tiep tuc apply cong viec? y/n ";cin>>a;                    
                } while (a == 'y');
                //cout<<dbee.MHS(m);
                system("pause");
                break;
            }
            case 5:
            {
                int m;
                cout<<"Nhap MHS can xem danh sach cong viec da apply: "; cin>>m;
                cout<<dbee.MHS(m);
                system("pause");
                break;
            }
            case 6:
            {
                int m;
                cout << "Nhap MHS can Delete: ";
                cin >> m;
                dbee.Delete(m);
                system("pause");
                break;
            }
        }
    }while(Choice!= 7);
}
void MEmployer(Manage_Ee& dbee,Manage_Er& dber)
{
    int Choice;
    do
    {
        do
        {
        cout << "\n\t====================EMPLOYER MANAGER====================";
        cout << "\n\t  1. Information of employer ";
        cout << "\n\t  2. Add information of employer";
        cout << "\n\t  3. Update information of employer";
        cout << "\n\t  4. Select employee";
        cout << "\n\t  5. List of employee apply";
        cout << "\n\t  6. Delete information of employer";
        cout << "\n\t  7. Exit";
        cout << "\n\t==========================END===========================\n";
        cout << "Enter Your Choice: ";
            cin >> Choice;
        } while (Choice < 1 && Choice > 7);
        switch (Choice)
        {
            case 1:
            {
                cout << "\n\t\t\t        ==================================Information of Employer==================================        \n";
                cout << left << setw(5) << "MS" << setw(25) << "Name" << setw(5) << "Year" << setw(25) << "Email"
                     << setw(12) << "PhoneNumber" << setw(10) << "Address"
                     << setw(25) << "Field" << setw(15) << "Requirement" << setw(10) << "Salary" << setw(11) << "Time"
                     << setw(11) << "NumberApply" << endl;
                dber.Show();
                system("pause");
                break;
            }
            case 2:
            {
                Employer p;
                p.Input();
                dber.Add(p);
                system("pause");
                break;
            }
            case 3:
            {
                int m;
                cout << "Nhap MHS can Update: ";
                cin >> m;
                dber.Update(m);
                system("pause");
                break;
            }
            case 4:
            {
                int n;
                cout<<"Nhap MS can thuc hien thao tac: ";
                cin >> n;
                cout<<"- Doi tuong dang thuc hien thao tac: "<<endl;
                dber.MS(n).Show();
                cout <<"- Danh sach cac ung vien hien co: "<<endl;
                cout<<dber.MS(n);
                if (dber.MS(n).employee.GetLength() == 0)
                {
                    cout<<"Khong co ung vien nao apply!"<<endl;
                    system("pause");
                    break;
                }
                else
                {
                Employer *t = new Employer(dber.MS(n));
                dber.Delete(n);
                dber.Add(*t);
                char a;
                int count = 0;
                //cout <<count;
                do
                {
                    int m;
                    cout <<"Nhap MHS ung vien muon chon: ";cin>>m;
                    // Employee *t = new Employee(dbee.MHS(m));
                    // Employer *k = new Employer(dber.MS(n));
                    // (*t).Show();
                    // (*k).Show();
                    dber.MS(n).AddEmployee(&dbee.MHS(m));
                    //cout<<dbee.MHS(m);
                    count++;
                    cout<<"Tiep tuc chon ung vien? y/n ";cin>>a;                    
                } while (a == 'y');
                //cout<<dbee.MHS(m);
                //cout<<count;
                dber.MS(n).SetNumberApply(count);
                system("pause");
                break;
                }
            }
            case 5:
            {
                int n;
                cout<<"Nhap MS can xem danh sach ung vien: "; cin>>n;
                cout<<"Thong tin nha tuyen dung: "<<endl;
                dber.MS(n).Show();
                cout<<"Danh sach ung vien: "<<endl;
                cout<<dber.MS(n);
                system("pause");
                break;
            }
            case 6:
            {
                int m;
                cout << "Nhap MS can Delete: ";
                cin >> m;
                dber.Delete(m);
                system("pause");
                break;
            }
        }
    }while(Choice!=7);
}
