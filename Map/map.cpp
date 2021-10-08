#include "Map.h"

//----- Territory Class -----//

//Default constructor
Territory::Territory() {

}

//Copy constructor
Territory::Territory(const Territory& copy) {
	name = copy.name;
	armies = copy.armies;
	player = copy.player;
}

//Accessor methods
std::string Territory::getName() const{
	return name;
}

int Territory::getArmies() const {
	return armies;
}

std::string Territory::getPlayer() {
	return player;
}

//Mutator methods
void Territory::setName(const std::string &name) {
	this->name = name;
}

void Territory::setArmies(int num) {
	armies = num;
}

void Territory::setPlayer(std::string &player) {
	this->player = player;
}

//Stream Operator
std::ostream & operator<<(std::ostream & out, const Territory &territory)
{
	return out << territory.name << "has " << territory.armies << " armies." << endl;
}

//Assignment Operator
Territory & Territory::operator=(const Territory &rightSide)
{
	name = rightSide.name;
	armies = rightSide.armies;
	return *this;
}

//Boolean operator (used to check if two territories are the same)
bool Territory::operator==(const Territory &equals) const {
	if (name == equals.name) {
		return true;
	}
	else {
		return false;
	}
}

//Functions
void Territory::increaseArmiesBy(int num) {
	armies += num;
}

void Territory::decreaseArmiesBy(int num) {
	armies -= num;
}

//----- Map Class -----//

//Constructors
Map::Map() {

}
