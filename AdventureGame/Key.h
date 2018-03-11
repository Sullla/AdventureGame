#pragma once
#include <iostream>
#include "Object.h";
using namespace std;
class Key : public Object {
private:
	string name;
	string description;
	int number;
	int currentPlaceKey;
	//bool itemStateTF = false;
public:
	Key(string name, string descriptions);
	~Key();
	string getName() override;
	string  getdesctiption() override;
	//implement interface Object 
	string examine() override;
    string open() override;
//	string useWith(Object& object) override;
	void setLoc(int currentLoc) override;
	int getLoc() override;
	bool openorclosed(bool OorC)override;
	bool itemState(bool itemstate) override;
	void setNum(int number) override;
	int getNum() override;


};