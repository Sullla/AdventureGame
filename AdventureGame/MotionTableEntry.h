#pragma once
#include <iostream>
#include <string>
#include "AdventureRooms.h";
using namespace std;
class MotionTableEntry
{
private:
	string wordDir;
	int code;
public:
	//MotionTableEntry();
	//~MotionTableEntry();
	const int goDirection = 4;
	enum corDir { north, east, south, west };
	void func();
	void mainMotion();
	void setDirection(vector <MotionTableEntry> &adv);
	void setLineWord(string wordDir);
	string getLineWord();
	void setCode(int code);
	int getCode();





	/*string room1();
	string room2();
	string room3();
	string room4();
	string room5();

	struct sdir;
	struct room;

	string north();
	string south();
	string east();
	string west();*/


		
};
