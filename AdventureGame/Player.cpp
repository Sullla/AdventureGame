#include <iostream>
//#include "Player.h"
#include "AdventureManager.h";
#include "Object.h";
#include "Key.h";
#include "Sword.h";
#include <vector>
//#include "AdventureManager.h"


Player::Player() 
{

}
Player::~Player() 
{
}
 Player::Player(string sickname) 
{
	name = sickname;
}
string Player::getname() 
{
	return name;
}
void Player::setinvent(string itemIninvent) 
{
	this->inventory = itemIninvent;
}
string Player::getInvent() 
{
	return this->inventory;
}

void Player::setTheAction(vector<MotionTableEntry> &actionWordsRef)
{
	vector<MotionTableEntry> *actionWords;
	MotionTableEntry *space = new MotionTableEntry;
	actionWords = &actionWordsRef;
	for (int x = 0;x < 7; x++) {
		actionWords->push_back(*space);
	}
	
	actionWords->at(take).setCode(take);
	actionWords->at(take).getCode();
	actionWords->at(take).setLineWord("TAKE");
	actionWords->at(take).getLineWord();

	actionWords->at(lookAround).setCode(lookAround);
	actionWords->at(lookAround).getCode();
	actionWords->at(lookAround).setLineWord("LOOK");
	actionWords->at(lookAround).getLineWord();
	

	actionWords->at(showInventory).setCode(showInventory);
	actionWords->at(showInventory).getCode();
	actionWords->at(showInventory).setLineWord("INVENTORY");
	actionWords->at(showInventory).getLineWord();

	actionWords->at(drop).setCode(drop);
	actionWords->at(drop).getCode();
	actionWords->at(drop).setLineWord("DROP");
	actionWords->at(drop).getLineWord();

	actionWords->at(unlock).setCode(unlock);
	actionWords->at(unlock).getCode();
	actionWords->at(unlock).setLineWord("UNLOCK");
	actionWords->at(unlock).getLineWord();



}

void Player::currentPlace(int currentPlace, vector<AdventureRooms> &roomsRef, vector<MotionTableEntry> &coridirRef, vector<Object> &lookForItem) 
{
	vector<AdventureRooms> *pointRoom;
	vector<MotionTableEntry> *pointDir;
	vector<Object> *describe;
	MotionTableEntry player;
	AdventureRooms thereIs;
	pointRoom = &roomsRef;
	pointDir = &coridirRef;
	describe = &lookForItem;

	int a;
	
	cout << "My dear "<< getname() <<  ", you're currently in " << pointRoom->at(currentPlace).getRoomDes() << endl;

	for (a = 0; a < player.goDirection; a++) 
	{
		if (pointRoom->at(currentPlace).arra[a] != thereIs.noDir)
		{
			cout << "We can go to " << pointDir->at(a).getLineWord() << " to get to "
				<< pointRoom->at(pointRoom->at(currentPlace).arra[a]).getRoomDes() << endl;
		}
	}
	for (a = 0;a <items; a++) 
	{
		if (describe->at(a).getLoc()==currentPlace)
		{
			cout << "There is  " << describe->at(a).getdesctiption() << endl;
		}
	}

}
void Player::listOfObjects(int currentPlace, vector<Object> &objectCopy)
{
	AdventureManager am;
	vector<Object> *object;
	AdventureRooms itemIn;
	object = &objectCopy;
	
	Key *key = new Key("KEY1", am.readDesRoom1());
	object->push_back(*key);


	Sword *sw = new Sword("SWORD",am.readDesRoom4());
	object->push_back(*sw);

	
	Key *key2 = new Key("KEY2", am.readDesRoom2());
	object->push_back(*key2);

	Key *key3 = new Key("KEY3", am.readDesRoom3());
	object->push_back(*key3);

	Key *key4 = new Key("KEY4", am.readDesRoom2());
	object->push_back(*key4);

	Key *key5 = new Key("KEY5", am.readDesRoom3());
	object->push_back(*key5);




	object->at(Key1).setNum(Key1);
	object->at(Key1).setLoc(itemIn.room1);
	object->at(Key1).getName();
	object->at(Key1).itemState(false);
	object->at(Key1).openorclosed(false);

	object->at(sword).setNum(sword);
	object->at(sword).setLoc(itemIn.room2);
	object->at(sword).getName();
	object->at(sword).itemState(false);
	object->at(sword).openorclosed(false);


}





