

class Rational{};


const Rational operator*(const Rational& lhs, const Rational& rhs)	// 반환형이 const Rational이 아닐 경우
{									// a * b = c 구문의 오류를 잡을 수 없게 된다!
};


int main()
{
	Rational a,b,c;
	(a*b) = c;
	return 0;
}

