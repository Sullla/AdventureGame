#pragma once
#include <iostream>

#include <string>
#include <vector>
#include "AdventureRooms.h"
#include "Object.h"
#include <time.h>
#include <fstream>
#include "Colors.h"
#include "Player.h"
#include <algorithm>
#include <sstream>
#include "MotionTableEntry.h"
#include "Enemy.h"

using namespace std;
class Player;

class AdventureManager
{
private:
	vector<AdventureRooms*> roomLevel;
	void Fight(Player *detective, Enemy* enemy, Colors color);
	bool restart;
	
	

public:


	AdventureManager();
	~AdventureManager();
	void setRestart(bool re);
	bool getRestart();
	void deleteRooms();
	bool runBool(Player* generalStyrax, Colors color);
	void FileToRead(ifstream& myDataFile);
};


