#include "MotionTableEntry.h";
#include "Object.h";
#include "Key.h";
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
private:
	string inventory;
	string name;
	vector <Player> *addToInv;
	
public:
	Player();
	~Player();
	Player(string username);
	string getname();
	int addtoIndex = 0;
	const int actions = 5 ;
	enum { take, lookAround,showInventory, drop, unlock};
	const int items = 5;
	enum { Key1, sword, Key3, Key4,Key5};
	void setinvent(string invent);
	string getInvent();
	void askForName();
	void listOfObjects(int currentPlace, vector<Object> &listOfObjects);
	void setTheAction(vector<MotionTableEntry> &actionWordsRef);
	void currentPlace(int curerentPlace, vector<AdventureRooms> &room, vector<MotionTableEntry> &corDir, vector <Object> &lookForItem);
	void inventoryPl(vector<Player> &invent);
	
};



