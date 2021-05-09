#include<stdexcept>

#include "_add_libs/PPP2Code/Window.h"


namespace ch12
{
	using namespace std;
	using namespace Graph_lib;

	int _02()
	{
		try
		{
			/// ...
		}
		catch(exception & e)
		{
			/// ...

			return 1;
		}
		catch(...)
		{
			/// ...

			return 2;
		}
	}
}