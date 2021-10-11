#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Map.h"
#include "Cards.h"
#include "OrdersList.h"
using namespace std;

class Territory;
class Hand;
class OrdersList;
class Order;


class Player
{
	string* name;
	vector<Territory*>* territoriesCollection;		
	Hand* hand;
	OrdersList* ordersList;


public:

	// Constructors
	Player();		// Default Constructor
	~Player();		// Destructor
	Player(const Player&);		// Copy Constructor
	Player(string* name, vector<Territory*>* territories, Hand* hand, OrdersList* ordersList);	// Parameter Constructor


	// Methods
	Player& operator = (const Player&);		// Assignment Operator
	friend ostream& operator<< (ostream&, const Player&);		// Stream Extraction Operator
	vector<Territory*>* toDefend();			// Returns the list of territores player can defend
	vector<Territory*>* toAttack();			// Returns the list of territories player can attack
	void issueOrder(Order* newOrder);						//	Creates an order and adds it the list

	// Getters
	string getName();
	vector<Territory*>* getTerritoriesCollection();
	Hand* getHand();
	OrdersList* getOrdersList();


	// Setters
	void setName(string* name);
	void setTerritoriesCollection(vector <Territory*>*);
	void setHand(Hand* hand);
	void setOrdersList(OrdersList* ordersList);

	


};