#include "GameEngine.h"
#include <iostream>

//----------------StateNodeClassImplementation----------------------------//

void StateNode::setName(string stateName) {
	//Set this node name to passed name value
	this->name = stateName; 
}

string StateNode::getName() {
	//return value of node name
	return this->name; 
}

void StateNode::setNextState1(StateNode* nextState) {
	//set pointer of primary next state node 
	this->nextState1 = nextState; 
}

void StateNode::setNextState2(StateNode* nextState) {
	//set pointer of secondary next state node 
	this->nextState2 = nextState; 
}

StateNode* StateNode::getNextState1() {
	//return pointer to primary next state
	return this->nextState1; 
}

StateNode* StateNode::getNextState2() {
	//return pointer to secondary next state
	return this->nextState2; 
}

//default constructor, set all data values to null
StateNode::StateNode() { 

}

//constructor with 1 next state node
StateNode::StateNode(string stateName, StateNode* nextState) { 
	this->name = stateName;
	this->nextState1 = nextState;
	this->nextState2 = nullptr;
}

//copy constructor
StateNode::StateNode(const StateNode& copy) {
	name = *new string (copy.name);
	nextState1 = new StateNode(*(copy.nextState1));
	nextState2 = new StateNode(*(copy.nextState2));
}

//stream operator
std::ostream & operator<<(std::ostream & out, const StateNode & state)
{
	return out << "State: " << state.name;
}

//assignment operator
StateNode & StateNode::operator=(const StateNode &rightSide)
{
	name = rightSide.name;
	nextState1 = rightSide.nextState1;
	nextState2 = rightSide.nextState2;
	return *this;
}

//methods
StateNode* StateNode::initiliazeStates() {
	StateNode* currentState = nullptr;

	//Initiliaze states with their primary next state
	StateNode* win = new StateNode("win", nullptr);
	StateNode* executeOrders = new StateNode("executeOrders", win);
	StateNode* issueOrders = new StateNode("issueOrders", executeOrders);
	StateNode* assignReinforcements = new StateNode("assignReinforcements", issueOrders);
	StateNode* playersAdded = new StateNode("playersAdded", assignReinforcements);
	StateNode* mapValidated = new StateNode("mapValidated", playersAdded);
	StateNode* mapLoaded = new StateNode("mapLoaded", mapValidated);
	StateNode* start = new StateNode("start", mapLoaded);

	//Set secondary next states 
	win->setNextState2(start);
	executeOrders->setNextState2(assignReinforcements);

	//Return pointer to start state
	currentState = start;
	return currentState;
	
	//NO DELETION = MEMORY LEAK?
}

//method responsible for collecting user commands
void StateNode::playGame(StateNode* startNode) {
	StateNode* temp = startNode; //initiliaze start node
	
	cout << "STATE: start" << endl;

	string input;

	do {
		cin >> input;
		temp = transition(input, temp);
	} while (temp != nullptr);
	//Continue commands until game is done

}

//method responsible for verifying transition commands
StateNode* StateNode::transition(string command, StateNode* currentState) {
	if (currentState->getName() == "start") { //check name of current statenode
		if (command == "loadmap") { //determine valid commands for states
			cout << "STATE: mapLoaded" << endl;
			return currentState->getNextState1(); //return pointer to next state node
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: start (unchanged)" << endl;
			return currentState;
		}
	}
	else if(currentState->getName() == "mapLoaded") {
		if (command == "validatemap") {
			cout << "STATE: mapValidated" << endl;
			return currentState->getNextState1();
		}
		else if (command == "loadmap") {
			cout << "STATE: mapLoaded" << endl;
			return currentState;
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: mapLoaded (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "mapValidated") {
		if (command == "addplayer") {
			cout << "STATE: playersAdded" << endl;
			return currentState->getNextState1();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: mapValidated (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "playersAdded") {
		if (command == "addplayer") {
			cout << "STATE: playersAdded" << endl;
			return currentState;
		}
		else if (command == "assigncountries") {
			cout << "STATE: assignReinforcement" << endl;
			return currentState->getNextState1();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: playersAdded (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "assignReinforcements") {
		if (command == "issueorder") {
			cout << "STATE: issueOrders" << endl;
			return currentState->getNextState1();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: assignReinforcements (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "issueOrders") {
		if (command == "issueorder") {
			cout << "STATE: issueOrders" << endl;
			return currentState;
		}
		else if (command == "endissueorders") {
			cout << "STATE: executeOrders" << endl;
			return currentState->getNextState1();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: issueOrders (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "executeOrders") {
		if (command == "execorder") {
			cout << "STATE: executeOrders" << endl;
			return currentState;
		}
		else if (command == "win") {
			cout << "STATE: win" << endl;
			return currentState->getNextState1();
		}
		else if (command == "endexecorders") {
			cout << "STATE: assignReinforcement" << endl;
			return currentState->getNextState2();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: executeOrders (unchanged)" << endl;
			return currentState;
		}
	}
	else if (currentState->getName() == "win") {
		if (command == "end") {
			cout << "Game Over." << endl;
			return currentState->getNextState1();
		}
		else if (command == "play") {
			cout << "STATE: start" << endl;
			return currentState->getNextState2();
		}
		else {
			cout << "Command not recognized." << endl;
			cout << "STATE: win (unchanged)" << endl;
			return currentState;
		}
	}
}
