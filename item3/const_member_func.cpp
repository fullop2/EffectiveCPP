/* member func에 붙는 const의 역할은 
 * '해당 member func가 const object에 대해 호출될 함수이다'
 * 라는 사실을 알려 주는 것이다
 * 
 * const 키워드가 있고 없고의 차이만 있는 member func은 overloading이 가능하다
 */
#include <iostream>
#include <string>

class TextBlock
{
	public:
		const char& operator[](std::size_t position) const // 상수 객체에 대한 operator[]
		{ return text[position];};

		char& operator[](std::size_t position) 	// 비상수 객체에 대한 operator[]
		{ return text[position];};		// 비상수 객체의 return value가 ref type이 아닐 경우 복사 되므로 
							// ref type으로 반환해야 제대로 값을 수정할 수 있음

	private:
		std::string text;
}

void print(const TextBLock& ctb)
{
	std::cout << ctb[0];
}

int main()
{
	TextBlock tb("Hello");
	std::cout << tb[0];
	tb[0] = 'x';

	const TextBlock ctb("World");
	std::cout << ctb[0];
	//	ctb[0] = 'x'; 	// const TextBlock 타입이므로 상수 객체에 대한 
				// operator[]이 호출되어 오류 발생
}

