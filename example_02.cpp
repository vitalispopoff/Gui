#include<stdexcept>
//#include "_add_libs/PPP2Code/Window.h"
#include "_add_libs/PPP2Code/Simple_window.h"


namespace ch12
{
	using namespace std;
	using namespace Graph_lib;

	int _02()
	{
		try
		{
			Point
				tl {100, 100};
			Simple_window
				win {tl, 600, 400, "Canvas"};
			win.wait_for_button();
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