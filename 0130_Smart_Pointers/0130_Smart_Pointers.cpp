//********************************************************************
// Умные указатели. Smart pointers. | C++ для начинающих | Урок #130
// https://youtu.be/ixsTu-ULh0Q
// -------------------------------------------------------------------
// С++ | Visual Studio 2022
// -------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//********************************************************************

#include <iostream>
#include "utils.h"

using namespace std;

/* Smart Pointers */

/***************************
 ПРОСТЕЙШИЙ УМНЫЙ УКАЗАТЕЛЬ
****************************/
template <typename T>
class SmartPointer
{
public:
	SmartPointer(T* ptr)	// конструктор
	{
		this->ptr = ptr;	// запомнить принятый адрес (указатель)
		cout << "=== Constructor (smart pointer) ===" << endl;

	}
	~SmartPointer()			// деструктор
	{
		delete ptr;			// освободить память (при выходе из области видимости {} - функция/метод)
		cout << "=== Destructor (clear memory) ===" << endl;
	}

	T& operator *()			// ccылка (адрес) для указателя (для шаблона типов)
	{
		return *ptr;		// вернуть данные по указателю 
	}

private:
	T* ptr;					// обобщенный указатель
};

/***************************
		  M A I N
****************************/
int main()
{
	setlocale(LC_ALL, "ru");

	//--- (1) Cтадартный указатель --- 
	int* ptr = new int(5);					// выделить дин.память для int с числом 5
	int* ptr2 = new int{ 5 };				// или так ....для массива с одним элементом 

	cout << "СТАНДАРТНЫЙ УКАЗАТЕЛЬ: ";
	cout << ptr << endl;					// адрес (указатель) - ptr
	cout << "СОДЕРЖИМОЕ (данные): ";
	cout << *ptr << endl;					// cодержимое (разъименование указателя) - *ptr

	// освободить дин. память - для предотовращения "утечки" памяти 
	delete ptr;
	delete ptr2;

	//--- (2) Умный указатель (Smart Pointer) ----
	SmartPointer<int> pointer = new int(5);
	cout << "\nУМНЫЙ УКАЗАТЕЛЬ: ";
	cout << &*pointer << endl;				// адрес
	cout << "СОДЕРЖИМОЕ (данные): ";
	cout << *pointer << endl;				// содержимое

	//====== END ======
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
