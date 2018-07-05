#include "AdventureManager.h"
#pragma comment(lib,"winmm.lib")




AdventureManager::AdventureManager()
{
	restart = true;
	
}


AdventureManager::~AdventureManager()
{

}

void AdventureManager::setRestart(bool re)
{
	restart = re;
}
bool AdventureManager::getRestart()
{
	return restart;
}

void AdventureManager::Fight(Player *detective, Enemy* enemy, Colors color)
{
	
	bool playerTurn = true;
	bool ifDefended = false;
	bool specialAttack = false;
	int countForSpecial = 0;
	bool battleEnded = false;
	bool needRefresh = true;
	bool death = false;
	int command;
	int attackDmg;

	while (!battleEnded)
	{

		if (detective->getHealth() == 0 || enemy->getHealth() == 0)
		{
			needRefresh = true;
			death = true;
		}


		if (needRefresh)
		{
			;
			system("cls");
			color.setcolor(color.purple, color.black);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Detective Conan" << "                                                          " << enemy->getName() << endl;
			cout << "Health  : " << detective->getHealthS() << "                                                         " << "Health: " << enemy->getHealthS() << endl;
			cout << "Damage  : " << detective->getAttackS() << "                                                         " << "Damage:  " << enemy->getAttackDamageS() << endl;
			cout << "Resistance : " << detective->getDefenseS() << "                                                         " << "Defense: " << enemy->getDefenseS() << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			color.setcolor(color.yellow, color.black);

			cout << "Enter Battle mode :" << endl << endl;
			needRefresh = false;
		}

		if (death)
		{

			if (detective->getHealth() == 0)
			{
				detective->theDeath();

				cout << endl;
				cout << "The battle has ended" << endl;
				cout << enemy->getVictory();
				cout << endl;
				battleEnded = true;
				
				system("pause");
				break;

			}
			else if (enemy->getHealth() == 0 && enemy->bossSpecial() == 1)
			{

				cout << enemy->getDefeated() << endl << endl;
				cout << "You have obtained: " << endl;

				for (int i = 0; i < enemy->receiveitemvec().size(); i++)
				{

					cout << enemy->receiveitemvec()[i]->gettype() << endl;
					detective->inventory.push_back(enemy->receiveitemvec()[i]);
				}

				cout << "The battle has ended" << endl;
				battleEnded = true;
				enemy->killEnemy();
				cout << endl;
				if (roomLevel[detective->getLoc() - 1]->geteventype() == 2)
					roomLevel[detective->getLoc() - 1]->setStatus(true);
				break;
			}
			else if (enemy->getHealth() == 0 && enemy->bossSpecial() == 2)
			{

				cout << enemy->getDefeated() << endl << endl;

				cout << "The battle has ended" << endl;
				battleEnded = true;
				enemy->killEnemy();
				cout << endl;
				detective->setWin();

				break;
			}


		}



		if (playerTurn)
		{
			cout << "Choose the command to trigger an action: " << endl << "0: Attack" << endl << "1: Dodge" << endl;
			playerTurn = false;

			cin >> command;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			Sleep(1000);

			if (command == 0)
			{
				attackDmg = detective->getAttack() - enemy->getDefense();
				if (attackDmg < 0)
				{
					attackDmg = 0;
				}
				enemy->getDamaged(attackDmg);
				if (enemy->getHealth() == 0)
				{
					cout << "Your final attack has killed an enemy !" << endl;
					system("PAUSE");

				}
				else  cout << "You gave a damage to your enemy! You have dealt " << attackDmg << " damage!" << endl;

			}
			else if (command == 1)
			{
				ifDefended = true;
				cout << "You tried to dodge his attacks." << endl;


			}
			else
			{
				cout << "wrong battle command." << endl;
				system("PAUSE");
				playerTurn = true;
				needRefresh = true;

			}
		}
		else
		{
			Sleep(1500);
			if (enemy->isAlive() && enemy->bossSpecial() == 1)
			{
				attackDmg = enemy->getAttackDamage() - detective->getDef();
				if (attackDmg < 0)
				{
					attackDmg = 0;
				}

				if (ifDefended)
				{
					if (attackDmg > 2)
					{
						attackDmg = 2;
					}
					detective->getDamaged(attackDmg);
					ifDefended = false;
					cout << enemy->getName() <<  " has given you damage! You could stand against his attack an only received " << attackDmg << " damage!" << endl;
				}
				else
				{
					detective->getDamaged(attackDmg);
					cout << " You've received damage from " << enemy->getName() << " and it is: " << attackDmg << "  damage!" << endl;
				}

			}
			else
			{
				attackDmg = enemy->getAttackDamage() - detective->getDef();
				if (attackDmg < 0)
				{
					attackDmg = 0;
				}
				if (specialAttack)
				{
					cout << "Lord Vampire: CLAW ATTACK" << endl;
					attackDmg = attackDmg * 2;
					specialAttack = false;
				}
				else countForSpecial++;

				if (ifDefended)
				{
					if (attackDmg > 2)
					{
						attackDmg = 2;
					}
					detective->getDamaged(attackDmg);
					ifDefended = false;
					cout << enemy->getName() << " has given you damage! You could stand against his attack an only received " << attackDmg << " damage!" << endl;
				}
				else
				{
					detective->getDamaged(attackDmg);
					cout <<" You've received damage from " << enemy->getName() <<  " and it is: " << attackDmg << "  damage!" << endl;

				}



				if (countForSpecial == 2)
				{
					specialAttack = true;
					countForSpecial = 0;
				}

			}
			playerTurn = true;
			needRefresh = true;
			system("PAUSE");
		}



	}
}

