#pragma once
#include <fstream>
using namespace std;
class Management
{
    public:
    Management();
    ~Management();
    virtual void Show() = 0;
    virtual int IndexOf(int) = 0;
    virtual void Update(int) = 0;
    virtual void Delete(int) = 0;
    virtual void Read_File(ifstream&) = 0;
};
