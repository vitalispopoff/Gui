#include "main.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{	
	try
	{
		return ch19::sample::s16::main();
		//scratch_book::main();
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