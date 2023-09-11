//*******************************************************************************************************
// id generator. Генератор уникальных идентификаторов с использованием static переменной| Уроки C++ #93  
// ------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//*******************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-------------------
 *	 id generator
 *------------------*/

class Apple;						// определение классов для поиска ниже
class Human;

// --- Human ---
class Human
{
public:
	// внешние методы 
	void TakeApple(Apple& apple);
	void EatApple(Apple& apple);
};

// --- Apple ---
class Apple
{
	friend Human;					// дружественный класс "Human" по отношению к текущему классу "Apple" (нарушение инкапсуляции)

public:
	static int Count;				// кол-во яблок - статическа¤ переменная 

	// к о н с т р у к т о р   
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;					// контроль кол-ва яблок при каждом создании соотв. объекта
		id = Count;					// идентификатор-счетчик - простой аналог SQL DB (c опцией "auto increment")
	}

	int GetId()
	{
		return id;
	}

private:
	// с в о й с т в а
	int weight;
	string color;
	int id;							// уникальный идентификатор 

};

// инициализация статического поля только вне класса 
int Apple::Count = 0;


/*********************************
		   === MAIN ===
**********************************/
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;

	Apple apple(150, "Red");
	Apple apple2(100, "Green");
	Apple apple3(200, "Yellow");


	Human human;
	human.TakeApple(apple);
	human.TakeApple(apple2);
	human.TakeApple(apple3);

	cout << "____________________________________________________________\n" << endl;

	cout << " ID = " << apple.GetId() << endl;
	cout << " ID = " << apple2.GetId() << endl;
	cout << " ID = " << apple3.GetId() << endl;

	cout << "\n COUNT = " << Apple::Count << endl;	// обращение к статической переменной (без экземпляра объекта) напрямую 

	cout << "____________________________________________________________\n" << endl;

	int a = 10;				// объявление переменной "a"
	int& ra = a;			// создание ссылки (reference) на переменную "a"

	cout << &a << endl;		// вывод на экран адреса переменой "a"
	cout << &ra << endl;	// ссылка "ra" хранит в себе этот же адрес

	cout << "____________________________________________________________\n" << endl;


	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}

/***********************
	=== METHODS ===
	  (external)
************************/
// внешние методы - вынесенные методы из области класса (Visual Studio standard) 
void Human::TakeApple(Apple& apple)
{
	cout << " TakeApple: " << "weight = " << apple.weight << " color = " << apple.color << endl;
}

void Human::EatApple(Apple& apple)
{
	cout << " EatApple: " << "weight = " << apple.weight << " color = " << apple.color << endl;
}
