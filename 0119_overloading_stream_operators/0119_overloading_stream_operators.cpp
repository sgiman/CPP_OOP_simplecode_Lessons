//*********************************************************************
// Потоковый ввод вывод в файл c++. Перегрузка операторов. 
// Изучение С++ для начинающих. | Visual Studio 2019 | LESSON #119 
// --------------------------------------------------------------------
// С++ | Visual Studio 2022 
// --------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//*********************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

using namespace std;

/*-------------------------------------------------
* перегрузка операторов потокового ввода/вывода
*-------------------------------------------------*/

//--- Class Point ---
class Point
{

	// публичная секция доступа 
public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	// защищённая секция доступа 
private:
	int x;
	int y;
	int z;

	// дружественные функции
	friend ostream& operator << (ostream& os, const Point& point);
	friend istream& operator >> (istream& is, Point& point);

};

/*--------------------------------------------------------
  перегрзука операторов "<<" и ">>" для "ostream"
  базовый класс может хранить ссылку на своего наследника
----------------------------------------------------------*/
// п а р а м е т р ы: 
// (ostream& os) - ссылка на объект типа "ostream" 
// (Point& point) - ссылка на наследника класса "Point"   

// перегрузка "<<" for ostream
ostream& operator << (ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;	// вывод в любой поток (консоль или файл)  
	return os;
}

// перегрузка ">>" for istream
istream& operator >> (istream& is, Point& point) // const не нужна только для считывания  
{
	is >> point.x >> point.y >> point.x;
	return is;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;

	Point point(212, 7, 44);							// cоздать объект "p" класса "Point" 	
	cout << " TEST POINT = " << point << endl;			// вывод данных объекта "p" с перегруженным оператором "<<" в "ostream" 

	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);	// открыть фрайл для чтения, записи и дозаписи

	if (!fs.is_open())
	{
		cout << "\n Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "\n Файл открыт!" << endl;

		//fs << point << endl;		// записать данные в файл с перегруженным оператором "<<"
		//Point pt (11,22,33);
		//fs << pt << endl;			// запись данных в файл

		while (true)
		{
			Point p;
			fs >> p;				// чтение данных в файл
			if (fs.eof())			// проверка на конец файла 
			{
				break;
			}
			cout << " " << p << endl;		// вывод данных на консоль 
		}
	}

	fs.close();
	cout << "\n____________________________________________________________\n" << endl;

	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
