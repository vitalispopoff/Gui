#include <stdexcept>
#include "main.h"
#include <iostream>
using namespace std;

int main()
{	
	try
	{
		return ch17::sample::s07::main();
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