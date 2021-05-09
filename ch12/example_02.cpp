#include "../_add_libs/PPP2Code/Simple_window.h"

using namespace Graph_lib;

namespace ch12
{
	namespace example
	{
		void _02()
		{
			Point
				tl {100, 100};
			Simple_window
				win {tl, 600, 400, "Canvas"};
			win.wait_for_button();
		}
	}
}