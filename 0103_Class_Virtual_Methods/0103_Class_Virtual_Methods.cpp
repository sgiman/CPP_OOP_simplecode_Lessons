// *****************************************************************************************************************
// Виртуальные методы класса c++. Ключевое слово virtual. Ключевое слово override. ООП. C++ #103  
// -----------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// -----------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// *****************************************************************************************************************

#include <iostream>
#include <string>

using namespace std;

/*----------------------------
* Виртуальные методы класса
*
* Полиморфизм
* Виртуальные функции:
* virtual
* override
*
*----------------------------*/

class Gun														// пистолет - базовый класс	
{
public:
	void virtual Shoot()										// виртуалный метод (для полиморфизма) - "virtual"
	{
		cout << " GUN: BANG! " << endl;
	}
};


class SubmachineGun : public Gun								// пистолет-пулемет
{
	void Shoot() override										// переопределить виртуальный метод Shoot() - полиморфизм
	{
		cout << " SUBMACHINE GUN: BANG! BANG! BANG! " << endl;
	}
};


class Bazooka : public Gun										// гранатомет - базука 
{
	void Shoot() override										// переопределить виртуальный метод Shoot() - полиморфизм
	{
		cout << " BAZOOKA: BUMBABABUM! " << endl;
	}
};


class Player													// игрок
{
public:
	void Shoot(Gun* gun)										// метод "выстрелить" c переданным оружием (указатель *gun)	
	{
		gun->Shoot();											// произести выстрел
	}
};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n  virtual & override functions for polymorphism \n" << endl;

	Gun gun;						// объект класса для "пистолет" (for virtual method - base class)
	SubmachineGun machinegun;		// объект класса для "пистолет-пулемет" (for override method)
	Bazooka bazooka;				// объект класса для "базука" (for override method)

	//Gun *weapon = &gun;			// "пистолет" (метод для полиморфизма)
	//Gun *weapon = &machinegun;	// "пистолет-пулемет" (метод для полиморфизма)
	//weapon->Shoot();

	Player player;					// объект класса "игрок"
	player.Shoot(&gun);				// выстрел из пистолета 
	player.Shoot(&machinegun);		// выстрел из пистолета-пулемета 
	player.Shoot(&bazooka);			// выстрел из базуки 

	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	system("pause");
	return 0;

}
