/* duplicated code - 중복 코드
 * operator[]의 핵심 기능만 구현해두고 두번 사용하기
 * casting은 일반적으로 좋지 않은 아이디어지만 필요악
 * 비상수 멤버가 상수 멤버를 호출하도록 설계하는 것이 좋음
 */
#include <string>

class TextBlock
{
	public:
		const char& operator[](std::size_t position)
		{ return text[position];}

		char& operator[](std::size_t position)
		{ return text[position];}

	private:
		std::string text;
}

// const와 비 const의 함완전한 코드 중복 현상 발생!
// 비 const member에서 casting을 이용해 const member를 호출하여 중복 방지

class NewTextBlock
{
	public:
		const char& operator[](std::size_t position)
		{ return text[position];}

		char& operator[](std::size_t position)
		{
			return 
				const_cast<char&>(				// 반환 전에 const를 제거하는 casting
					static_cast<const NewTextBlock&>	// *this type에 const를 붙임
					(*this)[position]			// const op[]를 호출 
				);
		}
	private:
		std::string text;
}
