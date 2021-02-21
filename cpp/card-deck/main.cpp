#include <iostream>
#include <string>
#include <vector>
#include <random>

enum class Rank : unsigned char
{
    ace   = 1,
    two   = 2,
    three = 3,
    four  = 4,
    five  = 5,
    six   = 6,
    seven = 7,
    eight = 8,
    nine  = 9,
    ten   = 10,
    jack  = 11,
    queen = 12,
    king  = 13
};

auto to_string(Rank s) -> std::string
{
	switch (s)
	{
	case Rank::ace:
		return "ace";
	case Rank::two:
		return "two";
	case Rank::three:
		return "three";
	case Rank::four:
		return "four";
	case Rank::five:
		return "five";
	case Rank::six:
		return "six";
	case Rank::seven:
		return "seven";
	case Rank::eight:
		return "eight";
	case Rank::nine:
		return "nine";
	case Rank::ten:
		return "ten";
	case Rank::jack:
		return "jack";
	case Rank::queen:
		return "queen";
	case Rank::king:
		return "king";
	}
}

enum class Suit : unsigned char
{
	hearts,
	diamonds,
	clubs,
	spades
};

auto to_string(Suit s) -> std::string
{
	switch (s)
	{
	case Suit::hearts:
		return "hearts";
	case Suit::diamonds:
		return "diamonds";
	case Suit::clubs:
		return "clubs";
	case Suit::spades:
		return "spades";
	}
}

class Card {
public:
    Card() {}
    ~Card() {}

    Rank rank;
    Suit suit;
};

class Deck {
public:
	Deck() {}
	~Deck() {}
	void make_deck();
	void print_deck();
	std::vector<Card> cards;
};

void Deck::make_deck()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 14; ++j)
		{
			Card card;
			card.suit = static_cast<Suit>(i);
			card.rank = static_cast<Rank>(j);
			cards.push_back(card);
		}
	}
}

void Deck::print_deck()
{
	for (int i = 0; i < cards.size(); ++i)
	{
		std::cout << to_string(cards[i].rank) + " of " + to_string(cards[i].suit) << std::endl;
	}
}

int main() {
	std::cout << "Building deck." << std::endl;
	Deck deck;
	deck.make_deck();
	deck.print_deck();

	return 0;
}