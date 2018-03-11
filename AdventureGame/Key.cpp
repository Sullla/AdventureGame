#include <iostream>
#include "Key.h";

Key::Key(string name, string description) :Object(name, description)
{
	this->name = name;
	this->description = description;
}
Key::~Key() {}
string Key::getName() 
{
	return this->name;
}
string Key::getdesctiption() 
{
	return this->description;
}


string Key::examine() 
{
	return string("This looks like it is a hundred years old");
}
string Key::open() 	
{
		return string("Nothing happens...");
}
bool Key::openorclosed(bool OorC) 
{
	return OorC;
}
//string Key::useWith(Object &object) {
//	if (object.getName() == "door") {
//		object.openorclosed(true);
	//}
//	return object.getName();

bool Key::itemState(bool itemStateTF)
{
	
	return itemStateTF;
}

void Key::setNum(int number) 
{
	this->number = number;
}
int Key::getNum() 
{
	return this->number;
}
void Key::setLoc(int currentLoc) 
{
	this->currentPlaceKey = currentLoc;
}
int Key::getLoc() 
{
	return this->currentPlaceKey;
}




