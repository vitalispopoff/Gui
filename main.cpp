#include <stdexcept>
#include "main.h"
#include <iostream>
using namespace std;

int main()
{	
	try
	{
		//ch13::drill::d05::main();
		//ch13::excercise::e02::main();
		ch13::excercise::e17::main(); 

		return 0;
	}
	catch (exception & e)
	{
		return 1;
	}
	catch (...)
	{
		return 2;
	}
}