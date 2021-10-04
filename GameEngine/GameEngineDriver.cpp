#include "GameEngine.h"

int main() {
	GameDriver gameObj;
	StateNode* currentNode = gameObj.initiliazeStates();
	gameObj.playGame(currentNode);
}