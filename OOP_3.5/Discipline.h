#pragma once
#include <string>

using namespace std;

struct Discipline
{
	string dis_name;
	int semestr;
	int students_amount;
	int hour_lec_amount;
	int hour_pract_amount;
	bool zalic;

	double zalic_h = 0.2;
	double exam_h = 0.3;
	double sum_h;
};