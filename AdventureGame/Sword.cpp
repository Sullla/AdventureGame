#include <iostream>
#include "Sword.h";

Sword::Sword(string name, string description) :Object(name, description)
{
	this->name = name;
	this->description = description;
}
Sword::~Sword() {}
string Sword::getName()
{
	return this->name;
}
string Sword::getdesctiption()
{
	return this->description;
}


string Sword::examine()
{
	return string("This looks like it is a hundred years old");
}
string Sword::open()
{
	return string("Nothing happens...");
}
bool Sword::openorclosed(bool OorC)
{
	return OorC;
}
//string Key::useWith(Object &object) {
//	if (object.getName() == "door") {
//		object.openorclosed(true);
//}
//	return object.getName();

bool Sword::itemState(bool itemStateTF)
{

	return itemStateTF;
}

void Sword::setNum(int number)
{
	this->number = number;
}
int Sword::getNum()
{
	return this->number;
}
void Sword::setLoc(int currentLoc)
{
	this->currentPlaceKey = currentLoc;
}
int Sword::getLoc()
{
	return this->currentPlaceKey;
}

