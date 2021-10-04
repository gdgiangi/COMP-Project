#include "Cards.h"

// ------------------------------- Card ---------------------------------
Card::Card() { // default constructor
}

Card::~Card() { // destructor but there are no pointers here
}

Card::Card(const Card& card) { // copy constructor
	this->cardTypeList = *new vector<string>(card.cardTypeList);
	this->cardType = new string(*(card.cardType));
}

// getter pointers
vector<string>* Card::getCardTypeList() {
	return &cardTypeList;
}
string* Card::getCardType() {
	return cardType;
}

void Card::setCardTypeNum(int num) { // sets number of card type for card type vector cardTypeList
	cardType = &cardTypeList.at(num);
}

// ------------------------------- Deck ---------------------------------

Deck::Deck(){ // default constructor
}

Deck::~Deck() { // destructor
	delete(ptrCard); // deletes ptr
	delete(tempCard); // deletes temp card
}

Deck::Deck(const Deck& deck) { // copy constructor
	this->deckList = *new vector<Card*>(deck.deckList);
	this->ptrCard = new Card(*(deck.ptrCard));
	this->tempCard = new Card(*(deck.tempCard));
}

// Adds 10 cards of each type to the vector list deckList
void Deck::deckStart() {
	for (int i = 0; i < 50; i++) {
		ptrCard = new Card;
		if (i < 10) {
			ptrCard->setCardTypeNum(0);
			deckList.push_back(ptrCard);
		}
		if (i >= 10 && i < 20) {
			ptrCard->setCardTypeNum(1);
			deckList.push_back(ptrCard);
		}
		if (i >= 20 && i < 30) {
			ptrCard->setCardTypeNum(2);
			deckList.push_back(ptrCard);
		}
		if (i >= 30 && i < 40) {
			ptrCard->setCardTypeNum(3);
			deckList.push_back(ptrCard);
		}
		if (i >= 40 && i < 50) {
			ptrCard->setCardTypeNum(4);
			deckList.push_back(ptrCard);
		}
	}
}

// prints deck size
void Deck::printDeckSize() {
	cout << ("Cards in deck: ") << deckList.size() << "\n" << endl;
}

// prints all cards in the deck
void Deck::printDeck() {
	int BombNum = 0, ReinforcementNum = 0, BlockadeNum = 0, AirliftNum = 0, DiplomacyNum = 0;
	for (int i = 0; i < deckList.size(); i++) {
		if (*deckList.at(i)->getCardType() == "Bomb") {
			BombNum++;
		}
		if (*deckList.at(i)->getCardType() == "Reinforcement") {
			ReinforcementNum++;
		}
		if (*deckList.at(i)->getCardType() == "Blockade") {
			BlockadeNum++;
		}
		if (*deckList.at(i)->getCardType() == "Airlift") {
			AirliftNum++;
		}
		if (*deckList.at(i)->getCardType() == "Diplomacy") {
			DiplomacyNum++;
		}
	}
	cout << "Printing all cards in the deck:" << endl;
	cout << "Bomb Cards: " << BombNum << endl;
	cout << "ReinforementNum Cards: " << ReinforcementNum << endl;
	cout << "Blockade Cards: " << BlockadeNum << endl;
	cout << "Airlift Cards: " << AirliftNum << endl;
	cout << "Diplomacy Cards: " << DiplomacyNum << "\n" << endl;
}

Card* Deck::draw() {
	srand(time(NULL)); // randomizes seed
	int random = (rand() % deckList.size()); // draws at random from deck between 0-deck.size()
	tempCard = deckList.at(random); // sets temp card to hold card to take
	deckList.erase(deckList.begin() + random); // removes card from deck
	return tempCard;
}

void Deck::returnCard(Card* deck) { // uses push_back to return card to deck
	deckList.push_back(deck);
}

// ------------------------------- Hand ---------------------------------

Hand::Hand() { // default constructor
}

Hand::~Hand(){ // destructor but nothing to delete
}

Hand::Hand(const Hand& hand) { // copy constructor
	this->handCards = *new vector<Card*>(hand.handCards);
	this->playCards = *new vector<Card*>(hand.playCards);
}

void Hand::setHandCards(Card* card) { // adds card to vector handCards
	handCards.push_back(card);
}

void Hand::printHandCards() { // prints all the cards the player is holding
	cout << "Printing players hand: " << endl;
	if (handCards.size() > 0) {
		cout << ("Cards in hands: ") << handCards.size() << endl;
		for (int j = 0; j < handCards.size(); j++) {
			cout << "- " << *handCards.at(j)->getCardType() << endl;
		}
		cout << "\n";
	}
	else {
		cout << ("the hand has no cards \n") << endl;
	}
}

void Hand::play(Card* card, Deck* deck) {
	playCards.push_back(card); 	// assign card to order of play
	removeCard(card);	// remove card from hands and places on play cards

	// To-do 
	// creates an order 
	// adds it to the player’s list of orders

	returnCard(deck); // returns card to deck
	playCards.pop_back(); 	// remove card from playCards
}

void Hand::returnCard(Deck* deck) { // return cards to deck
	for (int i = 0; i < playCards.size(); i++) {
		deck->returnCard(playCards.at(i));
	}
}

// get pointers
vector<Card*>* Hand::getHandCards() {
	return &handCards;
}
vector<Card*>* Hand::getPlayCards() {
	return &playCards;
}

// removes card from hand
void Hand::removeCard(Card* card) {
	for (int i = 0; i < handCards.size(); i++) {
		if (*handCards.at(i)->getCardType() == *card->getCardType()) { // scans for a card of the same type and removes it
			handCards.erase(handCards.begin() + i);
			cout << "- " << *card->getCardType() << (" deleted") << endl;
			return;
		}
	}
}
