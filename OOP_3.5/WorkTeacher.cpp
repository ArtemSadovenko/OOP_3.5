#include "WorkTeacher.h"

WorkTeacher::WorkTeacher() :
	name(""), objem_h(0), objem_stv(0)
{
	Date::Date();
	Array::Array();
}

WorkTeacher::WorkTeacher(string name, Date date_, double objem_h, double objem_stv, int k, Discipline* a):
	name(name), objem_h(objem_h), objem_stv(objem_stv)
{
	Date::Date(date_);
	Array::Array(a, k);

}

WorkTeacher::WorkTeacher(WorkTeacher& a):
	name(a.name), objem_h(a.objem_h), objem_stv(a.objem_stv), date(a.date)
{
	set_n(a.get_n());
	create();
	for (int i = 0; i < a.get_n(); i++) {
		this->operator[](i) = a[i];
	}/*
	date.day = a.date.day;
	date.month = a.date.month;
	date.year = a.date.year;*/
}

WorkTeacher::~WorkTeacher()
{
	//Array::~Array();
}

Discipline& WorkTeacher::operator[](int a)
{
	return get_dis(a);
	// TODO: вставьте здесь оператор return
}

WorkTeacher::operator string()
{
	stringstream ss;
	ss << endl << name << endl << date << "Amount of hource: " << objem_h << endl
		<< "Amount of stavka: " << objem_stv << endl;
	if (objem_stv > 1.5) {
		ss << "Teacher is overload" << endl;
	}
	ss	<< Array::operator std::string();//<< &Array::operator std::string;
	return ss.str();
}

void WorkTeacher::add()
{
	Array::add();
	for (int i = 0; i < get_n(); i++) {
		objem_h += this->operator[](i).sum_h;
	}
	objem_stv = objem_h / stavka;
}

void WorkTeacher::del(int i)
{
	Array::del(i);
	for (int i = 0; i < get_n(); i++) {
		objem_h += this->operator[](i).sum_h;
	}
	objem_stv = objem_h / stavka;
}

ostream& operator<<(ostream& out, WorkTeacher& a)
{
	
	out << (string)a;
	return out;
	// TODO: вставьте здесь оператор return
}

istream& operator>>(istream& in, WorkTeacher& a)
{
	int f;
	
	//a.date = new Date(4, 5, 6);
	cout << "Entet last name: "; in >> a.name;
	cout << "Enter date: "; in >> a.date;
	in << a;
	for (int i = 0; i < a.get_n(); i++) {
		a.objem_h += a[i].sum_h;
	}
	a.objem_stv = a.objem_h / a.stavka;
	//cout << "Enter amount of disciplines: "; in >> f; a.set_n(f);
	//a.create();
	//for (int i = 0; i < a.get_n(); i++) {
	//	cout << endl;
	//	cout << "Enter discipline name: "; in >> a[i].dis_name; //cout << a[i].dis_name;
	//	cout << "Enter semestr: "; in >> a[i].semestr;
	//	cout << "Enter amount of students: "; in >> a[i].students_amount;
	//	cout << "Exam(0)   Zalic(1): "; in >> a[i].zalic;
	//	cout << "Enter amount of lecture houre: "; in >> a[i].hour_lec_amount;
	//	cout << "Enter amount of practice houre: "; in >> a[i].hour_pract_amount;
	//	a[i].sum_h = a.sum_hour(a[i]);
	//}
	return in;
	// TODO: вставьте здесь оператор return
}
