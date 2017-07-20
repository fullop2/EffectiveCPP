#pragma once

class GamePlayer
{
	private:
		/*
		 * static const int NumTurns = 5; // 선언 됨; 정의된 것이 아님
		 */
		enum {NumTurns = 5}; // 나열자 둔갑술(enum hack)
		
		int scores[NumTurns];
	public:
		int getNum() { return NumTurns;};

};
