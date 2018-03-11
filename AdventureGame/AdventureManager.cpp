#include <iostream>
#include <string>
#include <fstream>
#include "AdventureManager.h";



void AdventureManager::setReadingRoom(string line2) 
{
	this->getLineRoom = line2;
}
string AdventureManager::getReadingRoom() 
{
	return this->getLineRoom;
}

void AdventureManager::dataStructure()
{
	ifstream redADes;
	redADes.open("Data.txt", ios::out);
	string lineForReading;
	for ( int lineNumber = 0; getline(redADes, lineForReading) && lineNumber < 75; lineNumber++)
	{
		if (lineNumber > 10 && lineNumber < 61) {
			setReadingRoom(lineForReading);
			cout << getReadingRoom() << endl;
		}	
	}
	redADes.close();

	
}
void AdventureManager::commandList()
{
	ifstream redACommands;
	redACommands.open("Data.txt", ios::out);
	string ReaddingCommands;
	int countingLines = 0;
	
	for (int lineNumber = 0; getline(redACommands, ReaddingCommands) && lineNumber < 75; lineNumber++)
	{
		if (lineNumber > 59 && lineNumber < 75) {
			cout << ReaddingCommands << endl;
		}
	}
	redACommands.close();
}

string  AdventureManager::north()
{
	AdventureManager *addRoom = new AdventureManager();
	string north;
	ifstream roomFile;
	
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, north) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 60) {

			addRoom->setReadingRoom(north);
		
			return addRoom->getReadingRoom();
		}
	}
	roomFile.close();

}
string  AdventureManager::south()
{
	AdventureManager *addRoom = new AdventureManager();
	string south;
	ifstream roomFile;
	
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, south) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 64) {

			addRoom->setReadingRoom(south);
		
			return addRoom->getReadingRoom();
		}
	}
	roomFile.close();
}
string  AdventureManager::east()
{
	AdventureManager *addRoom = new AdventureManager();
	string east;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, east) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 64) {
	
			addRoom->setReadingRoom(east);

			return addRoom->getReadingRoom();
		}
	}
	roomFile.close();
}
string  AdventureManager::west()
{
	AdventureManager *addRoom = new AdventureManager();
	string west;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, west) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 64) {
		
			addRoom->setReadingRoom(west);
		
			return addRoom->getReadingRoom();
		}
	}
	roomFile.close();
}



