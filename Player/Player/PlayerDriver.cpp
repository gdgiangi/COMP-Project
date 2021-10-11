#include "Player.h"
#include <iostream>



int main() {

	Territory* t1 = new Territory();
	Territory* t2 = new Territory();

	vector<Territory*>* territories = new vector<Territory*>{ t1, t2 };
	Hand* hand = new Hand();
	OrdersList* ordersList = new OrdersList();

	string* name = new string("P");

	Player* p1 = new Player(name, territories, hand, ordersList);

	vector<Territory*>* attack = p1->toAttack();
	vector<Territory*>* defend = p1->toDefend();


	Orders* newOrder = new Orders();
	p1->issueOrder(newOrder);


	cout << *p1;

	cout << p1->getHand();
	vector<Territory*>* list = p1->getTerritoriesCollection();
	for (int i = 0; i < list->size(); i++)
	{
		//cout << *list[i];

	}

	return 0;
}
