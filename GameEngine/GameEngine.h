#pragma once
#include <string>
using namespace std;

struct StateNode{
public:
	//Constuctors
	StateNode();
	StateNode(string, StateNode*);
	StateNode(string, StateNode*, StateNode*);
	StateNode(const StateNode&);
	//Getter methods
	string getName();
	StateNode* getNextState1();
	StateNode* getNextState2();
	//Setter methods
	void setName(string);
	void setNextState1(StateNode*);
	void setNextState2(StateNode*);
private:
	//Node data values
	string name;
	StateNode* nextState1;
	StateNode* nextState2;
};

class GameDriver {
public:
	StateNode* initiliazeStates(); //Initliaze multi-linked list of StateNodes
	void deleteStates(); //Delete multi-linked list of StateNodes
	void playGame(StateNode*); //Driver method that takes input and determines appropriate transition 
	StateNode* transition(string, StateNode*); //Validate transition 
};