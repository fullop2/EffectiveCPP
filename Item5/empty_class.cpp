// 클래스를 비어있게 만들어도 빈 클래스가 아닐 수 있다!

#include <string>

class Empty_{}; // 이렇게 만든 클래스는

class Empty
{
	public:
		Empty() {}				// 기본 ctor
		Empty(const Empty& rhs) {}		// 복사 ctor
		~Empty(){}				// dtor
		Empty& operator=(const Empty& rhs) {}	// 복사 대입 operator
}
// 이 클래스와 근본적으로 같다

template<typename T>
class NamedObject
{
	public:
		NamedObject(const std::string& name, const T& value);

	private:
		std::string& nameValue;
		const T objectValue;
};

int main()
{
	std::string newDog("Persephone");
	std::string oldDog("Satch");

	NamedObject<int> p{newDog,2};
	NamedObject<int> s{oldDog,36};

	// p=s; // 애매한 대입연산이 이루어지므로 
		//컴파일러는 암시적 복사 대입연산을 거부한다
}


/*
 * 컴파일러는 경우에 따라 클래스에 대해 기본 생성자, 복사 생성자,
 * 복사 대입 연산자, 소멸자를 암시적으로 만들어 놓을 수 있다
 */

