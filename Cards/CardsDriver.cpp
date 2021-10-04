#include "Cards.h"

int main() {
	Hand hand; // creates Hand object
	Deck deck; // creates Deck object
	cout << "Creating deck . . . \n" << endl;
	deck.deckStart(); // creates deck
	deck.printDeck(); // prints all cards in deck
	deck.printDeckSize(); // prints deck size

	cout << "Adding 5 cards to player's hand . . . \n" << endl;
	for (int i = 0; i < 5; i++) {
		hand.setHandCards(deck.draw()); // draws 5 cards
	}

	hand.printHandCards(); // print the current hand cards
	deck.printDeckSize(); // prints deck size
	deck.printDeck(); // prints all cards in deck

	cout << (" Playing cards using play() . . . \n") << endl;

	int handSize = hand.getHandCards()->size();
	for (int i = 0; i < handSize; i++) {
		hand.play(hand.getHandCards()->at(0), &deck);
	}
	cout << "" << endl;
	deck.printDeck(); // prints all cards in deck
	deck.printDeckSize(); // prints deck size
	hand.printHandCards(); // print hand cards

}