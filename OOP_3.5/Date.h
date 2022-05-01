#pragma once
#include <iostream>

using namespace std;

class Date
{
public:
	int year;
	int day;
	int month;

	Date(): year(0), month(0), day(0){}
	Date(int y, int m, int d):year(y), month(m), day(d){}
	Date(Date& a): year(a.year), month(a.month), day(a.day){}
	~Date(){}

	//Date& operator =(Date*& a);

	friend ostream& operator <<(ostream& out, Date& a);
	friend istream& operator >>(istream& out, Date& a);
};

