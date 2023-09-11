//****************************************************************************************
// auto_ptr, unique_ptr, shared_ptr.  Умные указатели.  | C++ для начинающих | Урок #131
// ---------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ---------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//****************************************************************************************

#include <iostream>
#include <string>
#include <memory>
#include "utils.h"

using namespace std;

/*------------------------------
	Smart Pointers:
	 - auto_ptr		(устарел - сейчас не используется)
	 - unique_ptr	(похоже на auto_ptr)
	 - shared_ptr	(новый)
------------------------------*/

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
		cout << "\n=== Constructor (smart pointer) ===" << endl;

	}
	~SmartPointer()			// деструктор
	{
		delete ptr;			// освободить память (при выходе из области видимости {} - функция/метод)
		cout << "\n=== Destructor (clear memory) ===\n" << endl;
	}

	T& operator *()			// ccылка (адрес) для указателя (для шаблона типов)
	{
		return *ptr;		// вернуть данные по указателю 
	}

private:
	T* ptr;					// обобщенный указатель
};


/*********************
		 MAIN
*********************/
int main()
{
	setlocale(LC_ALL, "ru");

	// Два указаиеля указывюат на одну область памяти 

	//SmartPointer<int> sp1 = new int(5);
	//SmartPointer<int> sp2 = sp1;

	/*****************************
		auto_ptr и unique_ptr
		СEЙЧАС НЕ ИСПОЛЬЗУЮТСЯ!
	*****************************/
	//--- auto_ptr ---
	auto_ptr<int> ap1(new int(5));		// указатель ap1
	auto_ptr<int> ap2(ap1);				// указатель ap2, ap1 - удален 

	//--- unique_ptr ---
	unique_ptr<int> p1(new int(5));		// указатель p1
	unique_ptr<int> p2;					// указатель p2 

	//p2 = move(p1);					// указатель p2 = p1 (p1 - удаляется) 
	//p2.swap(p1);						// поменять местами указатели (p1 - удаляется)
	int* p = p1.get();					// прямой (сырой) указатель 

	int* up1 = new int(5);				// указатель up1
	unique_ptr<int> up2(up1);			// указатель up2
	//up2.reset();						// метод для сброса указателя в ручную 
	up2.release();						// данные остаются в данными, up1 - затирается 

	/*************************************
				   shared_ptr
		   для одной области памяти
	**************************************/

	shared_ptr<int> ptr1(new int(5));	// указатель ptr1
	shared_ptr<int> ptr2(ptr1);			// указатель ptr2 (получен от ptr1)

	cout << "\nДва умных указателя \"shared_ptr\" для одной области памяти:\n" << endl;
	cout << "\tptr1 = " << ptr1 << endl;
	cout << "\t*ptr1 = " << *ptr1 << endl << endl;
	cout << "\tptr2 = " << ptr2 << endl;
	cout << "\t*ptr2 = " << *ptr2 << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
