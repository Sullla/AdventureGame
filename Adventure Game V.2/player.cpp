#include "Player.h"



Player::Player()
{
	theLocation = 1;
	hitPoints = 25;
	maxHp = 40;
	attackDamage = 2;
	defense = 1;
	numberOfMovements = 0;
	attack = NULL;
	defenseEquip = NULL;
	Win = false;
	facedeath = false;
	deathString = "'Damn it!!!!'";
}


Player::~Player()
{
}

void Player::displayInventory()
{
	if (inventory.size() == 0) cout << "There are currently no items in your Inventory" << endl;
	else
	{
		cout << "Your current Inventory includes: " << endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << i << ". : " << inventory[i]->getname() << endl;
		}

	}

}

void Player::take(Object* item)
{
	inventory.push_back(item);
}
void Player::regainHP(Object* item)
{
	hitPoints += item->getattribute();
	if (hitPoints > maxHp) hitPoints = maxHp;
}
void Player::increaseMaxHP(Object* item)
{
	maxHp += item->getattribute();
	hitPoints = maxHp;
}
int Player::getLoc()
{
	return theLocation;
}
void Player::setLocation(int loc)
{
	theLocation = loc;
}
void Player::setaEquip(Object* aEquip)
{
	attack = aEquip;

}
void Player::setdEquip(Object* dEquip)
{
	defenseEquip = dEquip;

}

void Player::getDamaged(int dmg)
{
	hitPoints -= dmg;

	if (hitPoints < 0)
	{
		hitPoints = 0;
	}
}

int Player::getHealth()
{
	return hitPoints;
}
int Player::getMovements()
{
	return numberOfMovements;
}
void Player::MovementsChange()
{
	numberOfMovements++;
}
string Player::getHealthS()
{

	if (hitPoints < 10)
		return "0" + to_string(hitPoints);
	else
		return  to_string(hitPoints);

}
int Player::getAttack()
{
	int newAttack;
	if (attack != NULL)
	{
		newAttack = attackDamage + attack->getattribute();
	}
	else newAttack = attackDamage;

	return newAttack;
}
string Player::getAttackS()
{
	int newAttack;
	if (attack != NULL)
	{
		newAttack = attackDamage + attack->getattribute();
	}
	else newAttack = attackDamage;
	if (newAttack < 10)
		return "0" + to_string(newAttack);
	else
		return  to_string(newAttack);
}

int Player::getDef()
{

	int newDef;
	if (defenseEquip != NULL)
	{
		newDef = defense + defenseEquip->getattribute();
	}
	else newDef = defense;

	return newDef;


}
string Player::getDefenseS()
{
	int newDefense;
	if (defenseEquip != NULL)
	{
		newDefense = defense + defenseEquip->getattribute();
	}
	else newDefense = defense;
	if (newDefense < 10)
		return "0" + to_string(newDefense);
	else
		return to_string(newDefense);
}
Object* Player::getFlashilight()
{
	return attack;
}
Object* Player::getGun()
{
	return defenseEquip;
}

void Player::theDeath()
{
	facedeath = true;
}

string Player::getDeathS()
{
	return deathString;
}
bool Player::faceDeath()
{
	return facedeath;
}

void Player::setDefault()
{
	theLocation = 1;
	hitPoints = 25;
	maxHp = 25;
	attackDamage = 2;
	defense = 1;
	numberOfMovements = 0;
	attack = NULL;
	defenseEquip = NULL;
	facedeath = false;
	Win = false;

	inventory.clear();

}

bool Player::getWin()
{
	return Win;
}
void Player::setWin()
{
	Win = true;
}