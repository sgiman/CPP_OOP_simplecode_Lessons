//**************************************************************************************************************
// Дружественный метод класса. ООП. friend c++ что это. Функции друзья. | C++ Для начинающих. | Уроки C++ #90  
// -------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// -------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//**************************************************************************************************************

#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*--------------------------------------
 *	дружественные методы класса
 * (аналогично дружественным функциям)
 *-------------------------------------*/

class Apple;		// определение классов для поиска ниже
class Human;

//--- Human ---
class Human
{
public:
	// Прототипы для внешних методов 
	void TakeApple(Apple& apple);
	void EatApple(Apple& apple);
};


//--- Apple ---
class Apple
{
public:
	// к о н с т р у к т о р   
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
private:
	// с в о й с т в а
	int weight;
	string color;

	// Дружественные внешние методы из другого класса 
	friend void Human::TakeApple(Apple& apple);
	friend void Human::EatApple(Apple& apple);
};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	cout << "\n____________________________________________________________\n" << endl;

	Apple apple(150, "Red");	// внутренний метод
	Human human;
	human.TakeApple(apple);		// внеший метод
	human.EatApple(apple);

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
