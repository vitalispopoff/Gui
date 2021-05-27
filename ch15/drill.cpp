#include <iostream>
#include "ch15.h"

namespace ch15
{
	namespace drill
	{
		namespace d01
		{
			void main()
			{
				constexpr Point
					win_anchor	{1000, 500},
					win_size	{600, 600};
				Graph_lib::Window
					win {win_anchor, win_size.x, win_size.y, "Function graphs"};
				Axis
				
				for (char c {0};  c != 'x'; std::cin >> c)
					Fl::wait();
			}

		}
	}
}