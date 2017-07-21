#include <iostream>

class CTextBlock
{
	public:
		char& operator[](std::size_t position) const
		{ return pText[position];}
		// 변경의 여지가 있지만 비트 수준 상수성을 만족해 허용되는 선언
	private:
		char *pText;
};

int main()
{
	const CTextBlock cctb("Hello");
	char *pc = &cctb[0];

	*pc = 'J';
	

	return 0;
}
