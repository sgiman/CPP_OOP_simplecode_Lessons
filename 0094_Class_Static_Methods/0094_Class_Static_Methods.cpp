//****************************************************************************************************************
// Статические методы класса зачем нужны. Модификатор static. Как влияет. ООП. | С++ Для начинающих | Урок #94  
// ---------------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ---------------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//****************************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*-----------------------------------------------------------------------------------------
 *  Class static methods
 *
 *  В статических методах запрещена работа с нестатическими полями.
 *  В статических методах разрешена работа только со статическими полями.
 *  Статический метод привязан тольто к типу (классу) и не привязан к конкректному объекту
 *  Статические поля и методы класса работают без экземпляра-объекта класса
 *  Eсли метод не статичеcкий - к нему можно обратиться только через экземпляр класса (объект.метод)
 *  this (указатель на самого себя) используется только для нестатических методов
 *  Статический метод не принадлежит ни какому объекту
 *-----------------------------------------------------------------------------------------*/

class Apple;		// определение классов для поиска ниже
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
	friend Human;	// дружественный класс "Human" по отношению к текущему классу "Apple" ("нарушение" инкапсуляции)

public:

	// к о н с т р у к т о р   
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++;					// Контроль кол-ва яблок при каждом создании соотв. объекта
		id = Count;					// Идентификатор-счетчик 
	}

	int GetId()
	{
		return id;
	}

	static int GetCount()									// Возврат значения "Count" (сатический getter)
	{
		return Count;
	}

	static void ChangeColor(Apple& apple, string color)		// статический (обязательна ссылка на объект!) 
	{
		apple.color = color;								// обращение только через экземпляр класса
		// this->color = color;								// ERROR!
	}

	void ChangeColorNoStatic(string color)					// нестатический метод (без передачи ссылки на объект)
	{
		this->color = color;
	}

private:
	// с в о й с т в а
	static int Count;			// статическая переменная
	int weight;					// не статическое поле, созданное на уровне объекта	
	string color;
	int id;						// уникальный идентификатор 

};

int Apple::Count = 0;			// инициализация статического поля только вне класса 


/*********************************
		   === MAIN ===
**********************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;

	// - OBJECTS - 
	Apple apple1(150, "Red");
	Apple apple2(100, "Green");
	Apple apple3(200, "Yellow");
	Human human;

	cout << "  Apple::GetCount(): " << Apple::GetCount() << endl;	// вызвать статический метод через класс 

	// - COLOR -
	apple1.ChangeColor(apple1, "Green");							// (1) обращение к методу через экземпляр (объект) - "new style"
	human.TakeApple(apple1);

	Apple::ChangeColor(apple1, "Yellow");							// (2) обращение к методу через класс - "old style"
	human.TakeApple(apple1);

	cout << endl;
	apple1.ChangeColorNoStatic("RED");								// (3) обращение к нестатическому методу

	// - TAKE APPLE -
	human.TakeApple(apple1);										// Info about apple
	human.TakeApple(apple2);
	human.TakeApple(apple3);

	// - GET ID -
	cout << endl;
	cout << " ID = " << apple1.GetId() << endl;
	cout << " ID = " << apple2.GetId() << endl;
	cout << " ID = " << apple3.GetId() << endl;

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
	cout << " TakeApple: " << "\tweight = " << apple.weight << "\tcolor = " << apple.color << "\tid = " << apple.id << endl;
}

void Human::EatApple(Apple& apple)
{
	cout << " EatApple: " << "\tweight = " << apple.weight << "\tcolor = " << apple.color << "\tid = " << apple.id << endl;
}
