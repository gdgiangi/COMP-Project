#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {
	private:
		// creates vector for the types of cards
		vector<string> cardTypeList = {"Bomb", "Reinforcement", "Blockade", "Airlift", "Diplomacy"};
		string* cardType{};

	public:
		Card(); // default constructor
		~Card(); // destructor
		Card(const Card& c); // copy constructor
		Card& operator = (const Card& c); // assignment operators

		// stream insertion operator
		friend std::ostream& operator<<(std::ostream& out, const Card& card);

		void printCardType(); // print card type
		void setCardTypeNum(int num); // set card number on vector

		// get pointer
		string* getCardType(); // get pointer
		vector<string>* getCardTypeList(); // get poi
};

class Deck : public Card {
	private:
		vector<Card*> deckList; // deck of cards
		Card* ptrCard{}; // pointer
		Card* tempCard{};// temp hold for card

	public:
		Deck(); // default constructor
		~Deck(); // destructor
		Deck(const Deck& d); //copy constructor 
		Deck& operator=(const Deck& d);	//assignment operators

		// stream insertion operator
		friend std::ostream& operator<<(std::ostream& out, const Deck& deck);

		void deckStart(); // creates the deck

		void printDeck(); // prints deck
		void printDeckSize(); // prints deck size

		// draw a card at random from the cards remaining in the deck and place it in their hand of cards.
		Card* draw();

		//the method is to return played cards into Deck_vec
		void returnCard(Card* card);
};

class Hand : public Deck {
	private:
		vector<Card*> handCards;//for store hand cards
		vector<Card*> playCards;//for store play cards

	public:
		Hand(); // default constructor
		~Hand(); // destructor
		Hand(const Hand& hand); //copy constructor
		Hand& operator=(const Hand& hand);	//assignment operators

		// stream insertion operator
		friend std::ostream& operator<<(std::ostream& out, const Hand& hand);

		void setHandCards(Card* card); // pointer to set hand cards
		void printPlayCards(); // print play cards
		void printHandCards(); // print play cards

		// play the card, which creates an order and adds it to the player’s list of orders
		// and then returns the card to the deck. Choose card and deck to deliver
		void play(Card* card, Deck* deck);

		// get pointers
		vector<Card*>* getHandCards();
		vector<Card*>* getPlayCards();

		void removeCard(Card* card); // removes card from hand cards
		void returnCard(Deck* deck); //return a card to the deck cards, for play() method
};