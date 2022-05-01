#include "WorkTeacher.h"

int main() {
	bool cont;
	WorkTeacher a;
	cin >> a;
	cout << a;
	//WorkTeacher b(a);
	//cout << b;

	cout << "Would you like to add new discipline&\n\tyes(1)\n\tno(o)\n"; cin >> cont;
	if (cont) {
		a.add();
		cout << a;
	}

	cout << "Would you like to delete discipline&\n\tyes(1)\n\tno(o)\n"; cin >> cont;
	if (cont) {
		int r;
		cout << "Enter num of discipline"; cin >> r;
		a.del(r-1);
		cout << a;
	}
}