void AdventureManager::FileToRead(ifstream& dataFile)
{

	int numberOfRooms;
	dataFile >> numberOfRooms;

	for (int size = 0; size < numberOfRooms; size++)
	{
		int roomNumb, currentInt, descriptionRepeat, eventNumber;
		string roomName, direction, symbol;
		string roomDescription, dialogueDescription, deniedAccessDesc;
		string requiredLine;
		MotionTableEntry *motion = NULL;
		Enemy * myEnemy = NULL;
		vector<MotionTableEntry*>motionVector;

		dataFile >> roomNumb;
		dataFile >> eventNumber;
		
		do
		{
			dataFile >> requiredLine;

			if (requiredLine != "****")
				roomName += requiredLine + " ";

		} while (requiredLine != "****");
		AdventureRooms *room = new AdventureRooms(roomNumb, roomName, eventNumber);

		
		dataFile >> descriptionRepeat;
		for (int d = 0; d < descriptionRepeat; d++)
		{
			do
			{
				dataFile >> requiredLine;

				if (requiredLine != "****")
				{
					roomDescription += requiredLine + " ";

				}
			} while (requiredLine != "****");

			if (d == 0)
			{
				room->roomDescription.push_back(roomDescription);
			}
			else room->roomDescription2.push_back(roomDescription);

			roomDescription = "";
			dataFile >> currentInt;


			if (currentInt == 1)
			{
				do
				{
					dataFile >> requiredLine;

					if (requiredLine != "****" && requiredLine != "+")
					{
						dialogueDescription += requiredLine + " ";
					}
					if (requiredLine == "+")
					{
						if (d == 0)
							room->roomDescription.push_back(dialogueDescription);
						else room->roomDescription2.push_back(dialogueDescription);
						dialogueDescription = "";
					}


				} while (requiredLine != "****");
			}
		}

		
		dataFile >> currentInt;
		if (currentInt == 2)
		{
			room->setActive(true);

		}
		else room->setActive(false);

		
		do
		{

			dataFile >> requiredLine;

			if (requiredLine != "****")
			{
				direction = requiredLine;

				dataFile >> currentInt;

				dataFile >> symbol;

				while (requiredLine != "===" && requiredLine != "****")
				{
					dataFile >> requiredLine;

					if (requiredLine != "===" && requiredLine != "****")
					{
						deniedAccessDesc += requiredLine + " ";
					}

				}


				motion = new MotionTableEntry(direction, currentInt, deniedAccessDesc, symbol);

				if (roomNumb == motion->getDest())
				{
					motion->setidden(true);

				}
				else motion->setidden(false);

				motionVector.push_back(motion);
				deniedAccessDesc = "";

			}

		} while (requiredLine != "****");

		
		do
		{

			dataFile >> requiredLine;

			if (requiredLine == "<>")
			{

				dataFile >> requiredLine;

				string name;
				string description;
				string type;
				int attribute;

				if (requiredLine == "GUN")
				{
					type = requiredLine;

					while (requiredLine != "===")
					{
						dataFile >> requiredLine;

						if (requiredLine != "===")
							name += requiredLine + " ";
					}

					do
					{
						dataFile >> requiredLine;


						if (requiredLine != "===")
							description += requiredLine + " ";

					} while (requiredLine != "===");

					dataFile >> attribute;
					dataFile >> requiredLine;
					if (requiredLine == "+" || requiredLine == "<" || requiredLine == "V" || requiredLine == ">")
					{
						Object *item = new Gun(name, description, type, attribute);
						room->roomObjects.push_back(item);
						for (int count = 0; count < motionVector.size(); count++)
						{
							if (requiredLine == motionVector[count]->getSymbol())
								motionVector[count]->requiredObjects.push_back(item);
						}


					}
					else
					{
						Object *item = new Gun(name, description, type, attribute);
						room->roomObjects.push_back(item);

					}


				}
				else if (requiredLine == "CROSS")
				{
					type = requiredLine;
					while (requiredLine != "===")
					{
						dataFile >> requiredLine;

						if (requiredLine != "===")
							name += requiredLine + " ";
					}

					do
					{
						dataFile >> requiredLine;


						if (requiredLine != "===")
							description += requiredLine + " ";

					} while (requiredLine != "===");

					dataFile >> attribute;
					dataFile >> requiredLine;

					if (requiredLine == "+" || requiredLine == "<" || requiredLine == "V" || requiredLine == ">")
					{
						Object *item = new Cross(name, description, type, attribute);
						room->roomObjects.push_back(item);
						for (int count = 0; count < motionVector.size(); count++)
						{
							if (requiredLine == motionVector[count]->getSymbol())
								motionVector[count]->requiredObjects.push_back(item);
						}

					}
					else
					{
						Object *item = new Cross(name, description, type, attribute);
						room->roomObjects.push_back(item);

					}
				}
				else if (requiredLine == "FLASHLIGHT")
				{

					type = requiredLine;
					while (requiredLine != "===")
					{
						dataFile >> requiredLine;

						if (requiredLine != "===")
							name += requiredLine + " ";
					}

					do
					{
						dataFile >> requiredLine;


						if (requiredLine != "===")
							description += requiredLine + " ";

					} while (requiredLine != "===");

					dataFile >> attribute;
					dataFile >> requiredLine;

					if (requiredLine == "+" || requiredLine == "<" || requiredLine == "V" || requiredLine == ">")
					{
						Object *item = new Flashlight(name, description, type, attribute, "The flashlight that you used clears the visibility.");
						room->roomObjects.push_back(item);
						for (int count = 0; count < motionVector.size(); count++)
						{
							if (requiredLine == motionVector[count]->getSymbol())
								motionVector[count]->requiredObjects.push_back(item);
						}
						
					}
					else
					{
						Object *item = new Flashlight(name, description, type, attribute, "The flashlight that you used clears the visibility.");
						room->roomObjects.push_back(item);

					}
				}
				else if (requiredLine == "SECRET")
				{

					type = requiredLine;
					while (requiredLine != "===")
					{
						dataFile >> requiredLine;

						if (requiredLine != "===")
							name += requiredLine + " ";
					}

					do
					{
						dataFile >> requiredLine;


						if (requiredLine != "===")
							description += requiredLine + " ";

					} while (requiredLine != "===");

					dataFile >> attribute;

					dataFile >> requiredLine;

					if (requiredLine == "+" || requiredLine == "<" || requiredLine == "V" || requiredLine == ">")
					{
						Object *item = new Secret(name, description, type, attribute, "You cannot use a secret?");
						room->roomObjects.push_back(item);
						for (int count = 0; count < motionVector.size(); count++)
						{
							if (requiredLine == motionVector[count]->getSymbol())
								motionVector[count]->requiredObjects.push_back(item);
						}

					}
					else
					{

						Object *item = new Secret(name, description, type, attribute, "You cannot use a secret?");
						room->roomObjects.push_back(item);

					}
				}

			}
		} while (requiredLine != "****");

		
		do {

			dataFile >> requiredLine;

			if (requiredLine == "###")
			{

				string type, defeat, victory, name;
				int hp, ad, def;

				dataFile >> type;

				do {
					dataFile >> requiredLine;

					if (requiredLine != "===")
						name += requiredLine + " ";
				} while (requiredLine != "===");


				do {
					dataFile >> requiredLine;

					if (requiredLine != "===")
						defeat += requiredLine + " ";
				} while (requiredLine != "===");

				do {
					dataFile >> requiredLine;

					if (requiredLine != "===")
						victory += requiredLine + " ";
				} while (requiredLine != "===");

				dataFile >> hp;
				dataFile >> ad;
				dataFile >> def;

				if (type == "ENEMY")
				{

					dataFile >> requiredLine;
					myEnemy = new Gargoyle(type, hp, ad, def, name, defeat, victory, requiredLine);
			
				}
				else if (type == "BOSS")
				{
					dataFile >> requiredLine;
					myEnemy = new Lordvampire(type, hp, ad, def, name, defeat, victory, requiredLine);
				}

				while (requiredLine != "****")
				{

					dataFile >> requiredLine;

					if (requiredLine == "<>")
					{

						dataFile >> requiredLine;
						string name;
						string description;
						string type;
						int attribute;

						if (requiredLine == "ALCOHOL")
						{
							type = requiredLine;

							while (requiredLine != "===")
							{
								dataFile >> requiredLine;

								if (requiredLine != "===")
									name += requiredLine + " ";
							}

							do
							{
								dataFile >> requiredLine;


								if (requiredLine != "===")
									description += requiredLine + " ";

							} while (requiredLine != "===");

							string whenUsed;
							dataFile >> attribute;

							do
							{
								dataFile >> requiredLine;


								if (requiredLine != "===")
									whenUsed += requiredLine + " ";
							} while (requiredLine != "===");


							Object *item = new Alcohol(name, description, type, attribute, whenUsed);
							myEnemy->getItem(item);
						}
					
					}
				}
				room->enemy = myEnemy;

			}


		} while (requiredLine != "****");

		room->motionTable = motionVector;
		roomLevel.push_back(room);
	}



}
void AdventureManager::deleteRooms()
{
	roomLevel.empty();
}

