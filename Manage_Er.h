#pragma once
#include "Employer.h"
#include "List.h"
#include <fstream>
#include "Management.h"
class Manage_Er : virtual public Management
{
    private:
    List<Employer> lister;
    public:
    Manage_Er();
    ~Manage_Er();
    void Add(Employer);
    void Show();
    int IndexOf(int);
    void Update(int);
    void Delete(int);
    void Read_File(ifstream&);
    Employer& MS(int);
};