bool AdventureManager::checkForEv(int &loc, string fLine, string sline, vector <MotionTableEntry> &checkDir, vector <AdventureRooms> &whichRoom, vector<MotionTableEntry> &actionWords, vector<Object>&object, Player &inventory, vector<Player>&setInventory)
{

	Player *lol = new Player();
	vector<Player> *inv;
	inv = &setInventory;
	MotionTableEntry mo;
	AdventureRooms ar;
	Player player;
	vector<Player> pl;
	string name;
	string des;
	int numForInvent = 0;
    static bool unlockDoor = false;
	int checkTheDoor =ar.noDir;
	int checktheroom = ar.noDir;
	int actionNum = ar.noDir;
	int items = ar.noDir;
	mo.setDirection(checkDir);
	ar.setrooms(whichRoom);
	
	int i;
	for (i = 0; i < mo.goDirection; i++)
	{
				if (fLine == checkDir.at(i).getLineWord())
				{
					if (whichRoom.at(loc).arra[checkDir.at(i).getCode()] != ar.noDir)
					{

						loc = whichRoom.at(loc).arra[checkDir.at(i).getCode()];
						cout << "I am now in a " << whichRoom.at(loc).getRoomDes() << "." << endl;
						return true;
					}
					else
					{
						cout << "No exit that way." << endl;
						return true;
					}
				}
	}
	
	for (i = 0;i < player.actions;i++)
	{
		if (fLine == actionWords.at(i).getLineWord())
		{
			actionNum = actionWords.at(i).getCode();
			break;

		}

	}


	if (actionNum == player.lookAround)
	{
		player.currentPlace(loc, whichRoom, checkDir, object);
		return true;
	}
	
	
	if (sline != " ") 
	{
		for (i = 0;i < player.items;i++) 
		{
			if (sline == object.at(i).getName()) 
			{
			
				items = object.at(i).getNum();
				break;
			}
		}
	}
	if (actionNum == player.take)
	{
		
			if (items == player.Key1) {
				if (object.at(items).itemState(true)) {

					object.at(items).itemState(false);
					inv->push_back(*lol);
					lol->setinvent(object.at(items).getName());

					cout << setInventory.size() << endl;


					cout << "You have succesfully taken an item " << endl;
					return true;
				}
		}
			if (items == player.sword) {
				if (object.at(items).itemState(true)) {

					object.at(items).itemState(false);
					inv->push_back(*lol);
					lol->setinvent(object.at(items).getName());

					cout << setInventory.size() << endl;


					cout << "You have succesfully taken an item " << endl;
					return true;
				}
			}
			
		return true;
	}
	
	
	
	

	if (actionNum == player.unlock)
	{
		if (items == player.Key1)
		{

			if (loc == ar.room1 ){
			

						if (object.at(items).openorclosed(true))
						{
							object.at(items).openorclosed(false);
							vector <AdventureRooms> Point;
						
							//Point.at(ar.room1).arra[mo.north] = ar.room2;
							//whichRoom.at(loc).arra[mo.north] = ar.room2;
							
							cout << "You opened the door and now free to move to the next room" << endl;
							return true;
						}
						else if (object.at(items).openorclosed(false))
						{
							cout << "You have already unlocked the door man." << endl;
							return true;
						}
					
			}
			else
			{
				cout << "Not meant to be for that door" << endl;
				return true;

			}
		}
		else
		{
			cout << "Unable to open that door. Find a key" << endl;
			return true;
		}

	}



	if (actionNum == player.showInventory)
	{
		
		for (int numberOfSlots = 0; numberOfSlots<inv->size();numberOfSlots++)
		{
			cout << "==" << numberOfSlots + 1 << "== " <<
				object.at(numberOfSlots).getName() << endl;
		}
		return true;
	}
	

	if (actionNum == player.drop) 
	{
		if (items == player.Key1) 
		{
			if (object.at(items).openorclosed(true)) {
				object.at(items).openorclosed(false);
				inv->at(items).setinvent("");
				inv->pop_back();
			}
			return true;
		}
	}
	


	

	cout << "????...Cant understand what are you saying. I was not programmed for that." << endl;
	return false;
	if (actionNum = ar.noDir)
	{
		cout << "Ummm....Looks like you want to look around, however i dont really get what are you saiying. " << endl;
	}


	

	
}


void AdventureManager::MotionTable()
{
	AdventureRooms the;
	int playersLocation = the.room1;
	string command;
	string word1;
	string word2;
	vector <MotionTableEntry> theDirections; 
	vector <AdventureRooms> allRooms;
	vector<MotionTableEntry> actions;
	Player invent;
	vector<Player> vectorForInvent;
	
	vector<Object> object;
	vector<Object> itemDescription;
	string strangersName;
	Player pl;
	pl.setTheAction(actions);
	pl.listOfObjects(playersLocation, object);

	
	cout << "Would you mind telling your name stranger?" << endl;
	cin >> strangersName;
	Player *newUser = new Player(strangersName);
	cout << endl;
	cout << "Welcome to this Mystical world, " << newUser->getname();
	cout << endl;
	while (word1 != "QUIT")
	{
		

		command.clear();
		cout << "=======YOUR CURRENT ROOM" << playersLocation + 1 << "========";
		cout << "What is your command? ";
	   //  cin >> command;
		getline(cin, command);
		cout << "Your  command was " << command << endl;
		word1.clear();
		word2.clear();
		
		usersCommands(command, word1, word2);
		checkForEv(playersLocation, word1, word2, theDirections, allRooms, actions, object, invent, vectorForInvent);
      //  pl.currentPlace(playersLocation, allRooms, theDirections);
		cout << word1 << " " << word2 << endl;
		if (word1 == "QUIT") 
		{
			
			cout << "\n\t\t================GAME OVER====================" << endl;
		}
	}
}

