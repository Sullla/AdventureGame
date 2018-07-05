#pragma once
#include "AdventureManager.h"
class Player
{
private:

	int theLocation;
	int hitPoints;
	int maxHp;
	int attackDamage;
	int defense;
	int numberOfMovements;
	Object* attack;
	Object* defenseEquip;
	string deathString;
	bool facedeath;
	bool Win;

public:
	Player();
	~Player();

	void displayInventory();
	void take(Object* object);
	void regainHP(Object* object);
	void increaseMaxHP(Object* object);
	void setLocation(int loc);
	int getLoc();
	vector<Object*> inventory;
	void setaEquip(Object* aEquip);
	void setdEquip(Object* dEquip);
	void getDamaged(int dmg);
	int getHealth();
	int getAttack();
	int getDef();
	void MovementsChange();

	string getAttackS();
	string getDefenseS();
	string getHealthS();
	string getDeathS();

	void theDeath();
	bool faceDeath();
	bool getWin();
	void setWin();
	int getMovements();
	Object* getFlashilight();
	Object* getGun();

	void setDefault();
};