bool AdventureManager::runBool(Player* detective, Colors color)
{

	
	string command = " ";
	string input = "start";

	bool viableCommand;
	string object;
	input = "start";
	viableCommand = false;
	color.setcolor(color.magenta, color.black);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Health  : " << detective->getHealth() << "               " << "Steps: " << detective->getMovements() << endl;

	cout << "Damage  : " << detective->getAttack() << "               " << "Currently Equiped: " << endl;
	if (detective->getFlashilight()== NULL)
		cout << "Resistance : " << detective->getDef() << "               " << "Hand gun: none" << endl;
	else
		cout << "Resistance : " << detective->getDef() << "             " << "Hand gun: " << detective->getFlashilight()->getname() << endl;
	if (detective->getGun() == NULL)
		cout << "                          " << "Holly cross: none" << endl;

	else
		cout << "                                                   " << "Holly cross: " << detective->getGun()->getname() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	color.setcolor(color.aqua, color.black);
	cout << roomLevel[(detective->getLoc()) - 1]->getName() << endl;
	if (roomLevel[(detective->getLoc()) - 1]->getActive())
	{
		if (!roomLevel[(detective->getLoc()) - 1]->getStatus())
		{
			for (int a = 0; a < roomLevel[detective->getLoc() - 1]->roomDescription.size(); a++)
			{
				cout << roomLevel[detective->getLoc() - 1]->roomDescription[a] << endl;
			}
		}
		else
		{
			for (int a = 0; a < roomLevel[detective->getLoc() - 1]->roomDescription2.size(); a++)
			{
				cout << roomLevel[detective->getLoc() - 1]->roomDescription2[a] << endl;
			}
		}
		
	}
	else
	{
		cout << "-----------------" << endl;
		cout << "Detective Conan: The room has not light at all!" << endl;
		cout << "Detective Conan: i better find something to USE that would help me see" << endl;

	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	color.setcolor(color.green, color.black);
	cout << "Possible Directions: " << endl;
	color.setcolor(color.green, color.black);
	if (roomLevel[(detective->getLoc()) - 1]->getActive())
	{
		for (int c = 0; c < roomLevel[detective->getLoc() - 1]->motionTable.size(); c++) {
			if (!roomLevel[detective->getLoc() - 1]->motionTable[c]->gethidden())
				cout << roomLevel[detective->getLoc() - 1]->motionTable[c]->getDir() << endl;
		}
	}
	else
	{
		cout << "-----" << endl << "-----" << endl << "-----" << endl;
	}
	color.setcolor(color.dark_aqua, color.black);
	cout << "~~~~~~~~~~~~~~~~~~" << endl;
	color.setcolor(color.white, color.black);

      while (!viableCommand)
	{
		viableCommand = true;

		getline(cin, input);
		istringstream iss(input);

		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
		int count = 0;
		while (iss)
		{
			if (count == 0)
			{
				iss >> command;
				object = "";
			}
			else if (count == 1)
			{
				iss >> object;
			}
			else
			{
				break;
			}
			count++;
		}
		iss.clear();
		iss.ignore();

		transform(command.begin(), command.end(), command.begin(), ::toupper);
		transform(object.begin(), object.end(), object.begin(), ::toupper);


		if (command == "EXIT")
		{
			cout << "Thank you for playing" << endl;
			system("PAUSE");
			setRestart(false);
			return true;


		}
		
		
		else if (command == "HELP")
		{
			color.setcolor(color.green, color.black);
			system("cls");
			cout << "Here is the list of commands that you will be able yo use: " << endl;
			cout << "Commands: " << endl;
			cout << "1.LOOK" << endl;
			cout << "2.USE=====For example: ALCOHOL===" << endl;
			cout << "3.EQUIP=====For example: GUN, HOLLY CROSS=====" << endl;
			cout << "4.BATTLE====For example: BOSS, ENEMY====" << endl;
			cout << "5.TAKE" << endl;
			cout << "6.INVENTORY " << endl;
			cout << "7.HELP " << endl;
			cout << "8.EXIT " << endl << endl;
			cout << "9.Movement Commands:" << endl;
			cout << "10.NORTH" << endl << "EAST " << endl << "SOUTH" << endl << "WEST" << endl << endl;
			
		}
		else if (command == "INVENTORY")
		{

			detective->displayInventory();
		}
		else if (command == "BATTLE")
		{

			if (object == "ENEMY" && roomLevel[detective->getLoc() - 1]->enemy != NULL && roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() != "FORCED" && roomLevel[detective->getLoc() - 1]->enemy->isAlive())
			{
				if (roomLevel[detective->getLoc() - 1]->enemy->isAlive())
					Fight(detective, roomLevel[detective->getLoc() - 1]->enemy, color);
				else
				{
					cout << "You have killed your enemies already here." << endl;
				}
			}
			else if (object == "BOSS" && roomLevel[detective->getLoc() - 1]->enemy != NULL)
			{
				if (object == "BOSS" && roomLevel[detective->getLoc() - 1]->enemy != NULL)
					Fight(detective, roomLevel[detective->getLoc() - 1]->enemy, color);
				else cout << "There is no Boss." << endl;
			}
			else
			{
				cout << "You cannot battle that." << endl;
			}

		}
		else if (command == "TAKE")
		{
			bool objectTaken = false;

			for (int i = 0; i < roomLevel[detective->getLoc() - 1]->roomObjects.size(); i++)
			{
				//checks if the object the user gave as input is in the room
				if (object == roomLevel[detective->getLoc() - 1]->roomObjects[i]->gettype())
				{
					if (object != "SECRET")
					{

						detective->take(roomLevel[detective->getLoc() - 1]->roomObjects[i]);
						cout << "You have obtained " << roomLevel[detective->getLoc() - 1]->roomObjects[i]->getname() << endl << endl;
						roomLevel[detective->getLoc() - 1]->roomObjects.erase(roomLevel[detective->getLoc() - 1]->roomObjects.begin() + i);
						objectTaken = true;
						if (roomLevel[detective->getLoc() - 1]->geteventype() == 2)
							roomLevel[detective->getLoc() - 1]->setStatus(true);
					
					
					}
				}
				if (objectTaken)break;
			}
			if (!objectTaken)
			{
				cout << "Sorry, you are unbale to pick this object" << endl;
			}



		}
		else if (command == "EQUIP")
		{
			int choice;
			bool equip = false;
			int count = 0;
			if (detective->inventory.size() != 0)
			{
				if (object == "GUN")
				{

					cout << "Type the gun you would wish to choose:" << endl << "Inventory: " << endl;
					for (int i = 0; i < detective->inventory.size(); i++)
					{
						if (detective->inventory[i]->gettype() == object)
						{
							cout << i << " " << detective->inventory[i]->getname() << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "There are no GUNS in your inventory" << endl;
						system("PAUSE");
						system("cls");
						break;
					}
					cin >> choice;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail(), '\n');
					if (choice >= detective->inventory.size() || choice < 0 || detective->inventory[choice]->gettype() != object)
					{
						cout << "Unfortunately there is not such option in your inventory" << endl;
						system("PAUSE");
						system("cls");
						break;
					}
					detective->setaEquip(detective->inventory[choice]);


					cout << "You have equipped " << detective->inventory[choice]->getname() << endl;


				}
				else if (object == "CROSS")
				{
					cout << "Type the CROSS you would wish to choose:" << endl << "Inventory: " << endl;
					for (int i = 0; i < detective->inventory.size(); i++)
					{
						if (detective->inventory[i]->gettype() == object)
						{
							cout <<  i << ". " << detective->inventory[i]->getname() << endl;
							count++;
						}

					}
					if (count == 0)
					{
						cout << "There are no CROSSES in your inventory" << endl;
						system("PAUSE");
						system("cls");
						break;
					}
					cin >> choice;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail(), '\n');
					if (choice >= detective->inventory.size() || choice < 0 || detective->inventory[choice]->gettype() != object)
					{
						cout << "Unfortunately there is not such option in your inventory" << endl;
						system("PAUSE");
						system("cls");
						break;
					}
					detective->setdEquip(detective->inventory[choice]);
					equip = true;
					cout << "You have equipped " << detective->inventory[choice]->getname() << endl;
				}
				else
				{
					cout << "No object was given with Command" << endl;
				}

			}
			else
			{
				cout << "You have not found anythisng in your invenotyr that you can equip" << endl;

			}

		}
		else if (command == "USE")
		{
			int choice;

			if (object == "ALCOHOL")
			{
				cout << "Enter the number of the alcohol you wish to use" << endl << "Inventory: " << endl;
				for (int i = 0; i < detective->inventory.size(); i++)
				{
					if (detective->inventory[i]->gettype() == object)
						cout << i << ".: " << detective->inventory[i]->getname() << endl;
				}
				cin >> choice;
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail(), '\n');

				if (choice >= detective->inventory.size() || choice < 0 || detective->inventory[choice]->gettype() != object)
				{
					cout << "Sorry, that is not an option in your Inventory" << endl;
					system("PAUSE");
					system("cls");
					break;
				}
				else
				{
					string Old = "Old";
					string Glass = "Glass";
					if (detective->inventory[choice]->getname()[0] == Old[0])
					{
						detective->regainHP(detective->inventory[choice]);
					}
					else if (detective->inventory[choice]->getname()[0] == Glass[0])
					{
						detective->increaseMaxHP(detective->inventory[choice]);
					}

					cout << detective->inventory[choice]->gettoUse() << endl;
					detective->inventory.erase(detective->inventory.begin() + choice);

				}

			}
			
			else if (object == "FLASHLIGHT")
			{
				for (int i = 0; i < detective->inventory.size(); i++)
				{
					if (detective->inventory[i]->gettype() == object)
					{
						if (detective->inventory[i]->getattribute() == detective->getLoc())
						{
							if (!roomLevel[detective->getLoc() - 1]->getActive())
							{
								roomLevel[detective->getLoc() - 1]->setActive(true);
								cout << detective->inventory[i]->gettoUse();
								cout << endl;

							}
						}
						else
						{
							cout << "Nothing happened..." << endl;
						}
					}
				}

			}
			else
			{
				cout << "No object was given with Command" << endl;

			}

		}
		else if (command == "LOOK")
		{
			bool objectLooked = false;

			for (int i = 0; i < roomLevel[detective->getLoc() - 1]->roomObjects.size(); i++)
			{

				if (object == roomLevel[detective->getLoc() - 1]->roomObjects[i]->gettype())
				{
					cout << roomLevel[detective->getLoc() - 1]->roomObjects[i]->Examine() << endl;
					objectLooked = true;
					if (roomLevel[detective->getLoc() - 1]->roomObjects[i]->gettype() == "SECRET")
					{
						detective->setLocation(roomLevel[detective->getLoc() - 1]->roomObjects[i]->getattribute());
						//system("PAUSE");
						//system("cls");
					}

				}
			}
			if (objectLooked == false)
			{
				cout << "Sorry, that is not an Object" << endl;
			}

		}
		else
		{
			//allows player to move between the rooms
			bool matchFound = false;
			if (roomLevel[(detective->getLoc()) - 1]->getActive())
			{
				for (int i = 0; i < roomLevel[detective->getLoc() - 1]->motionTable.size(); i++)
				{
					if (matchFound)break;

					
					if (command == roomLevel[detective->getLoc() - 1]->motionTable[i]->getDir() && !roomLevel[detective->getLoc() - 1]->motionTable[i]->gethidden())
					{
						
						if (roomLevel[detective->getLoc() - 1]->motionTable[i]->requiredObjects.size() == 0)
						{
							
							if (roomLevel[detective->getLoc() - 1]->enemy == NULL || (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() != command) || (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() == command && !roomLevel[detective->getLoc() - 1]->enemy->isAlive()))
							{
								

								detective->setLocation(roomLevel[detective->getLoc() - 1]->motionTable[i]->getDest());
								detective->MovementsChange();
								matchFound = true;
								
								if (roomLevel[detective->getLoc() - 1]->geteventype() == 1)
									roomLevel[detective->getLoc() - 1]->setStatus(true);

							}
							
							else if (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() == command && roomLevel[detective->getLoc() - 1]->enemy->isAlive())
							{
								cout << roomLevel[detective->getLoc() - 1]->motionTable[i]->getDeniedAccess() << endl;
								matchFound = true;

							}
						}
						else 
						{
							int count = 0;
						
							for (int b = 0; b < roomLevel[detective->getLoc() - 1]->motionTable[i]->requiredObjects.size(); b++)
							{
								for (int c = 0; c < detective->inventory.size(); c++)
								{
									if (detective->inventory[c] == roomLevel[detective->getLoc() - 1]->motionTable[i]->requiredObjects[b])
									{
										count++;
									}
								}
							}
							
							if (count == roomLevel[detective->getLoc() - 1]->motionTable[i]->requiredObjects.size())
							{
								
								if (roomLevel[detective->getLoc() - 1]->enemy == NULL || (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() != command) || (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() == command && !roomLevel[detective->getLoc() - 1]->enemy->isAlive()))
								{
									

									detective->setLocation(roomLevel[detective->getLoc() - 1]->motionTable[i]->getDest());
									detective->MovementsChange();
									matchFound = true;
									
									if (roomLevel[detective->getLoc() - 1]->geteventype() == 1)
										roomLevel[detective->getLoc() - 1]->setStatus(true);

								}
								else if (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() == command && roomLevel[detective->getLoc() - 1]->enemy->isAlive())
								{
									cout << roomLevel[detective->getLoc() - 1]->motionTable[i]->getDeniedAccess() << endl;
									matchFound = true;
								}

							}
							else 
							{
								cout << roomLevel[detective->getLoc() - 1]->motionTable[i]->getDeniedAccess() << endl;
								matchFound = true;
							}

						}


					}

					else if (roomLevel[detective->getLoc() - 1]->enemy != NULL && roomLevel[detective->getLoc() - 1]->motionTable[i]->gethidden())
					{

						if (roomLevel[detective->getLoc() - 1]->enemy->minionSpecial() == command && roomLevel[detective->getLoc() - 1]->enemy->isAlive())
						{
							cout << "IT IS A TRAP!" << endl;
							Fight(detective, roomLevel[detective->getLoc() - 1]->enemy, color);
							matchFound = true;
						}

					}

				}
				if (!matchFound)
				{
					viableCommand = false;
				}
			}
			else if (!roomLevel[(detective->getLoc()) - 1]->getActive())
			{
				if (command == "NORTH" || command == "SOUTH" || command == "EAST")
				{
					cout << "Detective Conan: DAMN IT!!! probably some kinda trap." << endl;;
					detective->getDamaged(2);

				}
				else if (command == "WEST")
				{
					detective->setLocation(2);

				}

			}

		}

		if (detective->getLoc() == 5)
		{

			if (roomLevel[4]->roomObjects.size() == 0)
			{
				
				detective->setLocation(4);

			}

		}



		if (detective->getWin())
		{
			
			Sleep(2500);
			system("cls");
			color.setcolor(color.green, color.black);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			color.setcolor(color.green, color.black);
			cout << "=======================YOU=WON!=======================" << endl;
			color.setcolor(color.green, color.black);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

			system("PAUSE");
			system("cls");
			cout << "Thank you for Playing" << endl;
			cout << "The game will now exit" << endl;
			setRestart(false);
			system("PAUSE");
			return true;
		}

		if (detective->faceDeath())
		{
			cout << detective->getDeathS() << endl;
			Sleep(2500);
			system("cls");
			color.setcolor(color.red, color.black);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			color.setcolor(color.red, color.black);
			cout << "======================GAME=OVER=======================" << endl;
			color.setcolor(color.red, color.black);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;


			system("PAUSE");
			system("cls");

			return true;
		}

		if (!viableCommand)
			cout << "Unable to understand this command, try again please " << endl;
		else
		{
			system("PAUSE");
			system("cls");
		}

	}	return false;

}

