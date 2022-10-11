// In the game of contract bridge, each of four players is dealt 13 cards, thus exhausting the
// entire deck.Modify the CARDARAY program in this chapter so that, after shuffling the
// deck, it deals four hands of 13 cards each.Each of the four players’ hands should then be
// displayed.

#include <iostream>
#include <cstdlib>
#include<ctime>

enum class Suit {clubs, diamonds, hearts, spades};

const auto jack{ 11 };
const auto queen{ 12 };
const auto king{ 13 };
const auto ace{ 14 };

class card
{
private:
	int number {0};
	Suit suit {};
public:
	card()
	{}
	void set(int n, Suit s);
	void display();
};

int main()
{
	card deck[52];           
	card deck_finish[4][13];
	int n = 0;

	for (int j = 0; j < 52; ++j)  // Ordered deck of cards
	{
		int num = (j % 13) + 2;
		Suit su = Suit(j / 13);
		deck[j].set(num, su);
	}

	for (int j = 0; j < 52; ++j)  // Show ordered deck of cards
	{
		deck[j].display();
		std::cout << " ";
		if(!(( j + 1) % 13 ))
			std::cout << std::endl;
	}

	srand(time(NULL));             // Shuffling a deck of cards
	for (int j = 0; j < 52; ++j)
	{
		int k = rand() % 52;
		card temp = deck[j];
		deck[j] = deck[k];
		deck[k] = temp;
	}

	std::cout << std::endl;

	for (int j = 0; j < 13; ++j)   // Distribution of one card
	{
		for (int i = 0; i < 4; ++i)
		{
			deck_finish[i][j] = deck[++n];
		}
	}

	std::cout << std::endl;     // Show card of each player
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Player " << i + 1 << ": ";
		for (int j = 0; j < 13; ++j)
		{
			deck_finish[i][j].display();
			if (j + 1 < 13) 
				std::cout << " "; 
			else 
				std::cout << std::endl;
		}
	}

	return EXIT_SUCCESS;
}

void card::set(int n, Suit s)
{
	suit = s;
	number = n;
}

void card::display()
{
	if (number >= 2 && number <= 10)
		std::cout << number;
	else
	{
		switch (number)
		{
		case jack:
			std::cout << 'J';
			break;
		case queen:
			std::cout << 'Q';
			break;
		case king:
			std::cout << 'K';
			break;
		case ace:
			std::cout << 'A';
			break;
		}
	}
	switch (suit)
	{
	case Suit::clubs:
		std::cout << static_cast<char>(5);
		break;
	case Suit::diamonds:
		std::cout << static_cast<char>(4);
		break;
	case Suit::hearts:
		std::cout << static_cast<char>(3);
		break;
	case Suit::spades:
		std::cout << static_cast<char>(6);
		break;
	}
}
