//*************************************************************************************************
// Дружественные функции и классы пример. Для чего используются. 
// Как определяются. Для двух классов... | Уроки C++ #88  
// ------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//*************************************************************************************************
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

/*--------------------------------------------------------------------
*	 д р у ж е с т в е н н ы е    ф у н к ц и и   и   к л а с с ы
*---------------------------------------------------------------------*/

class Test;						// предварительно объявить прототип класса

class Point {

	// --- С В О Й С Т В А ---
private:
	int x;
	int y;

public:

	// --- К О Н С Т Р У К Т О Р Ы ---

	Point() // Конcтруктор по умолчанию (инициализация данных)
	{
		x = 0;
		y = 0;
	}

	Point(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
		cout << this << " - constructor \"Point\"\n" << endl;
	}


	// --- С Е Т Е Р Ы - Г Е Т Е Р Ы ---

	int GetX()						// GETTER !	для поля X 	
	{
		return x;					// вернуть значене "x"
	}
	int GetY()						// GETTER !	для поля Y	
	{
		return y;
	}

	//void SetX(int valueX)			// SETTER ! параметер "valuaX" не должен быть "x" из области доступа private - для поля X 
	//{
	//	x = valueX;					// уcтановить "x"
	//}
	//void SetY(int valueY)			// SETTER ! для поля Y
	//{
	//	y = valueY;
	//}

	// --- М Е Т О Д Ы ---

	void Print()					// публичный метод 	
	{
		cout << " X = " << x << "\t Y =  " << y << endl << endl;
	}

	// П е р е г р у з к а  о п е р а т о р о в  ("==", "!=", ">" )
	bool operator == (const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.x;
		return temp;
	}

	Point& operator ++ ()				// для префиксной формы инкримента 
	{
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator ++ (int value) 	// для префиксной формы инкримента, "int value" - признак постфиксной операции 
	{
		Point temp(*this);				// запомнить объект в temp

		this->x++;
		this->y++;
		return temp;					// вернуть объект
	}

	// дружетвеннная функция для доступа к свойствам класса (может быть в любой секции доступа-видимомости) 
	friend void ChangeX(Point& value, Test& testValue);

};



// Тестовый класс
class Test
{
	int Data = 0;
	friend void ChangeX(Point& value, Test& testValue);	// дружетвенная функция (аналогично прототипу-объявлению функций)
};


/**************** Ф У Н К Ц И И *************/

// дружетвеннная функция
// не явлется объектом класса и имеет доспуп к "Private" и "Protected" полям класса
void ChangeX(Point& value, Test& testValue)
{
	value.x = -1;
	testValue.Data = -1;
};


/***********************
	  === MAIN ===
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	cout << "\n____________________________________________________________\n" << endl;

	Test test;					// создать объект test класса Test 

	Point a(5, 12);
	a.Print();

	ChangeX(a, test);			// дружественная функцимя с двумя параметрами 
	a.Print();

	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;					// деструктор запукается, когда поиcходит выход из области видимости функции 

}