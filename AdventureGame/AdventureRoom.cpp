#include <iostream>
#include <fstream>
#include <string>
//#include "AdventureRooms.h";
#include "MotionTableEntry.h";
#include "AdventureManager.h";



void AdventureRooms::setRoomDes(string room2) 
{
	room = room2;
}
string AdventureRooms::getRoomDes() 
{
	return room;
}

vector<int> AdventureRooms::getExit() { return exit; };

void AdventureRooms::setrooms(vector <AdventureRooms> &adv)
{

	MotionTableEntry from;
	AdventureRooms *lol = new AdventureRooms();
	vector <AdventureRooms> *adv2;
	vector <Object> *object;
	vector <Object> object2;
	object = &object2;
	AdventureManager fromFile;
	adv2 = &adv;
	int loc;
	adv2->push_back(*lol);
	adv2->push_back(*lol);
	adv2->push_back(*lol);
	adv2->push_back(*lol);
	adv2->push_back(*lol);

	adv2->at(room1).setRoomDes(adv2->at(room1).getRoomDes().assign(fromFile.Room1()));
	
    adv2->at(room1).arra[from.north] = noDir;	
	adv2->at(room1).arra[from.east] =noDir;
	adv2->at(room1).arra[from.west] = noDir;
	adv2->at(room1).arra[from.south] = noDir;


	adv2->at(room2).setRoomDes(adv2->at(room2).getRoomDes().assign(fromFile.Room2()));
	
	adv2->at(room2).arra[from.north] = room3;
	adv2->at(room2).arra[from.east] = noDir;
	adv2->at(room2).arra[from.west] = noDir;
	adv2->at(room2).arra[from.south] = room1;


	adv2->at(room3).setRoomDes(adv2->at(room3).getRoomDes().assign(fromFile.Room3()));
	
	adv2->at(room3).arra[from.north] = room2;
	adv2->at(room3).arra[from.east] = room4;
	adv2->at(room3).arra[from.west] = room5;
	adv2->at(room3).arra[from.south] = room2;


	adv2->at(room4).setRoomDes(adv2->at(room4).getRoomDes().assign(fromFile.Room4()));
	
	adv2->at(room4).arra[from.north] = noDir;
	adv2->at(room4).arra[from.east] = room3;
	adv2->at(room4).arra[from.west] = noDir;
	adv2->at(room4).arra[from.south] = noDir;



	adv2->at(room5).setRoomDes(adv2->at(room5).getRoomDes().assign(fromFile.Room5()));
	adv2->at(room5).arra[from.north] = noDir;
	adv2->at(room5).arra[from.east] = noDir;
	adv2->at(room5).arra[from.west] = room3;
	adv2->at(room5).arra[from.south] = noDir;

}












/*void AdventureRooms::setReadingRoom(string setRoom)
{
	roomsLine = setRoom;
}
string AdventureRooms::getReadingRoom()
{
	return roomsLine;
}
void AdventureRooms::readSingleRoom()
{
	string line;
}


string AdventureRooms::room1()
{
	
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber > 11 && lineNumber < 26) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			setReadingRoom(getlineForRoom);
			//cout << addRoom->getReadingRoom()<< endl;
			return getReadingRoom();
		}
	}
	roomFile.close();
	/*adRoom->readingRoom();
	adRoom->setlineForRoom(getlineForRoom);
	cout << adRoom->getlineForRoom()<< endl;
	


string AdventureRooms::room2()
{
	
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber > 26 && lineNumber < 34) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			setReadingRoom(getlineForRoom);
			return getReadingRoom();
		}
	}
	roomFile.close();


}
string  AdventureRooms::room3()
{
	
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber >35 && lineNumber < 42) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			setReadingRoom(getlineForRoom);
			return getReadingRoom();
		}
	}
	roomFile.close();
}
string AdventureRooms::room4()
{
	AdventureRooms *addRoom4 = new AdventureRooms();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber >43 && lineNumber < 50) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			setReadingRoom(getlineForRoom);
			return getReadingRoom();
		}
	}
	roomFile.close();
}
string AdventureRooms::room5()
{
	AdventureRooms *addRoom5 = new AdventureRooms();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber >50 && lineNumber < 58) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			setReadingRoom(getlineForRoom);
			return getReadingRoom();
		}
	}
	roomFile.close();
}*/

