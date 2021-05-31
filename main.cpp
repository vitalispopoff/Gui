#include <stdexcept>
#include "main.h"
#include <iostream>
using namespace std;

int main()
{	
	try
	{
		//ch15::drill::d09::main();
		ch15::excercise::e08::main();
		
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