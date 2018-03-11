#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class AdventureRooms
{
private:
	bool visited = false;
	string room;
	//string roomDescription;
	string wordDir;
	int code;
	vector<int> exit;
	
public:
	const int ROOMS = 5;
	enum allRooms { room1, room2, room3, room4, room5 };
	const int noDir = -1;

	//AdventureRooms(string oneRoom, string roomDescribe);
	//~AdventureRooms();
	int arra[4];
	string getRoomDesctiption();
	void roomDescription();
	void listOfObjects();
	void readSingleRoom();

	//setting directioms

	//setting rooms
	void setrooms(vector <AdventureRooms> &adv);
	void setRoomDes(string room);
	string getRoomDes();
	vector<int> getExit();
	
	



};