#include "Information.h"
//#include "Employer.h"
#include "List.h"
#include <vector>
#include <string>
#include <fstream>
#pragma once
using namespace std;
class Employer;
class Employee : public Information
{
private:
   int _MHS;
   string _Education;
   string _Experience;
   List<Employer*> employer;
   //vector<Employer*> employer;
public:
   Employee();
   Employee(string, string, string, string, string, int, string, string);
   Employee(const Employee&);
   ~Employee();
   void AddEmployer(Employer*);
   int GetMHS();
   void SetMHS(int);
   string GetEducation();
   void SetEducation(string);
   string GetExperience();
   void SetExperience(string);
   void Show();
   void Read_File(ifstream &);
   friend ostream& operator<<(ostream&, Employee& );
   void Input();
   bool operator==(const Employee&);
};
