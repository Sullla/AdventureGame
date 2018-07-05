#include "AdventureRooms.h"



AdventureRooms::AdventureRooms(int roomnum, string nameoftheroom, int eventNum)
{
	this->roomnum = roomnum;
	this->nameoftheroom = nameoftheroom;
	eventType = eventNum;
	eventHappened = false;
}


AdventureRooms::~AdventureRooms()
{
}

string AdventureRooms::getName()
{
	return nameoftheroom;
}

bool AdventureRooms::getActive()
{
	return isActive;
}

void AdventureRooms::setActive(bool active)
{

	isActive = active;

}
bool AdventureRooms::getStatus()
{
	return eventHappened;
}

void AdventureRooms::setStatus(bool status)
{

	eventHappened = status;

}

int AdventureRooms::geteventype()
{
	return eventType;

}


