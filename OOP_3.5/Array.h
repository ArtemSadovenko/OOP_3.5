#pragma once
#include "Discipline.h"
#include <iostream>
#include <sstream>
#include <iomanip>

class Array
{private:
	Discipline* discipline;
	int n;
public:
	void create();
	Discipline& get_dis(int i) { return discipline[i]; }


	Array();
	Array(Discipline* a, int k);
	Array(Array& a);
	~Array();



	void set_n(int a) { n = a; }
	int get_n() { return n; }

	Discipline& operator [](int a);
	operator string();

	friend istream& operator <<(istream& in, Array& a);

	void add();
	void del(int i);

	double sum_hour(Discipline a);
	
};

