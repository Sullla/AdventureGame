#pragma once
#include <string>
using namespace std;

class Object
{
protected:
	string name;
	string description;
	string type;
public:
	Object(){}
	~Object(){}


	virtual int getattribute() = 0;
	virtual string gettype() = 0;
	virtual string gettoUse() = 0;
	virtual string Examine() = 0;
	virtual string getname() = 0;

};

class Gun : public Object
{
private:
	int attackingdamage;


public:
	Gun(string n, string d, string t, int dmg)
	{
		name = n;
		description = d;
		type = t;
		attackingdamage = dmg;
	}
	Gun()
	{

	}

	string Examine()
	{
		return description;
	}

	string getname()
	{
		return name;
	}
	int  getattribute()
	{
		return attackingdamage;
	}
	string gettype()
	{
		return type;
	}
	string gettoUse()
	{
		return "Cannot use a Gun\n";
	}
};

class Cross : public Object
{
private:
	int defense;

public:

	Cross(string n, string d, string t, int def)
	{
		name = n;
		description = d;
		type = t;
		defense = def;
	}
	Cross() {}

	string Examine()
	{
		return description;
	}

	string getname()
	{
		return name;
	}
	int getattribute()
	{
		return defense;
	}
	string gettype()
	{
		return type;
	}
	string gettoUse()
	{
		return "Cannot use a Cross\n";
	}
};

class Alcohol : public Object
{
private:
	int healAmount;
	string whenUsed;

public:

	Alcohol(string n, string d, string t, int heal, string used)
	{
		name = n;
		description = d;
		type = t;
		healAmount = heal;
		whenUsed = used;
	}
	Alcohol() {}

	string Examine()
	{
		return description;
	}

	string getname()
	{
		return name;
	}
	int  getattribute()
	{
		return healAmount;
	}
	string gettype()
	{
		return type;
	}
	string gettoUse()
	{
		return whenUsed;
	}

	
};

class Hint : public Object
{
private:
	int dummy;
	string whenUsed;
public:

	Hint(string n, string d, string t, int atri, string used)
	{
		name = n;
		description = d;
		type = t;
		dummy = atri;
		whenUsed = used;
	}
	Hint() {}

	string Examine()
	{
		return description;
	}

	string getname()
	{
		return name;
	}
	int getatribute()
	{
		return dummy;
	}
	string gettype()
	{
		return type;
	}

	string gettouse()
	{
		return whenUsed;
	}
};

class Flashlight : public Object
{
private:
	int dummy;
	string whenUsed;
public:

	Flashlight(string n, string d, string t, int atri, string used)
	{
		name = n;
		description = d;
		type = t;
		dummy = atri;
		whenUsed = used;
	}
	Flashlight() {}

	string Examine()
	{
		return description;
	}
	 
	string getname()
	{
		return name;
	}
	int getattribute()
	{
		return dummy;
	}
	string gettype()
	{
		return type;
	}

	string gettoUse()
	{
		return whenUsed;
	}
};

class Secret : public Object
{
private:
	int dummy;
	string whenUsed;
public:

	Secret(string n, string d, string t, int atri, string used)
	{
		name = n;
		description = d;
		type = t;
		dummy = atri;
		whenUsed = used;
	}


	string Examine()
	{
		return description;
	}

	string getname()
	{
		return name;
	}
	int getattribute()
	{
		return dummy;
	}
	string gettype()
	{
		return type;
	}

	string gettoUse()
	{
		return whenUsed;
	}
};


