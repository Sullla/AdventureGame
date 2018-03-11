#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "MotionTableEntry.h";
#include "AdventureRooms.h";
#include "AdventureManager.h"




void MotionTableEntry::setCode(int code2)
{
	code = code2;
}
int MotionTableEntry::getCode()
{
	return code;
}

void MotionTableEntry::setLineWord(string line)
{
	wordDir = line;
}
string MotionTableEntry::getLineWord()
{
	return wordDir;
}



 void  MotionTableEntry::setDirection(vector <MotionTableEntry> &advR2)
 {
	 AdventureManager move;
	 MotionTableEntry *lol2 = new MotionTableEntry;
	 vector <MotionTableEntry> *advR;
	
	 advR = &advR2;
	 advR->push_back(*lol2);
	 advR->push_back(*lol2);
	 advR->push_back(*lol2);
	 advR->push_back(*lol2);

	 advR->at(north).setCode(north);
	 advR->at(north).getCode();
	 advR->at(north).setLineWord("NORTH");
	
	 advR->at(south).setCode(south);
	 advR->at(south).getCode();
	 advR->at(south).setLineWord("SOUTH");

	 advR->at(east).setCode(east);
	 advR->at(east).getCode();
	 advR->at(east).setLineWord("EAST");

	 advR->at(west).setCode(west);
	 advR->at(west).getCode();
	 advR->at(west).setLineWord("WEST");
	 
 }
 
 



