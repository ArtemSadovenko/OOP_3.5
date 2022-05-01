#include "Array.h"

void Array::create()
{
	discipline = new Discipline[n];
}

Array::Array()
{
	n = 1;
	create();
}

Array::Array(Discipline* a, int k)
{
	n = k;
	create();
	for (int i = 0; i < k; i++) {
		discipline[i] = a[i];
	}
}

Array::Array(Array& a)
{
	n = a.n;
	create();
	for (int i = 0; i < n; i++) {
		discipline[i] = a.discipline[i];
	}
}

Array::~Array()
{
	delete[] discipline;
}

Discipline& Array::operator[](int a)
{
	return discipline[n];
	// TODO: вставьте здесь оператор return
}

Array::operator string()
{
	stringstream ss;
	ss << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
	ss << "|   Discipline   |    semestr     |    Lections    |    Practice    |   Amount of students   |   Control    |   Suma of hour   |" << endl;
	ss << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		ss << "|" << setw(16) << discipline[i].dis_name << "|" << setw(9) << discipline[i].semestr << setw(8) << "|" << setw(9) << discipline[i].hour_lec_amount <<
			setw(8) << "|" << setw(9) << discipline[i].hour_pract_amount << setw(8) << "|" << setw(12) << discipline[i].students_amount << setw(13) << "|";
		if (discipline[i].zalic) {
			ss << "    zalic     |";
		}
		else {
			ss << "    exam      |";
		}
		discipline[i].sum_h = sum_hour(discipline[i]);
		ss << setw(9) << discipline[i].sum_h << setw(11) << "|\n";
		ss << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
		
	}
	return ss.str();
}

void Array::add()
{
	Array t(*this);
	n += 1;
	create();
	for(int i = 0; i < t.n; i++){
		discipline[i] = t.discipline[i];
	}
	int i = t.n;
	cout << "Enter discipline name: "; cin >> discipline[i].dis_name; //cout << a[i].dis_name;
	cout << "Enter semestr: "; cin >> discipline[i].semestr;
	cout << "Enter amount of students: "; cin >> discipline[i].students_amount;
	cout << "Exam(0)   Zalic(1): "; cin >> discipline[i].zalic;
	cout << "Enter amount of lecture houre: "; cin >> discipline[i].hour_lec_amount;
	cout << "Enter amount of practice houre: "; cin >> discipline[i].hour_pract_amount;
	discipline[i].sum_h = sum_hour(discipline[i]);
}

void Array::del(int i)
{
	if (i > n) {
		cerr << "Error del";
		exit(1);
	}
	for (int i = n; i < n - 1; i++) {
		discipline[i] = discipline[i + 1];
	}
	n -= 1;
}

double Array::sum_hour(Discipline a)
{
	if(a.zalic){
		return a.students_amount * a.zalic_h + a.hour_lec_amount + a.hour_pract_amount;
	}
	else {
		return a.students_amount * a.exam_h+ a.hour_lec_amount + a.hour_pract_amount;
	}
	
}

istream& operator<<(istream& in, Array& a)
{
	int f;
	cout << "Enter amount: "; in >> f; a.n = f;
	a.create();
	for (int i = 0; i < a.n; i++) {
		cout << "Enter discipline name: "; in >> a.discipline[i].dis_name; //cout << a[i].dis_name;
		cout << "Enter semestr: "; in >> a.discipline[i].semestr;
		cout << "Enter amount of students: "; in >> a.discipline[i].students_amount;
		cout << "Exam(0)   Zalic(1): "; in >> a.discipline[i].zalic;
		cout << "Enter amount of lecture houre: "; in >> a.discipline[i].hour_lec_amount;
		cout << "Enter amount of practice houre: "; in >> a.discipline[i].hour_pract_amount;
		a.discipline[i].sum_h = a.sum_hour(a.discipline[i]);
	}
	return in;
	// TODO: вставьте здесь оператор return
}
