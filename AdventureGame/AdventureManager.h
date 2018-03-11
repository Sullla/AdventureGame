#include <iostream>
#include <string>
#include <fstream>
#include "Player.h";
#include "Object.h";
using namespace std;

class AdventureManager
{
private:
	string getThatInfo;
	int countingRooms = 0;
	int lineNumber;
	string getLineRoom;
public:
	//AdventureManager();
	//~AdventureManager();
	
	void dataStructure();
	void commandList();
	void setLine(string line2);
	void setReadingRoom(string setlineForRoom);
	string getReadingRoom();



	string readDesRoom1();
	string readDirection1();

	string readDesRoom2();
	string readDirection2();

	string readDesRoom3();
	string readDirection3();

	string readDesRoom4();
	string readDirection4();

	string readDesRoom5();
	string readDirection5();
	//Prints each room by reading from file
	string Room1();
	string Room2();
	string Room3();
	string Room4();
	string Room5();
	//Prints each direction
	string north();
	string south();
	string east();
	string west();
	void MotionTable();
	bool checkForEv (int &loc, string Fline1, string Sline2, vector <MotionTableEntry> &dir, 
		vector <AdventureRooms> &rms,vector<MotionTableEntry> &actionWords, 
		vector<Object>&obj, Player &inventory, vector<Player>&setInventory);
	void usersCommands(string Cmd, string &wd1, string &wd2);


};
