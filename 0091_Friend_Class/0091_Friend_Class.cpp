//******************************************************************************************************
// Дружественные классы. ООП. friend class. friend c++ что это. | C++ Для начинающих | Уроки C++ #74  
// -----------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// -----------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//******************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*------------------------------
 *	дружественные классы
 *-----------------------------*/

class Apple;		// определение классов для поиска ниже...
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
	friend Human;	// дружественный класс "Human" по отношению к текущему классу "Apple" (нарушение инкапсуляции)

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

};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "ru");
	cout << "\n____________________________________________________________\n" << endl;

	Apple apple(150, "Red");
	Human human;
	human.TakeApple(apple);
	human.EatApple(apple);

	cout << "\n____________________________________________________________\n" << endl;

	int a = 10;				// объявление переменной "a"
	int& ra = a;			// создание ссылки (reference) на переменную "a"

	cout << &a << endl;		// вывод на экран адреса переменой "a"
	cout << &ra << endl;	// ссылка "ra" хранит в себе этот же адрес

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
