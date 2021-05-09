#include <stdexcept>
#include "main.h"

using namespace std;

int main()
{	
	try
	{
		//0;
		//test();
		//ch12::_01();
		//ch12::_02();
		//ch12::_03();
		//ch12::_04();
		ch12::_05();
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