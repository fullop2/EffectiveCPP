#include <iostream>
#include "GamePlayer.h"
#include "CostEstimate.h"
using namespace std;

int main()
{
	GamePlayer * gpp = new GamePlayer;
	cout << gpp->getNum() << endl;
	delete gpp;

	CostEstimate * cep = new CostEstimate;
	cout << cep->getCost() << endl;
	delete cep;

	return 0;
}
