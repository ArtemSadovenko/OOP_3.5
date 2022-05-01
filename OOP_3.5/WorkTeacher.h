#pragma once
#include "Date.h"
#include "Array.h"
class WorkTeacher :
    public Array
{
private:
    string name;
    Date date;
    double objem_h = 0;
    double objem_stv = 0;
    const double stavka = 3000;
public:
    void set_name(string a) { name = a; }
    void set_date(Date a) { date = a; }
    void set_objem_h(int a) { objem_h = a; }
    void set_objem_stv(int a) { objem_stv= a; }

    string get_name() { return name; }
    Date get_date() { return date; }
    double get_objem_stv() { return objem_stv; }
    double get_objem_h() { return objem_h; }

    WorkTeacher();
    WorkTeacher(string name,Date date_,double objem_h,double objem_stv, int k, Discipline* a);
    WorkTeacher(WorkTeacher& a);
    ~WorkTeacher();

    Discipline& operator[](int a);

    friend ostream& operator << (ostream & out, WorkTeacher & a);
    friend istream& operator >> (istream& in, WorkTeacher& a);

    operator string();

    void add();
    void del(int i);
};

