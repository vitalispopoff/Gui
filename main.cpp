#include <stdexcept>
#include "main.h"

using namespace std;

int main()
{	
	try
	{
		using namespace ch12;
		//0;
		//test();
		//_01();
		//_02();
		//_03();
		//_04();
		//_05();
		//_06();
		//_07();
		_08();

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