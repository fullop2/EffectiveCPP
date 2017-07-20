#include <iostream>
using namespace std;

void f(int x) {};

// 인라인 함수에 대한 템플릿
template<typename T>
inline void callWithMax(const T& a, const T& b) // 상수 객체에 대한 참조자를 사용
{
	f(a > b ? a : b);
}


int main()
{
	int a = 5, b = 0;
	callWithMax(++a, b);
	cout << a << " " << b << endl;
	a = 5; b = 0;
	callWithMax(++a, b+10);
	cout << a << " " << b << endl;
	return 0;
}

