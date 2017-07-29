class Widget
{
	public:
		~Widget(){}		// 여기서 exception이 발생하면?
};

void doSomeThing()
{
	std::vector<Widget> v;
}

class DBConnection
{
	public:
		static DBConnection create();

		void close();				// 실패 시 예외를 던진다
};

class DBConn						// DBConnection을 관리하는 함수
{
	public:
		~DBConn()				// DBConnection이 항상 닫히도록 하는 함수
		{
			db.close();			// 하지만 실패하면 예외가 전파됨
		}
	private:
		DBConnection db;
}

// 예외의 전파를 막는 두가지 방법
// 프로그램 종료, 예외 삼키기
class DBConn2
{
	public:
		~DBConn2()
		{
			try { db.close() }
			catch(...)
			{
				// close 호출 실패 로그 작성
				std::abort();		//프로그램 종료, 
			}				// 이 구문이 없으면 예외를 삼킨다
			
		}
}

// 종료할지, 삼킬지 사용자에게 선택하게 하기

class DBConn3
{
	public:
		void close()			// 사용자가 DB 제거를 호출할 수 있게 만듦
		{
			db.close();
			closed = true;
		}
		~DBConn3()
		{
			if(!closed)		// 만약 닫지 않았을 경우
			try
			{
				db.close();	// 닫아본다
			}
			catch(...)
			{
				// close 호출 실패 로그 작성
			}
		}
	private:
		DBConnection db;
		bool closed;
}

