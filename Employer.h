#include "Information.h"
#include "List.h"
#include "Employee.h"
#include <vector>
#include <string>
#include <fstream>
#pragma once
using namespace std;
class Employer : public Information
{
private:
   int _MS;
   string _Field;
   string _Requirement;
   string _Salary;
   string _Time;
   int _NumberApply;
   //vector<Employee*> employee;
public:
   List<Employee*> employee;
   Employer();
   Employer(string, string, string, string, string, int, string, string, string, string, int);
   Employer(const Employer&);
   ~Employer();
   // void AddEmployee(Employee&);
   void AddEmployee(Employee*);
   int GetMS();
   void SetMS(int);
   string GetField();
   void SetField(string);
   string GetRequirement();
   void SetRequirement(string);
   string GetSalary();
   void SetSalary(string);
   string GetTime();
   void SetTime(string);
   int GetNumberApply();
   void SetNumberApply(int);
   void Show();
   void Read_File(ifstream &);
   friend ostream& operator<<(ostream&,Employer&);
   void Input();
   bool operator==(const Employer&);
};