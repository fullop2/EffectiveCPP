// 템플릿의 타입 매개변수를 선언할 때는 class와 typename의 뜻이 동일하다
#include <iostream>

template<typename C>
void print2nd(const C& container)
{
	if(container.size() >= 2)
	{
		C::const_iterator iter(container.begin());
		++iter;
		int value = *iter;
		std::cout << value;
	}
}
// iter 타입은 C::const_iterator 타입인데, 템플릿 매개변수인 C에 따라 달라지는 타입이다
// 이렇게 템플릿 내에 템플릿 매개변수에 종속된 것을 가리켜 Dependent name이라고 한다
// 이 dependent name이 어떤 클래스 안에 중첩되어 있는 경우가 있는데, 이 경우 
// nested dependent type name이라고 부른다. 타입을 참조하는 중첩 이름이라는 뜻
//
// int는 템플릿 매개변수가 어떻든 상관없는 타입 이름이다. 이런 이름을 
// 비의존 이름(non-dependent name)이라고 한다
//
// 만약 C::const_iterator * x; 로 만들었다면
// 우리의 눈에는 const_iterator 타입이라는 것을 알 수 있지만 컴파일러는 아니다
// const_iterator 타입 정적 데이터
// C::const_iterator 와 x를 피연산자로 하는 곱셈
// 등으로 볼 수 있다
//
// C가 무엇인지 알려주지 않으면 컴파일러는 C가 무엇인지 알 수 없다
// 이런 모호성을 해결하기 위해 C++에서는 템플릿 안에서 중첩 의존 이름을 만나면 
// 그것을 타입이 아니라고 해석한다
// 이렇게 멋대로 타입이 아니라고 해석한 것을 우리가 원하는 대로 타입으로
// 받아들이게 하려면 타입 앞에 typename을 붙이면 된다!
//
// typename C::const_iterator(container.begin());
//

template<typename C>				// typename 쓸 수 있음("class"와 같은 의미)
void f(const C& container,			// typename 쓰면 안 됨
		typename C::iterator iter);	// typename 꼭 써야 함


// C는 중첩 의존 이름이 아니기 때문에, 컨테이너를 선언할 때는 typename을 앞에 붙이면 안됨
// 반면 C::iterator는 중첩 의존 이름이므로 앞에 typename을 반드시 붙여야 함

template<typename C>
class Derived
:public Base<T>::Nested						// 상속되는 기본 클래스 리스트, 
								// typename 쓰면 안 됨
{	
	public:
		explicit Derived(int x)
			:Base<T>::Nested(x)			// 멤버 초기화 리스트에 있는 기본 클래스 식별자
			 					// typename 쓰면 안 됨
		{
			typename Base<T>::Nested temp;		// 중첩 의존 이름이며
								// 기본 클래스 리스트에도 없고
								// 멤버 초기화 리스트의 기본 클래스 식별자도 아님
								// : typename 필요
		}

}

// 또한 "typename은 중첩 의존 타입 이름 앞에 붙여줘야 한다"의 하나의 예외는
// 중첩 의존 이름이 기본 클래스의 리스트에 있거나 멤버 초기화 리스트 내의
// 기본 클래스 식별자로 있을 경우에는 typename을 붙여 주면 안 된다

// 반복자를 매개변수로 받는 함수 템플릿을 만드는 데 매개변수로 넘어온
// 반복자가 가리키는 객체의 사본을 temp라는 이름의 지역 변수로 만들어 놓고 싶다면

template<typename IterT>
void workWithIterator(IterT iter)
{
	typedef typename std::iterator_traits<IterT>::value_type value_type;

	value_type temp(*iter);
}
// 특성 정보 클래스에 속한 value_type 등의 멤버 이름에 대해 typedef 이름을 만들 때는
// 그 멤버 이름과 똑같이 짓는 것이 관례


