// *******************************************************************************************************
// Виртуальное наследование c++. Ромбовидное наследование c++. | Изучение С++ для начинающих | Урок #114
//---------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
//---------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// *******************************************************************************************************

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-----------------------------------------------------------------------
*  виртуальное наследование
*  ромбовидное наследование
*------------------------------------------------------------------------*/

// --- C O M P U T E R (стандартное множественное наследование) --- 

class Component												// компонента - базовый класс
{
public:
	Component(string companyName)
	{
		cout << " конструктор Component " << endl;
		this->companyName = companyName;
	}
	string companyName;
};


class GPU : public Component								// графический процессор 	
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << " конструктор GPU " << endl;
	}
};


class Memory : public Component								// память
{
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << " конструктор Memory " << endl;
	}
};


class GraphicsCard : public GPU, public Memory				// графическая карта  
{
public:
	GraphicsCard(string GPUCompanyName, string MemoryCompanyName) : GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << " конструктор GarhicsCard " << endl;
	}
};


// --- G A M E (виртуальное-ромбовидное множественное наследование)---
class Character
{
public:
	Character()												// персонаж
	{
		cout << " конструктор Character " << endl;
		int HP;												// Hip-Points
	}
};


class Orc : public virtual Character						// орк (c виртуальным отдельным наследником "character" - не общим )	
{
public:
	Orc()
	{
		cout << " конструктор Orc " << endl;
	}
};


class Warrior : public virtual Character					// воин (c виртуальным отдельным наследником "character" - не общим )	 
{
public:
	Warrior()
	{
		cout << " конструктор Warrior " << endl;
	}
};


class OrcWarrior : public Orc, public Warrior				// орк-воин (множетсвенное "виртуальное-ромбовидное" наследование)
{
public:
	OrcWarrior()
	{
		cout << " конструктор OrcWarrior " << endl;
	}
};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;
	//GraphicsCard gc("AMD", "Sumsung");
	OrcWarrior orc;
	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;

}