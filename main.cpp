#include <stdexcept>
#include "main.h"
#include <iostream>
using namespace std;

int main()
{	
	try
	{
		//ch13::sample::s09::s09_main();
		
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