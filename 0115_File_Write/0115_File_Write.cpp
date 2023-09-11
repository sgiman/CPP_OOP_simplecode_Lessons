// ******************************************************
// Работа с файлами с++. Запись в файла с++ ifstream. 
// Изучение С++ для начинающих. Урок #115
// ------------------------------------------------------
// С++ | Visual Studio 2022 
// ------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
// ******************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

using namespace std;

/*-----------------------------------------------
* сохранение данных в файл
* стиль С++ и С
*-----------------------------------------------*/
// К Л А С С Ы (С++):
// fstream	- чтение и запись для файла (read/write) 
// ifstream	- чтение данных из файла (read)
// ofstream	- запись данных в файл (write)


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;
	string path = "myFile.txt";
	ofstream fout;

	//fout.open(path);
	fout.open(path, ofstream::app);
	if (!fout.is_open()) // если невозможно открыть файл
	{
		cout << " Ошибка открытия файла! " << endl;
	}
	else
	{
		cout << " Файл открыт! " << endl;
		cout << " Введите 5 чисел." << endl;
		fout << " Это наши данные!" << endl;;
		fout << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << " Введите чиcло (file): ";
			int a;
			cin >> a;
			fout << "INPUT № " << i << " NUMBER = " << a << endl;
		}
	}
	fout.close();
	cout << "\n____________________________________________________________\n" << endl;


	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}
