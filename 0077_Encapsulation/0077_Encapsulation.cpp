//*****************************************************************************************************
// Инкапсуляция ООП пример. private методы. Что такое инкапсуляция. C++ Для начинающих.| Уроки C++ #77  
// ----------------------------------------------------------------------------------------------------
// С++ | Visual Studio 2022 
// ----------------------------------------------------------------------------------------------------
// Журавлёв Сергей | #SimpleCode | Udemy
// https://www.udemy.com/user/zhuravliov-sergei/
//
// 2019-2023 @ sgiman
//*****************************************************************************************************

#include <iostream>
#include "utils.h"

using namespace std;

/*--------------------------------------------------------------------
 *	инкапсуляция
 *	private методы
 ---------------------------------------------------------------------*/

class CofeeGrinder
{
private:
	bool voltage = true;

	bool checkVoltage()					// METHOD (private)
	{
		return this->voltage;
	}

public:
	void SetVoltage(bool vol)			// SET
	{
		this->voltage = vol;
	}

	bool GetVoltage()					// GET						
	{
		return this->voltage;
	}

	void Start()						// METHOD (public)
	{
		if (checkVoltage())
			cout << "\tVjuHHH! ВжуХХХ! - WORKS!\n" << endl;
		else
			cout << "\tBeep Beep - STOP!\n" << endl;
	}
};


/***********************
		  MAIN
************************/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");

	cout << "\n____________________________________________________________\n" << endl;

	CofeeGrinder a;
	a.Start();

	a.SetVoltage(false);	// electro off
	a.Start();				// stop

	a.SetVoltage(true);		// electro on
	a.Start();				// works


	//=== END ===
	cout << endl;
	MyDate();
	system("pause");
	return 0;
}