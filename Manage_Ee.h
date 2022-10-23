#pragma once
#include "Employee.h"
#include "Management.h"
#include "List.h"
#include <fstream>
class Manage_Ee : public Employee, virtual public Management
{
    private:
    List<Employee> listee;
    public:
    Manage_Ee();
    ~Manage_Ee();
    void Add(Employee);
    void Show();
    int IndexOf(int);
    void Update(int);
    void Delete(int);
    void Read_File(ifstream&);
    Employee& MHS(int);

};