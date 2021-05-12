#include <stdexcept>
#include "main.h"

using namespace std;

int main()
{	
	try
	{
		//ch13::sample::s01();
		
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