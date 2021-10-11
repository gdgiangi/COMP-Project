#include "Player.h"
#include <iostream>
#include <string>
using namespace std;


// Constructor
Player::Player()
{
	this->name = new string{ "Unknown" };
	this->territoriesCollection = new vector<Territory*>();
	this->hand = new Hand();
	this->ordersList = new OrdersList();

}

// Destrucor
Player::~Player()
{
	delete name;
	name = NULL;
	delete territoriesCollection;
	territoriesCollection = NULL;
	delete hand;
	hand = NULL;
	delete ordersList;
	ordersList = NULL;
}

// Copy Constructor
Player::Player(const Player& player)
{
	name = new string();
	*name = *player.name;
	hand = new Hand();
	*hand = *player.hand;
	ordersList = new OrdersList();
	*ordersList = *player.ordersList;

	for (int i = 0; i < player.territoriesCollection->size(); i++) {
		territoriesCollection[i] = player.territoriesCollection[i];
	}


}

// Parameter Constructor
Player::Player(string* name, vector<Territory*>* territoriesCollection, Hand* hand, OrdersList* ordersList)
{
	this->name = name;
	this->territoriesCollection = territoriesCollection;
	this->hand = hand;
	this->ordersList = ordersList;
}

// Assignment Operator
Player& Player::operator = (const Player& player)
{
	return *new Player(player);
}

// Stream Insertion Operator
ostream& operator<<(ostream& out, const Player& player)
{
	out << "Player: " << *player.name << endl;
	out << "Territories Collection: " << endl;
	for (int i = 0; i < player.territoriesCollection->size(); i++) {
		//out << *player.territoriesCollection[i].getName() << endl;
	}
	out << "Hand: " << player.hand << endl;
	out << "Orders List: " << player.ordersList << endl;
	out << endl;

	return out;
}


vector<Territory*>* Player::toDefend()
{
	return getTerritoriesCollection();
}


vector<Territory*>* Player::toAttack()
{

	return getTerritoriesCollection();
}


void Player::issueOrder(Orders* order)
{
	//ordersList->move(order);
}


// Getters
string Player::getName()
{
	return *name;
}
vector<Territory*>* Player::getTerritoriesCollection()
{
	return territoriesCollection;
}
Hand* Player::getHand()
{
	return hand;
}
OrdersList* Player::getOrdersList()
{
	return ordersList;
}

//Setters
void Player::setName(string* newName)
{
	name = newName;
}
void Player::setTerritoriesCollection(vector <Territory*>* newTerritoriesCollection)
{
	territoriesCollection = newTerritoriesCollection;
}
void Player::setHand(Hand* newHand)
{
	hand = newHand;
}
void Player::setOrdersList(OrdersList* newOrdersList)
{
	ordersList = newOrdersList;
}



