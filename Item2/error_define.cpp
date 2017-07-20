#include <iostream>

void f(int a){};

#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))
using namespace std;

int main()
{
	int a = 5, b = 0;

	CALL_WITH_MAX(++a,b);
	cout << "a : " << a << " b : " << b << endl;
	a= 5; b = 0;
	CALL_WITH_MAX(++a,b+10);
	cout << "a : " << a << " b : " << b << endl;
	return 0;
}
