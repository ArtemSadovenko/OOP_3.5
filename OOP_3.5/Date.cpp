#include "Date.h"

//Date& Date::operator=(Date*& a)
//{
//    year = a->year;
//    month = a->month;
//    day = a->day;
//    return *this;
//    // TODO: вставьте здесь оператор return
//}

ostream& operator<<(ostream& out, Date& a)
{
    if (a.day < 10) {
        out << "0" << a.day;
    }
    else {
        out << a.day;
    }
    out << ".";

    if (a.month < 10) {
        out << "0" << a.month;
    }
    else {
        out << a.month;
    }
    out << ".";
    out << a.year << endl;
    return out;
    // TODO: вставьте здесь оператор return
}

istream& operator>>(istream& in, Date& a)
{
    cout << "Day: "; in >> a.day;
    cout << "Month: ";in >> a.month;
    cout << "Year: "; in >> a.year;
    return in;
    // TODO: вставьте здесь оператор return
}
