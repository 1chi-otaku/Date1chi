#include <iostream>
#include "Date.h"
using namespace std;
int main() {
	//Checking operators
	Date obj(16,5,2022);
	Date obj2(obj + 1);
	obj2.Print();
	Date obj3(obj2 - 25);
	obj3.Print();
	obj = obj2 - obj;
	obj.Print();
	obj = obj2 + obj;
	obj.Print();
	obj += 10;
	obj.Print();
	obj -= 50;
	obj.Print();

	cout << endl;
	cout << "obj - "; obj.Print();
	cout << "obj2 - "; obj2.Print();


	if (obj2 > obj) cout << "obj 2  > obj" << endl;
	else cout << "obj > obj2" << endl;
	obj = (12, 10, 2077);
	cout << "obj - "; obj.Print();
	cout << "obj2 - "; obj2.Print();
	if (obj2 < obj) cout << "obj 2  < obj" << endl;
	else cout << "obj > obj2" << endl;
	obj2 = obj;
	cout << "obj - "; obj.Print();
	cout << "obj2 - "; obj2.Print();
	if (obj2 == obj) cout << "obj2 == obj" << endl;
	else cout << "obj != obj2" << endl;
	obj = (1, 12, 2014);
	cout << "obj - "; obj.Print();
	cout << "obj2 - "; obj2.Print();
	if (obj2 != obj) cout << "obj2 != obj" << endl;
	else cout << "obj == obj2" << endl;

	for (int i = 0; i < 93;i++) {
		obj++;
		obj.Print();
	}
		

	return 0;
}