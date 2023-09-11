// *******************************************************************************************
// Что такое интерфейс в ООП. Интерфейс c++ пример | Изучение С++ для начинающих | Урок #113
// -------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022
// -------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// *******************************************************************************************

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*------------------------------------------
*  И Т Е Р Ф Е Й С:
*
* - наследование
* - множественное наследование
* - абстрактный класс
* - виртуальные методы
* - переопредедение виртуальных методов
*
*------------------------------------------*/

class IBicycle									// ВЕЛОСИПЕД
{
public:
	void virtual TwistTheWeel() = 0;			// руль
	void virtual Ride() = 0;					// eхать
};


class SimpleBicyle : public IBicycle			// ПРОСТОЙ ВЕЛОСИПЕД
{
public:
	void TwistTheWeel() override
	{
		cout << " метод TwistTheWeel() SimpleBicycle " << endl;
	}

	void Ride() override
	{
		cout << " метод Ride() SimpleBicycle " << endl;
	}
};


class SportBicyle : public IBicycle			// СПОРТИВНЫЙ ВЕЛОСИПЕД
{
public:
	void TwistTheWeel() override
	{
		cout << " метод TwistTheWeel() SortBicyle " << endl;
	}

	void Ride() override
	{
		cout << " метод Ride() SortBicyle " << endl;
	}
};


class Human										// ЧЕЛОВЕК
{
public:
	void RideOn(IBicycle& bicycle)
	{
		cout << " Крутим руль! " << endl;
		bicycle.TwistTheWeel();
		cout << endl << " Поехали! " << endl;
		bicycle.Ride();
	}
};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;
	SimpleBicyle sb;
	SportBicyle sportB;

	Human h;
	cout << " S i m p l e  B i c y l e : \n" << endl;
	h.RideOn(sb);
	cout << "\n____________________________________________________________\n" << endl;
	cout << "\n S p o r t  B i c y l e : \n" << endl;
	h.RideOn(sportB);
	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;

}