// ****************************************************************************************************************
// Наследование в ООП пример. Что такое наследование. Для чего нужно наследование классов. ООП. C++| Уроки C++ #98  
// --------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// --------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei//
// 2019-2023 @ sgiman
// ****************************************************************************************************************

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*--------------------
*	 наследование
*---------------------*/

class Human							// базовый класс "Human"
{
private:
	// string name = " Имя: Иванов Иван Иванович";
	string name;

public:
	string GetName()				// Getter for "name"
	{
		return name;
	}

	void SetName(string name)		// Setter for "name"
	{
		this->name = name;
	}
};


class Student : public Human		// наcледование от класса "Human" 
{
public:
	string group;

	void Learn()
	{
		cout << " Student: Я учусь!" << endl;
	}

public:
	string name;
};


class Professor : public Human		// наcледование от класса "Human" 
{
public:
	string subject;
};


class ExtramuralStudent : public Student
{
public:
	void Learn()
	{
		cout << " Заочник: Я бываю в университете реже обычного студента!" << endl;
	}
};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;

	Student st;								// Объект класса "Студент"
	st.Learn();
	st.SetName(" Студент: Аристарх");		// Cетер для имени студента
	cout << st.GetName() << endl;			// Гетер для имени студента  

	cout << endl;

	ExtramuralStudent ExtraSt;				// Объект класса "Заочник"
	ExtraSt.Learn();
	ExtraSt.SetName(" Заочник: Евлампий");	// Cетер для имени заочника
	cout << ExtraSt.GetName() << endl;		// Гетер для имени заочника  


	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;

}