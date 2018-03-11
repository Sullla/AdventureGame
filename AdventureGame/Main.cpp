#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
#include "AdventureManager.h";
//#include "Player.h"
//#include "MotionTableEntry.h";
//#include "AdventureRooms.h";

using namespace std;

#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)

enum console
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
	
};

void setcolor(console textcol, console backcol)
{
	unsigned short wattributes = (backcol << 4) | textcol;

	SetConsoleTextAttribute(std_con_out, wattributes);
}

int main(vector <MotionTableEntry> dir2, vector <AdventureRooms> rms2)
{
	AdventureManager* AM = new AdventureManager();
	MotionTableEntry* MTE  = new MotionTableEntry();
	
	SetConsoleTitle("Swords and Dungeons");
	string strangersName;

	setcolor(green, blue);

	
	string QUIT;

	while (QUIT != "QUIT") {
		char menu;
		setcolor(black, green);
		cout << "\t============" << "============" << endl;
		cout << "\t\tMAIN MENU " << "" << endl;
		cout << "\t============" << "============" << endl;


	
		cout << "\n\tPress 1 to to see the data structure"
			<< "\n\tPress 2 to list of commands knows by program\n\tPress to move through rooms" << endl;
	
		cout << "\tPress 3 to start the game" << endl;
		cin >> menu;
		switch (menu) {
		case '1':
			setcolor(green, black);
			//AM->dataStructure();
			break;
		case '2':
			setcolor(yellow, black);
		//	AM->commandList();
			break;
		case '3':

			cout << "\t\t--------------THE GAME HAS BEEN STARTED--------------" << endl;

			cout << " ----------     ----------       ---------- \n";
			cout << "|         |     |         |      |         | \n";
			cout << "|  ROOM4  |  == |  ROOM3  |  ==  |  ROOM5  | \n";
			cout << "|         |     |         |      |         |\n";
			cout << "|         |     |         |      |         |\n";
			cout << "----------      ----------       ---------- \n";

			cout << "              \t ----------\n";
			cout << "              \t|         |\n";
			cout << "              \t|  ROOM2  |\n";
			cout << "              \t|         |\n";
			cout << "              \t|         |\n";
			cout << "              \t ----------\n";
			cout << "              \t ----------\n";
			cout << "              \t|         |\n";
			cout << "              \t|  ROOM1  |\n";
			cout << "              \t|         |\n";
			cout << "              \t|         |\n";
			cout << "              \t ----------\n";

			setcolor(black, green);
			
			setcolor(red, black);
		AM->MotionTable();
			break;

		}

		system("Pause");
		return 0;

	}
}