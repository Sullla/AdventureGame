#pragma once
#include <iostream>

using namespace std;

class Object {
private:
	//private members etc. 
	//bool itemStateTF = false;
	string name;
	string description;
	int number;
	int current;
public:
	
	Object(string name, string description);
	virtual	~Object();
    virtual string examine();
	virtual string open();
	//virtual string useWith(Object& object);
	//getters and setters for name etc. 
	virtual string getName();
	virtual string getdesctiption();
	virtual void setNum(int number);
	virtual int getNum();
	//void getOpen();
	virtual bool itemState(bool itemState);
	virtual bool openorclosed(bool openclosed);
	virtual void setLoc(int currentLoc);
	virtual int getLoc();
};


