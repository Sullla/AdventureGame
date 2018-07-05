#pragma once
#include "Object.h"
#include <vector>

class MotionTableEntry
{
private:
	string deniedAccess;
	string symb;
	bool ishidden;
	string dir;
	int destRoom;


public:
	MotionTableEntry(string direction, int destinationRoomNum, string deniedA, string symbol);

	~MotionTableEntry();

	string getDeniedAccess();

	string getSymbol();

	bool gethidden();

	void setidden(bool hid);

	vector<Object*> requiredObjects;

	string getDir();
	int getDest();

	
};

