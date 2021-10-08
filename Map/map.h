#pragma once
#include<string>
#include<vector>
using namespace std;

class Map {
public:
	//Constructors
	Map();
	Map(const Map&);
	//Accessor methods
	int getNumTerritories();
	//Functions
	bool validate();
	void addEdge(int, int);
private:
	std::vector<Continent> continents; //Dynamic array of continents
	int numTerritories;
	Territory **adjTerritory; //Pointer to pointer to an adjacent territory
};

class MapLoader {
public:
	//Function to load the map file
	static Map loadMap(std::string filename);
};

struct Territory {
public:
	//Constructors
	Territory();
	Territory(const Territory&);
	//Accessor methods
	std::string getName() const;
	int getArmies() const;
	std::string getPlayer();
	//Mutator methods
	void setName(const std::string&);
	void setArmies(int);
	void setPlayer(std::string&);
	//Assignment operators
	Territory& operator=(const Territory&);
	//Stream insertion operator
	friend std::ostream& operator<<(std::ostream&, const Territory&);
	//Boolean operator
	bool operator==(const Territory&) const;
	//Functions
	void increaseArmiesBy(int);
	void decreaseArmiesBy(int);
private:
	std::string name;
	int armies;
	std::string player;
};

struct Continent {
public:
	//Constructors
	Continent();
	Continent(const Continent&);
	//Accessor methods
	int getArmyReward() const;
	std::string getName() const;
	//Mutator methods
	void addTerritory(const Territory&);
	void setArmyReward(int);
	void setName(std::string);
	//Assignment operators
	Territory& operator=(const Continent&);
	//Stream insertion operator
	friend std::ostream& operator<<(std::ostream&, const Continent&);
	//Functions
	bool isControlled(const Continent&); //method to check if continent is controlled by a player
private:
	std::string name;
	std::vector<Territory> territories; //dynamic array of territories contained inside of the continent
	int armyReward; //armies given if one player controls the continent
};

