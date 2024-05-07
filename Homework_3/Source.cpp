#include <iostream>
#include <string>
#include<vector>

class Mushroom
{
public:
	std::string type;
	std::string name;
	virtual void interact(int& basket) = 0;

};

class EdibleMushroom : public Mushroom
{
public:
	EdibleMushroom()
	{
		type = "Edible Mushroom";

		std::vector<std::string> names = { "Maslyonok", "Mahovic", "Syroezhka", "Opyonok", "Volnushka", "Ryzhik" };
		int index = rand() % 6;
		name = names[index];
	}


	void interact(int& basket) override {
		std::cout << "This mushroom is edible!!!!!!" << std::endl;
		basket += 1;
	}
};

class PoisonousMushroom : public Mushroom {
public:
	PoisonousMushroom()
	{
		type = "Poisonous Mushroom";

		std::vector<std::string> names = { "Matan", "Muhomor", "Algebra", "Blednaya_poganka", "Rubopletulus_satanas", "Gypnopilus" };
		int index = rand() % 6;
		name = names[index];
	}

	void interact(int& basket) override {
		double randomChoice1 = rand() % 2;
		double randomChoice2 = rand() % 3;
		if (randomChoice1 == 1)
		{
			if (randomChoice2 == 1)
			{
				std::cout << "You ate hallucinogenic mushroom and had hallucinations, now you're arrested. Game over." << std::endl;
				basket = -5;
				exit(0);
			}
			else
			{
				std::cout << "You ate hallucinogenic mushroom, had hallucinations and fell off a cliff. Game over." << std::endl;
				basket = -5;
				exit(0);
			}
		}
		else
		{
			std::cout << "You ate poisonous mushroom. You died. Game over." << std::endl;
			exit(0);
		}

	}
};

class UselessMushroom : public Mushroom
{
public:
	UselessMushroom()
	{
		type = "Useless Mushroom";

		std::vector<std::string> names = { "Trurovic", "Peziza", "Puccinia", "Penicillium", "Cladosporium", "Aspergillus" };
		int index = rand() % 6;
		name = names[index];
	}

	void interact(int& basket) override
	{
		std::cout << "This mushroom is useless." << std::endl;
	}
};

class Player
{
	int basket = 0;
	int uselessMushroomsCount = 0;
public:
	void interactWithMushroom(Mushroom* mushroom) {
		mushroom->interact(basket);

		if (mushroom->type == "Useless Mushroom") {
			uselessMushroomsCount++;
			if (uselessMushroomsCount == 3) {
				std::cout << "You died of hunger!" << std::endl;
				exit(0);
			}
		}
		else if (mushroom->type == "Poisonous Mushroom") {
			uselessMushroomsCount = 0;
			std::cout << "You died!" << std::endl;
			exit(0);
		}
		else {
			if (basket == 5) {
				uselessMushroomsCount = 0;
				std::cout << "You won! You collected 5 edible mushrooms." << std::endl;
				exit(0);
			}
		}
	}
};

int main()
{
	std::cout << "You need to collect 5 edible mushrooms to the basket." << std::endl;

	Player player;

	std::string userInput;
	int counterNo = 0;
	while (true)
	{
		Mushroom* mushroom;
		int randomMushroomId = rand() % 3;

		if (randomMushroomId == 0)
		{
			mushroom = new EdibleMushroom();
		}
		else if (randomMushroomId == 1)
		{
			mushroom = new PoisonousMushroom();
		}
		else
		{
			mushroom = new UselessMushroom();
		}

		std::cout << "Your mushroom is " << mushroom->name << ". Do you want to interact with a mushroom? (Y/N): ";
		std::cin >> userInput;

		if (userInput == "Y" || userInput == "y")
		{
			player.interactWithMushroom(mushroom);
			counterNo = 0;
		}
		else
		{
			counterNo += 1;
			if (counterNo > 8)
			{
				std::cout << "You died from hunger. Game Over." << std::endl;
				break;
			}
		}
	}

	return 0;
}
