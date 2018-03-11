#include <iostream>
#include "Object.h";

Object::Object(string name, string description) 
{
	this->name = name;
	this->description = description;
}
Object::~Object(){}

string Object::getName() 
{
	return this->name;
}
string Object::getdesctiption() 
{
	return this->description;
}

string Object::open() 
{
	return string("This is an item");
}

string Object::examine()
{
	return string("Nothing happens...");
}
bool Object::openorclosed(bool openclosed) 
{
	return openclosed;
}
//string Object::useWith(Object &object) {
	//if (object.getName() == "door") {
	//	object.openorclosed(true);
	//}
	//return object.getName();
//}
bool Object::itemState(bool itemStateTF)
{

	return itemStateTF;

}


void Object::setNum(int number) 
{
	this->number = number;
}
int Object::getNum() 
{
	return this->number;
}


void Object::setLoc(int currentLoc) 
{
	this->current = currentLoc;
}
int Object::getLoc() 
{
	return this->current;
}

