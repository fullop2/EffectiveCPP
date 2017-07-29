class Uncopyable
{
	protected:
		Uncopyable() {}					// 생성과 소멸을
		~Uncopyable() {}				// 허용한다
	private:
		HomeForSale(const HomeForSale&);		// 복사 방지
		HomeForSale& operator=(const HomeForSale&); 	
};

class HomeForSale : private Uncopyable		// 복사 생성자, 복사 대입 연산자 사용 불가
{
	
};

/* 
 * 컴파일러에서 자동으로 제공하는 기능을 막으려면, 대응되는 멤버 함수를 private로 
 * 선언한 후에 구현은 하지 않은 채로 둔다. Uncopyable과 비슷한 기본 클래스를 사용하는 것도 가능
 */

