#include <iostream>
#include "AdventureManager.h";

using namespace std;


int main()
{
	bool exit = false;
	Player *detective = new Player();
	AdventureManager myAdventure;

	while (myAdventure.getRestart())
	{
		myAdventure = AdventureManager();
		ifstream myFile("Data.txt", ios::out);
		
		myAdventure.FileToRead(myFile);

		myFile.close();

		Colors color;



		while (!exit)
		{
			exit = myAdventure.runBool(detective, color);
		}
		detective->setDefault();
		myAdventure.deleteRooms();
		exit = false;
		system("cls");
	}
	return 0;
}