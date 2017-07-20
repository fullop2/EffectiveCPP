#include <iostream>
using namespace std;

int main()
{
	char greeting[] = "Hello";
	char * csp = greeting;			// 비상수 포인터,
						// 비상수 데이터
						
	const char * ccsp = greeting;		// 비상수 포인터,
						// 상수 데이터

	char * const cscp = greeting;		// 상수 포인터,
						// 비상수 데이터
						
	const char * const ccscp = greeting;	// 상수 포인터, 
						// 상수 데이터

	return 0;
}

/* const keyword가 *의 왼쪽에 있으면 포인터가 가리키는 대상이 상수인 반면
 * const가 *의 오른쪽에 있는 경우엔 포인터 자체가 상수임
 */

class Widget
{

};

void f1(const Widget * cwp)
{}

void f2(Widget const * wcp)
{}

/* 위의 매개변수는 같은 타입이다 */
