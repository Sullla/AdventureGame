#pragma once
#include "Object.h"
#include "MotionTableEntry.h"
#include <vector>
#include "Enemy.h"


class AdventureRooms
{
private:
	int roomnum;
	int eventType;
	string nameoftheroom;
	bool isActive;
	bool eventHappened;

public:
	AdventureRooms(int numb, string name, int eventNum);
	~AdventureRooms();
	string getName();
	bool getActive();
	void setActive(bool active);
	Enemy* enemy;
	vector<Object*> roomObjects;
	vector<MotionTableEntry*> motionTable;
	vector<string>roomDescription;
	vector<string>roomDescription2;
	bool getStatus();
	void setStatus(bool status);
	int geteventype();


};