void AdventureManager::usersCommands(string Cmd, string &wd1, string &wd2)
{

	string sub_str;
	vector<string> words;
	char search = ' ';
	int i, j;
	for (i = 0;i < Cmd.size(); i++)
	{
		if (Cmd.at(i) != search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i));

		}
		if (i == Cmd.size() - 1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}

	}

	for (i = words.size() - 1; i > 0; i--)
	{
		if (words.at(i) == "")
		{
			words.erase(words.begin() + i);
		}
	}
	for (i = 0; i < words.size(); i++)
	{
		for (j = 0; j < words.at(i).size(); j++)
		{
			if (islower(words.at(i).at(j)))
			{
				words.at(i).at(j) = toupper(words.at(i).at(j));
			}
		}
	}
	if (words.size() == 0)
	{
		cout << "No command given" << endl;
	}
	if (words.size() == 1)
	{
		wd1 = words.at(0);
	}
	if (words.size() == 2)
	{
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2)
	{
		cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
	}


}


string  AdventureManager::Room1()
{
	AdventureManager *addRoom = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 12) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom->setReadingRoom(getlineForRoom);
			//cout << addRoom->getReadingRoom()<< endl;
			return addRoom->getReadingRoom();
		}
	}
	roomFile.close();
	

}
string  AdventureManager::Room2()
{
	AdventureManager *addRoom2 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 27) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom2->setReadingRoom(getlineForRoom);
			return addRoom2->getReadingRoom();
		}
	}
	roomFile.close();


}
string  AdventureManager::Room3()
{
	AdventureManager *addRoom3 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber ==35) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom3->setReadingRoom(getlineForRoom);
			return addRoom3->getReadingRoom();
		}
	}
	roomFile.close();
}
string  AdventureManager::Room4()
{
	AdventureManager *addRoom4 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber==43) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom4->setReadingRoom(getlineForRoom);
			return addRoom4->getReadingRoom();
		}
	}
	roomFile.close();
}
string  AdventureManager::Room5()
{
	AdventureManager *addRoom5 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber ==51) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom5->setReadingRoom(getlineForRoom);
			return addRoom5->getReadingRoom();
		}
	}
	roomFile.close();
}
string AdventureManager::readDesRoom1()
{

	AdventureManager *addRoom5 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 23) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom5->setReadingRoom(getlineForRoom);
			return addRoom5->getReadingRoom();
		}
	}
}
string AdventureManager::readDesRoom2()
{

	AdventureManager *addRoom5 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 33) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom5->setReadingRoom(getlineForRoom);
			return addRoom5->getReadingRoom();
		}
	}
}
string AdventureManager::readDesRoom3()
{

	AdventureManager *addRoom5 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 40) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom5->setReadingRoom(getlineForRoom);
			return addRoom5->getReadingRoom();
		}
	}
}
string AdventureManager::readDesRoom4()
{

	AdventureManager *addRoom5 = new AdventureManager();
	string getlineForRoom;
	ifstream roomFile;
	//	AdventureRooms *arrayRoom[5];
	roomFile.open("Data.txt", ios::out);
	for (int lineNumber = 0; getline(roomFile, getlineForRoom) && lineNumber < 76; lineNumber++) {
		if (lineNumber == 32) {
			//arrayRoom[0] = new AdventureRooms();
			//arrayRoom[0]->setReadingRoom(getlineForRoom);
			//cout << arrayRoom[0]->getReadingRoom() << endl;
			addRoom5->setReadingRoom(getlineForRoom);
			return addRoom5->getReadingRoom();
		}
	}
}






#pragma endre


