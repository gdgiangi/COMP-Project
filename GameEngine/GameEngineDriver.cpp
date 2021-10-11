#include "GameEngine.h"

int main() {
	StateNode gameObj;
	StateNode* currentNode = gameObj.initiliazeStates();
	gameObj.playGame(currentNode);
}
