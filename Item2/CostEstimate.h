#pragma once

class CostEstimate
{
	private:
		static const double FudgeFactor; // 정적 클래스 상수의 선언, 헤더 파일에 존재해야 함
	public:
		const double& getCost() const {return FudgeFactor;} ;
};

