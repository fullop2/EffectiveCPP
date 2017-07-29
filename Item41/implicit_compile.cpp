// OOP는 명시적 인터페이스(explicit interface)와
// 런타임 다형성(Runtime polymorphism)으로 돌아간다

class Widget
{
	public:
		Widget();
		virtual ~Widget();
		virtual std::size_t size() const;
		virtual void normalize();
		void swap(Widget& other);
};

void doProcessing(Widget& w)
{
	if(w.size() > 10 && w != someNastyWidget)
	{
		Widget temp(w);
		temp.normalize();
		temp.swap(w);
	}		
}

/* doProc~에 대해 말할 수 있는 부분은 아래와 같다
 * w는 Widget 타입으로 선언되었으므로, w는 Widget의 interface를 지원해야 함 - 명시적 인터페이스
 * Widget의 멤버 함수 중 일부는 virtual func이므로 이 함수에 대한 호출은 런타임에 이루어짐 - 런타임 다형성
 */

// 반면 doProcessing Template을 보자
template<typename T>
void doProcessing(T& w)
{
	if(w.size() > 10 && w != someNastyWidget)
	{
		T temp(w);
		temp.normalize();
		temp.swap(w);
	}
}
/* w가 지원해야 하는 인터페이스는 이 템플릿 안에서 w에 대해 실행되는 연산이 결정함
 * 지금의 경우 size,normalize,swap 멤버함수를 지원해야 함
 * 또한 복사생성자와 부등 비교 연산도 지원해야 한다
 * 이렇듯 이 템플릿이 제대로 컴파일 되려면 몇 개의 표현식이 유효해야 하는데
 * 이 표현식들이 바로 T가 지원해야 하는 암시적 인터페이스임
 *
 * w의 함수 호출이 일어날 때 (operator>나 operator!=같은) 호출을 성공시키기 위해
 * 템플릿의 인스턴스화가 일어난다. 이 인스턴스화는 컴파일 타임에 진행되고
 * 함수 템플릿에 어떤 매개변수가 들어가냐에 따라 호출되는 함수가 달라지므로
 * 이것을 컴파일 타임 다형성이라고 한다
 */


