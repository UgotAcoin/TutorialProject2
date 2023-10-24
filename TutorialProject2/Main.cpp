#include <iostream>
#include <string>

using namespace std;

const int numItems = 6;
const string shopItemNames[numItems] = { "Boots", "Swords", "Helmets", "Kittens", "Maces", "Helmets" };


void printInventory(const int playerInventory[numItems]);
void printShop();
bool buyItems(int playerInventory[numItems]);

int main() 
{
	
	bool isDone = false;
	
	int playerInventory[numItems] = { 0, 0, 0, 1, 0, 0 };

	cout << "*** Welcome to the item shop! ***\n";

	while (isDone == false) {

		printShop();

		printInventory(playerInventory);

		isDone = buyItems(playerInventory);

		cout << "\n\n\n";
	}


	system("pause");
	return 0;
}

void printInventory(const int playerInventory[numItems]) 
{
	cout << "Your inventory is: \n";
	for (int i = 0; i < numItems; i++) {
		if (playerInventory[i] > 0) {
			cout << playerInventory[i] << " X " << shopItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printShop() {
	cout << "Shop Inventory: \n";
	for (int i = 0; i < numItems; i++) {
		cout << i + 1 << shopItemNames[i] << endl;
	}
	cout << "****************\n";
}

bool buyItems(int playerInventory[numItems])
{
	int input;
	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;

	if (input == -1) {
		return true; //the program is over
	}

	if (input < 0 || input > numItems) {
		cout << "That was a bad input!\n";
		return false; //keep going
	}

	playerInventory[input - 1]++;
	return false;
}