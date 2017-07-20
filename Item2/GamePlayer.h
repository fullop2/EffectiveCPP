#pragma once

class GamePlayer
{
	private:
		/*
		 * static const int NumTurns = 5; // 선언 됨; 정의된 것이 아님
		 */
		enum {NumTurns = 5}; 	// 나열자 둔갑술(enum hack)
					// enum이므로 reference type을 통한 접근이 불가능함 -> #define과 비슷한 효과!	
		int scores[NumTurns];
	public:
		const int getNum() const { return NumTurns;};

};
