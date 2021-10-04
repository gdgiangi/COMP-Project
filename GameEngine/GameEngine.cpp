#include "GameEngine.h"
#include <iostream>

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
	this->name = nullptr;
	this->nextState1 = nullptr;
	this->nextState2 = nullptr;
}

//constructor with 1 next state node
StateNode::StateNode(string stateName, StateNode* nextState) { 
	this->name = stateName;
	this->nextState1 = nextState;
	this->nextState2 = nullptr;
}

//constructor with both primary and secondary state nodes
StateNode::StateNode(string stateName, StateNode* nextStateNode1, StateNode* nextStateNode2) {
	this->name = stateName;
	this->nextState1 = nextStateNode1;
	this->nextState2 = nextStateNode2;
}

//copy constructor
//StateNode::StateNode(const StateNode &copy) {
	//this->name = new string *(copy.name);
	//this->nextState1 = new StateNode(*(copy.nextState1));
	//this->nextState2 = new StateNode(*(copy.nextState2));
//}

StateNode* GameDriver::initiliazeStates() {
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
}

void GameDriver::deleteStates() {
	 
}

void GameDriver::playGame(StateNode* startNode) {
	StateNode* temp = startNode;
	
	cout << "STATE: start" << endl;

	string input;

	do {
		cin >> input;
		temp = transition(input, temp);
	} while (temp != nullptr);

}

StateNode* GameDriver::transition(string command, StateNode* currentState) {
	if (currentState->getName() == "start") {
		if (command == "loadmap") {
			cout << "STATE: mapLoaded" << endl;
			return currentState->getNextState1();
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