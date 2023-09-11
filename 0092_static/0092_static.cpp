//**************************************************************************************************
// static что это. Статические поля класса. Инициализация. Kлючевое слово static. | Уроки C++ #92  
// -------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// -------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//**************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-----------------------------------------
*	static
*   полезно для работы с ID класса и DB
*-----------------------------------------*/

class Apple;		// определение классов для поиска ниже
class Human;

// Глобальная переменнная 
// char *str_gtest = (char*) "\n str_gtest: Глобальная строковая перменнная\n";		// old style     
string str_gtest = "\n str_gtest: Глобальная строковая перменнная";					// new style

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
	friend Human;			// дружественный класс "Human" по отношению к текущему классу "Apple" (нарушение инкапсуляции)

public:
	static int Count;		// кол-во яблок - статическая переменная !!! (начальная инициализация "Count = 0" возможна только вне класса ниже)

	// к о н с т р у к т о р   
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;			//  Контроль кол-ва яблок при каждом создании соотв. объекта
	}

private:
	// с в о й с т в а
	int weight;
	string color;
};

int Apple::Count = 0;  // начальная инициализация статического поля только вне класса (в отличие от С# и Java)


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


	cout << "\n COUNT1 = " << apple.Count << endl;
	cout << "\n COUNT2 = " << apple2.Count << endl;
	cout << "\n COUNT3 = " << apple3.Count << endl;


	cout << "\n COUNT = " << Apple::Count;		// обращение к статической переменной (без экземпляра объекта) напрямую !!!

	cout << "\n____________________________________________________________\n" << endl;

	int a = 10;									// объявление переменной "a"
	int& ra = a;								// создание ссылки (reference) на переменную "a"

	cout << "АДРЕС &a = " << &a << endl;		// вывод на экран адреса переменой "a"
	cout << "ССЫЛКА &ra = " << &ra << endl;		// ссылка "ra" хранит в себе этот же адрес

	cout << str_gtest;							// глобальня переменная 				

	cout << "\n____________________________________________________________\n" << endl;

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
	cout << "TakeApple: " << "weight = " << apple.weight << " color = " << apple.color << endl;
}

void Human::EatApple(Apple& apple)
{
	cout << "EatApple: " << "weight = " << apple.weight << " color = " << apple.color << endl;
}
