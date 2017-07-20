
/* STL iterator(반복자)는 포인터를 본뜬 것이므로, 기본적인 동작원리가 T* 포인터와 흡사함
 * 어떤 iterator를 const로 선언하는 일은 포인터를 상수로 선언한느 것과 같다
 * 반복자는 자신이 가리키는 대상을 변경하는 것은 불가능 하지만,
 * 가리키는 대상 자체를 변경하는 것은 가능하다.
 * 
 * 만약 변경 불가능한 객체를 가리키는 반복자(const T* 포인터의 STL 대응물)가 필요하다면
 * const_iterator를 사용하면 된다. 
 */

#include <vector>

int main()
{
	std::vector<int> vec;

	const std::vector<int>::iterator iter = vec.begin();
					// iter는 T* const 처럼 동작한다
	*iter = 10;			// iter가 가리키는 대상을 변경한다
	++iter;				// iter는 상수라서 불가능

	std::vector<int>::const_iterator cIter = vec.begin();
					// cIter는 const T* 처럼 동작한다
	*cIter = 10; 			// cIter는 데이터가 상수이므로 불가능
	++cIter;			// cIter가 가리키는 대상을 변경하므로 가능
	
	return 0;
}
