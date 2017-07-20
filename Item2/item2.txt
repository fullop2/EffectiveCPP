// Item 2 : Prefer consts, enums, and inlines to #defines
/*
 * 선행처리자(Preprocessor)보다 컴파일러를 더 가까이 하자
 *
 * 아래의 코드를 보자
 *
 * #define ASPECT_RATIO 1.653
 * 위의 코드는 선행처리자가 컴파일 전에 ASPECT_RATIO를 1.653으로 치환하는 과정을 거친다
 * 이 경우 에러가 발생하면 오류에 1.653을 출력하며 문제 해결을 어렵게 만든다
 *
 * 이런 문제의 해결법은 매크로 대신 상수를 쓰는 것이다
 * const double AspectRatio = 1.653;
 * 
 * #define을 상수로 교채할 경우 주의해야할 점
 * 1. 상수 포인터(constant pointer)를 정의하는 경우
 * 	상수 정의는 헤더 파일에 넣는 것이 상례이므로 포인터와 그가 가리키는 대상까지 상수로 선언해야 한다
 * 	const char * const authorName = "Scott Meyers";
 * 	그리고 문자열 상수를 쓸 때는 std::string을 사용하는 것이 더 좋다
 * 	const std::string authorName("Scott Meyers");
 * 2. 클래스 멤버를 상수로 정의하는 경우
 * 	
