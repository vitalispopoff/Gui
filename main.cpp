#include "main.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{	
	try
	{
		return ch18::drill::d05::main();
	}
	catch (exception & e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...)
	{
		cerr << "some exception\n";
		return 2;
	}
}