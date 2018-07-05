#include "MotionTableEntry.h"



MotionTableEntry::MotionTableEntry(string dir, int destRoom, string deniedAccess, string symb)
{
	this->dir = dir;
	this->destRoom = destRoom;
	this->deniedAccess = deniedAccess;
	this->symb = symb;
}


MotionTableEntry::~MotionTableEntry()
{
}

string MotionTableEntry::getDir()
{
	return dir;
}
int MotionTableEntry::getDest()
{
	return destRoom;
}
string MotionTableEntry::getDeniedAccess()
{
	return deniedAccess;
}
string MotionTableEntry::getSymbol() {
	return symb;
}

bool MotionTableEntry::gethidden()
{
	return ishidden;
}
void MotionTableEntry::setidden(bool hid)
{
	ishidden = hid;
}