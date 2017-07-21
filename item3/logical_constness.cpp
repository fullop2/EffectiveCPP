/* Logical Constness - 논리적 상수성
 * const member function이 object의 1bit도 수정할 수 없는 것이 아니라,
 * 일부 몇 bits는 바꿀 수 있되 사용자 측에서 알아채지 못하게만 하면
 * const member로 볼 수 있다는 주장
 */
#include <string>

class CTextBLock
{
	public:
		std::size_t length() const;

	private:
		char *pText;
		mutable	std::size_t textlength; // mutable 속성을 주면 어떤 순간에도
		mutable bool lengthIsValid;	// 데이터 수정이 가능하다 (상수 멤버 함수에서도)
};

std::size_t CTextBLock::length() const
{
	if(lengthIsValid)
	{
	textlength = std::strlen(pText); 	// 상수 멤버 함수이므로 대입연산이 불가능
	lengthIsValid = true;			// 마찬가지
	}					// 하지만 mutable 속성을 가지므로 가능해진다

	return textLength;
}


