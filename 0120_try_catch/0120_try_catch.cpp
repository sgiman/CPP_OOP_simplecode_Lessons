//************************************************************************************************************
// С++ try catch. Обработка исключений С++. try catch что это. Изучение С++ для начинающих. | Уроки C++ #120 
// -----------------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022
// -----------------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
// 2019-2023 @ sgiman
//************************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

using namespace std;


/*
 *	обработка исключений try-catch
 */

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	// К Л А С Ы:
	// fstream	- чтение и запись для файла (outut) 
	// ifstream	- чтение данных из файла (input)

	string path = "myFile.txt-";		// имя файла (путь)	
	ifstream fin;						// открыть на чтение 

	fin.exceptions(ifstream::badbit | ifstream::failbit); // включить "exceptions" в "ifstream"

	/*-------------------------------------------------
	fin.open(path);
	if (true)
	{
		cout << "Oшибка открытия файла" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
	}
	fin.close();
	---------------------------------------------------*/

	try												// попытка ("try")
	{
		cout << "Попытка окрыть файл!" << endl;
		fin.open(path);								// открыть файл
		cout << "Файл успешно открыт" << endl;

	}
	//catch (const std::exception &ex)				// поймать ("catch") иcключение ("exception" - standard) в объект "ex"
	catch (const ifstream::failure& ex)				// более конкретное исключение для ifstream - "failure" 
	{
		cout << ex.what() << endl;					// что-то пошло не так - "what()" из cтандартного класса "std::exception"
		cout << ex.code() << endl;					// иключение из расширенного класса "ifstream::failure" - "code()" 
		cout << "Oшибка открытия файла" << endl;
	}


	//=== END ===
	cout << endl;
	//MyDate();
	system("pause");
	return 0;
}
