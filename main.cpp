#include <stdexcept>
#include "main.h"
#include <iostream>
using namespace std;

int main()
{	
	try
	{

		//ch13::excercise::e12::main();
		//ch14::excercise::e11::main();
		ch14::excercise::e14::main();
		
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